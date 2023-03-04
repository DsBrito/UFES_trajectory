#include "alvo.h"
#include <math.h>

void Alvo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
  glColor3f(R,G,B);
  glPointSize(3.0);
  glBegin(GL_POLYGON);
      for (int i = 0; i < 18; i++){
         glVertex2f(radius*cos(2*M_PI*i/18),radius*sin(2*M_PI*i/18));
      }
    glEnd();
}

void Alvo::DesenhaAlvo(GLfloat x, GLfloat y)
{
    int* cor = AlvoGcolor(); 
    glPushMatrix();
    glTranslatef(x,y,0);
    switch (*cor)
    {
    case(1):
        DesenhaCirc(radiusAlvo,0,1,0);
        break;
    case(2):
        DesenhaCirc(radiusAlvo,0,0,1);
        break;
    
    default:
        DesenhaCirc(radiusAlvo,1,0,0);
        break;
    }
    glPopMatrix();
}

void Alvo::Recria(GLfloat x, GLfloat y)
{
    *(AlvoAdressX()) = x;
    *(AlvoAdressY()) = y;
    *(AlvoGcolor()) +=1;
    if(*(AlvoGcolor()) > 2){
        *(AlvoGcolor()) = 0;
    }
}

GLfloat quadrado(GLfloat x){
    return x*x;
}
bool Alvo::Atingido(Tiro *tiro)
{
    float distancia = sqrt(quadrado(*(tiro->ObtemXadressTiro())-*(AlvoAdressX())) + quadrado(*(tiro->ObtemYadressTiro()) - *(AlvoAdressY())));
    if((radiusAlvo+radiusTiro) > distancia){
        return true;
    }
    return false;
}