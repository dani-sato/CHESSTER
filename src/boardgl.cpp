//Boardgl.cpp
#include "gltools.h"
#include "boardgl.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "glut.h"
#include "piece.h"
#include "board.h"
#include "ETSIDI.h"
#include <thread>
#include <chrono>

using ETSIDI::playMusica;
using ETSIDI::stopMusica;
using ETSIDI::play;

#define DEG2RAD M_PI/180.0

using namespace ETSIDI;
using ETSIDI::getTexture;

void TableroGL::init() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH); // Habilitar el modelo de sombreado suave

	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_NORMALIZE); // Normaliza las normales para que la iluminación sea consistente
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
}

void DrawCaballo2D() {
	glDisable(GL_LIGHTING); // Desactivar iluminación para dibujos 2D

	// Base del caballo
	glBegin(GL_QUADS);
	glVertex3f(-0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.065f, 0.01f);
	glVertex3f(-0.03f, -0.065f, 0.01f);
	glEnd();

	// Primera sección de la base
	glBegin(GL_QUADS);
	glVertex3f(-0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.055f, 0.01f);
	glVertex3f(-0.025f, -0.055f, 0.01f);
	glEnd();

	// Segunda sección de la base (estrechamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.045f, 0.01f);
	glVertex3f(-0.02f, -0.045f, 0.01f);
	glEnd();

	// Cuerpo del caballo
	glBegin(GL_POLYGON);
	glVertex3f(-0.015f, -0.045f, 0.01f);
	glVertex3f(0.015f, -0.045f, 0.01f);
	glVertex3f(0.015f, -0.015f, 0.01f);
	glVertex3f(0.02f, 0.0f, 0.01f);
	glVertex3f(0.01f, 0.015f, 0.01f);
	glVertex3f(-0.005f, 0.025f, 0.01f);
	glVertex3f(-0.015f, 0.015f, 0.01f);
	glVertex3f(-0.02f, 0.0f, 0.01f);
	glVertex3f(-0.015f, -0.015f, 0.01f);
	glEnd();

	// Detalles de la cabeza del caballo
	glBegin(GL_LINES);
	// Línea de la mandíbula
	glVertex3f(-0.015f, 0.015f, 0.01f);
	glVertex3f(-0.01f, 0.02f, 0.01f);

	// Línea del cuello
	glVertex3f(-0.01f, 0.02f, 0.01f);
	glVertex3f(-0.015f, 0.025f, 0.01f);

	// Línea de la melena
	glVertex3f(-0.015f, 0.025f, 0.01f);
	glVertex3f(-0.005f, 0.035f, 0.01f);

	// Línea de la frente
	glVertex3f(-0.005f, 0.035f, 0.01f);
	glVertex3f(0.005f, 0.035f, 0.01f);

	// Línea del hocico
	glVertex3f(0.005f, 0.035f, 0.01f);
	glVertex3f(0.015f, 0.03f, 0.01f);

	// Línea del hocico
	glVertex3f(0.015f, 0.03f, 0.01f);
	glVertex3f(0.02f, 0.025f, 0.01f);

	// Línea de la nariz
	glVertex3f(0.02f, 0.025f, 0.01f);
	glVertex3f(0.01f, 0.02f, 0.01f);

	// Línea de la mandíbula
	glVertex3f(0.01f, 0.02f, 0.01f);
	glVertex3f(-0.015f, 0.015f, 0.01f);
	glEnd();

	// Ojo del caballo
	glBegin(GL_QUADS);
	glVertex3f(0.005f, 0.03f, 0.01f);
	glVertex3f(0.01f, 0.03f, 0.01f);
	glVertex3f(0.01f, 0.025f, 0.01f);
	glVertex3f(0.005f, 0.025f, 0.01f);
	glEnd();

	glEnable(GL_LIGHTING); // Reactivar iluminación si es necesario
}


