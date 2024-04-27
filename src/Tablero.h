#include <vector>
#include<iostream>

using namespace std;

class Pieza; // Declaración anticipada para que Tablero conozca la clase Pieza.

class Tablero{
private:
    bool posicionesOcupadas[5][4]; // Matriz para mantener las piezas en el tablero.
public:
 //   Tablero() : posicionesOcupadas(5, vector<Pieza*>(4, nullptr)) {} // Constructor que inicializa el tablero de 5x4 vacío.

    Tablero() { 
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                posicionesOcupadas[i][j] = false;
            }
        }
    }

    void ocuparPos(int x, int y) { 
        posicionesOcupadas[x][y] = true; 
        cout << "Casilla [" << x << "," << y<< "] ocupada" << endl;
    }
    void liberarPos(int x, int y) { 
        posicionesOcupadas[x][y] = false; 
        cout << "Casilla [" << x << "," << y << "] liberada" << endl;
    }
    bool esPosOcupada(int x, int y) { 
        return posicionesOcupadas[x][y];
    }

    friend class Pieza;

    // ... Resto de la clase Tablero ...
};

