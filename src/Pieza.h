#pragma once

#include "ETSIDI.h"
#include<iostream>
#include"Tablero.h"

using namespace std;


//class Pieza;
//class Tablero;

class Pieza {
private:
	ETSIDI::Vector2D pos;
	int color; //0 Negro 1 Blanco
	const int limite_sup = 5; //Limites del tablero
	const int limite_dch = 4;
	const int limite_inf = 0;
	string tipoPieza; // (Peon,torre...) que segun el tipo de pieza, el movimiento tiene ciertas restricciones

public:
	Pieza(/*Tablero& tablero,*/ string tipo_c = "Vacio", int color_c = 0, int x_c = 0, int y_c = 0) { //Constructor
		setPosx(x_c);
		setPosy(y_c);
		setColor(color_c);
		setTipo(tipo_c);
	//	cout << "Pieza de tipo " << getTipo() << " creada en la posicion: "<<getPosx()<< getPosy() << endl;
	}
	virtual ~Pieza() { //Destructor
		cout << "Pieza de tipo "<<tipoPieza<<" destruida" << endl; 
	} 

	int getColor() { return color; }
	void setColor(int color_s) { color = color_s; }
	int getPosx() { return pos.x; }
	void setPosx(int posx_s) { pos.x = posx_s; }
	int getPosy() { return pos.y; }
	void setPosy(int posy_s) { pos.y = posy_s; }
	string getTipo() { return tipoPieza; }
	void setTipo(string tipo_c) { tipoPieza = tipo_c; }

	int getLimSup() { return limite_sup; }
	int getLimDch() { return limite_dch; }
	int getLimInf() { return limite_inf; }

	virtual void mover_izq(int casillas);   //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
	virtual void mover_dch(int casillas);   
	virtual void mover_arriba(int casillas);
	virtual void mover_abajo(int casillas);
	virtual void mover_arr_dcha(int casillas);
	virtual void mover_arr_izq(int casillas);
	virtual void mover_abajo_dcha(int casillas);
	virtual void mover_abajo_izq(int casillas);

	void rellenarPos(); //Rellena al inicio, las casillas que estan ocupadas y las que estan libres


	//friend class Tablero;
};