void DrawAlfil2D() {
	glDisable(GL_LIGHTING); // Desactivar iluminación para dibujos 2D

	// Base del alfil
	glBegin(GL_QUADS);
	glVertex3f(-0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.065f, 0.01f);
	glVertex3f(-0.03f, -0.065f, 0.01f);
	glEnd();

	// Primera sección de la base
	glBegin(GL_QUADS);
	glVertex3f(-0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.055f, 0.01f);
	glVertex3f(-0.025f, -0.055f, 0.01f);
	glEnd();

	// Segunda sección de la base (estrechamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.045f, 0.01f);
	glVertex3f(-0.02f, -0.045f, 0.01f);
	glEnd();

	// Tercera sección (ensanchamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.025f, -0.045f, 0.01f);
	glVertex3f(0.025f, -0.045f, 0.01f);
	glVertex3f(0.025f, -0.035f, 0.01f);
	glVertex3f(-0.025f, -0.035f, 0.01f);
	glEnd();

	// Cuerpo del alfil
	glBegin(GL_QUADS);
	glVertex3f(-0.015f, -0.035f, 0.01f);
	glVertex3f(0.015f, -0.035f, 0.01f);
	glVertex3f(0.015f, 0.015f, 0.01f);
	glVertex3f(-0.015f, 0.015f, 0.01f);
	glEnd();

	// Cuello del alfil (estrechamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.02f, 0.015f, 0.01f);
	glVertex3f(0.02f, 0.015f, 0.01f);
	glVertex3f(0.02f, 0.03f, 0.01f);
	glVertex3f(-0.02f, 0.03f, 0.01f);
	glEnd();

	// Cabeza del alfil (redonda)
	float radius = 0.012f;
	int num_segments = 100; // Número de segmentos para aproximar el círculo
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.03f + radius, 0.01f); // Centro del círculo
	for (int i = 0; i <= num_segments; i++) {
		float angle = 2.0f * M_PI * float(i) / float(num_segments);
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex3f(dx, 0.03f + dy, 0.01f);
	}
	glEnd();

	// Corte de la cabeza del alfil
	glBegin(GL_QUADS);
	glVertex3f(-0.01f, 0.03f, 0.01f);
	glVertex3f(0.01f, 0.03f, 0.01f);
	glVertex3f(0.01f, 0.04f, 0.01f);
	glVertex3f(-0.01f, 0.04f, 0.01f);
	glEnd();

	glEnable(GL_LIGHTING); // Reactivar iluminación si es necesario
}


void DrawTorre2D() {
	glDisable(GL_LIGHTING); // Desactivar iluminación para dibujos 2D

	// Base de la torre
	glBegin(GL_QUADS);
	glVertex3f(-0.0225f, -0.0675f, 0.01f);
	glVertex3f(0.0225f, -0.0675f, 0.01f);
	glVertex3f(0.0225f, -0.0525f, 0.01f);
	glVertex3f(-0.0225f, -0.0525f, 0.01f);
	glEnd();

	// Cuerpo de la torre
	glBegin(GL_QUADS);
	glVertex3f(-0.015f, -0.0525f, 0.01f);
	glVertex3f(0.015f, -0.0525f, 0.01f);
	glVertex3f(0.015f, 0.0375f, 0.01f);
	glVertex3f(-0.015f, 0.0375f, 0.01f);
	glEnd();

	// Parte superior de la torre
	glBegin(GL_QUADS);
	glVertex3f(-0.0225f, 0.0375f, 0.01f);
	glVertex3f(0.0225f, 0.0375f, 0.01f);
	glVertex3f(0.0225f, 0.0525f, 0.01f);
	glVertex3f(-0.0225f, 0.0525f, 0.01f);
	glEnd();

	// Merlones de la torre
	glBegin(GL_QUADS);
	glVertex3f(-0.0225f, 0.0525f, 0.01f);
	glVertex3f(-0.015f, 0.0525f, 0.01f);
	glVertex3f(-0.015f, 0.0675f, 0.01f);
	glVertex3f(-0.0225f, 0.0675f, 0.01f);

	glVertex3f(-0.0075f, 0.0525f, 0.01f);
	glVertex3f(0.0f, 0.0525f, 0.01f);
	glVertex3f(0.0f, 0.0675f, 0.01f);
	glVertex3f(-0.0075f, 0.0675f, 0.01f);

	glVertex3f(0.0075f, 0.0525f, 0.01f);
	glVertex3f(0.015f, 0.0525f, 0.01f);
	glVertex3f(0.015f, 0.0675f, 0.01f);
	glVertex3f(0.0075f, 0.0675f, 0.01f);

	glVertex3f(0.015f, 0.0525f, 0.01f);
	glVertex3f(0.0225f, 0.0525f, 0.01f);
	glVertex3f(0.0225f, 0.0675f, 0.01f);
	glVertex3f(0.015f, 0.0675f, 0.01f);
	glEnd();

	glEnable(GL_LIGHTING); // Reactivar iluminación si es necesario
}

