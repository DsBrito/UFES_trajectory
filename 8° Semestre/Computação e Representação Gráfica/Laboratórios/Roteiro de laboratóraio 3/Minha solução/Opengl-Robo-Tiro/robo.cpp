#include "robo.h"
#include <math.h>

void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
 //passar pra RGB
 glColor3f(R,G,B);

 //desenha o retangulo
 glRectf(-width/2.0,0,width/2.0,height);
}

void Robo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
     //passar pra RGB
    glColor3f(R,G,B);

    //tamanho dos pontos
    glPointSize(3.0);
    
    //desenhando o circulo em  20 graus até 360
    glBegin(GL_POINTS);
        for (int i = 0; i < 18; i++){
            glVertex2f(radius* cos(2*M_PI*i/18),radius*sin(2*M_PI*i/18));
        }
    glEnd();
}

void Robo::DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat R, GLfloat G, GLfloat B)
{

    //salva  o sistema de coordenadas do momento
    glPushMatrix();

    glTranslatef(x,y,0);  //-- translada
    glRotatef(thetaWheel,0,0,1); //-- roda
    DesenhaCirc(radiusWheel,R,G,B); //-- desenha

    //recupera o último o sistema salvo pelo push)
    glPopMatrix();
}

void Robo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
    //salva  o sistema de coordenadas do momento
    glPushMatrix();

    //colocando a haste na possição correta
    glTranslatef(x,y,0); //- sobe
    glRotatef(theta1,0,0,1); //- roda
    //chamada para desenhar a primeira haste
    DesenhaRect(paddleHeight,paddleWidth,0,0,1);

    //----------------------------------------------
    //colocando a haste na possição correta
    glTranslatef(x,paddleHeight,0); //- sobe
    glRotatef(theta2,0,0,1); //- roda 
    //chamada para desenhar a segunda haste
    DesenhaRect(paddleHeight,paddleWidth,1,1,0);

    //----------------------------------------------
    //colocando a haste na possição correta
    glTranslatef(x,paddleHeight,0); //- sobe
    glRotatef(theta3,0,0,1); //- roda
    //chamada para desenhar a terceira haste
    DesenhaRect(paddleHeight,paddleWidth,1,0,1); 


    //recupera o último o sistema salvo pelo push)
    glPopMatrix();

}

void Robo::DesenhaRobo(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{

    //salva  o sistema de coordenadas do momento
    glPushMatrix();

    //-- DESENHANDO BASE 
    //colocando o retangulo na posição correta
    glTranslatef(x,y,0);
    //chamada de desenho do retangulo base
    DesenhaRect(baseHeight,baseWidth,1,0,0);


    //-- DESENHANDO BRAÇO
    DesenhaBraco( 0,  baseHeight,  theta1,  theta2,  theta3);


    //-- DESENHANDO RODA
    DesenhaRoda((baseWidth/2),0,thetaWheel,1,1,1);
    DesenhaRoda(-(baseWidth/2),0,thetaWheel,1,1,1);


    //recupera o último o sistema salvo pelo push)
    glPopMatrix();
}

void Robo::RodaBraco1(GLfloat inc)
{   
    //girando o braço do rôbo em teta1
    gTheta1+=inc;
}

void Robo::RodaBraco2(GLfloat inc)
{
    //girando o braço do rôbo em teta2
    gTheta2+=inc;
}

void Robo::RodaBraco3(GLfloat inc)
{
    //girando o braço do rôbo em teta3
    gTheta3+=inc;
}

void Robo::MoveEmX(GLfloat dx)
{
    //incrementando o Rôbo/base em X
    gX+=dx;
    gThetaWheel+= -(360*dx)/(2*M_PI*radiusWheel);
}

//Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){
      GLfloat a = x;
      xOut =  x*cos(angle*M_PI/180) - (y*sin(angle*M_PI/180));
      yOut = (a*sin(angle*M_PI/180)) + y*cos(angle*M_PI/180); 
}

//Funcao auxiliar de translação
void translatePoint(GLfloat x, GLfloat y,GLfloat dx, GLfloat dy, GLfloat &xOut, GLfloat &yOut){
  xOut = x+dx;
  yOut = y+dy;
}

Tiro* Robo::Atira()
{
  GLfloat xBase3=0, yBase3=0; //-- a base da haste é representada por x = 0.0 e y = 0.0 (após aplicartodas as transformações usadas para desenhá-la)
  GLfloat pontaX, pontaY; //-- a ponta da haste é representada por x = 0.0 e y = paddleHeight (após aplicartodas as transformações usadas para desenhá-la)


//------------ primeira parte --------
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);//-- colocando a ponta/base na posição correta

  RotatePoint(xBase3,yBase3,gTheta3,xBase3,yBase3); //-- rotação de gTheta3
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3); //-- translação de paddleHeight em y

  RotatePoint(xBase3,yBase3,gTheta2,xBase3,yBase3);//-- rotação de gTheta2
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);//-- translação depaddleHeight em y
  
  RotatePoint(xBase3,yBase3,gTheta1,xBase3,yBase3);//-- rotação de gTheta1
  translatePoint(xBase3,yBase3,0,baseHeight,xBase3,yBase3);//--translação de baseHeightem y  

  translatePoint(xBase3,yBase3,gX,gY,xBase3,yBase3);//--  translação para a posição no mundo gX e gY.

  
//------------ segunda parte --------
  pontaX = xBase3;
  pontaY = yBase3;
  
  xBase3=0; yBase3=0;
  RotatePoint(xBase3,yBase3,gTheta3,xBase3,yBase3);//-- rotação de gTheta3
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);//-- translação de paddleHeight em y

  RotatePoint(xBase3,yBase3,gTheta2,xBase3,yBase3);//-- rotação de gTheta2
  translatePoint(xBase3,yBase3,0,paddleHeight,xBase3,yBase3);//-- translação depaddleHeight em y

  RotatePoint(xBase3,yBase3,gTheta1,xBase3,yBase3);//-- rotação de gTheta1
  translatePoint(xBase3,yBase3,0,baseHeight,xBase3,yBase3);//--translação de baseHeightem y 

  translatePoint(xBase3,yBase3,gX,gY,xBase3,yBase3);//--  translação para a posição no mundo gX e gY.

//------------ terceira parte --------
// TIRO
  float angulo = atan2((pontaY-yBase3),(pontaX-xBase3))*M_PI/180;
  Tiro* tiro = new Tiro(pontaX,pontaY, angulo);
  return tiro;
  
}
 
