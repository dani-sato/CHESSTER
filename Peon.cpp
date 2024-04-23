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
		Pieza::mover_arriba(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_abajo(int casillas) {
	if (getColor() == 1 && casillas == 1) {
		Pieza::mover_abajo(casillas);
	}
	else {
		cout << "Un peon no puede retroceder su posicion ni avanzar mas de una posicion" << endl;
	}
}
void Peon::mover_arr_dcha(int casillas) {
	cout << "Un peon no puede moverse a la derecha" << endl;
}
void Peon::mover_arr_izq(int casillas) {
	cout << "Un peon no puede moverse en diagonal" << endl;
}
void Peon::mover_abajo_dcha(int casillas) {
	cout << "Un peon no puede moverse en diagonal" << endl;
}
void Peon::mover_abajo_izq(int casillas) {
	cout << "Un peon no puede moverse en diagonal" << endl;
}