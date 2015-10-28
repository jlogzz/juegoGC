//
// Juan Lorenzo Gonzalez A01190381
// Alexander Baumann A00814393
//
#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
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
bool playing = FALSE;
bool canHit = FALSE;
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
	glTranslatef(x, y, 0);
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

	double xOffset = 200;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, ancho, 0, alto);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (viewDisplay == 0) { //menu
		glPushMatrix();
		glTranslatef(400, 300, 0.1);
		glScalef(800, 600, 0);
		glColor3ub(139, 69, 19);
		glutSolidCube(1);
		glColor3ub(139, 69, 19);
		glutWireCube(1);
		glPopMatrix();

		glColor3ub(0, 0, 0);
		output(100, 500, "MUGRE SUCIEDAD", 80, 8);

		if (menuOpcion == 0) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(220, 340, "NUEVO JUEGO", 50, 4);

		if (menuOpcion == 1) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(220, 270, "INSTRUCIONES", 50, 4);

		if (menuOpcion == 2) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(220, 200, "CREDITOS", 50, 4);

		if (menuOpcion == 3) {
			glColor3ub(255, 255, 255);
		}
		else {
			glColor3ub(0, 0, 0);
		}
		output(220, 130, "SALIR", 50, 4);
	}
	else if (viewDisplay == 1) { //ayuda

	}
	else if (viewDisplay == 2) { //juego

	}
	else if (viewDisplay == 3) { //pausa

	}
	else if (viewDisplay == 4) { //game over

	}
	else if (viewDisplay == 5) { //creditos

	}
	else {
		//Teteras
		if (tetera > 0) {
			glPushMatrix();
			if (tetera == 1) {
				glTranslatef(150, 250, 0);
				glScalef(100, 70, 0.5);
				glRotatef((GLfloat)angulo, 0, 1, 0);
				glColor3f(1, 0, 0);
			}
			else if (tetera == 2) {
				glTranslatef(650, 250, 0);
				glScalef(100, 70, 0.5);
				glRotatef((GLfloat)angulo, 0, 1, 0);
				glColor3f(0, 1, 0);
			}

			glutSolidTeapot(1);
			glColor3f(1, 1, 1);
			glutWireTeapot(1);

			glPopMatrix();
		}

		char scoreDealer[200] = "";
		sprintf(scoreDealer, "Score Dealer: %d", pDealer);

		char scorePlayer[200] = "";
		sprintf(scorePlayer, "Score Player: %d", pPlayer);

		glColor3ub(0, 0, 0);
		output(50, 550, "BlackJack", 50);
		output(50, 500, "Dealer", 50);
		output(50, 350, "Player", 50);
		output(50, 170, "Autor: Juan Gonzalez, Matricula: 1190381", 30);
		output(50, 140, "Autor: Alexander Baumann, Matricula: 814393", 30);
		output(50, 100, "D-Deal, H-Hit, S-Stand, Esc-Salir", 40);
		glColor3f(0, 0, 0);
		output(100, 220, resultado1, 40);
		output(500, 220, resultado2, 40);
		glColor3f(0, 0, 0);

		output(50, 50, scoreDealer, 40);
		output(380, 50, scorePlayer, 40);
	}
	
	glutSwapBuffers();

}

void init(void)
{
	glClearColor(1.0, 0.5, 0.33, 1.0);
	glShadeModel(GL_SMOOTH);
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
	cout << theKey << endl;
	switch (theKey)
	{
	case 'd':
	case 'D':
		opcion = 1;
		glutPostRedisplay();
		break;
	case 'h':
	case 'H':
		opcion = 2;
		glutPostRedisplay();
		break;
	case 's':
	case 'S':
		opcion = 3;
		glutPostRedisplay();
		//glutTimerFunc(1, myTimer, 3);
		break;
	case 13:
		if (menuOpcion == 3 && viewDisplay == 0) {
			exit(-1);
			//terminate the program
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
		if (menuOpcion > 0) {
			menuOpcion--;
		}
		glutPostRedisplay();
		break;
	case 103:
		if (menuOpcion < 3) {
			menuOpcion++;
		}
		glutPostRedisplay();
		break;
	default:
		break;		      // do nothing
	}
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}



int main(int argc, char *argv[])
{
	srand(time(0));

	glutInit(&argc, argv);
	glutInitWindowSize(ancho, alto);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	int mainWindow = glutCreateWindow("BlackJack!");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(5, myTimer, opt);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialKeyboard);
	//glutMouseFunc(myMouse);
	creacionMenu();

	glutMainLoop();

	cout << "BlackJack" << endl;
	return EXIT_SUCCESS;
}

