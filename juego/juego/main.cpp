//
// Juan Lorenzo Gonzalez A01190381
// Alexander Baumann A00814393
//
//  main.cpp
//  juegoGC
//
//  baumann jlo 10/28/15
//


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/GL.h>
#include <gl/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <time.h> 

using namespace std;

int min = 0, sec = 0, ms = 0;
int i;
int alto = 600;
int ancho = 800;
int opcion = 0;
int pDealer = 0;
int pPlayer = 0;
char* resultado1 = "";
char* resultado2 = "";

int viewDisplay = 0;
int menuOpcion = 0;

int angulo = 10;
int anguloTetera = 0;
int opt = 0;
int tetera = 0;

void myTimer(int opcion) {
	if (opt) {
		if (angulo < 370) {
			angulo += 2;

		}
		else {
			angulo = 10;
			opt = 0;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(5, myTimer, opt);
}

void output(GLfloat x, GLfloat y, char* text, int size, int weight = 1)
{
	glPushMatrix();
	glTranslatef(x, y, 0.1f);
	int fontsize = size;
	glLineWidth(weight);
	glScalef(fontsize / 152.38, fontsize / 152.38, fontsize / 152.38);
	for (char* p = text; *p; p++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	}
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (viewDisplay == 0) { //menu
		glColor3ub(0, 0, 0);
		output(-300, 200, "MUGRE SUCIEDAD", 80, 8);

		if (menuOpcion == 0) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(-220, 50, "NUEVO JUEGO", 50, 4);

		if (menuOpcion == 1) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(-220, -20, "INSTRUCIONES", 50, 4);

		if (menuOpcion == 2) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(-220, -90, "CREDITOS", 50, 4);

		if (menuOpcion == 3) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(-220, -160, "SALIR", 50, 4);
	}
	else if (viewDisplay == 1) { //ayuda
		glColor3ub(0, 0, 0);
		output(-300, 200, "MUGRE SUCIEDAD", 80, 8);

		output(-360, 100, "Utiliza las teclas: ARRIBA, ABAJO, IZQUIERDA, DERECHA", 30, 2);
		output(-360, 60, "para mover la cubeta. Debes de atrapar las gotas de", 30, 2);
		output(-360, 20, "agua para poder lavarte los dientes.", 30, 2);

		output(-400, -250, "Presiona ESC para regresar", 40, 4);
	}
	else if (viewDisplay == 2) { //juego
		
	}
	else if (viewDisplay == 3) { //pausa
		glColor3ub(0, 0, 0);
		output(-300, 200, "MUGRE SUCIEDAD", 80, 8);

		output(-400, -250, "Presiona ESC para regresar", 40, 4);
	}
	else if (viewDisplay == 4) { //game over

	}
	else if (viewDisplay == 5) { //creditos
		glColor3ub(0, 0, 0);
		output(-300, 200, "MUGRE SUCIEDAD", 80, 8);

		output(-360, 100, "Juan Lorenzo Gonzalez - A01190381", 30, 2);
		output(-360, 60, "Roland Alexander Baumann - A01190690", 30, 2);

		output(-400, -250, "Presiona ESC para regresar", 40, 4);

	}
	else {
		
	}

	glutSwapBuffers();

}

void init(void)
{
	glClearColor(139/255.0, 69 / 255.0, 19 / 255.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}

void onMenu(int op) {
	switch (op) {
	case 1:
		opcion = 1;
		glutPostRedisplay();
		break;
	case 2:
		opcion = 2;
		glutPostRedisplay();
		//glutTimerFunc(1, myTimer, 3);
		break;
	case 3:
		opcion = 3;
		glutPostRedisplay();
		break;
	case 4:
		exit(-1);
		break;
	}
	glutPostRedisplay();
}

void creacionMenu(void) {
	int menuPrincipal;

	glutCreateMenu(onMenu);
	glutAddMenuEntry("Deal", 1);
	glutAddMenuEntry("Hit", 2);
	glutAddMenuEntry("Stand	", 3);
	glutAddMenuEntry("Salir", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void myKeyboard(unsigned char theKey, int x, int y)
{
	//cout << theKey << endl;
	switch (theKey)
	{
	case 27:
		if (menuOpcion == 1 && viewDisplay == 1) {
			viewDisplay = 0;
		}
		else if (menuOpcion == 2 && viewDisplay == 5) {
			viewDisplay = 0;
		}
		break;
	case 13:
		if (menuOpcion == 3 && viewDisplay == 0) {
			exit(-1);
			//terminate the program
		}
		else if (menuOpcion == 0 && viewDisplay == 0) {
			viewDisplay = 2;//juego
		}
		else if (menuOpcion == 1 && viewDisplay == 0) {
			viewDisplay = 1;//ayuda
		}
		else if (menuOpcion == 2 && viewDisplay == 0) {
			viewDisplay = 5;//creditos
		}
	default:
		break;		      // do nothing
	}
}

void mySpecialKeyboard(int theKey, int x, int y)
{
	//cout << theKey << endl;
	switch (theKey)
	{
	case 101:
		if (menuOpcion > 0 && viewDisplay == 0) {
			menuOpcion--;
		}
		glutPostRedisplay();
		break;
	case 103:
		if (menuOpcion < 3 && viewDisplay == 0) {
			menuOpcion++;
		}
		glutPostRedisplay();
		break;
	default:
		break;		      // do nothing
	}
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-400, 400, -300*(GLfloat)h / (GLfloat)w,
			300*(GLfloat)h / (GLfloat)w, -10.0, 0.0);
	else
		glOrtho(-400*(GLfloat)w / (GLfloat)h,
			400*(GLfloat)w / (GLfloat)h, -300, 300, -10.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char *argv[])
{
	srand(time(0));

	glutInit(&argc, argv);
	glutInitWindowSize(ancho, alto);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	int mainWindow = glutCreateWindow("Mugre Suciedad");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(5, myTimer, opt);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialKeyboard);
	//glutMouseFunc(myMouse);
	creacionMenu();

	glutMainLoop();
	return EXIT_SUCCESS;
}