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

static int shoulder = 0, elbow = 0, hand = 0, finger = 0;

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
		glLineWidth(3);

		glPushMatrix();
		glTranslatef(-1.0, 0.0, 0.0);
		glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);

		glPushMatrix();
		glScalef(2.0, 0.4, 1.0);
		glColor3f(2, 0.4, 1);
		glutSolidCube(1.0);
		glColor3f(1, 1, 1);
		glutWireCube(1.0);
		glPopMatrix();

		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);

		glPushMatrix();
		glScalef(2.0, 0.4, 1.0);
		glColor3f(0, 0, 1);
		glutWireCube(1.0);

		glPopMatrix();


		glTranslatef(1, 0.0, 0.0);
		glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
		glTranslatef(0.25, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(1, 0, 1);
		glutWireCube(1.0);

		glPopMatrix();

		glTranslatef(0.25, 0.0, 0.0);
		glRotatef((GLfloat)finger, 1, 0.0, 0);
		glTranslatef(0.25, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.25, 0.25, 1);
		glColor3f(1, 0, 0);
		glutSolidCube(1.0);
		glColor3f(1, 1, 1);
		glutWireCube(1.0);

		glPopMatrix();

		glPopMatrix();

		glPopMatrix();
	}
	else if (viewDisplay == 3) { //pausa

	}
	else if (viewDisplay == 4) { //game over

	}
	else if (viewDisplay == 5) { //creditos

	}
	else {

	}

	glutSwapBuffers();

}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
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
	//cout << theKey << endl;
	switch (theKey)
	{
	case 's':   /*  s key rotates at shoulder  */
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':  /*  e key rotates at elbow  */
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;

	case 'd':  /*  e key rotates at elbow  */
		hand = (hand + 5) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		hand = (hand - 5) % 360;
		glutPostRedisplay();


	case 'w':  /*  e key rotates at elbow  */
		finger = (finger + 5) % 360;
		glutPostRedisplay();
		break;
	case 'W':
		finger = (finger - 5) % 360;
		glutPostRedisplay();
		break;
	case 13:
		if (menuOpcion == 3 && viewDisplay == 0) {
			exit(-1);
			//terminate the program
		}
		else if (menuOpcion == 0 && viewDisplay == 0) {
			viewDisplay = 2;
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
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

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