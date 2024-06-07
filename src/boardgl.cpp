//Boardgl.cpp
#include "gltools.h"
#include "boardgl.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "glut.h"
#include "piece.h"
#include "board.h"
#include "board.cpp"
#include "ETSIDI.h"

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


void TableroGL::DrawGrid() {
	float dist_filas = filas * width;
	float dist_columnas = columnas * width;
	bool isGray = true;  // Comienza con gris

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			glColor3f(isGray ? 0.2f : 0.8f, isGray ? 0.2f : 0.8f, isGray ? 0.2f : 0.8f);  // Gris o blanco
			glBegin(GL_QUADS);
			glVertex3f(j * width, -i * width, 0);
			glVertex3f((j + 1) * width, -i * width, 0);
			glVertex3f((j + 1) * width, -(i + 1) * width, 0);
			glVertex3f(j * width, -(i + 1) * width, 0);
			glEnd();
			isGray = !isGray;  // Alterna el color para la siguiente casilla
		}
		if (columnas % 2 == 0) isGray = !isGray; // Cambia el inicio de color en la siguiente fila si columnas es par
	}

	GLTools::Color(gltools::BLACK);
	for (int i = 0; i <= filas; i++) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(0, -i * width, 0);
		glVertex3f(dist_columnas, -i * width, 0);
		glEnd();
	}
	for (int j = 0; j <= columnas; j++) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(j * width, 0, 0);
		glVertex3f(j * width, -dist_filas, 0);
		glEnd();
	}

	// Dibuja el borde exterior
	glLineWidth(4);  // Ajusta el grosor del borde si es necesario
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0);
	glVertex3f(dist_columnas, 0, 0);
	glVertex3f(dist_columnas, -dist_filas, 0);
	glVertex3f(0, -dist_filas, 0);
	glEnd();
}


void TableroGL::DrawCell(int i, int j) {
	float glx, gly;

	switch (m_tablero->getTab()[i][j].getTipo()) {
	case Object::PIEZA_BLANCA:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::GREY);
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width / 2.0f) * 0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::PIEZA_NEGRA:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::BLACK);
		glTranslatef(glx, gly, 0);
	//	sprite = new ETSIDI::Sprite("C:/Users/Daniel Sato/source/repos/glut_boardgame4/imagenes/reinablanca.png", -2, -2, 1, 1);
	//	sprite->draw();
	//	torrenegra->draw();
		glutSolidSphere((width / 2.0f) * 0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::TORRE_BLANCA:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::GREY);
		glTranslatef(glx, gly, 0);
		glutSolidCube((width / 2.0f) * 0.9f);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::TORRE_NEGRA:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::BLACK);
		glTranslatef(glx, gly, 0);
		glutSolidCube((width / 2.0f) * 0.9f);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::REY_BLANCO:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::GREEN);
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width / 2.0f) * 0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::REY_NEGRO:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::BLUE);
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width / 2.0f) * 0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::PEON_BLANCO:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::GREY);
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width / 3.0f) * 0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::PEON_NEGRO:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::BLACK);
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width / 3.0f) * 0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);
		break;
	case Object::CASILLA_VACIA:
	default:
		;
	}
}



void TableroGL::Draw() {
	center_x = columnas * width / 2;
	center_y = -filas * width / 2;
	center_z = 0;

	// Borrado de la pantalla    
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(center_x, center_y, dist, center_x, center_y, center_z, 0, 1, 0);

	// Dibuja el tablero y la cuadrícula
	DrawGrid();
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			DrawCell(i, j);
		}
	}

	// Dibuja un rectángulo transparente sobre el tablero para capturar la entrada del mouse con gluUnProject
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLTools::Color(gltools::WHITE, 1.0f);
	glTranslatef(center_x, center_y, center_z);
	glRectf(columnas * width / 2.0f, filas * width / 2.0f, -columnas * width / 2.0f, -filas * width / 2.0f);
	glTranslatef(-center_x, -center_y, -center_z);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
}


void TableroGL::MouseButton(int x, int y, int button, bool down, bool sKey, bool ctrlKey) {
	/////////////////////////
	// sets state of mouse control buttons + special keys

	/////////
	//computes cell coordinates from mouse coordinates

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//finally cell coordinates
	world2cell(posX, posY, xcell_sel, ycell_sel);

	///////////////////////////	
	//capture other mouse events

	if (down) {
		controlKey = ctrlKey;
		shiftKey = sKey;
	}
	else {
		controlKey = shiftKey = false;
	}

	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;
	///////////////////////////

		//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

		//print cell coordinates after click
	if (down)
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;
	// Calcula las coordenadas de la celda desde las coordenadas del mundo
	world2cell(posX, posY, xcell_sel, ycell_sel);

	if (down && button == MOUSE_LEFT_BUTTON) {
		if (selectedPiece) {
			// Intenta mover la pieza seleccionada a la nueva ubicación
			bool moveSuccessful = m_tablero->movePiece(selected_x, selected_y, xcell_sel, ycell_sel);
			if (moveSuccessful) {
				moveRandomBlackPiece(); // Mueve una pieza negra automáticamente si la blanca se movió
			}
			selectedPiece = false; // Deselecciona la pieza después de moverla
		}
		else {
			// Selecciona la pieza en la ubicación actual
			selected_x = xcell_sel;
			selected_y = ycell_sel;
			selectedPiece = true;
		}
	}

	glutPostRedisplay();
}

void TableroGL::KeyDown(unsigned char key) {
	//////////////////
	// enlarges or reduces grid by one

	if (key == 's') {
		//** do something
		//if(N<=8) N++;
	}
	if (key == 'a') {
		//** do something
		//if(N>=2) N--;
	}
}

void TableroGL::moveRandomBlackPiece() {

	vector<pair<int, int>> piezasNegras;
	// Encuentra todas las piezas negras, incluyendo torres
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (m_tablero->getTab()[i][j].getTipo() == Pieza::PIEZA_NEGRA ||
				m_tablero->getTab()[i][j].getTipo() == Pieza::TORRE_NEGRA ||
				m_tablero->getTab()[i][j].getTipo() == Pieza::REY_NEGRO ||
				m_tablero->getTab()[i][j].getTipo() == Pieza::PEON_NEGRO) {
				piezasNegras.push_back(make_pair(i, j));
			}
		}
	}
	// Intenta mover una pieza negra aleatoriamente hasta que tenga éxito
	while (!piezasNegras.empty()) {
		int randIndex = rand() % piezasNegras.size();
		int from_x = piezasNegras[randIndex].first;
		int from_y = piezasNegras[randIndex].second;

		int attempts = 0;
		bool movimientoHecho = false;
		while (attempts < 8) {
			int dx = rand() % 3 - 1; // -1, 0, 1
			int dy = rand() % 3 - 1; // -1, 0, 1
			if (dx != 0 || dy != 0) {
				int to_x = from_x + dx;
				int to_y = from_y + dy;
				if (to_x >= 0 && to_x < filas && to_y >= 0 && to_y < columnas) {
					if (m_tablero->movePiece(from_x, from_y, to_x, to_y)) {
						movimientoHecho = true;
						break;
					}
				}
			}
			attempts++;
		}

		if (movimientoHecho) {
			break;
		}
		else {
			// Elimina la pieza de la lista si no se pudo mover
			piezasNegras.erase(piezasNegras.begin() + randIndex);
		}
	}
}

