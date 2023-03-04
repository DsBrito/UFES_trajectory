#ifndef ALVO_H
#define	ALVO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "tiro.h"

#define radiusAlvo 20

class Alvo {
    GLfloat gX; 
    GLfloat gY;
    int gColor;
private:
    void DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B);
    void DesenhaAlvo(GLfloat x, GLfloat y);
public:
    Alvo(GLfloat x, GLfloat y){
        gX = x; 
        gY = y;
        gColor = 0;
    };
    void Desenha(){ 
        DesenhaAlvo(gX, gY);
    };
    void Recria(GLfloat x, GLfloat y);
    bool Atingido(Tiro *tiro);
};

#endif	/* ALVO_H */

