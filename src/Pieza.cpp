#include "Pieza.h"
#include "freeglut.h" 

void Pieza::mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
	if ((pos.x - casillas) < getLimInf())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else
	pos.x = pos.x - casillas;
}
void Pieza::mover_dch(int casillas) {
	if ((pos.x + casillas) > getLimDch())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else
		pos.x = pos.x + casillas;
}
void Pieza::mover_arriba(int casillas) {
	if ((pos.y + casillas) > getLimSup()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else
		pos.y = pos.y + casillas;
}
void Pieza::mover_abajo(int casillas) {
	if ((pos.y - casillas) > getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else
		pos.y = pos.y - casillas;
}
void Pieza::mover_arr_dcha(int casillas) {
	if ((pos.x + casillas) > getLimDch() || (pos.y + casillas) > getLimSup() ){
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else {
		pos.x = pos.x + casillas;
		pos.y = pos.y + casillas;
	}
}
void Pieza::mover_arr_izq(int casillas) {
	if ((pos.x - casillas) < getLimInf() || (pos.y + casillas) > getLimSup()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else {
		pos.x = pos.x - casillas;
		pos.y = pos.y + casillas;
	}
}
void Pieza::mover_abajo_dcha(int casillas) {
	if ((pos.x + casillas) > getLimDch() || (pos.y - casillas) < getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else {
		pos.x = pos.x + casillas;
		pos.y = pos.y - casillas;
	}
}
void Pieza::mover_abajo_izq(int casillas) {
	if ((pos.x - casillas) < getLimInf() || (pos.y - casillas) < getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else {
		pos.x = pos.x - casillas;
		pos.y = pos.y - casillas;
	}
}

/*
bool Pieza::posOcupada(int x, int y) {
	//Aquí debe ir el codigo que dice si la nueva posición está ocupada por alguna pieza
}
*/
/*
ETSIDI::Sprite PeonNegro1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 2.5,17.5 , 2.5, 2.5 }; 
ETSIDI::Sprite PeonNegro2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 7.5,17.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonNegro3{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 12.5,17.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonNegro4{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-negro.png", 17.5,17.5 , 2.5, 2.5 };
ETSIDI::Sprite TorreNegra1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-negra.png", 2.5, 22.5, 2.5, 2.5 };
ETSIDI::Sprite TorreNegra2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-negra.png", 17.5, 22.5, 2.5, 2.5 };
ETSIDI::Sprite ReyNegro{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/rey-negro.png", 7.5, 22.5, 2.5, 2.5 };
ETSIDI::Sprite ReinaNegra{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/reina-negra.png", 12.5, 22.5, 2.5, 2.5 };

ETSIDI::Sprite PeonBlanco1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 2.5, 7.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonBlanco2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 7.5, 7.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonBlanco3{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 12.5, 7.5 , 2.5, 2.5 };
ETSIDI::Sprite PeonBlanco4{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/peon-blanco.png", 17.5,7.5 , 2.5, 2.5 };
ETSIDI::Sprite TorreBlanca1{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-blanca.png", 2.5, 2.5, 2.5, 2.5 };
ETSIDI::Sprite TorreBlanca2{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/torre-blanca.png", 17.5, 2.5, 2.5, 2.5 };
ETSIDI::Sprite ReyBlanco{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/rey-blanco.png", 12.5,2.5, 2.5, 2.5 };
ETSIDI::Sprite ReinaBlanca{ "C:/Users/Daniel Sato/source/repos/trabajo2024/tema4inicial_VS19x64/imagenes/reina-blanca.png",7.5, 2.5, 2.5, 2.5 };
*/

/*
void Pieza::dibuja() {
	
	/* Si descomentas esto, no se dibujan las piezas
	gluLookAt(10, 12.5, 40,  // posicion del ojo
			10, 12.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)   
    */
	//aqui es donde hay que poner el codigo de dibujo
/*
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

	//dibujo del suelo
		glDisable(GL_LIGHTING);




		glEnable(GL_LIGHTING);
} */

/*
void Pieza::tecla(unsigned char key)
{
	if (key == '1')

}*/
