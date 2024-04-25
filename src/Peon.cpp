#include"Peon.h"
#include"Pieza.h"

using namespace std;

void Peon::mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
	cout << "Un peon no puede moverse a la izquierda" << endl;
}
void Peon::mover_dch(int casillas) {
	cout << "Un peon no puede moverse a la derecha" << endl;
}
void Peon::mover_arriba(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
	if (getColor() == 0 && casillas == 1) {
		if ((getPosy() + casillas * 5) < getLimSup()) { //Esto funciona bien para controlar los limites del tablero 
			Pieza::mover_arriba(casillas);
		}
		else {
			cout << "No puedes hacer ese movimiento, te has salido del tablero" << endl;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo(int casillas) {
	if (getColor() == 1 && casillas == 1) {
		if ((getPosy() - casillas * 5) > getLimInf()) {
			Pieza::mover_abajo(casillas);
		}
		else {
			cout << "No puedes hacer ese movimiento, te has salido del tablero" << endl;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
	
}
void Peon::mover_arr_dcha(int casillas) {
	cout << "Un peon no puede mover en diagonal, salvo para comer" << endl;
}
void Peon::mover_arr_izq(int casillas) {
	cout << "Un peon no puede mover en diagonal, salvo para comer" << endl;
}
void Peon::mover_abajo_dcha(int casillas) {
	cout << "Un peon no puede mover en diagonal, salvo para comer" << endl;
}
void Peon::mover_abajo_izq(int casillas) {
	cout << "Un peon no puede mover en diagonal, salvo para comer" << endl;
}