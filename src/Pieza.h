#pragma once

#include "ETSIDI.h"

using namespace std;

class Pieza {
private:
	ETSIDI::Vector2D pos;
	int color; //0 Negro 1 Blanco
//	string tipoPieza; que segun el tipo de pieza, el movimiento tiene ciertas restricciones
	bool posOcupada(){};//0 No ocupada 1 Ocupada | Diferenciar si ocupada por tu color o el otro
public:
	Pieza(int color_c = 0, float x_c = 0, float y_c = 0) { //Constructor
		setPosx(x_c);
		setPosy(y_c);
		setColor(color_c);
	}
	~Pieza() {} //Destructor

	int getColor() { return color; }
	void setColor(int color_s) { color = color_s; }
	float getPosx() { return pos.x; }
	void setPosx(float posx_s) { pos.x = posx_s; }
	float getPosy() { return pos.y; }
	void setPosy(float posy_s) { pos.y = posy_s; }

	void mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
		pos.x =pos.x- casillas *5.0;
	}
	void mover_dch(int casillas) {
		pos.x = pos.x+ casillas*5.0;
	}
	void mover_arriba(int casillas) {
		pos.y = pos.y+ casillas*5.0;
	}
	void mover_abajo(int casillas) {
		pos.y = pos.y -casillas *5.0;
	}
	void mover_arr_dcha(int casillas) {
		pos.x = pos.x +casillas*5.0;
		pos.y = pos.y+ casillas*5.0;
	}
	void mover_arr_izq(int casillas) {
		pos.x =pos.x- casillas*5.0;
		pos.y =pos.y+ casillas*5.0;
	}
	void mover_abajo_dcha(int casillas) {
		pos.x =pos.x+ casillas*5.0;
		pos.y =pos.y- casillas*5.0;
	}
	void mover_abajo_izq(int casillas) {
		pos.x =pos.x- casillas*5.0;
		pos.y= pos.y- casillas*5.0;
	}
};



// Marcos soplapollas