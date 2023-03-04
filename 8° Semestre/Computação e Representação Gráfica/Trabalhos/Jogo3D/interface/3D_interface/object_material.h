
#ifndef OBJECT_MATERIAL_H
#define OBJECT_MATERIAL_H

#include <GL/gl.h>
#include <GL/glut.h>

/*Arquivo criado para modularizar o código (object_material) e tratar a parte de material separado e retirado de
    trechos de código presente nos labs : animação em modelo (Draw Axes) e terrasol (Display -> plane,erth, sun)
*/
class object_material
{
public:
    GLuint material_firstexture{};
    GLuint material_secondtexture{};
    GLfloat material_ambient[4] = {0, 0, 0, 1};
    GLfloat material_diffuse[4] = {0, 0, 0, 1};
    GLfloat material_specular[4] = {0, 0, 0, 1};
    GLfloat material_emission[4] = {0, 0, 0, 1};
    GLfloat material_shininess[1] = {30};
    GLfloat material_color[4] = {0, 0, 0, 1};

    void setMaterialColor(GLfloat r, GLfloat g, GLfloat b);
    // void setMaterialGroupColor(object_player &p, GLfloat idx, GLfloat a, GLfloat d, GLfloat s, GLfloat e);
};
#endif // OBJECT_MATERIAL_H
