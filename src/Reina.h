#pragma once

#include"ETSIDI.h"
#include "Pieza.h"
#include <iostream>

using namespace std;

class Reina :public Pieza {

public:
	Reina(int color_c = 0, int x_c = 0, int y_c = 0, string tipo_c = "Vacio") {
		setPosx(x_c);
		setPosy(y_c);
		setColor(color_c);
		cout << "Se ha creado la reina de color " << getColor() << " y toma la posicion: " << x_c << y_c << endl;
	}
	~Reina() { cout << "Rey destruido" << endl; }

	void mover_izq(int casillas, int color);
	void mover_dch(int casillas, int color);
	void mover_arriba(int casillas, int color);
	void mover_abajo(int casillas, int color);
	void mover_arr_dcha(int casillas, int color);
	void mover_arr_izq(int casillas, int color);
	void mover_abajo_dcha(int casillas, int color);
	void mover_abajo_izq(int casillas, int color);

};
