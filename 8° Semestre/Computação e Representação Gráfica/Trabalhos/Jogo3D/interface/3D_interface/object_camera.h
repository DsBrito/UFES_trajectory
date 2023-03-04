
#ifndef OBJECT_CAMERA_H
#define OBJECT_CAMERA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define CAMERA_PERCENT 360

class object_camera
{
public:
    // varaiveis de controle da camera

    // estado 1,2 ou 3
    int camera_state;
    GLdouble camera_size;

    // visão pelos angulos
    GLdouble camera_angleXY;
    GLdouble camera_angleXZ;
    GLdouble camera_angleYZ;

    // visão pelos olhos
    GLdouble camera_eyeX;
    GLdouble camera_eyeY;
    GLdouble camera_eyeZ;

    // visão pelo meio
    GLdouble camera_middleX;
    GLdouble camera_middleY;
    GLdouble camera_middleZ;
    // GLdouble camera_perspective;

    // controle de on/off
    GLdouble camera_onX;
    GLdouble camera_onY;
    GLdouble camera_onZ;
    // GLdouble camera_offX;
    // GLdouble camera_offY;
    // GLdouble camera_ffZ;

    void ReadCamera(int c_state, GLdouble c_ex, GLdouble c_ey, GLdouble c_ez, GLdouble c_mx, GLdouble c_my, GLdouble c_mz, GLdouble c_onx, GLdouble c_ony, GLdouble c_onz);
};

#endif // OBJECT_CAMERA_H
