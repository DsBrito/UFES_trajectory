
#ifndef OBJECT_RECTANGLE_H
#define OBJECT_RECTANGLE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <string>


//dimensões - variaveis das formas retangulares
class object_rectangle {
public:
    GLfloat retangle_height;
    GLfloat retangle_width;
    GLfloat retangle_R;
    GLfloat retangle_G;
    GLfloat retangle_B;

    object_rectangle();

    object_rectangle(GLfloat _height, GLfloat _width, GLfloat r, GLfloat g, GLfloat b);

    void DrawRectangle();
};


#endif 
