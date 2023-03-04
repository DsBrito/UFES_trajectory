#ifndef OBJECT_ARENA_H
#define OBJECT_ARENA_H

#include <GL/gl.h>
#include <GL/glut.h>
#include "../3D_tools/objloader.h"

using namespace std;

class object_arena
{
public:
    GLfloat arena_x{};
    GLfloat arena_y{};
    GLfloat arena_z{};
    GLfloat arena_height{};
    GLfloat arena_width{};

    bool arena_side = false;

    // void ReadArena(GLfloat a_x, GLfloat a_y, GLfloat a_height, GLfloat a_width, const string &a_color);
    // função que irá criar/ler a arena
    void ReadArena(GLfloat a_x, GLfloat a_y, GLfloat a_z, GLfloat a_height, GLfloat a_width);
    void DrawArena();

    // função que irá ler a textura da arena
    void ReadTexture();

private:
    // materias retirados do lab 4 -> void DrawObj(double size). linha +-68
    GLfloat arena_matAmbient[4] = {0.1, 0.1, 0.1, 1};
    GLfloat arena_matDiffuse[4] = {5, 5, 5, 1};
    GLfloat arena_matSpecular[4] = {5, 5, 5, 1};
    GLfloat arena_matEmission[4] = {0.1, 0.1, 0.2, 1};
    GLfloat arena_matShininess[1] = {50.0};

    // desenho dos lados da arena arena
    //  texturas da arena (base/lado/cobertura)
    //  GLuint arena_textureBase{};
    GLuint arena_textureBase{};
    GLuint arena_textureSide{};
    GLuint arena_textureSky{};
    GLfloat arena_color[4] = {1, 1, 1, 1}; // cor da arena

    // void DrawBase(GLuint a_texture, norm a_norm, GLfloat a_width, GLfloat a_height, int calc);
    void DrawSky(GLuint a_texture, GLfloat a_size);
    void DrawSide(GLuint a_texture, GLfloat a_width, GLfloat a_height, int calc);
    void DrawBase(GLuint a_texture, norm a_norm, GLfloat a_width, GLfloat a_height, int calc);
};

#endif // OBJECT_ARENA_H
