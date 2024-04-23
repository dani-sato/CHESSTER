#pragma once

#include"ETSIDI.h"
#include "Pieza.h"
#include <iostream>

using namespace std;

class Torre :public Pieza {
private:
	int numTorre;
public:
	Torre(int numTorre_c = 0, int color_c = 0, float x_c = 0, float y_c = 0) { //Constructor
		numTorre = numTorre_c;
		setColor(color_c);
		setPosx(x_c);
		setPosy(y_c);
		cout << "Se ha creado la torre de color: " << getColor() << "  :" << " (" << getPosx() << ", " << getPosy() << ")" << endl;
	}
	int getNumTorre() { return numTorre; }
};
