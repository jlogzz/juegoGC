////
////  main.cpp
////  TimerGCAD13
////
////  Created by Ma. Guadalupe Roque on 27/08/13.
////  Copyright (c) 2013 Ma. Guadalupe Roque. All rights reserved.
////
//#include <windows.h>
//
//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/GL.h>
//#include <gl/glut.h>
//#endif
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <algorithm>
//#include <iostream>
//
//int min = 0, sec = 0, ms = 0;
//int i;
//int alto = 600;
//int ancho = 800;
//int opcion = 0;
//int turnos = 0;
//int baraja[16]   = { 5,4,6,7,1,2,3,0,4,3,0,7,1,5,6,2 };
//int expuesta[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//int carta1, carta2;
//int estado = 0;
//bool ayuda = false;
//
//void myTimer(int i) {
//	if (opcion == 1)
//	{
//		ms++;
//		if (ms >= 10) {
//			ms = 0;
//			sec++;
//			if (sec >= 60) {
//				sec = 0;
//				min++;
//			}
//		}
//		glutTimerFunc(100, myTimer, 1);
//		glutPostRedisplay();
//	}
//	else if (opcion == 2) {
//		min = 0, sec = 0, ms = 0;
//		glutPostRedisplay();
//	}
//
//}
//
//void output(GLfloat x, GLfloat y, char* text, int size)
//{
//	glPushMatrix();
//	glTranslatef(x, y, 0);
//	int fontsize = size;
//	glScalef(fontsize / 152.38, fontsize / 152.38, fontsize / 152.38);
//	for (char* p = text; *p; p++)
//	{
//		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
//	}
//	glPopMatrix();
//}
//
//void shuffle() {
//	for (int i = 0; i < 16; i++) {
//		expuesta[i] = 0;
//	}
//	std::random_shuffle(&baraja[0], &baraja[16]);
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	
//	double xOffset = 200;
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, ancho, 0, alto);
//
//	for (i = 1; i <= 16; i++) {
//		glBegin(GL_QUADS);
//
//		if (expuesta[i - 1] == 0) {
//			glColor3f(1.0f, 1.0f * (i % 2), 0.0f);
//		}
//		else
//		{
//			glColor3f(0.0f, 0.8f, 0.0f);
//		}
//
//		glVertex2f(0.0f + xOffset * ((i - 1) - 4 * ((i - 1) / 4)), alto - (alto / 8.0*((i - 1) / 4)));
//		glVertex2f(0.0f + xOffset * ((i - 1) - 4 * ((i - 1) / 4)), alto - (alto / 8.0*((i-1) / 4 + 1)));
//		glVertex2f(0.0f + xOffset * (i - 4 * ((i - 1) / 4)), alto - (alto / 8.0*((i - 1) / 4 + 1)));
//		glVertex2f(0.0f + xOffset * (i - 4 * ((i - 1) / 4)), alto - (alto / 8.0*((i - 1) / 4)));
//
//		glEnd();
//	}
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glColor3ub(0, 0, 0);
//
//	for (int i = 1; i <= 16; i++) {
//		if (expuesta[i - 1] == 1) {
//			char num[200] = "";
//			sprintf(num, "%d", baraja[i - 1]);
//			output(15+50*(i-1), 470, num, 40);
//		}
//	}
//
//	glColor3ub(120, 0, 0);
//
//	char msg[200] = "";
//	sprintf(msg, "%d:%02d.%d", min, sec, ms);
//
//	char turns[200] = "";
//	sprintf(turns, "Turnos::%d", turnos);
//
//	char numeros[200] = "";
//	sprintf(numeros, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", baraja[0], baraja[1], baraja[2], baraja[3], baraja[4], baraja[5], baraja[6], baraja[7], baraja[8], baraja[9], baraja[10], baraja[11], baraja[12], baraja[13], baraja[14], baraja[15]);
//
//	output(70, 200, msg, 70);
//	output(450, 200, turns, 70);
//	output(50, 150, "Autor: Juan Gonzalez, Matricula: 1190381", 40);
//	output(50, 100, "I-Iniciar, P-Pausa, R-Reiniciar, Esc-Salir", 40);
//
//	if (estado == 3) {
//		output(180, 320, "FELICIDADES!!!!", 80);
//	}
//
//	if(ayuda)
//		output(30, 20, numeros, 40);
//
//	glutSwapBuffers();
//
//}
//
//void init(void)
//{
//	glClearColor(1.0, 0.5, 0.33, 1.0);
//}
//
//void onMenu(int op) {
//	switch (op) {
//	case 1:
//		if (opcion != 1) {
//			opcion = 1;
//			glutTimerFunc(100, myTimer, 1);
//		}
//		break;
//	case 2:
//		opcion = 3;
//		glutTimerFunc(1, myTimer, 3);
//		break;
//	case 3:
//		ayuda = !ayuda;
//		glutPostRedisplay();
//		break;
//	case 4: 
//		opcion = 2;
//		estado = 0;
//		turnos = 0;
//		shuffle();
//		glutTimerFunc(1, myTimer, 2);
//		break;
//	case 5:
//		exit(-1);
//		break;
//	}
//	glutPostRedisplay();
//}
//
//void creacionMenu(void) {
//	int menuPrincipal;
//
//	glutCreateMenu(onMenu);
//	glutAddMenuEntry("Iniciar", 1);
//	glutAddMenuEntry("Pausa", 2);
//	glutAddMenuEntry("Ayuda", 3);
//	glutAddMenuEntry("Restablecer", 4);
//	glutAddMenuEntry("Salir", 5);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//}
//
//void myKeyboard(unsigned char theKey, int x, int y)
//{
//	switch (theKey)
//	{
//	case 'i':
//	case 'I':
//		if (opcion != 1) {
//			opcion = 1;
//			glutTimerFunc(100, myTimer, 1);
//		}
//		break;
//	case 'a':
//	case 'A':
//		ayuda = !ayuda;
//		glutPostRedisplay();
//		break;
//	case 'p':
//	case 'P':
//		opcion = 3;
//		glutTimerFunc(1, myTimer, 3);
//		break;
//
//	case 'r':
//	case 'R':
//		opcion = 2;
//		estado = 0;
//		turnos = 0;
//		shuffle();
//		glutTimerFunc(1, myTimer, 2);
//		break;
//	case 27:
//		exit(-1);
//		//terminate the program
//	default:
//		break;		      // do nothing
//	}
//}
//
//void myMouse(int button, int state, int x, int y)
//{
//
//
//	if (state == GLUT_DOWN)
//	{
//		//Si el usuario oprime el boton izq del mouse
//		if (button == GLUT_LEFT_BUTTON)
//		{
//			if (y <= 150) {
//				int i = x / 50;
//
//				if (expuesta[i] == 0) {
//					if (opcion != 1) {
//						opcion = 1;
//						glutTimerFunc(100, myTimer, 1);
//					}
//
//					if (estado == 0) {
//						carta1 = i;
//						estado = 1;
//						expuesta[i] = 1;
//					}
//					else if (estado == 1) {
//						carta2 = i;
//						expuesta[i] = 1;
//						estado = 2;
//						turnos++;
//
//						bool flag = true;
//						for (int j = 0; j < 16; j++) {
//							if (expuesta[j] == 0) {
//								flag = false;
//							}
//						}
//						if (flag) {
//							//termina juego
//							opcion = 3;
//							estado = 3;
//						}
//					}
//					else if (estado == 2) {
//						if (baraja[carta1] == baraja[carta2]) {
//				
//						}
//						else {
//							expuesta[carta1] = 0;
//							expuesta[carta2] = 0;
//						}
//						estado = 1;
//						expuesta[i] = 1;
//						carta1 = i;
//					}
//					//std::cout << baraja[i] << std::endl;
//					glutPostRedisplay();
//				}
//			}
//		}
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(ancho, alto);
//	glutInitWindowPosition(10, 10);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//	int mainWindow = glutCreateWindow("MEMORAMA");
//	glutDisplayFunc(display);
//	init();
//	glutKeyboardFunc(myKeyboard);
//	glutMouseFunc(myMouse);
//	creacionMenu();
//
//	shuffle();
//
//	glutMainLoop();
//	return EXIT_SUCCESS;
//}
//
