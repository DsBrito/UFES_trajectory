#ifndef ROBO_H
#define	ROBO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "tiro.h"
// Dimensions
#define paddleHeight 80
#define paddleWidth 10
#define baseHeight 40
#define baseWidth 100
#define radiusWheel 30

class Robo {
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gTheta1; 
    GLfloat gTheta2; 
    GLfloat gTheta3; 
    GLfloat gThetaWheel; 
    GLfloat direction;
private:
    void DesenhaRect(  GLint height, GLint width, 
                    GLfloat R, GLfloat G, GLfloat B);
    void DesenhaCirc(  GLint radius, GLfloat R, 
                    GLfloat G, GLfloat B);
    void DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, 
                    GLfloat R, GLfloat G, GLfloat B);
    void DesenhaBraco(   GLfloat x, GLfloat y, GLfloat theta1, 
                    GLfloat theta2, GLfloat theta3);
    void DesenhaRobo( GLfloat x, GLfloat y, GLfloat thetaWheel, 
                    GLfloat theta1, GLfloat theta2, GLfloat theta3);

public:
    Robo(){
        gX = 0; 
        gY = -200; 
        gTheta1 = 0; 
        gTheta2 = 0; 
        gTheta3 = 0; 
        gThetaWheel = 0; 
    };
    void Desenha(){ 
        DesenhaRobo(gX, gY, gThetaWheel, gTheta1, 
                gTheta2, gTheta3);
    };
    void RodaBraco1(GLfloat inc);
    void RodaBraco2(GLfloat inc);
    void RodaBraco3(GLfloat inc);
    void MoveEmX(GLfloat dx);
    Tiro* Atira();
    GLfloat ObtemX(){
        return gX;
    };
    GLfloat ObtemY(){
        return gY;
    };
};

#endif	/* ROBO_H */

