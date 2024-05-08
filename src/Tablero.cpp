#include "Tablero.h"
#include "Peon.h"
#include "Torre.h"
#include "Rey.h"

Peon* ptrPeonB1 = new Peon(1, 1, 0, 1, "Peon"); Peon* ptrPeonB2 = new Peon(2, 1, 1, 1, "Peon");
Peon* ptrPeonB3 = new Peon(3, 1, 2, 1, "Peon"); Peon* ptrPeonB4 = new Peon(4, 1, 3, 1, "Peon");

Peon* ptrPeonN1 = new Peon(1, 0, 0, 3, "Peon"); Peon* ptrPeonN2 = new Peon(2, 0, 1, 3, "Peon");
Peon* ptrPeonN3 = new Peon(3, 0, 2, 3, "Peon"); Peon* ptrPeonN4 = new Peon(4, 0, 3, 3, "Peon");

Torre* ptrTorreB1 = new Torre(1, 1, 0, 0, "Torre"); Torre* ptrTorreB2 = new Torre(2, 1, 3, 0, "Torre");
Torre* ptrTorreN1 = new Torre(1, 0, 0, 4, "Torre"); Torre* ptrTorreN2 = new Torre(2, 0, 3, 4, "Torre");

Rey* ptrReyB = new Rey(1, 2, 0, "Rey");
Rey* ptrReyN = new Rey(0, 2, 4, "Rey");


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
    cout << "Entra el la funcion eliminarPieza" << endl;
    if (ptrPeonB1->getPosx() == x && ptrPeonB1->getPosy() == y) {
        delete ptrPeonB1;
        cout << "Peon Blanco 1 Eliminado" << endl;
        return;
    }
    if (ptrPeonB2->getPosx() == x && ptrPeonB2->getPosy() == y) {
        delete ptrPeonB2;
        cout << "Peon Blanco 2 Eliminado" << endl;
        return;
    }
    if (ptrPeonB3->getPosx() == x && ptrPeonB3->getPosy() == y) {
        delete ptrPeonB3;
        cout << "Peon Blanco 3 Eliminado" << endl;
        return;
    }
    if (ptrPeonB4->getPosx() == x && ptrPeonB4->getPosy() == y) {
        delete ptrPeonB4;
        cout << "Peon Blanco 4 Eliminado" << endl;
        return;
    }
    if (ptrPeonN1->getPosx() == x && ptrPeonN1->getPosy() == y) {
        delete ptrPeonN1;
        cout << "Peon Negro 1 Eliminado" << endl;
        return;
    }
    if (ptrPeonN2->getPosx() == x && ptrPeonN2->getPosy() == y) {
        delete ptrPeonN2;
        cout << "Peon Negro 2 Eliminado" << endl;
        return;
    }
    if (ptrPeonN3->getPosx() == x && ptrPeonN3->getPosy() == y) {
        delete ptrPeonN3;
        cout << "Peon Negro 3 Eliminado" << endl;
        return;
    }
    if (ptrPeonN4->getPosx() == x && ptrPeonN4->getPosy() == y) {
        delete ptrPeonN4;
        cout << "Peon Negro 4 Eliminado" << endl;
        return;
    }

    if (ptrTorreB1->getPosx() == x && ptrTorreB1->getPosy() == y) {
        delete ptrTorreB1;
        cout << "Torre Blanca 1 Eliminada" << endl;
        return;
    }
    if (ptrTorreB2->getPosx() == x && ptrTorreB2->getPosy() == y) {
        delete ptrTorreB2;
        cout << "Torre Blanca 2 Eliminada" << endl;
        return;
    }
    
    if (ptrTorreN1->getPosx() == x && ptrTorreN1->getPosy() == y) {
        delete ptrTorreN1;
        cout << "Torre Negra 1 Eliminada" << endl;
        return;
    }
    if (ptrTorreN2->getPosx() == x && ptrTorreN2->getPosy() == y) {
        delete ptrTorreN2;
        cout << "Torre Negra 2 Eliminada" << endl;
        return;
    }
}

