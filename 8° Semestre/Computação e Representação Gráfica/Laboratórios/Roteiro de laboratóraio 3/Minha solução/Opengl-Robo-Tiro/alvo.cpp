#include "alvo.h"
#include <math.h>

void Alvo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
     //passar pra RGB
    glColor3f(R,G,B);

    //tamnaho dos pontos/polygno
    glPointSize(3.0);

    //mesma função que desenha a roda, com apenas um polígno fechado ao invés dos pontos
    glBegin(GL_POLYGON);
        for (int i = 0; i < 18; i++){
            glVertex2f(radius*cos(2*M_PI*i/18),radius*sin(2*M_PI*i/18));
        }
        glEnd();
}

void Alvo::DesenhaAlvo(GLfloat x, GLfloat y)
{
    //DESENHO DO ALVO - Similar ao do tiro, utilizando o radiusAlvo e a cor adicionada ao valor de gColor(vermelho/verde/azul)
    int* cor = retornaAlvoCor(); 
    glPushMatrix();
    glTranslatef(x,y,0);
    switch (*cor)
    {
    case(1):
        DesenhaCirc(radiusAlvo,1,1,0);//100 - amarelo
        break;
    case(2):
        DesenhaCirc(radiusAlvo,0,1,0); //001 - verde
        break;
    
    default:
        DesenhaCirc(radiusAlvo,1,0,0); //vermelho
        break;
    }
    glPopMatrix();
}

void Alvo::Recria(GLfloat x, GLfloat y)
{
    //retornaAlvoCor = dar acesso a variavel gColor para incremento
    //a cor gColor pode variar em valores entre (0, 1 e 2)
    *(retornaXAlvo()) = x; //--gX
    *(retornaYAlvo()) = y; //--gY
    *(retornaAlvoCor()) +=1; //-- gColor
    if(*(retornaAlvoCor()) > 2){
        *(retornaAlvoCor()) = 0;
    }
}

//funcão auxiliar de quadrado
GLfloat quadrado(GLfloat x){
    return x*x;
}
bool Alvo::Colisao(Tiro *tiro)
{
    //retornar verdadeiro se o tiro estiver dentro do raio do alvo radiusAlvo;
    float distancia = sqrt(quadrado(*(tiro->retornaXTiro())-*(retornaXAlvo())) + quadrado(*(tiro->retornaYTiro()) - *(retornaYAlvo())));
    if((radiusAlvo+radiusTiro) > distancia){
        return true;
    }
    return false;
}