//#include "Tablero.h"
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "Rey.h"
#include "freeglut.h"
#include "Tablero.h"
#include<iostream>

using namespace std;

extern Tablero tablero;

//VARIABLES PARA CONTROLAR LA PIEZA QUE HAY EN UNA CASILLA -> HABRIA QUE CAMBIAR LAS FUNCIONES DE PIEZA PARA QUE RECIBIESEN TAMBIEN ARGUMENTOS DE COLOR Y NUMERO DE PIEZA

//BLANCAS
extern int PeonB1x; extern int PeonB1y;  //No se actualizan los cambios
extern int PeonB2x; extern int PeonB2y;
extern int PeonB3x; extern int PeonB3y;
extern int PeonB4x; extern int PeonB4y;

int TorreB1x = 0; int TorreB1y = 0;
int TorreB2x = 3; int TorreB2y = 0;

int ReyBx = 2; int ReyBy = 0;

int ReinaBx = 1; int ReinaBy = 0;

//NEGRAS
extern int PeonN1x; extern int PeonN1y;
extern int PeonN2x; extern int PeonN2y;
extern int PeonN3x; extern int PeonN3y;
extern int PeonN4x; extern int PeonN4y;

int TorreN1x = 0; int TorreN1y = 4;
int TorreN2x = 3; int TorreN2y = 4;

int ReyNx = 2; int ReyNy = 4;

int ReinaNx = 1; int ReinaNy = 4;

//Piezas
Peon* ptrPeonB1 = new Peon(1, 1, PeonB1x, PeonB1y, "Peon"); Peon* ptrPeonB2 = new Peon(2, 1, PeonB2x, PeonB2y, "Peon");
Peon* ptrPeonB3 = new Peon(3, 1, PeonB3x, PeonB3y, "Peon"); Peon* ptrPeonB4 = new Peon(4, 1, PeonB4x, PeonB4y, "Peon");

Peon* ptrPeonN1 = new Peon(1, 0, PeonN1x, PeonN1y, "Peon"); Peon* ptrPeonN2 = new Peon(2, 0, PeonN2x, PeonN2y, "Peon");
Peon* ptrPeonN3 = new Peon(3, 0, PeonN3x, PeonN3y, "Peon"); Peon* ptrPeonN4 = new Peon(4, 0, PeonN4x, PeonN4y, "Peon");

Torre* ptrTorreB1 = new Torre(1, 1, TorreB1x, TorreB1y, "Torre"); Torre* ptrTorreB2 = new Torre(2, 1, TorreB2x, TorreB2y, "Torre");
Torre* ptrTorreN1 = new Torre(1, 0, TorreN1x, TorreN1y, "Torre"); Torre* ptrTorreN2 = new Torre(2, 0, TorreN2x, TorreN2y, "Torre");

Rey* ptrReyB = new Rey(1, ReyBx, ReyBy, "Rey");
Rey* ptrReyN = new Rey(0, ReyNx, ReyNy, "Rey");

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


	//PRUEBAS DE MOVIMIENTO
	cout << "La posicion del peon numero " << ptrPeonB2->getNumPeon()<<" de color: "<< ptrPeonB2->getColor()<<" es : "<<" ("
	<< ptrPeonB2->getPosx() << ", " << ptrPeonB2->getPosy() << ")" << endl;

	cout << endl;
	ptrPeonB2->mover_arriba(1,1,1);
	cout << "La nueva posicion del peon numero " << ptrPeonB2->getNumPeon() << " de color: " << ptrPeonB2->getColor() << " es : " << " ("
		<< ptrPeonB2->getPosx() << ", " << ptrPeonB2->getPosy() << ")" << endl;
	cout << endl;

	ptrPeonN1->mover_abajo(1,1,1);
	cout << "La nueva posicion del peon numero " << ptrPeonN1->getNumPeon() << " de color: " << ptrPeonN1->getColor() << " es : " << " ("
		<< ptrPeonN1->getPosx() << ", " << ptrPeonN1->getPosy() << ")" << endl;
	cout << endl;

	ptrPeonB3->mover_arriba(1, 1, 1);
	cout << "La nueva posicion del peon numero " << ptrPeonB3->getNumPeon() << " de color: " << ptrPeonB3->getColor() << " es : " << " ("
		<< ptrPeonB3->getPosx() << ", " << ptrPeonB3->getPosy() << ")" << endl;
	cout << endl;

	ptrPeonN4->mover_abajo_izq(1, 1, 1);
	cout << "La nueva posicion del peon numero " << ptrPeonN4->getNumPeon() << " de color: " << ptrPeonN4->getColor() << " es : " << " ("
		<< ptrPeonN4->getPosx() << ", " << ptrPeonN4->getPosy() << ")" << endl;
	cout << endl;

	ptrPeonB4->mover_arr_izq(1, 1, 1);
	cout << "La nueva posicion del peon numero " << ptrPeonB4->getNumPeon() << " de color: " << ptrPeonB4->getColor() << " es : " << " ("
		<< ptrPeonB4->getPosx() << ", " << ptrPeonB4->getPosy() << ")" << endl;
	cout << endl;

	ptrPeonN2->mover_abajo_dcha(1, 1, 1);
	cout << "La nueva posicion del peon numero " << ptrPeonN2->getNumPeon() << " de color: " << ptrPeonN2->getColor() << " es : " << " ("
		<< ptrPeonN2->getPosx() << ", " << ptrPeonN2->getPosy() << ")" << endl;
	cout << endl;

	ptrReyB->mover_arriba(1, 1);
	cout << "La nueva posicion del rey de color: " << ptrReyB->getColor() << " es : " << " ("
		<< ptrReyB->getPosx() << ", " << ptrReyB->getPosy() << ")" << endl;

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
