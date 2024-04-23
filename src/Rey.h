#pragma once

#include<iostream>
#include "ETSIDI.h"

class Rey {
private:
	ETSIDI::Vector2D pos;
	int color; //0 Negro 1 Blanco
public:
	Rey(int color_c, float x_c, float y_c) { //Constructor
		pos.x = x_c;
		pos.y = y_c;
		color = color_c;
	}

	void mover_izq() { //Izquierda de la pantalla, no del punto de vista del peon
			pos.x -= - 1;
	}
	void mover_dch() {
		pos.x += 1;
	}
	void mover_arriba() {
		pos.y += 1;
	}
	void mover_abajo() {
		pos.y -= 1;
	}
	void mover_arr_dcha() {
		pos.x += 1;
		pos.y += 1;
	}
	void mover_arr_izq() {
		pos.x += 1;
		pos.y += 1;
	}
	void mover_abajo_dcha() {
		pos.x += 1;
		pos.y -= 1;
	}
	void mover_abajo_izq() {
		pos.x -= 1;
		pos.y -= 1;
	}
};