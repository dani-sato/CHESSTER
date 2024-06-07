#ifndef __TABLERO_H__
#define __TABLERO_H__

#include <iostream>
#include "piece.h"
#include "ETSIDI.h"

using namespace std;

class Tablero {
private:
    int filas;
    int columnas;
    Pieza** tab;
    bool primer_movimiento;
    int contador;
public:
    Tablero(int filas, int columnas, bool modoDemi = false);
    ~Tablero();

    int getFilas() { return filas; }
    int getColumnas() { return columnas; }
    void setFilas(int f) { filas = f; }
    void setColumnas(int c) { columnas = c; }
    Pieza** getTab() { return tab; }

    pair<int, int> findKing(string color);
    bool isKingInCheck(string color);
    bool movimientoPosible(int from_x, int from_y, int to_x, int to_y);
    bool movePiece(int from_x, int from_y, int to_x, int to_y);
};

#endif