bool Tablero::esCaminoLibre(int x1, int y1, int x2, int y2) {

    //MOVIMIENTOS HORIZONTALES
    if (y1 == y2 && x2>x1) { //Movimiento horizontal a derecha y de mas de una casilla (Aquí se evaluan los caminos, no los movimientos de una sola casilla)
        int x = x1;
        for (int i = x1+1; i <x2; i++) { //Desde x1 hasta x2 
            if (posicionesOcupadasPorBlanca[x+1][y1] == true || posicionesOcupadasPorNegra[x+1][y1] == true) {
                cout << "Camino hacia derecha ocupado" << endl;
                return false;
            }
            x++;
        }
        return true;
    }
    if (y1 == y2 && x2<x1) { //Movimiento horizontal a izquierda y de mas de una casilla (Aquí se evaluan los caminos, no los movimientos de una sola casilla)
        int x = x1;
        for (int i = x2; i > x1-1; i--) { //Desde x1 hasta x2 
            if (posicionesOcupadasPorBlanca[x-1][y1] == true || posicionesOcupadasPorNegra[x-1][y1] == true) {
                cout << "Camino hacia Izquierda ocupado" << endl;
                return false;
            }
            x--;
        }
        return true;
    }
    
    //MOVIMIENTOS VERTICALES
    if (y2>y1 && x1==x2) { //Movimiento vertical hacia arriba y de mas de una casilla (Aquí se evaluan los caminos, no los movimientos de una sola casilla)
        int y = y1;
        for (int i = y1; i < y2; i++) { //Desde x1 hasta x2 
            if (posicionesOcupadasPorBlanca[x1][y+1] == true || posicionesOcupadasPorNegra[x1][y+1] == true) {
                cout << "Camino hacia arriba ocupado" << endl;
                return false;
            }
            y++;
        }
        return true;
    }

    if (y2<y1 && x1 == x2) { //Movimiento vertical hacia abajo y de mas de una casilla (Aquí se evaluan los caminos, no los movimientos de una sola casilla)
        int y = y1;
        for (int i = y2; i > y1; i--) { //Desde x1 hasta x2 
            if (posicionesOcupadasPorBlanca[x1][y1-1] == true || posicionesOcupadasPorNegra[x1][y1-1] == true) {
                cout << "Camino hacia Abajo ocupado" << endl;
                return false;
            }
            y--;
        }
        return true;
    }

    //MOVIMIENTOS DIAGONALES
    if (x2 > x1 && y2 > y1) { //Arriba Derecha
        int x = x1;
        int y = y1;
        for (int i = x1+1; i < x2; i++) {
            if (posicionesOcupadasPorBlanca[x+1][y+1] == true || posicionesOcupadasPorNegra[x+1][y+1] == true) {
                cout << "Camino Arriba derecha ocupado" << endl;
                return false;
            }
            x++;
            y++;
        }
        return true;
    }
    
    if (x2 < x1 && y2 > y1) { //Arriba Izquierda
        for (int i = x2; i > x1-1; i--) {
            int x = x1;
            int y = y1;
            if (posicionesOcupadasPorBlanca[x-1][y + 1] == true || posicionesOcupadasPorNegra[x-1][y + 1] == true) {
                cout << "Camino Arriba Izquierda ocupado" << endl;
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    if (x2 > x1 && y2 < y1) { //Abajo derecha
        for (int i = x1+1; i <x2 ; i++) {
            int x = x1;
            int y = y1;
            if (posicionesOcupadasPorBlanca[x+1][y - 1] == true || posicionesOcupadasPorNegra[x + 1][y- 1] == true) {
                cout << "Camino Abajo derecha ocupado" << endl;
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    if (x2 < x1 && y2 < y1) { //Abajo izquierda
        int x = x1;
        int y = y1;
        for (int i = x2; i > x1-1; i--) {
            if (posicionesOcupadasPorBlanca[x - 1][y - 1] == true || posicionesOcupadasPorNegra[x - 1][y - 1] == true) {
                cout << "Camino Abajo izquierda ocupado" << endl;
                return false;
            }
            x--;
            y--;
        }
        return true;
    }
}

void Tablero::partida() {
    //PRUEBAS DE MOVIMIENTO
    cout << "La posicion del peon numero " << ptrPeonB2->getNumPeon() << " de color: " << ptrPeonB2->getColor() << " es : " << " ("
        << ptrPeonB2->getPosx() << ", " << ptrPeonB2->getPosy() << ")" << endl;

    cout << endl;
    ptrPeonB2->mover_arriba(1, 1, 1);
    cout << "La nueva posicion del peon numero " << ptrPeonB2->getNumPeon() << " de color: " << ptrPeonB2->getColor() << " es : " << " ("
        << ptrPeonB2->getPosx() << ", " << ptrPeonB2->getPosy() << ")" << endl;
    cout << endl;

    ptrPeonN1->mover_abajo(1, 1, 1);
    cout << "La nueva posicion del peon numero " << ptrPeonN1->getNumPeon() << " de color: " << ptrPeonN1->getColor() << " es : " << " ("
        << ptrPeonN1->getPosx() << ", " << ptrPeonN1->getPosy() << ")" << endl;
    cout << endl;

    ptrPeonB3->mover_arriba(1, 1, 1);
    cout << "La nueva posicion del peon numero " << ptrPeonB3->getNumPeon() << " de color: " << ptrPeonB3->getColor() << " es : " << " ("
        << ptrPeonB3->getPosx() << ", " << ptrPeonB3->getPosy() << ")" << endl;
    cout << endl;

    ptrPeonN4->mover_abajo_izq(1, 1, 1);
    cout << "La nueva posicion del peon numero " << ptrPeonN4->getNumPeon() << " de color: " << ptrPeonN4->getColor() << " es : " << " ("
        << ptrPeonN4->getPosx() << ", " << ptrPeonN4->getPosy() << ")" << endl;
    cout << endl;

    ptrPeonB4->mover_arr_izq(1, 1, 1);
    cout << "La nueva posicion del peon numero " << ptrPeonB4->getNumPeon() << " de color: " << ptrPeonB4->getColor() << " es : " << " ("
        << ptrPeonB4->getPosx() << ", " << ptrPeonB4->getPosy() << ")" << endl;
    cout << endl;

    ptrPeonN2->mover_abajo_dcha(1, 1, 1);
    cout << "La nueva posicion del peon numero " << ptrPeonN2->getNumPeon() << " de color: " << ptrPeonN2->getColor() << " es : " << " ("
        << ptrPeonN2->getPosx() << ", " << ptrPeonN2->getPosy() << ")" << endl;
    cout << endl;

    ptrReyB->mover_arriba(1, 1);
    cout << "La nueva posicion del rey de color: " << ptrReyB->getColor() << " es : " << " ("
        << ptrReyB->getPosx() << ", " << ptrReyB->getPosy() << ")" << endl;
}

void Tablero::dibujar_Tablero() {

}