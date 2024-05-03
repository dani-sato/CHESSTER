#pragma once

#include"ETSIDI.h"
#include "Pieza.h"
// #include"Tablero.h"
#include <iostream>

using namespace std;

class Peon :public Pieza {
private:
	int numPeon;

public:
	Peon(int numPeon_c = 0, int color_c = 0, int x_c = 0, int y_c = 0, string tipo_c = "Vacio") {
		numPeon = numPeon_c;
		setPosx(x_c);
		setPosy(y_c);
		setColor(color_c);
		cout << "Se ha creado el peon de color " << getColor() <<" numero " << numPeon << " y toma la posicion: " << x_c << y_c << endl;
	}
	~Peon() { cout << "Peon " << numPeon << " destruido" << endl; }
	int getNumPeon() { return numPeon; }

	void mover_izq(int casillas, int color, int num);
	void mover_dch(int casillas, int color, int num);
	void mover_arriba(int casillas,int color, int num);
	void mover_abajo(int casillas,int color, int num);
	void mover_arr_dcha(int casillas,int color, int num);
	void mover_arr_izq(int casillas,int color, int num);
	void mover_abajo_dcha(int casillas,int color, int num);
	void mover_abajo_izq(int casillas,int color, int num);

};