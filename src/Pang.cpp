#include "Tablero.h"
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "freeglut.h"
#include<iostream>

using namespace std;

Tablero tablero;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc,char* argv[])
{
	Peon* ptrPeonB1 = new Peon(1, 1, 2.5, 17.5, "Peon"); Peon* ptrPeonB2 = new Peon(2, 1, 7.5, 17.5, "Peon");
	Peon* ptrPeonB3 = new Peon(3, 1, 12.5, 17.5, "Peon"); Peon* ptrPeonB4 = new Peon(4, 1, 17.5, 17.5, "Peon");

	Peon* ptrPeonN1 = new Peon(1, 0, 2.5, 5.5, "Peon"); Peon* ptrPeonN2 = new Peon(2, 0, 7.5, 5.5, "Peon");
	Peon* ptrPeonN3 = new Peon(3, 0, 12.5, 5.5, "Peon"); Peon* ptrPeonN4 = new Peon(4, 0, 17.5, 5.5, "Peon");

	Torre* ptrTorreB1 = new Torre(1, 1, 2.5, 22.5, "Torre"); Torre* ptrTorreB2 = new Torre(2, 1, 17.5, 22.5, "Torre");
	Torre* ptrTorreN1 = new Torre(1, 0, 2.5, 5.5, "Torre"); Torre* ptrTorreN2 = new Torre(2, 0, 17.5, 5.5, "Torre");


	cout << "La posicion del peon numero " << ptrPeonB1->getNumPeon()<<" de color: "<< ptrPeonB1->getColor()<<" es : "<<" ("
	<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;

	ptrPeonB1->mover_abajo(1);
	cout << "La nueva posicion del peon numero " << ptrPeonB1->getNumPeon() << " de color: " << ptrPeonB1->getColor() << " es : " << " ("
		<< ptrPeonB1->getPosx() << ", " << ptrPeonB1->getPosy() << ")" << endl;


/*	peonB1.mover_arriba(1);
	cout << "La nueva posicion del peon de color: " << peonB1.getColor() << " es :" << " (" << peonB1.getPosx() <<
	", " << peonB1.getPosy() << ")" << endl;

	cout << "La posicion de la torre numero " << torreN1.getNumTorre() << " de color: " <<torreN1.getColor() << " es : " << " ("
		<< torreN1.getPosx() << ", " << torreN1.getPosy() << ")" << endl;
	torreN1.mover_arriba(3);
	cout << "La posicion de la torre numero " << torreN1.getNumTorre() << " de color: " << torreN1.getColor() << " es : " << " ("
		<< torreN1.getPosx() << ", " << torreN1.getPosy() << ")" << endl;
*/
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
