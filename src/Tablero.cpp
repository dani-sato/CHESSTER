#include "Tablero.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
#include "Pieza.h"

/*Estoy intentando ponerlo en piezascpp
ETSIDI::Sprite PeonNegro1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 2.5,17.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonNegro2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 7.5,17.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonNegro3{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 12.5,17.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonNegro4{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 17.5,17.5 , 2.5, 2.5 };
ETSIDI::Sprite TorreNegra1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-negra.png", 2.5, 22.5, 2.5, 2.5 };
ETSIDI::Sprite TorreNegra2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-negra.png", 17.5, 22.5, 2.5, 2.5 };
ETSIDI::Sprite ReyNegro{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/rey-negro.png", 7.5, 22.5, 2.5, 2.5 };
ETSIDI::Sprite ReinaNegra{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/reina-negra.png", 12.5, 22.5, 2.5, 2.5 };

ETSIDI::Sprite PeonBlanco1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 2.5,7.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonBlanco2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 7.5,7.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonBlanco3{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 12.5,7.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonBlanco4{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 17.5,7.5 , 2.5, 2.5 };
ETSIDI::Sprite TorreBlanca1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-blanca.png", 2.5, 2.5, 2.5, 2.5 };
ETSIDI::Sprite TorreBlanca2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-blanca.png", 17.5, 2.5, 2.5, 2.5 };
ETSIDI::Sprite ReyBlanco{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/rey-blanco.png", 12.5,2.5, 2.5, 2.5 };
ETSIDI::Sprite ReinaBlanca{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/reina-blanca.png",7.5, 2.5, 2.5, 2.5 };
*/
void Tablero::dibuja()
{
	gluLookAt(10, 12.5, 40,  // posicion del ojo
			10, 12.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);

	int color=50; //Negro
	float x = 0, y = 0,z=-0.05;

	//Estos dos bucles for dibujan el tablero
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			glBegin(GL_POLYGON);
			glColor3ub(color, color, color);
			glVertex3f(x, y, z);
			x += 5;
			glVertex3f(x, y, z);
			y += 5;
			glVertex3f(x, y, z);
			x -= 5;
			glVertex3f(x, y, z);
			glEnd();
			if (color == 50) //Negro
				color = 255; //Blanco
			else
				color = 50; //Negro
		}
		x += 5;
		y = 0;
	}
/*Estoy probando a pnerlo en piezacpp
	PeonNegro1.draw();
	PeonNegro2.draw();
	PeonNegro3.draw();
	PeonNegro4.draw();
	TorreNegra1.draw();
	TorreNegra2.draw();
	ReinaNegra.draw();
	ReyNegro.draw();

	PeonBlanco1.draw();
	PeonBlanco2.draw();
	PeonBlanco3.draw();
	PeonBlanco4.draw();
	TorreBlanca1.draw();
	TorreBlanca2.draw();
	ReinaBlanca.draw();
	ReyBlanco.draw();
	*/
	glEnable(GL_LIGHTING);
}



void Tablero::tecla(unsigned char key)
{

}

