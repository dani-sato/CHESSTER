#include"Rey.h"
#include "Tablero.h"
#include "Pieza.h"

using namespace std;

extern Tablero tablero;

//BLANCAS
extern int ReyBx; extern int ReyBy;

//NEGRAS
extern int ReyNx; extern int ReyNy;

void Rey::mover_izq(int casillas, int color) { //Izquierda de la pantalla, no del punto de vista del peon
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() - casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_izq(casillas);

		ReyBx = ReyBx - casillas;
	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_izq(casillas);

		ReyNx = ReyNx - casillas;
	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}
void Rey::mover_dch(int casillas, int color) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() + casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_dch(casillas);

		ReyBx = ReyBx + casillas;
	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_dch(casillas);

		ReyNx = ReyNx + casillas;
	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}
void Rey::mover_arriba(int casillas, int color) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_arriba(casillas);

		ReyBy = ReyBy + casillas;
	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_arriba(casillas);

		ReyNy = ReyNy + casillas;
	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}
void Rey::mover_abajo(int casillas, int color) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() - casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_abajo(casillas);

		ReyBy = ReyBy - casillas;
	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() - casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_abajo(casillas);

		ReyNy = ReyNy - casillas;
	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}

void Rey::mover_arr_dcha(int casillas, int color) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() + casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_dcha(casillas);

		ReyBx = ReyBx + casillas;
		ReyBy = ReyBy + casillas;

	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_dcha(casillas);

		ReyNx = ReyNx + casillas;
		ReyNy = ReyNy + casillas;

	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}
void Rey::mover_arr_izq(int casillas, int color) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() - casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_izq(casillas);

		ReyBx = ReyBx - casillas;
		ReyBy = ReyBy + casillas;

	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_izq(casillas);

		ReyNx = ReyNx - casillas;
		ReyNy = ReyNy + casillas;

	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}
void Rey::mover_abajo_dcha(int casillas, int color) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() + casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_dcha(casillas);

		ReyBx = ReyBx + casillas;
		ReyBy = ReyBy - casillas;

	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_dcha(casillas);

		ReyNx = ReyNx + casillas;
		ReyNy = ReyNy - casillas;

	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}
void Rey::mover_abajo_izq(int casillas, int color) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx() - casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_izq(casillas);

		ReyBx = ReyBx - casillas;
		ReyBy = ReyBy - casillas;

	}
	else if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_izq(casillas);

		ReyNx = ReyNx - casillas;
		ReyNy = ReyNy - casillas;

	}
	else {
		cout << "El rey no puede avanzar mas de una posicion" << endl;
	}
}