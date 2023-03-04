

#include "object_style.h"
#include "../2D_tools/tools.h"
#include <iostream>
using namespace std;

// função para carregar o OBJ
// bool mesh::loadMesh(string path){
/*___________________________________________________________________________________________________________________________________
|Função:                                  ReadStyle                                                                                  |
|------------------------------------------------------------------------------------------------------------------------------------|
|Comentários:   Baseado na função de ler mesh, onde era necessário dá push_back e criar uma lista com os indices de vértices/frames  |
|               na ordem apropriada para o desenho das faces do jogodor.                                                             |
|               idle = 1 frame                                                                                                       |
|               walking = 23 frames                                                                                                  |
|               boxing = 43 frames                                                                                                   |
|                                                                                                                                    |
|               textura_upper/lower = retiradas do site mixamo "https://www.mixamo.com/#/?page=2&type=Character" Zlorp personagem    |
|               textura walking/punching = retirada em "https://www.mixamo.com/#/?page=1&type=Character" Alien Soldier personagem    |
|                                                                                                                                    |
|------------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Baseado na função loadMesh(string path) do objloader.c do laboratório codigo- Animacao de Modelos.                         |
| ___________________________________________________________________________________________________________________________________|*/

void object_style::ReadStyle()
{
    object_mesh frame;

    cout << "- loading object_style texture..." << endl;

    mat.material_firstexture = Tools::TextureTools("../blender/texture/texture_upper.bmp");
    cout << "   texture_upper (1/2)" << endl;
    mat.material_secondtexture = Tools::TextureTools("../blender/texture/texture_lower.bmp");
    cout << "   texture_lower (2/2)" << endl;
    cout << " object_style texture ok." << endl
         << endl;

    // lendo a mesh "Idle Ready"
    ReadMesh("../blender/idle/aliensolide_idle.obj", mesh_stop);

    cout << "- loading object_style mesh..." << endl;

    // lendo a mesh " Walking"
    cout << "   reading aliensolide_walking.obj (01/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking1.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (02/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking2.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (03/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking3.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (04/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking4.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (05/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking5.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (06/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking6.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (07/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking7.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (08/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking8.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (09/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking9.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (10/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking10.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (11/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking11.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (12/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking12.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (13/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking13.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (14/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking14.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (15/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking15.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (16/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking16.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (17/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking17.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (18/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking18.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (19/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking19.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (20/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking20.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (21/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking21.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (22/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking22.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (23/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking23.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (24/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking24.obj", frame);
    mesh_walk.push_back(frame);

    cout << "   reading aliensolide_walking.obj (25/25)" << endl;
    ReadMesh("../blender/walking/aliensolide_walking25.obj", frame);
    mesh_walk.push_back(frame);
    cout << "    aliensolide_walking ok." << endl;

    // for retiradado da mesma função de loadMesh
    for (int i = (int)mesh_walk.size() - 1; i >= 0; i--)
    {
        mesh_forwalk.push_back(mesh_walk[i]);
    }

    // lendo a mesh "Boxing"
    cout << "   reading aliensolide_boxing.obj (01/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing1.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (02/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing2.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (03/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing3.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (04/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing4.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (05/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing5.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (06/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing6.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (07/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing7.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (08/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing8.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (09/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing9.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (10/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing10.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (11/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing11.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (12/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing12.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (13/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing13.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (14/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing14.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (15/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing15.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (16/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing16.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (17/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing17.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (18/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing18.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (19/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing19.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (20/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing20.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (21/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing21.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (22/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing22.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (23/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing23.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (24/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing24.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (25/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing25.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (26/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing26.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (27/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing27.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (28/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing28.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (29/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing29.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (30/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing30.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (31/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing31.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (32/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing32.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (33/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing33.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (34/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing34.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (35/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing35.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (36/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing36.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (37/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing37.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (38/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing38.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (39/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing39.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (40/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing40.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (41/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing41.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (42/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing42.obj", frame);
    mesh_punch.push_back(frame);

    cout << "   reading aliensolide_boxing.obj (43/43)" << endl;
    ReadMesh("../blender/boxing/aliensolide_boxing43.obj", frame);
    mesh_punch.push_back(frame);
    cout << "    aliensolide_boxing mesh ok." << endl;

    cout << " object_style mesh ok." << endl
         << endl;
}

