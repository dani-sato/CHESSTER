#include "Tablero.h"
#include "Peon.h"
#include "Torre.h"

//BLANCAS
extern int PeonB1x; extern int PeonB1y;
extern int PeonB2x; extern int PeonB2y;
extern int PeonB3x; extern int PeonB3y;
extern int PeonB4x; extern int PeonB4y;

extern int TorreB1x; extern int TorreB1y;
extern int TorreB2x; extern int TorreB2y;

//NEGRAS
extern int PeonN1x; extern int PeonN1y;
extern int PeonN2x; extern int PeonN2y;
extern int PeonN3x; extern int PeonN3y;
extern int PeonN4x; extern int PeonN4y;

extern int TorreN1x; extern int TorreN1y;
extern int TorreN2x; extern int TorreN2y;


extern Peon* ptrPeonB1; extern Peon* ptrPeonB2;
extern Peon* ptrPeonB3; extern Peon* ptrPeonB4;

extern Peon* ptrPeonN1; extern Peon* ptrPeonN2;
extern Peon* ptrPeonN3; extern Peon* ptrPeonN4;

extern Torre* ptrTorreB1; extern Torre* ptrTorreB2;
extern Torre* ptrTorreN1; extern Torre* ptrTorreN2;

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

void Tablero::eliminarPieza(int x, int y) {
    if (PeonB1x == x && PeonB1y == y) {
        delete ptrPeonB1;
        cout << "Peon Blanco 1 Eliminado" << endl;
        return;
    }
    if (PeonB2x == x && PeonB2y == y) {
        delete ptrPeonB2;
        cout << "Peon Blanco 2 Eliminado" << endl;
        return;
    }
    if (PeonB3x == x && PeonB3y == y) {
        delete ptrPeonB3;
        cout << "Peon Blanco 3 Eliminado" << endl;
        return;
    }
    if (PeonB4x == x && PeonB4y == y) {
        delete ptrPeonB4;
        cout << "Peon Blanco 4 Eliminado" << endl;
        return;
    }
    if (PeonN1x == x && PeonN1y == y) {
        delete ptrPeonN1;
        cout << "Peon Negro 1 Eliminado" << endl;
        return;
    }
    if (PeonN2x == x && PeonN2y == y) {
        delete ptrPeonN2;
        cout << "Peon Negro 2 Eliminado" << endl;
        return;
    }
    if (PeonN3x == x && PeonN3y == y) {
        delete ptrPeonN3;
        cout << "Peon Negro 3 Eliminado" << endl;
        return;
    }
    if (PeonN4x == x && PeonN4y == y) {
        delete ptrPeonN4;
        cout << "Peon Negro 4 Eliminado" << endl;
        return;
    }

    if (TorreB1x == x && TorreB1y == y) {
        delete ptrTorreB1;
        cout << "Torre Blanca 1 Eliminada" << endl;
        return;
    }
    if (TorreB2x == x && TorreB2y == y) {
        delete ptrTorreB2;
        cout << "Torre Blanca 2 Eliminada" << endl;
        return;
    }
    
    if (TorreN1x == x && TorreN1y == y) {
        delete ptrTorreN1;
        cout << "Torre Negra 1 Eliminada" << endl;
        return;
    }
    if (TorreN2x == x && TorreN2y == y) {
        delete ptrTorreN2;
        cout << "Torre Negra 2 Eliminada" << endl;
        return;
    }
}