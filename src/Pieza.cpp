#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h" 
#include "Peon.h"
#include"Torre.h"

Tablero tablero;

extern Peon* ptrPeonB1; extern Peon* ptrPeonB2;
extern Peon* ptrPeonB3 ; extern Peon* ptrPeonB4;

extern Peon* ptrPeonN1; extern Peon* ptrPeonN2;
extern Peon* ptrPeonN3 ; extern Peon* ptrPeonN4;

extern Torre* ptrTorreB1; extern Torre* ptrTorreB2;
extern Torre* ptrTorreN1; extern Torre* ptrTorreN2;

void Pieza::rellenarPos() {
	tablero.inicializarTablero();
	tablero.iniciarTurno();
}

void Pieza::mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
									 // Hacer lo mismo con todos los movimientos
	if ((pos.x - casillas) < getLimInf())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas,pos.y) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada por una pieza amiga" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl; //Crear una funcion eliminarPieza(int x,int y) que elimine la que haya en esa pos
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}

		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada por una pieza amiga" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}
}

void Pieza::mover_dch(int casillas) { //Esta no esta acabada
	if ((pos.x + casillas) > getLimDch())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}
}
void Pieza::mover_arriba(int casillas) {
	if ((pos.y + casillas) > getLimSup())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada por una pieza amiga" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y + casillas) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y + casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada por una pieza amiga" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x, pos.y + casillas) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}

}

void Pieza::mover_abajo(int casillas) {
	if ((pos.y - casillas) > getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y - casillas) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y - casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x, pos.y - casillas) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x, pos.y - casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}

}
void Pieza::mover_arr_dcha(int casillas) {
	if ((pos.x + casillas) > getLimDch() || (pos.y + casillas) > getLimSup()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y + casillas) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.eliminarPieza(pos.x + casillas, pos.y + casillas);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y + casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y + casillas) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y + casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}
}

void Pieza::mover_arr_izq(int casillas) {
	if ((pos.x - casillas) < getLimInf() || (pos.y + casillas) > getLimSup()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y + casillas) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y + casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y + casillas) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y + casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}
}
void Pieza::mover_abajo_dcha(int casillas) {
	if ((pos.x + casillas) > getLimDch() || (pos.y - casillas) < getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y - casillas) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y - casillas) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}
}
void Pieza::mover_abajo_izq(int casillas) {
	if ((pos.x - casillas) < getLimInf() || (pos.y - casillas) < getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y - casillas) == true) {
				//Eliminar pieza blanca (No se como hacerlo)
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
		if (getColor() == 1) {
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y - casillas) == true) {
				//Eliminar pieza Negra (No se como hacerlo)
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}
}
