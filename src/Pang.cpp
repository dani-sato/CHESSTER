//#include "Tablero.h"
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "Rey.h"
#include "freeglut.h"
#include "Tablero.h"
#include<iostream>
#include "ETSIDI.h"

using namespace std;

extern Tablero tablero;

ETSIDI::Sprite peonb1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peonblanco.png", 0,0,1,1 };

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc,char* argv[])
{
	Pieza pieza; 
	pieza.rellenarPos();



	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	//Codigo de dibujo aquí
	gluLookAt(1.5, 2, 8,  // Posición del ojo: arriba del centro del tablero a 10 unidades de altura
		1.5, 2, 0,   // Centro del tablero
		0, 1, 0);      // Vector up en dirección Y


	peonb1.draw();
	
	for (int i = 0; i < 5; i++) { // Filas
		for (int j = 0; j < 4; j++) { // Columnas
			// Calcula la coordenada x de la esquina inferior izquierda de la casilla
			float x = -0.5f + j;
			// Calcula la coordenada y de la esquina inferior izquierda de la casilla
			float y = -0.5f + i;

			// Alterna los colores de las casillas
			if ((i + j) % 2 == 0) {
				glColor3ub(180, 180, 180); // Blanco
			}
			else {
				glColor3ub(80, 80, 80);// Negro
			}
			glBegin(GL_POLYGON); // Comienza a dibujar un cuadrado
			glVertex3f(x, y,-0.5);
			glVertex3f(x + 1, y,-0.5);
			glVertex3f(x + 1, y + 1,-0.5);
			glVertex3f(x, y + 1,-0.5);
			glEnd();
		}
	}
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado


	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
