#include"TorreDePrueba.h"
#include"Pieza.h"

using namespace std;

void TorreDePrueba::mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista de  la torre. x es el numero de casillas
	Pieza::mover_izq(casillas);
}
void TorreDePrueba::mover_dch(int casillas) {
	Pieza::mover_dch(casillas);
}
void TorreDePrueba::mover_arriba(int casillas) { //Izquierda de la pantalla, no del punto de vista de la torre. x es el numero de casillas
		Pieza::mover_arriba(casillas);	
}
void TorreDePrueba::mover_abajo(int casillas) { //Las torrres se pueden mover para arriba y abajo, y para los lados cuando quieran, hay que meter las restricciones
		Pieza::mover_abajo(casillas);	
}
/*
void Torre::mover_arr_dcha(int casillas) {
	cout << "Un peon no puede moverse a la derecha" << endl;
}
void Torre::mover_arr_izq(int casillas) {
	cout << "Un peon no puede moverse en diagonal" << endl;
}
void Torre::mover_abajo_dcha(int casillas) {
	cout << "Un peon no puede moverse en diagonal" << endl;
}
void Torre::mover_abajo_izq(int casillas) {
	cout << "Un peon no puede moverse en diagonal" << endl;
}
Las torres no se mueven en diagonal en ningún momento
*/ 