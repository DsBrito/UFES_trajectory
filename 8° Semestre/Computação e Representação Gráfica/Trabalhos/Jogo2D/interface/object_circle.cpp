


#include "object_circle.h"


//setando a cor dos circulos a serem desenhados

object_circle::object_circle(GLfloat c_r,const string &c_color) {
    circle_radius = c_r;
    
    if (strcmp(c_color.c_str(),"blue")==0) {
        circle_R = 0;
        circle_G = 0;
        circle_B = 1;
    } else if(strcmp(c_color.c_str(),"red")==0) {
        circle_R = 1;
        circle_G = 0;
        circle_B = 0;
    } else if (strcmp(c_color.c_str(),"green")==0)  {
        circle_R = 0;
        circle_G = 1;
        circle_B = 0;
    }
}

/*________________________________________________________________________________________________________________________________
|Função:                                        desenha circulo                                                                   |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:  Seguindo funções dadas em laboratório                                                                              | 
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)                                                               |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo alvo.cpp -> linha 4..)                                                                               |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/
//retirada do lab robo
void object_circle::DrawCircle() const {
     //passar pra RGB
    glColor3f(circle_R,circle_G,circle_B);

    //tamanho dos pontos
    glPointSize(3.0);
    
    //desenhando o circulo
    //mesma função que desenha a roda do lab 3 do robÔ, com apenas um polígno fechado ao invés dos pontos

    glBegin(GL_POLYGON); ////GL_POINST Só desenha os pontos e não perenche
        for (int i = 0; i < 18; i++){
            glVertex2f(circle_radius* cos(2*M_PI*i/18),circle_radius*sin(2*M_PI*i/18));
        }
    glEnd();
}


//circulo das mãos  (menores)
object_circle::object_circle(GLfloat c_radius, GLfloat c_R, GLfloat c_G, GLfloat c_B) {

    object_circle:: circle_radius = c_radius;
                    circle_R = c_R;
                    circle_G = c_G;
                    circle_B = c_B;
}

