#pragma once

#include"ETSIDI.h"
#include "Pieza.h"
#include <iostream>

using namespace std;

class Peon :public Pieza {
private:
	int numPeon;
public:
	Peon(int numPeon_c = 0, int color_c = 0, float x_c = 0, float y_c = 0) { //Constructor
		numPeon = numPeon_c;
		setColor(color_c);
		setPosx(x_c);
		setPosy(y_c);
		cout << "Se ha creado el peon de color: " << getColor() << "  :" << " (" << getPosx() << ", " << getPosy() << ")" << endl;
	}
	int getNumPeon() { return numPeon; }
};