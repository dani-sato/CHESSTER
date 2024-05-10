#include"Torre.h"
#include"Pieza.h"
#include "Tablero.h"

using namespace std;

void Torre::mover_izq(int casillas, int color, int num) { 
	Pieza::mover_izq(casillas);	
}

void Torre::mover_dch(int casillas, int color, int num) {
	Pieza::mover_dch(casillas);
}
void Torre::mover_arriba(int casillas, int color, int num) { 
	Pieza::mover_arriba(casillas);
}

void Torre::mover_abajo(int casillas, int color, int num) {
	Pieza::mover_abajo(casillas);
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