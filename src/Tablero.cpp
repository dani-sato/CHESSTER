#include "Tablero.h"

void Tablero::inicializarTablero() { 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2) {
                posicionesOcupadasPorBlanca[i][j] = false;
                posicionesOcupadasPorNegra[i][j] = false;
            }
            if (j == 0 || j == 1) {
                posicionesOcupadasPorBlanca[i][j] = true;
                posicionesOcupadasPorNegra[i][j] = false;
            }
            if (j == 3 || j == 4) {
                posicionesOcupadasPorBlanca[i][j] = false;
                posicionesOcupadasPorNegra[i][j] = true;
            }
        }
    }
    for (int i = 0; i < 4; i++) {  //FUNCIONA MAL
        for (int j = 0; j < 5; j++) {
            if (posicionesOcupadasPorBlanca[i][j]==true) {
                cout << " 1 ";
                goto exit;
            }
            if (posicionesOcupadasPorNegra[i][j] == true) {
                cout << " 0 ";
                goto exit;
            }
            if (posicionesOcupadasPorBlanca[i][j] == false && posicionesOcupadasPorNegra[i][j] == false) {
                cout << " - ";
                goto exit;
            }
        exit: cout << "";
        }
        cout << endl;
    }
}

void Tablero::ocuparPosPorBlanca(int x, int y){
    posicionesOcupadasPorBlanca[x][y] = true;
    cout << "Casilla [" << x << "," << y << "] ocupada por pieza blanca" << endl;
}
void Tablero::ocuparPosPorNegra(int x, int y) {
    posicionesOcupadasPorNegra[x][y] = true;
    cout << "Casilla [" << x << "," << y << "] ocupada por pieza negra" << endl;
}

void Tablero::liberarPosPorBlanca(int x, int y) {
    posicionesOcupadasPorBlanca[x][y] = false;
    cout << "Casilla [" << x << "," << y << "] liberada" << endl;
}
void Tablero::liberarPosPorNegra(int x, int y) {
    posicionesOcupadasPorNegra[x][y] = false;
    cout << "Casilla [" << x << "," << y << "] liberada" << endl;
}

bool Tablero::esPosOcupadaPorBlanca(int x, int y) {
    return posicionesOcupadasPorBlanca[x][y];
}
bool Tablero::esPosOcupadaPorNegra(int x, int y) {
    return posicionesOcupadasPorNegra[x][y];
}

void Tablero::setTurno() {
    if (turno == 0) {
        turno = 1;
    }
    else
        turno = 0;
    cout << "Turno del jugador " << turno << endl;
}

void Tablero::iniciarTurno() {
    turno = 1;
}