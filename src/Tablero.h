//Tablero.h
#pragma once
#include "ETSIDI.h"
#include<iostream>

using namespace std;

//class Pieza; // Declaración anticipada para que Tablero conozca la clase Pieza.

class Tablero{
private:
    bool posicionesOcupadasPorNegra[3][4]; // Matriz 5 filas *4 columnas para el tablero
    bool posicionesOcupadasPorBlanca[3][4];
    int turno; //0 para negro 1 para blanco
public:

    Tablero() {}  //Rellenar el tablero. Todas las casillas a true (ocupada) excepto la fila de en medio a false (libre)
    
    void inicializarTablero();
    void iniciarTurno();
    void setTurno();

    void ocuparPosPorBlanca(int x, int y);
    void ocuparPosPorNegra(int x, int y);

    void liberarPosPorBlanca(int x, int y);
    void liberarPosPorNegra(int x, int y);

    bool esPosOcupadaPorBlanca(int x, int y);
    bool esPosOcupadaPorNegra(int x, int y);
    bool esCaminoLibre(int x1, int y1, int x2,int y2);

    void eliminarPieza(int x, int y);

    //friend class Pieza;
    // ... Resto de la clase Tablero ...
};
