//Tablero.h
#pragma once
#include "ETSIDI.h"
#include<iostream>

using namespace std;

//class Pieza; // Declaración anticipada para que Tablero conozca la clase Pieza.

class Tablero{
private:
    bool posicionesOcupadas[3][4]; // Matriz 5 filas *4 columnas para el tablero
public:

    Tablero() {}  //Rellenar el tablero. Todas las casillas a true (ocupada) excepto la fila de en medio a false (libre)
    
    void rellenarPosiciones();

    void ocuparPos(int x, int y);
    void liberarPos(int x, int y);
    bool esPosOcupada(int x, int y);

    //friend class Pieza;
    // ... Resto de la clase Tablero ...
};
