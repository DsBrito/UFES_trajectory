#ifndef OBJECT_CIRCLE_H
#define OBJECT_CIRCLE_H


#include <cstring>
#include <cmath>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;


class object_circle {
public:
    GLfloat circle_radius;
    GLfloat circle_R;
    GLfloat circle_G;
    GLfloat circle_B;
    object_circle(GLfloat c_radius, const string &c_color);

    object_circle(GLfloat c_radius, GLfloat c_R, GLfloat c_G, GLfloat c_B);

    void DrawCircle()const;
};

#endif //OBJECT_CIRCLE