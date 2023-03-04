
#include "object_camera.h"

// inicializa a camera
void object_camera::ReadCamera(int c_state, GLdouble c_ex, GLdouble c_ey, GLdouble c_ez, GLdouble c_mx, GLdouble c_my, GLdouble c_mz, GLdouble c_onx, GLdouble c_ony, GLdouble c_onz)
{
    camera_state = c_state;

    // GLdouble camera_angleXY =;
    // GLdouble camera_angleXZ =;
    // GLdouble camera_angleYZ =;

    // camera_size = ;
    camera_eyeX = c_ex;
    camera_eyeY = c_ey;
    camera_eyeZ = c_ez;
    camera_middleX = c_mx;
    camera_middleY = c_my;
    camera_middleZ = c_mz;
    //   camera_perspective = ;

    camera_onX = c_onx;
    camera_onY = c_ony;
    camera_onZ = c_onz;
    //   camera_offX =;
    //   camera_offY = ;
    //   camera_ffZ= ;
}
