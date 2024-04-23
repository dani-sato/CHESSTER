#pragma once

#include"ETSIDI.h"
#include "Pieza.h"
#include <iostream>

using namespace std;

class Peon :public Pieza {
private:
	int numPeon;
public:
	Peon(int numPeon_c = 0, int color_c = 0, float x_c = 0, float y_c = 0, string tipoPieza_c="Vacio") //Constructor 
	{
		numPeon = numPeon_c;
		setColor(color_c);
		setPosx(x_c);
		setPosy(y_c);
		setTipo(tipoPieza_c);
		cout << "Se ha creado el peon de color: " << getColor() << "  :" << " (" << getPosx() << ", " << getPosy() << ")" << endl;
	}
	~Peon() { cout << "Peon" << numPeon << " destruido" << endl; }
	int getNumPeon() { return numPeon; }

	void mover_izq(int casillas);
	void mover_dch(int casillas);
	void mover_arriba(int casillas);
	void mover_abajo(int casillas);
	void mover_arr_dcha(int casillas);
	void mover_arr_izq(int casillas);
	void mover_abajo_dcha(int casillas);
	void mover_abajo_izq(int casillas);

};