#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h" 
#include "Peon.h"
#include"Torre.h"
#include "Rey.h"

Tablero tablero;

void Pieza::rellenarPos() {
	tablero.inicializarTablero();
	tablero.iniciarTurno();
	tablero.pruebas();
}

void Pieza::mover_izq(int casillas) { //Izquierda de la pantalla, no del punto de vista del peon. x es el numero de casillas
									 // Hacer lo mismo con todos los movimientos
	if ((pos.x - casillas) < getLimInf())
	{
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x - casillas, pos.y) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0){
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas,pos.y) == true){
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada por una pieza amiga" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y) == true) {
				tablero.eliminarPieza(pos.x - casillas, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza Blanca comida" << endl; //Crear una funcion eliminarPieza(int x,int y) que elimine la que haya en esa pos
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
				tablero.eliminarPieza(pos.x - casillas, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
		return;
	}
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x + casillas, pos.y) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y) == true) {
				tablero.eliminarPieza(pos.x + casillas, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza Blanca comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
				tablero.eliminarPieza(pos.x + casillas, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x, pos.y+casillas) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada por una pieza amiga" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y + casillas) == true) {
				tablero.eliminarPieza(pos.x, pos.y + casillas);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza Blanca comida" << endl;
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
				tablero.eliminarPieza(pos.x, pos.y + casillas);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}

}

void Pieza::mover_abajo(int casillas) {
	if ((pos.y - casillas) < getLimInf()) {
		cout << "No puedes realizar ese movimiento porque tu pieza saldria del tablero" << endl;
		return;
	}
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x, pos.y - casillas) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y - casillas) == true) {
				tablero.eliminarPieza(pos.x, pos.y - casillas);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x, pos.y - casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
				tablero.eliminarPieza(pos.x, pos.y - casillas);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
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
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x+casillas, pos.y + casillas) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y + casillas) == true) {
				tablero.eliminarPieza(pos.x + casillas, pos.y + casillas);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza Blanca comida" << endl;
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
				tablero.eliminarPieza(pos.x + casillas, pos.y + casillas);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y + casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x-casillas, pos.y + casillas) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y + casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y + casillas) == true) {
				tablero.eliminarPieza(pos.x - casillas, pos.y + casillas);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y + casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
				tablero.eliminarPieza(pos.x - casillas, pos.y + casillas);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y + casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y + casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x+casillas, pos.y - casillas) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y - casillas) == true) {
				tablero.eliminarPieza(pos.x + casillas, pos.y - casillas);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza Blanca comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x + casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
				tablero.eliminarPieza(pos.x + casillas, pos.y - casillas);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x + casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x + casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
	if (tablero.esCaminoLibre(pos.x, pos.y, pos.x-casillas, pos.y-casillas) == false) {
		cout << "No puedes hacer ese movimiento porque hay una pieza en medio del camino" << endl;
		return;
	}
	else {
		if (getColor() == 0) {
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y - casillas) == true) {
				cout << "No puedes realizar ese movimiento porque esa casilla esta ocupada" << endl;
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y - casillas) == true) {
				tablero.eliminarPieza(pos.x - casillas, pos.y - casillas);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorNegra(pos.x, pos.y);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				cout << "Pieza comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorBlanca(pos.x - casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorNegra(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
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
				tablero.eliminarPieza(pos.x - casillas, pos.y - casillas);
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.liberarPosPorNegra(pos.x, pos.y);
				cout << "Pieza Negra comida" << endl;
				tablero.setTurno();
				return;
			}
			if (tablero.esPosOcupadaPorNegra(pos.x - casillas, pos.y - casillas) == false) {
				tablero.liberarPosPorBlanca(pos.x, pos.y);
				pos.x = pos.x - casillas;
				pos.y = pos.y - casillas; cout << "La nueva posicion de la pieza es " << pos.x << pos.y << endl;
				tablero.ocuparPosPorBlanca(pos.x, pos.y);
				tablero.setTurno();
				return;
			}
		}
	}
}
