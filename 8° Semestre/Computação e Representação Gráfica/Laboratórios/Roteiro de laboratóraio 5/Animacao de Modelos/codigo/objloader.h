#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include <vector>
#include <stdio.h>
#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H
using namespace std;

typedef struct POS{
    float x;
    float y;
    float z;
} pos;

typedef struct NORM{
    float x;
    float y;
    float z;
} norm;

typedef struct TEX{
    float u;
    float v;
} tex;

typedef struct VERTICE_STRIP{
    pos vPos;
    norm vNorm;
    tex vTex;
} verticeStrip;

class mesh{
	
    public:
    vector<pos> vertsPos; //Lista de posicao dos vertices (original do OBJ)   
    vector<norm> vertsNorm; //Lista de normais dos vertices (original do OBJ)   
    vector<tex> vertsTex; //Lista de coor de textura dos vertices (original do OBJ)   
    vector<verticeStrip> vertsS;//Lista ordenada de vertices das faces para o desenho do modelo via trangle strip
    mesh(){
    };
    bool loadMesh(string path);//Path é o caminho para o arquivo .obj e deve conter o nome do arquivo.obj
    void draw();
};

class meshes{
	
    public:
    //Variaveis de textura
    GLuint texID;
    char* texPixels;
    int texWidth;
    int texHeight;
    //Variaveis das meshes dos movimentos
    vector<vector<mesh>> vecMeshes;
    int currentMovID;
    int currentFrame;
    meshes(){
        texID = -1;
        currentMovID = -1;
        currentFrame = -1;
        vecMeshes.clear();
    };
    ~meshes(){
    };
    
    int loadMeshAnim(string path, int qtd);//Path é o caminho para o arquivo .obj e deve conter o nome do arquivo.obj
    bool loadTexture(string path);//Path é o caminho para o arquivo .png e deve conter o nome do arquivo.png
    void draw(int movID, int frameId);
    void drawInit(int movID);
    void drawCurrent();
    bool drawNext();
};
#endif
