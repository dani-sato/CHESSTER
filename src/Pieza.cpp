#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h" 

Tablero tablero;

void Pieza::rellenarPos() {
	tablero.rellenarPosiciones();
}

void Pieza::mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
	if ((pos.x - casillas) < getLimInf())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x - casillas, pos.y) == true) {
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else {
		tablero.liberarPos(pos.x, pos.y);
		pos.x = pos.x - casillas;
		tablero.ocuparPos(pos.x, pos.y);
	}
	
}

void Pieza::mover_dch(int casillas) {
	if ((pos.x + casillas) > getLimDch())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x + casillas, pos.y) == true) {
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else {
		tablero.liberarPos(pos.x, pos.y); cout << "Casilla [" << pos.x << "," << pos.y << "] liberada" << endl;
		pos.x = pos.x + casillas;
		tablero.ocuparPos(pos.x, pos.y); cout << "Casilla [" << pos.x << "," << pos.y << "] ocupada" << endl;
	}
}
void Pieza::mover_arriba(int casillas) {
	if ((pos.y + casillas) > getLimSup()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x, pos.y + casillas) == true) {
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else {
		tablero.liberarPos(pos.x, pos.y);
		pos.y = pos.y + casillas;
		tablero.ocuparPos(pos.x, pos.y);
	}
		
}
void Pieza::mover_abajo(int casillas) {
	if ((pos.y - casillas) > getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x, pos.y = pos.y - casillas) == true)
	{
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else
	{
		tablero.liberarPos(pos.x, pos.y);
		pos.y = pos.y - casillas;
		tablero.ocuparPos(pos.x, pos.y);
	}
		
}
void Pieza::mover_arr_dcha(int casillas) {
	if ((pos.x + casillas) > getLimDch() || (pos.y + casillas) > getLimSup() ){
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x + casillas, pos.y + casillas) == true) {
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else {
		tablero.liberarPos(pos.x, pos.y);
		pos.x = pos.x + casillas;
		pos.y = pos.y + casillas;
		tablero.ocuparPos(pos.x, pos.y);
	}
}
void Pieza::mover_arr_izq(int casillas) {
	if ((pos.x - casillas) < getLimInf() || (pos.y + casillas) > getLimSup()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x - casillas, pos.y + casillas) == true) {
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else {
		tablero.liberarPos(pos.x, pos.y);
		pos.x = pos.x - casillas;
		pos.y = pos.y + casillas;
		tablero.ocuparPos(pos.x, pos.y);
	}
}
void Pieza::mover_abajo_dcha(int casillas) {
	if ((pos.x + casillas) > getLimDch() || (pos.y - casillas) < getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x + casillas, pos.y - casillas) == true) {
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else {
		tablero.liberarPos(pos.x, pos.y);
		pos.x = pos.x + casillas;
		pos.y = pos.y - casillas;
		tablero.ocuparPos(pos.x, pos.y);
	}
}
void Pieza::mover_abajo_izq(int casillas) {
	if ((pos.x - casillas) < getLimInf() || (pos.y - casillas) < getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	if (tablero.esPosOcupada(pos.x - casillas, pos.y - casillas) == true) {
		cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
	}
	else {
		tablero.liberarPos(pos.x, pos.y);
		pos.x = pos.x - casillas;
		pos.y = pos.y - casillas;
		tablero.ocuparPos(pos.x, pos.y);
	}
}
