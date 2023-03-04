
#ifndef OBJECT_MESH_H
#define OBJECT_MESH_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <string>
#include <cstring>
#include "../3D_tools/objloader.h"

using namespace std;

/*Arquivo criado para modularizar o código (object_mesh) e tratar a parte da mesh separado.
   Trecho de código retirado do objectload.h do laboratório codigo- Animacao de Modelos.
*/
class object_mesh
{

public:
    unsigned long mesh_changetexture;
    vector<pos> vertsPos;        // Lista de posicao dos vertices (original do OBJ)
    vector<norm> vertsNorm;      // Lista de normais dos vertices (original do OBJ)
    vector<tex> vertsTex;        // Lista de coor de textura dos vertices (original do OBJ)
    vector<verticeStrip> vertsS; // Lista ordenada de vertices das faces para o desenho do modelo via trangle strip
};

// Trecho de código retirado do objectload.h do laboratório codigo- Animacao de Modelos.

/*
mesh(){};

bool loadMesh(string path); // Path é o caminho para o arquivo .obj e deve conter o nome do arquivo.obj

void draw();

class meshes
{

public:
    // Variaveis de textura
    GLuint texID;
    char *texPixels;
    int texWidth;
    int texHeight;
    // Variaveis das meshes dos movimentos
    vector<vector<mesh>> vecMeshes;
    int currentMovID;
    int currentFrame;
    meshes()
    {
        texID = -1;
        currentMovID = -1;
        currentFrame = -1;
        vecMeshes.clear();
    };
    ~meshes(){};

    int loadMeshAnim(string path, int qtd); // Path é o caminho para o arquivo .obj e deve conter o nome do arquivo.obj
    bool loadTexture(string path);          // Path é o caminho para o arquivo .png e deve conter o nome do arquivo.png
    void draw(int movID, int frameId);
    void drawInit(int movID);
    void drawCurrent();
    bool drawNext();

};*/

#endif // OBJECT_MESH_H
