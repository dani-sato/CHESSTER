#include <iostream>
#include "boardgl.h"
#include "glut.h"
#include "board.h"



//AHORA SE COMEN LAS PIEZAS
//DEFINIMOS LOS TAMAÑOS DE LOS TABLEROS PARA CADA MODO DE JUEGO

#define FILAS_SILVER 5
#define COLUMNAS_SILVER 4

#define FILAS_DEMI 8
#define COLUMNAS_DEMI 4

/////////////////////////////////
//call back declarations: will be called by glut when registered
void OnDraw(void);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void OnTimer(int value);

////////////////////////////////////////////////
// Objetos globales para el tablero
Tablero* gameboard = nullptr;
TableroGL* boardGL = nullptr;

// Funciones del menú
void menu();
void startGame(int mode);
void displayMenu();

///////////////////////////////////////////////

int main(int argc, char* argv[]) {
    menu();
    return 0;
}

void menu() {
    char choice;
    displayMenu();
    std::cout << "Selecciona una opción: ";
    std::cin >> choice;

    if (choice == '1') {
        startGame(1); // Modo Silver
    }
    else if (choice == '2') {
        startGame(2); // Modo Demi
    }
    else if (choice == 'q' || choice == 'Q') {
        std::cout << "Saliendo del juego. ¡Adiós!\n";
        exit(0);
    }
    else {
        std::cout << "Opción no válida. Inténtalo de nuevo.\n";
        menu();
    }
}

void displayMenu() {
    std::cout << "==============================\n";
    std::cout << "       EGO D E AJED REZ       \n";
    std::cout << "==============================\n";
    std::cout << "1. Modo Silver\n";
    std::cout << "2. Modo Demi\n";
    std::cout << "q. Salir\n";
    std::cout << "==============================\n";
}
//Definición modos de juego

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
	//////////////////////
	//captures drawing event
	//gives control to scene
	scene.Draw();
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
	//////////////////////
	//captures keyboard event
	//gives control to scene
	scene.KeyDown(key);
	glutPostRedisplay();
}

void OnMouseClick(int b, int state, int x, int y) {
	//////////////
	//captures clicks with mouse with or without special keys (CTRL or SHIFT)
	//gives control to board scene
	bool down = (state == GLUT_DOWN);
	int button;
	if (b == GLUT_LEFT_BUTTON) {
		button = MOUSE_LEFT_BUTTON;
	}
	if (b == GLUT_RIGHT_BUTTON) {
		button = MOUSE_RIGHT_BUTTON;
		cout << "MOUSE_RIGHT_BUTTON" << endl;
	}

	int specialKey = glutGetModifiers();
	bool ctrlKey = (specialKey & GLUT_ACTIVE_CTRL) ? true : false;
	bool sKey = specialKey & GLUT_ACTIVE_SHIFT;


	scene.MouseButton(x, y, b, down, sKey, ctrlKey);
	glutPostRedisplay();
}


void OnTimer(int value) {
	//****WRITE TIMER CODE HERE
	if (value == 1) {
		scene.moveRandomBlackPiece();  // Mueve una pieza negra
		glutPostRedisplay();  // Solicita redibujar la ventana
	}
	//sets new timer (do not delete)
//	glutTimerFunc(25,OnTimer,0);
//	glutPostRedisplay();
}