void DrawPeon2D() {
	glDisable(GL_LIGHTING); // Desactivar iluminación para dibujos 2D

	// Base del peón
	glBegin(GL_QUADS);
	glVertex3f(-0.0225f, -0.0675f, 0.01f);
	glVertex3f(0.0225f, -0.0675f, 0.01f);
	glVertex3f(0.0225f, -0.0525f, 0.01f);
	glVertex3f(-0.0225f, -0.0525f, 0.01f);
	glEnd();

	// Cuerpo del peón
	glBegin(GL_QUADS);
	glVertex3f(-0.015f, -0.0525f, 0.01f);
	glVertex3f(0.015f, -0.0525f, 0.01f);
	glVertex3f(0.015f, 0.0375f, 0.01f);
	glVertex3f(-0.015f, 0.0375f, 0.01f);
	glEnd();

	// Cabeza del peón (redonda)
	float radius = 0.015f;
	int num_segments = 100; // Número de segmentos para aproximar el círculo
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0525f + radius, 0.01f); // Centro del círculo
	for (int i = 0; i <= num_segments; i++) {
		float angle = 2.0f * M_PI * float(i) / float(num_segments);
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex3f(dx, 0.0525f + dy, 0.01f);
	}
	glEnd();

	glEnable(GL_LIGHTING); // Reactivar iluminación si es necesario
}

void DrawReina2D() {
	glDisable(GL_LIGHTING); // Desactivar iluminación para dibujos 2D

	// Base de la reina
	glBegin(GL_QUADS);
	glVertex3f(-0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.065f, 0.01f);
	glVertex3f(-0.03f, -0.065f, 0.01f);
	glEnd();

	// Primera sección
	glBegin(GL_QUADS);
	glVertex3f(-0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.055f, 0.01f);
	glVertex3f(-0.025f, -0.055f, 0.01f);
	glEnd();

	// Segunda sección (estrechamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.03f, 0.01f);
	glVertex3f(-0.02f, -0.03f, 0.01f);
	glEnd();

	// Tercera sección (ensanchamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.025f, -0.03f, 0.01f);
	glVertex3f(0.025f, -0.03f, 0.01f);
	glVertex3f(0.025f, -0.02f, 0.01f);
	glVertex3f(-0.025f, -0.02f, 0.01f);
	glEnd();

	// Cuarta sección (estrechamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.015f, -0.02f, 0.01f);
	glVertex3f(0.015f, -0.02f, 0.01f);
	glVertex3f(0.015f, 0.02f, 0.01f);
	glVertex3f(-0.015f, 0.02f, 0.01f);
	glEnd();

	// Quinta sección (ensanchamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.02f, 0.02f, 0.01f);
	glVertex3f(0.02f, 0.02f, 0.01f);
	glVertex3f(0.02f, 0.03f, 0.01f);
	glVertex3f(-0.02f, 0.03f, 0.01f);
	glEnd();

	// Cabeza de la reina (redonda)
	float radius = 0.012f;
	int num_segments = 100; // Número de segmentos para aproximar el círculo
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.03f + radius, 0.01f); // Centro del círculo
	for (int i = 0; i <= num_segments; i++) {
		float angle = 2.0f * M_PI * float(i) / float(num_segments);
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex3f(dx, 0.03f + dy, 0.01f);
	}
	glEnd();

	// Corona de la reina con cinco puntas
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.03f, 0.03f, 0.01f); // Primera punta
	glVertex3f(-0.02f, 0.07f, 0.01f);
	glVertex3f(-0.01f, 0.03f, 0.01f);

	glVertex3f(-0.015f, 0.03f, 0.01f); // Segunda punta
	glVertex3f(-0.0075f, 0.08f, 0.01f);
	glVertex3f(0.0f, 0.03f, 0.01f);

	glVertex3f(0.0f, 0.03f, 0.01f); // Tercera punta
	glVertex3f(0.0075f, 0.08f, 0.01f);
	glVertex3f(0.015f, 0.03f, 0.01f);

	glVertex3f(0.01f, 0.03f, 0.01f); // Cuarta punta
	glVertex3f(0.02f, 0.07f, 0.01f);
	glVertex3f(0.03f, 0.03f, 0.01f);
	glEnd();

	glEnable(GL_LIGHTING); // Reactivar iluminación si es necesario
}


