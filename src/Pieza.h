#pragma once

#include "ETSIDI.h"
#include<iostream>

using namespace std;

class Pieza {
private:
	ETSIDI::Vector2D pos;
	int color; //0 Negro 1 Blanco
	const int limite_sup = 25; //Limites del tablero
	const int limite_inf = 0;
	string tipoPieza; // (Peon,torre...) que segun el tipo de pieza, el movimiento tiene ciertas restricciones
	
public:
	Pieza(string tipo_c="Vacio", int color_c = 0, float x_c = 0, float y_c = 0) { //Constructor
		setPosx(x_c);
		setPosy(y_c);
		setColor(color_c);
		setTipo(tipo_c);
		cout << "Pieza de tipo " << getTipo() << " creada" << endl;
	}
	virtual ~Pieza() { cout << "Pieza de tipo "<<tipoPieza<<" destruida" << endl; } //Destructor

	int getColor() { return color; }
	void setColor(int color_s) { color = color_s; }
	double getPosx() { return pos.x; }
	void setPosx(float posx_s) { pos.x = posx_s; }
	double getPosy() { return pos.y; }
	void setPosy(float posy_s) { pos.y = posy_s; }
	string getTipo() { return tipoPieza; }
	void setTipo(string tipo_c) { tipoPieza = tipo_c; }

	int getLimSup() { return limite_sup; }
	int getLimInf() { return limite_inf; }

	virtual void mover_izq(int casillas);  //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
	virtual void mover_dch(int casillas);
	virtual void mover_arriba(int casillas);
	virtual void mover_abajo(int casillas);
	virtual void mover_arr_dcha(int casillas);
	virtual void mover_arr_izq(int casillas);
	virtual void mover_abajo_dcha(int casillas);
	virtual void mover_abajo_izq(int casillas);

//	bool posOcupada(int x, int y);//0 No ocupada 1 Ocupada | Diferenciar si ocupada por tu color o el otro. CREO QUE MEJOR HACERLO EN TABLERO
};



// Marcos soplapollas