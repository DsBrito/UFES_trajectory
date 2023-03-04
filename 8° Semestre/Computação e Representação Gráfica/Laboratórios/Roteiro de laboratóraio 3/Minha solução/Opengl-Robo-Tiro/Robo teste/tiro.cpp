#include "tiro.h"
#include <math.h>
#define DISTANCIA_MAX 500

void Tiro::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
   glColor3f(R,G,B);
  glPointSize(2.0);
  glBegin(GL_POLYGON);
      for (int i = 0; i < 18; i++){
         glVertex2f(radius*cos(2*M_PI*i/18),radius*sin(2*M_PI*i/18));
      }
    glEnd();
}

void Tiro::DesenhaTiro(GLfloat x, GLfloat y)
{
glPushMatrix();
  glTranslatef(x,y,0);
  DesenhaCirc(radiusTiro,1,1,1);
glPopMatrix();
}

void Tiro::Move(GLdouble time)
{
  *(ObtemXadressTiro()) += *(ObtemXgVelAdress())*cos(*(obtemDirection())*180/M_PI)*time;
  *(ObtemYadressTiro()) += *(ObtemXgVelAdress())*sin(*(obtemDirection())*180/M_PI)*time;
}

bool Tiro::Valido()
{
  if(*(ObtemXadressTiro()) > DISTANCIA_MAX | *(ObtemYadressTiro()) > DISTANCIA_MAX)
    return false;
  return true;
}