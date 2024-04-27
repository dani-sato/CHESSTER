#pragma once

#include"ETSIDI.h"
#include "Pieza.h"
#include <iostream>

using namespace std;

class Torre :public Pieza {
private:
	int numTorre;
public:
	Torre(int numTorre_c = 0, int color_c = 0, int x_c = 0, int y_c = 0, string tipoPieza_c = "Vacio") //Constructor 
	{
		numTorre = numTorre_c;
		setColor(color_c);
		setPosx(x_c);
		setPosy(y_c);
		setTipo(tipoPieza_c);
		cout << "Se ha creado la torre de color " << getColor()<<" numero "<<numTorre << " y toma la posicion: " << x_c << y_c << endl;
	}
	~Torre() { cout << "Torre" << numTorre << " destruida" << endl; }
	int getNumTorre() { return numTorre; }

	void mover_izq(int casillas);
	void mover_dch(int casillas);
	void mover_arriba(int casillas);
	void mover_abajo(int casillas);
	void mover_arr_dcha(int casillas);
	void mover_arr_izq(int casillas);
	void mover_abajo_dcha(int casillas);
	void mover_abajo_izq(int casillas);
	//Estas últimas 4 funciones están comentadas porque la torre no puede desplazarse en diagonal
};