
#ifndef OBJECT_ARENA_H
#define OBJECT_ARENA_H


#include "object_rectangle.h"
using namespace std;

class object_arena {
public:
    GLfloat arena_x;
    GLfloat arena_y;
    GLfloat arena_height;
    GLfloat arena_width;
    GLfloat arena_R;
    GLfloat arena_G;
    GLfloat arena_B;

//função que irá criar/ler a arena
    void ReadArena(GLfloat a_x, GLfloat a_y, GLfloat a_height, GLfloat a_width, const string &a_color);
};


#endif //OBJECT_ARENA_H
