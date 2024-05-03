//#include "Tablero.h"
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "freeglut.h"
#include "Tablero.h"
#include<iostream>

using namespace std;

extern Tablero tablero;

//VARIABLES PARA CONTROLAR LA PIEZA QUE HAY EN UNA CASILLA -> HABRIA QUE CAMBIAR LAS FUNCIONES DE PIEZA PARA QUE RECIBIESEN TAMBIEN ARGUMENTOS DE COLOR Y NUMERO DE PIEZA
//BLANCAS
int PeonB1x = 0; int PeonB1y = 1;
int PeonB2x = 1; int PeonB2y = 1;
int PeonB3x = 2; int PeonB3y = 1;
int PeonB4x = 3; int PeonB4y = 1;

int TorreB1x = 0; int TorreB1y = 0;
int TorreB2x = 3; int TorreB2y = 0;

//NEGRAS
int PeonN1x = 0; int PeonN1y = 3;
int PeonN2x = 1; int PeonN2y = 3;
int PeonN3x = 2; int PeonN3y = 3;
int PeonN4x = 3; int PeonN4y = 3;

int TorreN1x = 0; int TorreN1y = 4;
int TorreN2x = 3; int TorreN2y = 4;

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

	Peon* ptrPeonB1 = new Peon(1, 1, PeonB1x, PeonB1y, "Peon"); Peon* ptrPeonB2 = new Peon(2, 1, PeonB2x, PeonB2y, "Peon");
	Peon* ptrPeonB3 = new Peon(3, 1, PeonB3x, PeonB3y, "Peon"); Peon* ptrPeonB4 = new Peon(4, 1, PeonB4x, PeonB4y, "Peon");

	Peon* ptrPeonN1 = new Peon(1, 0, PeonN1x, PeonN1y, "Peon"); Peon* ptrPeonN2 = new Peon(2, 0, PeonN2x, PeonN2y, "Peon");
	Peon* ptrPeonN3 = new Peon(3, 0, PeonN3x, PeonN3y, "Peon"); Peon* ptrPeonN4 = new Peon(4, 0, PeonN4x, PeonN4y, "Peon");

	Torre* ptrTorreB1 = new Torre(1, 1, TorreB1x, TorreB1y, "Torre"); Torre* ptrTorreB2 = new Torre(2, 1, TorreB2x, TorreB2y, "Torre");
	Torre* ptrTorreN1 = new Torre(1, 0, TorreN1x, TorreN1y, "Torre"); Torre* ptrTorreN2 = new Torre(2, 0, TorreN2x, TorreN2y, "Torre");


	//PRUEBAS DE MOVIMIENTO
	cout << "La posicion del peon numero " << ptrPeonB1->getNumPeon()<<" de color: "<< ptrPeonB1->getColor()<<" es : "<<" ("
	<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;

	ptrPeonB1->mover_arriba(4,1);
	cout << "La nueva posicion del peon numero " << ptrPeonB1->getNumPeon() << " de color: " << ptrPeonB1->getColor() << " es : " << " ("
		<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;
	ptrPeonB1->mover_arriba(1,1);
	cout << "La nueva posicion del peon numero " << ptrPeonB1->getNumPeon() << " de color: " << ptrPeonB1->getColor() << " es : " << " ("
		<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;
	ptrPeonB1->mover_arriba(1,1);
	cout << "La nueva posicion del peon numero " << ptrPeonB1->getNumPeon() << " de color: " << ptrPeonB1->getColor() << " es : " << " ("
		<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;
	ptrPeonB1->mover_arriba(1,1);
	cout << "La nueva posicion del peon numero " << ptrPeonB1->getNumPeon() << " de color: " << ptrPeonB1->getColor() << " es : " << " ("
		<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;
	ptrPeonB1->mover_arriba(1,1);
	cout << "La nueva posicion del peon numero " << ptrPeonB1->getNumPeon() << " de color: " << ptrPeonB1->getColor() << " es : " << " ("
		<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;

	ptrPeonB1->mover_arr_dcha(1,1);
	cout << "La nueva posicion del peon numero " << ptrPeonB1->getNumPeon() << " de color: " << ptrPeonB1->getColor() << " es : " << " ("
		<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;






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
