#pragma once

#include"ETSIDI.h"
#include "Pieza.h"
// #include "Tablero.h"
#include <iostream>

using namespace std;

class Torre :public Pieza {

private:
	int numTorre;

public:
	Torre(int numTorre_c = 0, int color_c = 0, int x_c = 0, int y_c = 0, string tipoPieza_c = "Vacio")
	{
		numTorre = numTorre_c;
		setColor(color_c);
		setPosx(x_c);
		setPosy(y_c);
		cout << "Se ha creado la torre de color " << getColor() <<" numero "<< numTorre << " y toma la posicion: " << x_c << y_c << endl;
	}
	~Torre() { cout << "Torre" << numTorre << " destruida" << endl; }
	int getNumTorre() { return numTorre; }

	void mover_izq(int casillas, int color, int num);
	void mover_dch(int casillas, int color, int num);
	void mover_arriba(int casillas, int color, int num);
	void mover_abajo(int casillas, int color, int num);
	void mover_arr_dcha(int casillas, int color, int num);
	void mover_arr_izq(int casillas, int color, int num);
	void mover_abajo_dcha(int casillas, int color, int num);
	void mover_abajo_izq(int casillas, int color, int num);
	
};