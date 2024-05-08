#include"Torre.h"
#include"Pieza.h"
#include "Tablero.h"

using namespace std;

extern Tablero tablero;



void Torre::mover_izq(int casillas, int color, int num) { 
	if (getColor() == 1 && casillas >= 1 && casillas <= 3 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) {
		Pieza::mover_izq(casillas);
/*		switch (num)
		{
		case 1: TorreB1x = TorreB1x - casillas;
			break;
		case 2: TorreB2x = TorreB2x - casillas;
			break;
		default:
			break;
		}*/
	}
	else if (getColor() == 0 && casillas >= 1 && casillas <= 3 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) {
		Pieza::mover_izq(casillas);
/*		switch (num)
		{
		case 1: TorreN1y = TorreN1y - casillas;
			break;
		case 2: TorreN2y = TorreN2y - casillas;
			break;
		default:
			break;
		}*/
	}
	else {
		cout << "La torre " << color << " se sale de los limites del tablero" << endl;

	}
}

void Torre::mover_dch(int casillas, int color, int num) {
	if (getColor() == 1 && casillas >= 1 && casillas <= 3 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) {
		Pieza::mover_dch(casillas);
/*		switch (num)
		{
		case 1: TorreB1x = TorreB1x + casillas;
			break;
		case 2: TorreB2x = TorreB2x + casillas;
			break;
		default:
			break;
		}*/
	}
	else if (getColor() == 0 && casillas >= 1 && casillas <= 3 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) {
		Pieza::mover_dch(casillas);
/*		switch (num)
		{
		case 1: TorreN1y = TorreN1y + casillas;
			break;
		case 2: TorreN2y = TorreN2y + casillas;
			break;
		default:
			break;
		}*/
	}
	else {
		cout << "La torre " << color << " se sale de los limites del tablero" << endl;

	}
}
void Torre::mover_arriba(int casillas, int color, int num) { 
	if (getColor() == 1 && casillas >= 1 && casillas <= 4 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) { 
		Pieza::mover_arriba(casillas);
/*		switch (num)
		{
		case 1: TorreB1y = TorreB1y + casillas;
			break;
		case 2: TorreB2y = TorreB2y + casillas;
			break;
		default:
			break;
		}*/
	}
	else if (getColor() == 0 && casillas >= 1 && casillas <= 4 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) {
		Pieza::mover_arriba(casillas);
/*		switch (num)
		{
		case 1: TorreN1y = TorreN1y + casillas;
			break;
		case 2: TorreN2y = TorreN2y + casillas;
			break;
		default:
			break;
		}*/
	}
	else {
		cout << "La torre " << color << " se sale de los limites del tablero" << endl;

	}
}

void Torre::mover_abajo(int casillas, int color, int num) {
	if (getColor() == 1 && casillas >= 1 && casillas <= 4 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) {
		Pieza::mover_abajo(casillas);
	/*	switch (num)
		{
		case 1: TorreB1y = TorreB1y + casillas;
			break;
		case 2: TorreB2y = TorreB2y + casillas;
			break;
		default:
			break;
		}*/
	}
	else if (getColor() == 0 && casillas >= 1 && casillas <= 4 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) {
/*		Pieza::mover_arriba(casillas);
		switch (num)
		{
		case 1: TorreN1y = TorreN1y + casillas;
			break;
		case 2: TorreN2y = TorreN2y + casillas;
			break;
		default:
			break;
		}*/
	}
	else {
		cout << "La torre " << color << " se sale de los limites del tablero" << endl;

	}
}

void Torre::mover_arr_dcha(int casillas, int color, int num) {
	cout << "Una torre no puede moverse en diagonal" << endl;
}
void Torre::mover_arr_izq(int casillas, int color, int num) {
	cout << "Una torre no puede moverse en diagonal" << endl;
}
void Torre::mover_abajo_dcha(int casillas, int color, int num) {
	cout << "Una torre no puede moverse en diagonal" << endl;
}
void Torre::mover_abajo_izq(int casillas, int color, int num) {
	cout << "Una torre no puede moverse en diagonal" << endl;
}