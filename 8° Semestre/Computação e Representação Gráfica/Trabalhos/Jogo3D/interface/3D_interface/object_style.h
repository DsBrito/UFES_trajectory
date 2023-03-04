
#ifndef OBJECT_STYLE_H
#define OBJECT_STYLE_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <string>
#include <cstring>
#include "../3D_tools/objloader.h"
#include "object_material.h"
#include "object_mesh.h"

using namespace std;

class object_style
{
public:
    vector<object_mesh> mesh_punch;
    vector<object_mesh> mesh_walk;
    vector<object_mesh> mesh_forwalk;
    object_mesh mesh_stop;
    object_material mat;

    void ReadStyle();

    void DrawStyle(object_mesh &mesh);

private:
    // Path é o caminho para o arquivo .obj e deve conter o nome do arquivo.obj
    bool ReadMesh(const char *path, object_mesh &mesh);
    // bool loadMesh(const char *path, object_mesh &mesh);
};

#endif // OBJECT_STYLE_H
