#include"Peon.h"
#include "Tablero.h"
#include "Pieza.h"

using namespace std;

extern Tablero tablero;


void Peon::mover_izq(int casillas,int color, int num) { //Izquierda de la pantalla, no del punto de vista del peon
	cout << "Un peon no puede moverse a un lado" << endl;
}
void Peon::mover_dch(int casillas, int color, int num) {
	cout << "Un peon no puede moverse a un lado" << endl;
}
void Peon::mover_arriba(int casillas, int color, int num){
	if (getColor() == 1 && casillas == 1) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_arriba(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo(int casillas, int color, int num) {
	if (getColor() == 0 && casillas == 1) {
		Pieza::mover_abajo(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}

void Peon::mover_arr_dcha(int casillas, int color, int num) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() + casillas) == true) {
		Pieza::mover_arr_dcha(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_arr_izq(int casillas, int color, int num) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() + casillas) == true) {
		Pieza::mover_arr_izq(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo_dcha(int casillas, int color, int num) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() + casillas, getPosy() - casillas) == true) {
		Pieza::mover_abajo_dcha(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo_izq(int casillas, int color, int num) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() - casillas, getPosy() - casillas) == true) {
		Pieza::mover_abajo_izq(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}