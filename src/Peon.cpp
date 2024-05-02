#include"Peon.h"
#include "Tablero.h"
#include "Pieza.h"

using namespace std;

extern Tablero tablero;

void Peon::mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
	cout << "Un peon no puede moverse a un lado" << endl;
}
void Peon::mover_dch(int casillas) {
	cout << "Un peon no puede moverse a un lado" << endl;
}
void Peon::mover_arriba(int casillas) { 
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas)==false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_arriba(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo(int casillas) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() - casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() - casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_abajo(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}

void Peon::mover_arr_dcha(int casillas) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() + casillas)) {
		Pieza::mover_arr_dcha(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_arr_izq(int casillas) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() + casillas)) {
		Pieza::mover_arr_izq(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo_dcha(int casillas) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() - casillas)) {
		Pieza::mover_abajo_dcha(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo_izq(int casillas) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() - casillas)) {
		Pieza::mover_arr_izq(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}