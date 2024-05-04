#include"Reina.h"
#include "Tablero.h"
#include "Pieza.h"

using namespace std;

extern Tablero tablero;

//BLANCAS
extern int ReinaBx; extern int ReinaBy;

//NEGRAS
extern int ReinaNx; extern int ReinaNy;

void Reina::mover_izq(int casillas, int color) { //Izquierda de la pantalla, no del punto de vista del peon
	if (getColor() == 1 && casillas >= 1 && casillas < 4 && tablero.esPosOcupadaPorBlanca(getPosx() - casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_izq(casillas);

		ReinaBx = ReinaBx - casillas;
	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 4 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_izq(casillas);

		ReinaNx = ReinaNx - casillas;
	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}
void Reina::mover_dch(int casillas, int color) {
	if (getColor() == 1 && casillas >= 1 && casillas < 4 && tablero.esPosOcupadaPorBlanca(getPosx() + casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_dch(casillas);

		ReinaBx = ReinaBx + casillas;
	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 4 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy()) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_dch(casillas);

		ReinaNx = ReinaNx + casillas;
	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}
void Reina::mover_arriba(int casillas, int color) {
	if (getColor() == 1 && casillas >= 1 && casillas < 5 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_arriba(casillas);

		ReinaBy = ReinaBy + casillas;
	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 5 && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_arriba(casillas);

		ReinaNy = ReinaNy + casillas;
	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}
void Reina::mover_abajo(int casillas, int color) {
	if (getColor() == 1 && casillas >= 1 && casillas < 5 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() - casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_abajo(casillas);

		ReinaBy = ReinaBy - casillas;
	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 5 && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() - casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_abajo(casillas);

		ReinaNy = ReinaNy - casillas;
	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}

void Reina::mover_arr_dcha(int casillas, int color) {
	if (getColor() == 1 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorBlanca(getPosx() + casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_dcha(casillas);

		ReinaBx = ReinaBx + casillas;
		ReinaBy = ReinaBy + casillas;

	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_dcha(casillas);

		ReinaNx = ReinaNx + casillas;
		ReinaNy = ReinaNy + casillas;

	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}
void Reina::mover_arr_izq(int casillas, int color) {
	if (getColor() == 1 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorBlanca(getPosx() - casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_izq(casillas);

		ReinaBx = ReinaBx - casillas;
		ReinaBy = ReinaBy + casillas;

	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() + casillas) == false) {
		Pieza::mover_arr_izq(casillas);

		ReinaNx = ReinaNx - casillas;
		ReinaNy = ReinaNy + casillas;

	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}
void Reina::mover_abajo_dcha(int casillas, int color) {
	if (getColor() == 1 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorBlanca(getPosx() + casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_dcha(casillas);

		ReinaBx = ReinaBx + casillas;
		ReinaBy = ReinaBy - casillas;

	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_dcha(casillas);

		ReinaNx = ReinaNx + casillas;
		ReinaNy = ReinaNy - casillas;

	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}
void Reina::mover_abajo_izq(int casillas, int color) {
	if (getColor() == 1 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorBlanca(getPosx() - casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_izq(casillas);

		ReinaBx = ReinaBx - casillas;
		ReinaBy = ReinaBy - casillas;

	}
	else if (getColor() == 0 && casillas >= 1 && casillas < 3 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() - casillas) == false) {
		Pieza::mover_abajo_izq(casillas);

		ReinaNx = ReinaNx - casillas;
		ReinaNy = ReinaNy - casillas;

	}
	else {
		cout << "Error de movimiento, te sales del tablero" << endl;
	}
}
