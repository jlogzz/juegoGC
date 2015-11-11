//
//  main.cpp
//  juegoGC
//
//  baumann jlo 10/28/15
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
#include <vector>


using namespace std;


#include "clases.h"


vector<Gota> gotas;

Cubeta cubeta(20);

static int shoulder = 0, elbow = 0, hand = 0, finger = 0;


bool pausa = true;

int atrapados = 0;
int no_atrapados = 0;

void init(void)
{
    glClearColor (0.2, 1, 0.2, 0.0);
    glShadeModel (GL_FLAT);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3);
    
    
    glPushMatrix();
    glTranslatef (0, 0.0, 0.0);
    glScalef (500.0, 500, 1);
    glColor3f(.350, .250, .250);
    glutSolidCube (1.0);
    glPopMatrix();
    
    

    
    //dibuja sombra de gotas
    for (int i = 0; i < gotas.size(); i++) {
        glPushMatrix();
        glTranslatef (gotas[i].getX(), gotas[i].getY(), 0);
        glScalef (20.0, 20, 2);
        glColor3f(0, 0, 0);
        glutSolidSphere (1.0,10,10);
        glPopMatrix();
    }
    
    
    
    
    GLUquadricObj *quad = gluNewQuadric();
    
    glLineWidth(1);
    
    
    
    glPushMatrix();
    glTranslatef (cubeta.getX(), cubeta.getY(), 0.0);
    glScalef (33.0, 33, 5);
    glColor3f(.1, .1, .1);
    
    glutSolidSphere(1, 10, 10);
    //glColor3f(0, 0, 0);
    //glutWireCube (1.0);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef (cubeta.getX(), cubeta.getY(), 0.0);
    glScalef (40.0, 40, 80);
    glColor3f(.6, .6, .6);
    gluCylinder(quad, 0.8, 1, 1, 10, 10);
    
    
    glPopMatrix();
    
    
    
    
    //dibuja gotas
    for (int i = 0; i < gotas.size(); i++) {
        glLineWidth(1);
        glPushMatrix();
        glTranslatef (gotas[i].getX(), gotas[i].getY(), gotas[i].getZ());
        glScalef (20.0, 20, 40);
        glColor3f(0, 0, 1);
        glutSolidSphere (1.0, 10,10);
        glColor3f(0.3, 0.3, 1);
        glutWireSphere (1.0,5,5);
        glPopMatrix();
        
    }
    
    
    
    
    glutSwapBuffers();
}


void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 2000.0);
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -500, 800, 0, 0, 0, 0, 1, 0);
}


void arrows (int key, int x, int y){
    
    if(!pausa){
        switch (key) {
            case 100:
            //izq
                cubeta.mover('l');
                glutPostRedisplay();
            
                break;
            case 101:
            //arriba
            
                cubeta.mover('d');
                glutPostRedisplay();
                break;
            case 102:
            //der
            
                cubeta.mover('r');
                glutPostRedisplay();
                break;
            case 103:
            //abajo
                cubeta.mover('u');
                glutPostRedisplay();
                break;
            
            default:
                break;
        }
    }
    
}


void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'p':
            pausa = !pausa;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}


void timerdrop(int param){
    if(!pausa){
        vector<int> toDelete;
    
        for(int i = 0; i < gotas.size();i++){
            if(gotas[i].caer()){
            
                int difx = abs(gotas[i].getX()-cubeta.getX());
                int dify = abs(gotas[i].getY()-cubeta.getY());
            
                if(difx < 50 && dify < 50 && gotas[i].getZ()<50){
                
                    toDelete.push_back(i);
                    atrapados++;
                
                
                }
            
            
            
            } else {
                toDelete.push_back(i);
                no_atrapados++;
            }
        
        }
    
        while (!toDelete.empty()) {
            gotas.erase(gotas.begin()+toDelete.back());
            toDelete.pop_back();
        }
    
    /*
    for(int i = 0; i < gotas.size();i++){
        if(!gotas[i].caer()){
            toDelete.push_back(i);
        }
    }
    
    while (!toDelete.empty()) {
        gotas.erase(gotas.begin()+toDelete.back());
        toDelete.pop_back();
    }*/
    
        cout << atrapados << " " << no_atrapados << endl;
    
    }
    glutPostRedisplay();
    glutTimerFunc(20, timerdrop, param);
}


void timergenerar(int param){
    
    if(!pausa){
        Gota gota(1);
        gotas.push_back(gota);
    }
    glutPostRedisplay();
    glutTimerFunc(3000, timergenerar, 1);
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
    glutSpecialFunc(arrows);
    glutTimerFunc(20, timerdrop, 1);
    glutTimerFunc(3000, timergenerar, 1);
    glutMainLoop();
    return 0;
}


