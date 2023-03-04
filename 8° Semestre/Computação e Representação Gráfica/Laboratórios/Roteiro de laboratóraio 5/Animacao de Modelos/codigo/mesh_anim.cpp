#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include "objloader.h"
using namespace std;

//Malhas a serem desenhadas
meshes lutador;

//Controles gerais
int zoom = 150;
int coordsysToggle = 1;
double camXYAngle=0;
double camXZAngle=0;
int lastX = 0;
int lastY = 0;
int buttonDown=0;

//ID das meshes lidas
int movIdle = -1;
int movPunch = -1;
int movKick = -1;
int movDance = -1;

//Controles dos golpes
int kicking = 0;
int punching = 0;
int dancing = 0;
int acting = 0;

//Controle do tempo
//Soh trata maquinas mais rapidas, nao faz animacao relativa ao tempo
int currentTime = 0;
int lastTime = 0;
int updateDrawing = 0;


void init ()
{
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    
    //Carrega as meshes dos arquivos
    movIdle = lutador.loadMeshAnim("Blender/idle/ninja_idle_######.obj", 40);
    movPunch = lutador.loadMeshAnim("Blender/punch/ninja_punching_######.obj", 35);
    movKick = lutador.loadMeshAnim("Blender/kick/ninja_kick_######.obj", 35);
    movDance = lutador.loadMeshAnim("Blender/dance/ninja_dance_######.obj", 90);
    lutador.loadTexture("Blender/Ch24_1001_Diffuse.bmp");
    
    lutador.drawInit(movIdle);

}

void reshape (int w, int h)
{
    //Ajusta o tamanho da tela com a janela de visualizacao
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluPerspective (45, (GLfloat)h/(GLfloat)w, 1, 1000);
    else
        gluPerspective (45, (GLfloat)w/(GLfloat)h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void DrawAxes(double size)
{
    GLfloat mat_ambient_r[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient_g[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat mat_ambient_b[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, 
            no_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_mat);

    //x axis
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_r);
        glColor3fv(mat_ambient_r);
        glScalef(size, size*0.1, size*0.1);
        glTranslatef(0.5, 0, 0); // put in one end
        glutSolidCube(1.0);
    glPopMatrix();

    //y axis
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_g);
        glColor3fv(mat_ambient_g);
        glRotatef(90,0,0,1);
        glScalef(size, size*0.1, size*0.1);
        glTranslatef(0.5, 0, 0); // put in one end
        glutSolidCube(1.0);
    glPopMatrix();

    //z axis
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_b);
        glColor3fv(mat_ambient_b);
        glRotatef(-90,0,1,0);
        glScalef(size, size*0.1, size*0.1);
        glTranslatef(0.5, 0, 0); // put in one end
        glutSolidCube(1.0);
    glPopMatrix();
    
}

//Usar meshlab para obter os pontos abaixo
void desenhaJogador(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        //Translada para o centro do lutador para facilitar a rotacao da camera
        glTranslatef(0,-50,0);

        //Escolhe entre iniciar o desenho do chute ou soco
        if (kicking && !acting){
            lutador.drawInit(movKick);
            acting = 1;
        } else if (punching && ! acting){
            lutador.drawInit(movPunch);
            acting = 1;
        } else if (dancing && ! acting){
            lutador.drawInit(movDance);
            acting = 1;
        }

        //Desenha as proximas frames ateh acabar
        int rtn = lutador.drawNext();
        //Reinicia com o movimento de parado esperando a luta
        if (rtn){
            lutador.drawInit(movIdle);
            acting = 0;
            punching = 0;
            kicking = 0;
            dancing = 0;
        }
        
        if (coordsysToggle == 1)
            DrawAxes(10);
    glPopMatrix();
}

void display(void)
{
    //Desenha de acordo com o tempo transcorrido
    //Evita que maquinas mais rapidas acelerem os movimentos
    if (updateDrawing){
        updateDrawing = 0;
    } else{
        return;
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //Limpa a cor com azulado
    glClearColor (0.30, 0.30, 1.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Utiliza uma esfera de raio zoom para guiar a posicao da camera
    //baseada em dois angulos (do plano XZ e do plano XY)
    gluLookAt(  zoom*sin(camXZAngle*M_PI/180)*cos((camXYAngle*M_PI/180)),
                zoom*                         sin((camXYAngle*M_PI/180)),
                zoom*cos(camXZAngle*M_PI/180)*cos((camXYAngle*M_PI/180)),
                0, 0, 0,
                0, 1, 0);
    
    desenhaJogador();

    //Define e desenha a fonte de luz
    GLfloat light_position[] = {10, 10, 50, 1};
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glDisable(GL_LIGHTING);
        glPointSize(15);
        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POINTS);
            glVertex3f(light_position[0],light_position[1],light_position[2]);
        glEnd();    
    glEnable(GL_LIGHTING);
    
    glutSwapBuffers ();
}

void keyPress(unsigned char key, int x, int y)
{
    switch(key){
    case 'a':
        if (acting) break;
        kicking = 1;
        break;
    case 'd':
        if (acting) break;
        punching = 1;
        break;
    case ' ':
        if (acting) break;
        dancing = 1;
        break;
    case 'c':
        coordsysToggle = !coordsysToggle;
        break;
    case '+':
        zoom++;
        break;
    case '-':
        zoom--;
         break;
    case 27 :
         exit(0);
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        lastX = x;
        lastY = y;
        buttonDown = 1;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        buttonDown = 0;
    }
    glutPostRedisplay();
}

void mouse_motion(int x, int y)
{
    if (!buttonDown)
        return;
    
    camXZAngle -= x - lastX;
    camXYAngle += y - lastY;

    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

void idle()
{
    // Elapsed time from the initiation of the game.
    currentTime = glutGet(GLUT_ELAPSED_TIME);

    int fatorTempo = 20;
    if (currentTime - lastTime > fatorTempo){
        lastTime = currentTime;
        updateDrawing = 1;
    }
    
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (700,700);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Mesh Animation");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);
    glutMotionFunc(mouse_motion);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
