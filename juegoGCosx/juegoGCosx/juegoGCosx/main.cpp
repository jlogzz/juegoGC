//
//  main.cpp
//  juegoGCosx
//
//  baumann 10/28/15.
//


#ifdef WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;




static int shoulder = 0, elbow = 0, hand = 0, finger = 0;

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3);
    
    glPushMatrix();
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glColor3f(2, 0.4, 1);
    glutSolidCube (1.0);
    glColor3f(1, 1, 1);
    glutWireCube (1.0);
    glPopMatrix();
    
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glColor3f(0, 0, 1);
    glutWireCube (1.0);
    
    glPopMatrix();
    
    
    glTranslatef (1, 0.0, 0.0);
    glRotatef ((GLfloat) hand, 0.0, 0.0, 1.0);
    glTranslatef (0.25, 0.0, 0.0);
    
    glPushMatrix();
    glScalef (0.5, 0.5, 0.5);
    glColor3f(1, 1, 1);
    glutSolidCube (1.0);
    glColor3f(1, 0, 1);
    glutWireCube (1.0);
    
    
    
    
    glPopMatrix();
    
    
    glTranslatef (0.25, 0.0, 0.0);
    glRotatef ((GLfloat) finger, 1, 0.0, 0);
    glTranslatef (0.25, 0.0, 0.0);
    
    glPushMatrix();
    glScalef (0.25, 0.25, 1);
    glColor3f(1, 0, 0);
    glutSolidCube (1.0);
    glColor3f(1, 1, 1);
    glutWireCube (1.0);
    
    
    
    
    glPopMatrix();
    
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
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
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


