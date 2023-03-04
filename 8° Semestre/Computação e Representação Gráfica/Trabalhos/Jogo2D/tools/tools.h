#ifndef TOOLS_H
#define TOOLS_H

#include <GL/gl.h>
#include <GL/glu.h>

#include <cstdio>
#include <cmath>
using namespace std;

class Tools {
public:

//funções de ferramentas auxiliares
    static double DistanceTools(GLfloat _xTools, GLfloat _yTools, GLfloat x_Tools, GLfloat y_Tools);
    static double MagnitudeTools(GLfloat _xTools, GLfloat x_Tools);
    static void TranslateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat _tTollsX, GLfloat _tTollsY);
    static double DegressToRadiansTools(GLfloat degress);
    static void RotateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat degress);
    static void FixHandTools(GLfloat &gX_head,GLfloat &gY_head,GLfloat &gTheta_Head,GLfloat &newHandX,GLfloat &newHandY,GLfloat &d_HandX,GLfloat &d_HandY,GLfloat &d_ForearmX,GLfloat &d_ArmX,GLfloat &d_ArmY,GLfloat &d_ForearmY,GLfloat &d_ForearmAngle,GLfloat &d_ArmAngle,GLfloat &d_ForearmRotation,GLfloat &d_ArmRotation);
    static void CircleTraceTools(GLfloat p_radius);
    static void tTools(GLfloat &d_X, GLfloat &d_Y);
    static void trTools(GLfloat &d_X,GLfloat &d_Y, GLfloat &d_Angle, GLfloat &d_Rotation);
    static double RadiansToDegressTools(GLfloat radians); 
};
#endif //TOOLS_H