// desenha a malha
// ninja svoid mesh::draw()
/*___________________________________________________________________________________________________________________________________
|Função:                                  DrawStyle                                                                                  |
|------------------------------------------------------------------------------------------------------------------------------------|
|Comentários:   Exatamente igual a função passada pelo professor para desenhar a malha do jogador                                    |
|------------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Retirado da função draw() do objloader.c do laboratório codigo- Animacao de Modelos.                                       |
| ___________________________________________________________________________________________________________________________________|*/
void object_style::DrawStyle(object_mesh &style)
{
    bool cont = true;

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat.material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat.material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat.material_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat.material_emission);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat.material_shininess);
    mat.material_color[0] = 1;
    mat.material_color[1] = 1;
    mat.material_color[2] = 1;
    glColor3f(mat.material_color[0], mat.material_color[1], mat.material_color[2]); // aqui
    //   glColor3f(mat.material_color[1], mat.material_color[0], mat.material_color[2]); //aqui

    glBindTexture(GL_TEXTURE_2D, mat.material_firstexture);
    for (unsigned int i = 0; i < style.vertsS.size(); i = i + 3)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (unsigned int j = i; j < i + 3; j++)
        {
            glNormal3f(style.vertsS[j].vNorm.x, style.vertsS[j].vNorm.y, style.vertsS[j].vNorm.z);
            glTexCoord2f(style.vertsS[j].vTex.u, style.vertsS[j].vTex.v);
            glVertex3f(style.vertsS[j].vPos.x, style.vertsS[j].vPos.y, style.vertsS[j].vPos.z);
        }
        glEnd();

        if (i >= style.mesh_changetexture && cont)
        {
            cont = false;
            glBindTexture(GL_TEXTURE_2D, mat.material_secondtexture);
        }
    }
}

// função para carregar o OBJ
// bool mesh::loadMesh(string path){

/*___________________________________________________________________________________________________________________________________
|Função:                                  ReadMesh                                                                                   |
|------------------------------------------------------------------------------------------------------------------------------------|
|Comentários:   Exatamente igual a função passada pelo professor para ler a malha do jogador                                         |
|------------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Retirado da função draw() do objloader.c do laboratório codigo- Animacao de Modelos.                                        |
| ___________________________________________________________________________________________________________________________________|*/
bool object_style::ReadMesh(const char *path, object_mesh &mesh)
{
    std::vector<int> vertIndex, uvIndex, normIndex; // indexadores para vertices, mapeamento de textura e normais
    mesh.vertsPos.clear();
    mesh.vertsNorm.clear();
    mesh.vertsTex.clear();
    mesh.vertsS.clear();
    FILE *file = fopen(path, "r");
    if (file == nullptr)
    {
        cout << "**falha ao carregar o arquivo." << endl;
        return false;
    }
    else
    {
        while (true)
        {
            char lineHeader[128];
            int res = fscanf(file, "%s", lineHeader);
            if (res == EOF)
            {
                break;
            }
            if (strcmp(lineHeader, "v") == 0)
            {
                pos vert;
                fscanf(file, "%f %f %f\n", &vert.x, &vert.y, &vert.z);
                mesh.vertsPos.push_back(vert);
            }
            else if (strcmp(lineHeader, "vt") == 0)
            {
                tex vert;
                fscanf(file, "%f %f\n", &vert.u, &vert.v);
                mesh.vertsTex.push_back(vert);
            }
            else if (strcmp(lineHeader, "vn") == 0)
            {
                norm vert;
                fscanf(file, "%f %f %f\n", &vert.x, &vert.y, &vert.z);
                mesh.vertsNorm.push_back(vert);
            }
            else if (strcmp(lineHeader, "usemtl") == 0)
            {
                fscanf(file, "%*s\n");
                mesh.mesh_changetexture = vertIndex.size();
            }
            else if (strcmp(lineHeader, "f") == 0)
            {
                std::string v1, v2, v3;
                unsigned int vertInd[3], uvInd[3], normInd[3];
                int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertInd[0], &uvInd[0], &normInd[0],
                                     &vertInd[1], &uvInd[1], &normInd[1], &vertInd[2], &uvInd[2], &normInd[2]);
                if (matches != 9)
                {
                    cout << "QUantidade de valores lidos diferente doesperado. Falha ao ler uma linha de face" << endl;
                    return false;
                }
                // Cria uma lista com os índices na ordem apropriada para o desenho das faces
                // Esta é a lista de índices de vértices
                vertIndex.push_back(vertInd[0]);
                vertIndex.push_back(vertInd[1]);
                vertIndex.push_back(vertInd[2]);
                // Esta é a lista de índices de mapeamento de textura
                uvIndex.push_back(uvInd[0]);
                uvIndex.push_back(uvInd[1]);
                uvIndex.push_back(uvInd[2]);
                // Esta é a lista de índices de normais
                normIndex.push_back(normInd[0]);
                normIndex.push_back(normInd[1]);
                normIndex.push_back(normInd[2]);
            }
        }
        for (unsigned int i = 0; i < vertIndex.size(); i++)
        {
            verticeStrip vert;
            vert.vPos.x = mesh.vertsPos[vertIndex[i] - 1].x;
            vert.vPos.y = mesh.vertsPos[vertIndex[i] - 1].y;
            vert.vPos.z = mesh.vertsPos[vertIndex[i] - 1].z;
            vert.vTex.u = mesh.vertsTex[uvIndex[i] - 1].u;
            vert.vTex.v = mesh.vertsTex[uvIndex[i] - 1].v;
            vert.vNorm.x = mesh.vertsNorm[normIndex[i] - 1].x;
            vert.vNorm.y = mesh.vertsNorm[normIndex[i] - 1].y;
            vert.vNorm.z = mesh.vertsNorm[normIndex[i] - 1].z;
            mesh.vertsS.push_back(vert);
        }
    }
    fclose(file);
    return true;
}
