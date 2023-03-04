#include "tiro.h"
#include <math.h>
#define DISTANCIA_MAX 500

void Tiro::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
     //passar pra RGB
    glColor3f(R,G,B);

    //tamnaho dos pontos/polygno
    glPointSize(2.0);

    //mesma função que desenha a roda, com apenas um polígno fechado ao invés dos pontos
    glBegin(GL_POLYGON);
        for (int i = 0; i < 18; i++){
            glVertex2f(radius*cos(2*M_PI*i/18),radius*sin(2*M_PI*i/18));
        }
        glEnd();
}

void Tiro::DesenhaTiro(GLfloat x, GLfloat y)
{    //salva  o sistema de coordenadas do momento
    glPushMatrix();

    glTranslatef(x,y,0); //-- translada 
    DesenhaCirc(radiusTiro,1,1,1); //-- desenha

    //recupera o último o sistema salvo pelo push)
    glPopMatrix();

}

void Tiro::Move(GLdouble time)
{

    //atualizando o estado do tiro com base na posição anterior
    gX += gVel*cos(gDirectionAng*180/M_PI)*time;
    gY += gVel*sin(gDirectionAng*180/M_PI)*time;
}

bool Tiro::Valido()
{
    //se o tiro estiver longe da janela de vizualização ele se torna inválido/igorado
    if(gX > DISTANCIA_MAX | gY> DISTANCIA_MAX)
        return false;
    return true;
}
