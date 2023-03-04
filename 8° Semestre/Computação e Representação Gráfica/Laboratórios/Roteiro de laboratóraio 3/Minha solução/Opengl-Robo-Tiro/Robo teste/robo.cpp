#include "robo.h"
#include <math.h>
#include <stdio.h>
void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{

  /* Limpar todos os pixels  */
  //glClear (GL_COLOR_BUFFER_BIT);

  /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
  glColor3f (R, G, B);
  /* Desenhar um polígono branco (retângulo) */
  glBegin(GL_POLYGON);
    glVertex2f((width/2), 0.0 );
    glVertex2f((width/2), height );
    glVertex2f(-(width/2), height);
    glVertex2f(-(width/2),0);
     glEnd();
  
}

void Robo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
  glColor3f(R,G,B);
  glPointSize(3.0);
  glBegin(GL_POINTS);
      for (int i = 0; i < 18; i++){
         glVertex2f(radius* cos(2*M_PI*i/18),radius*sin(2*M_PI*i/18));
      }
   glEnd();
}

void Robo::DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat R, GLfloat G, GLfloat B)
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(thetaWheel,0,0,1);
    DesenhaCirc(radiusWheel,R,G,B);
    glPopMatrix();
}

void Robo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(theta1,0,0,1);
    DesenhaRect(paddleHeight,paddleWidth,0,0,1);
    glTranslatef(x,paddleHeight,0);
    glRotatef(theta2,0,0,1);
    DesenhaRect(paddleHeight,paddleWidth,1,1,0);
    glTranslatef(x,paddleHeight,0);
    glRotatef(theta3,0,0,1);
    DesenhaRect(paddleHeight,paddleWidth,0,1,0);
    glPopMatrix();  
}

void Robo::DesenhaRobo(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
  glPushMatrix();
  glTranslatef(x,y,0.0);
  DesenhaRect(baseHeight,baseWidth,1.0,0,0);
  DesenhaRoda((baseWidth/2),0,thetaWheel,1,1,1);
  DesenhaRoda(-(baseWidth/2),0,thetaWheel,1,1,1);
  DesenhaBraco(0.0,baseHeight,theta1,theta2,theta3);
  glPopMatrix();
}

void Robo::RodaBraco1(GLfloat inc)
{
    *(ObtemTheta1adress()) += inc;
}

void Robo::RodaBraco2(GLfloat inc)
{
      *(ObtemTheta2adress()) += inc;
}

void Robo::RodaBraco3(GLfloat inc)
{
    *(ObtemTheta3adress()) += inc;
}

void Robo::MoveEmX(GLfloat dx)
{
  
  *(ObtemXadress()) += dx;
  *(ObtemThetawheeladress()) += -(360*dx)/(2*M_PI*radiusWheel);
}

//Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){
      GLfloat a = x;
      xOut =  x*cos(angle*M_PI/180) - (y*sin(angle*M_PI/180));
      yOut = (a*sin(angle*M_PI/180)) + y*cos(angle*M_PI/180); 
}

void translatePoint(GLfloat x, GLfloat y,GLfloat dx, GLfloat dy, GLfloat &xOut, GLfloat &yOut){
  xOut = x+dx;
  yOut = y+dy;
}


Tiro* Robo::Atira()
{
 
  GLfloat xBase3=0, yBase3=0;
  GLfloat pontaX, pontaY;

  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);
  RotatePoint(xBase3,yBase3,*(ObtemTheta3adress()),xBase3,yBase3);
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);
  RotatePoint(xBase3,yBase3,*(ObtemTheta2adress()),xBase3,yBase3);
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);
  RotatePoint(xBase3,yBase3,*(ObtemTheta1adress()),xBase3,yBase3);
  translatePoint(xBase3,yBase3,0,baseHeight,xBase3,yBase3);
  translatePoint(xBase3,yBase3,ObtemX(),ObtemY(),xBase3,yBase3);
  
  pontaX = xBase3;
  pontaY = yBase3;
  
  xBase3=0; yBase3=0;
  RotatePoint(xBase3,yBase3,*(ObtemTheta3adress()),xBase3,yBase3);
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);
  RotatePoint(xBase3,yBase3,*(ObtemTheta2adress()),xBase3,yBase3);
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);
  RotatePoint(xBase3,yBase3,*(ObtemTheta1adress()),xBase3,yBase3);
  translatePoint(xBase3,yBase3,0,baseHeight,xBase3,yBase3);
  translatePoint(xBase3,yBase3,ObtemX(),ObtemY(),xBase3,yBase3);


  float angulo = atan2((pontaY-yBase3),(pontaX-xBase3))*M_PI/180;
  Tiro* tiro = new Tiro(pontaX,pontaY, angulo);
  return tiro;
  
}