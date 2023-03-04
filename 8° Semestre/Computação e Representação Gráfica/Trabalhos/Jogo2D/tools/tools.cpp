#include "tools.h"


using namespace std;

double Tools::DistanceTools(GLfloat _xTools, GLfloat _yTools, GLfloat x_Tools, GLfloat y_Tools){
    return sqrt(pow(_xTools - x_Tools, 2) + pow(_yTools - y_Tools, 2));

}
double Tools::MagnitudeTools(GLfloat _xTools, GLfloat _yTools){
    return sqrt(pow(_xTools, 2) + pow(_yTools, 2));

}
/*________________________________________________________________________________________________________________________________
|Função:                                  Auxiliar de Rotação                                                                     |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:    Funções TranslateTools e RotateTools foram retiradas do lab3                                                     |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  void translatePoint(GLfloat x, GLfloat y,GLfloat dx, GLfloat dy, GLfloat &xOut, GLfloat &yOut) e                         |
|        void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut)                                      |
|                                                                                                                                 |
|        Meu Github (arquivo robo.cpp -> linha 126...)                                                                            |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/
void Tools::TranslateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat _tTollsX, GLfloat _tTollsY) {
    _xTools += _tTollsX;
    _yTools += _tTollsY;
}
void Tools::RotateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat degress) {
    double radians = DegressToRadiansTools(degress);
    GLfloat timeX = _xTools;
    GLfloat timeY = _yTools;

    _xTools = timeX * cos(radians) - timeY * sin(radians);
    _yTools = timeX * sin(radians) + timeY * cos(radians);
}


//Fonte: https://matika.com.br/radianos/formula-para-converter-graus-para-radianos
double Tools::DegressToRadiansTools(GLfloat degress) {
    return degress * (M_PI / 180);
}
//Fonte: https://matika.com.br/radianos/conversao-de-radianos-para-graus
double Tools::RadiansToDegressTools(GLfloat radians) {
    return radians * (180 / M_PI);
}


/*________________________________________________________________________________________________________________________________
|Função:                                  Desenha Braços                                                                          |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:   A função FixHandTools  segue a mesma lógica da função DesenhaBraco presente no lab3                               | 
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)                                       |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo robo.cpp -> linha 43...)                                                                             |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/
void Tools::FixHandTools(GLfloat &gX_head,GLfloat &gY_head,GLfloat &gTheta_Head,GLfloat &newHandX,GLfloat &newHandY,GLfloat &d_HandX,GLfloat &d_HandY,GLfloat &d_ForearmX,GLfloat &d_ArmX,GLfloat &d_ArmY,GLfloat &d_ForearmY,GLfloat &d_ForearmAngle,GLfloat &d_ArmAngle,GLfloat &d_ForearmRotation,GLfloat &d_ArmRotation){
    TranslateTools(newHandX, newHandY, d_HandX, d_HandY);
    RotateTools(newHandX, newHandY, d_ForearmAngle + d_ForearmRotation);
    TranslateTools(newHandX, newHandY, d_ForearmX, d_ForearmY);

    RotateTools(newHandX, newHandY, d_ArmAngle + d_ArmRotation);
    TranslateTools(newHandX, newHandY, d_ArmX, d_ArmY);

    RotateTools(newHandX, newHandY, gTheta_Head);
    TranslateTools(newHandX, newHandY, gX_head, gY_head);
}



/*________________________________________________________________________________________________________________________________
|Função:                                        desenha circulo                                                                   |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:  Seguindo funções dadas em laboratório                                                                              | 
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)                                                               |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo robo.cpp -> linha 13..)                                                                               |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/
void Tools::CircleTraceTools(GLfloat p_radius){
    //passar pra RGB
    glColor3f(0,0,0);
    //tamanho dos pontos
    glPointSize(3.0);
    
    //desenhando o circulo em  20 graus até 360
    glBegin(GL_LINES);
        for (int i = 0; i < 36; i++){
            glVertex2f(p_radius* cos(2*M_PI*i/36),p_radius*sin(2*M_PI*i/36));
        }
    glEnd();

}


//Função auxiliar que faz  Translate e Rotate
 void Tools:: trTools(GLfloat &d_X,GLfloat &d_Y, GLfloat &d_Angle, GLfloat &d_Rotation){
    
    glTranslatef(d_X, d_Y, 0);
    glRotatef(d_Angle+ d_Rotation, 0, 0, 1);
  
 }
//Função auxiliar que faz  Rotate

void Tools::tTools(GLfloat &d_X, GLfloat &d_Y){
    glTranslatef(d_X, d_Y, 0);
}