
// cabeçario simples
#include "object_material.h"

void object_material::setMaterialColor(GLfloat r, GLfloat g, GLfloat b)
{
    material_color[0] = r;
    material_color[1] = g;
    material_color[2] = b;
};

/*
void object_material ::setMaterialGroupColor(object_style &p, GLfloat idx, GLfloat a, GLfloat d, GLfloat s, GLfloat e)
{
    p.mat.material_ambient[idx] = a;
    p.mat.material_diffuse[idx] = d;
    p.mat.material_specular[idx] = s;
    p.mat.material_emission[idx] = e;
}*/