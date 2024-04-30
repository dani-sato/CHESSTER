#include "Tablero.h"

void Tablero::rellenarPosiciones() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2) {
                posicionesOcupadas[i][j] = false;
            }
            else
                posicionesOcupadas[i][j] = true;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout<<posicionesOcupadas[i][j]<<" ";
        }
        cout << endl;
    }
}

void Tablero::ocuparPos(int x, int y) {
    posicionesOcupadas[x][y] = true;
    cout << "Casilla [" << x << "," << y << "] ocupada" << endl;
}

void Tablero::liberarPos(int x, int y) {
   posicionesOcupadas[x][y] = false;
    cout << "Casilla [" << x << "," << y << "] liberada" << endl;
}

bool Tablero::esPosOcupada(int x, int y) {
    return posicionesOcupadas[x][y];
}