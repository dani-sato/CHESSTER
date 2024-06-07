#include <iostream>
#include <string>
#include "glut.h"
#include "boardgl.h"
#include "board.h"
#include "board.cpp"
#include "ETSIDI.h"
#include <Windows.h>
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0 )
#define VK_LEFT0x25 // Izquierda
#define VK_RIGHT0x27 // Derecha
#define VK_RETURN0x0D // Intro
#define VK_DOWN0x28 // Abajo
#define VK_UP0x26 // Arriba

using ETSIDI::playMusica;
using ETSIDI::stopMusica;
using ETSIDI::play;

// Define los tamaños de los tableros para cada modo de juego
#define FILAS_SILVER 5
#define COLUMNAS_SILVER 4

#define FILAS_DEMI 8
#define COLUMNAS_DEMI 4

// Funciones de callback
void OnDraw(void);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void OnTimer(int value);

// Objetos globales para el tablero
Tablero* gameboard = nullptr;
TableroGL* boardGL = nullptr;

// Funciones del menú
void menu(int);
void startGame(int mode);
void displayMenu(int);

int main(int argc, char* argv[]) {

    int eleccion = 0;
    menu(eleccion);
    displayMenu(eleccion);

    return 0;
}

void menu(int eleccion) {

    char marca = 16, elec[3] = {};

    if (eleccion == 0) {

        elec[0] = marca;
    }
    else if (eleccion == 1) {

        elec[1] = marca;
    }
    else if (eleccion == 2) {

        elec[2] = marca;
    }

    std::cout << "==============================\n";
    std::cout << "       JUEGO DE AJEDREZ       \n";
    std::cout << "==============================\n";
    std::cout << elec[0] << " Modo Silver\n";
    std::cout << elec[1] << " Modo Demi\n";
    std::cout << elec[2] << " Salir\n";
    std::cout << "==============================\n";
}

void displayMenu(int eleccion) {

    int elegir = 1, cursor = 0;

    while (elegir == 1) {

        if (cursor == 0) { // Mover cursor
            if (KEYDOWN(VK_DOWN)) {

                eleccion++;

                if (eleccion > 2) {

                    eleccion = 0;
                }

                cursor = 1;

                system("cls");
                menu(eleccion);
            }
            else if (KEYDOWN(VK_UP)) {

                eleccion--;

                if (eleccion < 0) {

                    eleccion = 2;
                }

                cursor = 1;

                system("cls");
                menu(eleccion);

            }
            else if (KEYDOWN(VK_RETURN)) {
                if (eleccion == 0) {

                    elegir = 0;
                    playMusica("sonidos/iniciojuego.mp3", true);
                    startGame(1); // Modo Silver
                }
                else if (eleccion == 1) {
                    
                    elegir = 2;
                    playMusica("sonidos/iniciojuego.mp3",true);
                    startGame(2); // Modo Demi
                }
                else if (eleccion == 2) {

                    elegir = 3;

                    std::cout << "\nSaliendo del juego. ¡Adios!\n";
                    exit(0);
                }
            }
        }
        else if (cursor > 0) { // Mantener el cursor en un punto

            cursor++;

            if (cursor > 100000000) {

                cursor = 0;
            }
        }
    }


    //ETSIDI::Sprite menu("C:/Users/Daniel Sato/source/repos/glut_boardgame5/imagenes/menus.png",0,0,20,20 );
    //menu.draw();
    ////// dibujo del fondo
    ////glEnable(GL_TEXTURE_2D);
    ////glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("C:/Users/Daniel Sato/source/repos/glut_boardgame5/imagenes/menus.png").id);
    ////glDisable(GL_LIGHTING);
    ////glBegin(GL_POLYGON);
    ////glColor3f(1, 1, 1);
    ////glTexCoord2d(0, 1); glVertex2f(-15, -5);
    ////glTexCoord2d(1, 1); glVertex2f(15, -5);
    ////glTexCoord2d(1, 0); glVertex2f(15, 20);
    ////glTexCoord2d(0, 0); glVertex2f(-15, 20);
    ////glEnd();
    ////glEnable(GL_LIGHTING);
    ////glDisable(GL_TEXTURE_2D);
    //////fin fondo

}

void startGame(int mode) {
    if (mode == 1) {
        gameboard = new Tablero(FILAS_SILVER, COLUMNAS_SILVER);
    }
    else if (mode == 2) {
        gameboard = new Tablero(FILAS_DEMI, COLUMNAS_DEMI, true); // Pasamos 'true' para el modo Demi
    }

    boardGL = new TableroGL(gameboard);

    // Inicialización de GLUT
    int argc = 1;
    char* argv[1] = { (char*)"Something" };
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("MiJuego");

    // Registrar callbacks
    glutDisplayFunc(OnDraw);
    glutKeyboardFunc(OnKeyboardDown);
    glutMouseFunc(OnMouseClick);

    // Configurar iluminación y perspectiva
    boardGL->init();

    // Entrar en el bucle principal de GLUT
    glutMainLoop();
}


void OnDraw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    boardGL->dibuja();
    glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
    boardGL->KeyDown(key);
    glutPostRedisplay();
}

void OnMouseClick(int b, int state, int x, int y) {
    bool down = (state == GLUT_DOWN);
    int button = (b == GLUT_LEFT_BUTTON) ? MOUSE_LEFT_BUTTON : MOUSE_RIGHT_BUTTON;

    int specialKey = glutGetModifiers();
    bool ctrlKey = (specialKey & GLUT_ACTIVE_CTRL) ? true : false;
    bool sKey = specialKey & GLUT_ACTIVE_SHIFT;

    boardGL->MouseButton(x, y, button, down, sKey, ctrlKey);
    glutPostRedisplay();
}

void OnTimer(int value) {
    if (value == 1) {
        boardGL->moveRandomBlackPiece();
        glutPostRedisplay();
    }
}