void DrawRey2D() {
	glDisable(GL_LIGHTING); // Desactivar iluminación para dibujos 2D

	// Base del rey
	glBegin(GL_QUADS);
	glVertex3f(-0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.07f, 0.01f);
	glVertex3f(0.03f, -0.065f, 0.01f);
	glVertex3f(-0.03f, -0.065f, 0.01f);
	glEnd();

	// Primera sección
	glBegin(GL_QUADS);
	glVertex3f(-0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.065f, 0.01f);
	glVertex3f(0.025f, -0.055f, 0.01f);
	glVertex3f(-0.025f, -0.055f, 0.01f);
	glEnd();

	// Segunda sección (estrechamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.055f, 0.01f);
	glVertex3f(0.02f, -0.03f, 0.01f);
	glVertex3f(-0.02f, -0.03f, 0.01f);
	glEnd();

	// Tercera sección (ensanchamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.025f, -0.03f, 0.01f);
	glVertex3f(0.025f, -0.03f, 0.01f);
	glVertex3f(0.025f, -0.02f, 0.01f);
	glVertex3f(-0.025f, -0.02f, 0.01f);
	glEnd();

	// Cuarta sección (estrechamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.015f, -0.02f, 0.01f);
	glVertex3f(0.015f, -0.02f, 0.01f);
	glVertex3f(0.015f, 0.02f, 0.01f);
	glVertex3f(-0.015f, 0.02f, 0.01f);
	glEnd();

	// Quinta sección (ensanchamiento)
	glBegin(GL_QUADS);
	glVertex3f(-0.02f, 0.02f, 0.01f);
	glVertex3f(0.02f, 0.02f, 0.01f);
	glVertex3f(0.02f, 0.03f, 0.01f);
	glVertex3f(-0.02f, 0.03f, 0.01f);
	glEnd();

	// Cabeza del rey (redonda)
	float radius = 0.015f;
	int num_segments = 100; // Número de segmentos para aproximar el círculo
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.03f + radius, 0.01f); // Centro del círculo
	for (int i = 0; i <= num_segments; i++) {
		float angle = 2.0f * M_PI * float(i) / float(num_segments);
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex3f(dx, 0.03f + dy, 0.01f);
	}
	glEnd();

	// Corona del rey con tres puntas
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.02f, 0.03f, 0.01f); // Primera punta
	glVertex3f(-0.01f, 0.06f, 0.01f);
	glVertex3f(-0.005f, 0.03f, 0.01f);

	glVertex3f(-0.005f, 0.03f, 0.01f); // Segunda punta
	glVertex3f(0.0f, 0.07f, 0.01f);
	glVertex3f(0.005f, 0.03f, 0.01f);

	glVertex3f(0.005f, 0.03f, 0.01f); // Tercera punta
	glVertex3f(0.01f, 0.06f, 0.01f);
	glVertex3f(0.02f, 0.03f, 0.01f);
	glEnd();

	// Cruz en la parte superior de la corona, más baja
	glBegin(GL_QUADS);
	glVertex3f(-0.005f, 0.05f, 0.01f);
	glVertex3f(0.005f, 0.05f, 0.01f);
	glVertex3f(0.005f, 0.07f, 0.01f);
	glVertex3f(-0.005f, 0.07f, 0.01f);

	glVertex3f(-0.01f, 0.06f, 0.01f);
	glVertex3f(0.01f, 0.06f, 0.01f);
	glVertex3f(0.01f, 0.07f, 0.01f);
	glVertex3f(-0.01f, 0.07f, 0.01f);
	glEnd();

	glEnable(GL_LIGHTING); // Reactivar iluminación si es necesario
}
