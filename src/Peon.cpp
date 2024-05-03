#include"Peon.h"
#include "Tablero.h"
#include "Pieza.h"

using namespace std;

extern Tablero tablero;

//BLANCAS
extern int PeonB1x; extern int PeonB1y;
extern int PeonB2x; extern int PeonB2y;
extern int PeonB3x; extern int PeonB3y;
extern int PeonB4x; extern int PeonB4y;

//NEGRAS
extern int PeonN1x; extern int PeonN1y;
extern int PeonN2x; extern int PeonN2y;
extern int PeonN3x; extern int PeonN3y;
extern int PeonN4x; extern int PeonN4y;

void Peon::mover_izq(int casillas,int color, int num) { //Izquierda de la pantalla, no del punto de vista del peon
	cout << "Un peon no puede moverse a un lado" << endl;
}
void Peon::mover_dch(int casillas, int color, int num) {
	cout << "Un peon no puede moverse a un lado" << endl;
}
void Peon::mover_arriba(int casillas, int color, int num){
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() + casillas)==false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() + casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_arriba(casillas);
		switch (num)
		{
		case 1: PeonB1y = PeonB1y + casillas;
			break;
		case 2: PeonB2y = PeonB2y + casillas;
			break;
		case 3: PeonB3y = PeonB3y + casillas;
			break;
		case 4: PeonB4y = PeonB4y + casillas;
			break;
		default:
			break;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo(int casillas, int color, int num) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorBlanca(getPosx(), getPosy() - casillas) == false && tablero.esPosOcupadaPorNegra(getPosx(), getPosy() - casillas) == false) { //Esto funciona bien para controlar los limites del tablero 
		Pieza::mover_abajo(casillas);
		switch (num)
		{
		case 1: PeonN1y = PeonN1y - casillas;
			break;
		case 2: PeonN2y = PeonN2y - casillas;
			break;
		case 3: PeonN3y = PeonN3y - casillas;
			break;
		case 4: PeonN4y = PeonN4y - casillas;
			break;
		default:
			break;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}

void Peon::mover_arr_dcha(int casillas, int color, int num) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() + casillas)) {
		Pieza::mover_arr_dcha(casillas);
		switch (num)
		{
		case 1:
			PeonB1x = PeonB1x + casillas;
			PeonB1y = PeonB1y + casillas;
			break;
		case 2:
			PeonB2x = PeonB2x + casillas;
			PeonB2y = PeonB2y + casillas;
			break;
		case 3:
			PeonB3x = PeonB3x + casillas;
			PeonB3y = PeonB3y + casillas;
			break;
		case 4:
			PeonB4x = PeonB4x + casillas;
			PeonB4y = PeonB4y + casillas;
			break;
		default:
			break;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_arr_izq(int casillas, int color, int num) {
	if (getColor() == 1 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() + casillas)) {
		Pieza::mover_arr_izq(casillas);
		switch (num)
		{
		case 1:
			PeonB1x = PeonB1x - casillas;
			PeonB1y = PeonB1y + casillas;
			break;
		case 2:
			PeonB2x = PeonB2x - casillas;
			PeonB2y = PeonB2y + casillas;
			break;
		case 3:
			PeonB3x = PeonB3x - casillas;
			PeonB3y = PeonB3y + casillas;
			break;
		case 4:
			PeonB4x = PeonB4x - casillas;
			PeonB4y = PeonB4y + casillas;
			break;
		default:
			break;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo_dcha(int casillas, int color, int num) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() + casillas, getPosy() - casillas)) {
		Pieza::mover_abajo_dcha(casillas);
		switch (num)
		{
		case 1:
			PeonN1x = PeonN1x + casillas;
			PeonN1y = PeonN1y - casillas;
			break;
		case 2:
			PeonN2x = PeonN2x + casillas;
			PeonN2y = PeonN2y - casillas;
			break;
		case 3:
			PeonN3x = PeonN3x + casillas;
			PeonN3y = PeonN3y - casillas;
			break;
		case 4:
			PeonN4x = PeonN4x + casillas;
			PeonN4y = PeonN4y - casillas;
			break;
		default:
			break;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo_izq(int casillas, int color, int num) {
	if (getColor() == 0 && casillas == 1 && tablero.esPosOcupadaPorNegra(getPosx() - casillas, getPosy() - casillas)) {
		Pieza::mover_abajo_izq(casillas);
		switch (num)
		{
		case 1:
			PeonN1x = PeonN1x - casillas;
			PeonN1y = PeonN1y - casillas;
			break;
		case 2:
			PeonN2x = PeonN2x - casillas;
			PeonN2y = PeonN2y - casillas;
			break;
		case 3:
			PeonN3x = PeonN3x - casillas;
			PeonN3y = PeonN3y - casillas;
			break;
		case 4:
			PeonN4x = PeonN4x - casillas;
			PeonN4y = PeonN4y - casillas;
			break;
		default:
			break;
		}
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}