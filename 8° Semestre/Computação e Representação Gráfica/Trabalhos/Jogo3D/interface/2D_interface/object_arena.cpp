
#include "object_arena.h"
#include "../2D_tools/tools.h"
#include <iostream>

using namespace std;

// função que irá criar/ler a arena
void object_arena::ReadArena(GLfloat a_x, GLfloat a_y, GLfloat a_z, GLfloat a_height, GLfloat a_width)
{
    // dimensões
    arena_x = a_x;
    arena_y = a_y;
    arena_z = a_z;
    arena_height = a_height;
    arena_width = a_width;

    /* NÃO UTILIZADO (restante da função do trabalho2)
        //setando a cor da arena
        if (strcmp(a_color.c_str(),"blue")==0) {
            arena_R = 0;
            arena_G = 0;
            arena_B = 1;
        } else if(strcmp(a_color.c_str(),"red")==0) {
            arena_R = 1;
            arena_G = 0;
            arena_B = 0;
        } else if (strcmp(a_color.c_str(),"gren")==0)  {
            arena_R = 0;
            arena_G = 1;
            arena_B = 0;
        }*/
}

/*________________________________________________________________________________________________________________________________
|Função:                                           ReadTexture                                                                    |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Adaptação de função passada pelo professor                                                                         |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  bool meshes::loadTexture(string path){                                                                                   |
|        Função do laboratório  "codigo- Animacao de Modelos "linha +-63 do arquivo objloader.cpp"                                |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void object_arena::ReadTexture()
{
    cout << "-------------------------- LOADING --------------------------" << endl
         << endl
         << "- loading object_arena texture..." << endl;

    /* texturas possiveis para a arena-> hexagono-cinza,
                                        azul,
                                        preto,
                                        arco-iris,
                                        hexagono-hd,
                                        marca-stok,
                                        mma,
                                        stars1,
                                        earth,
                                        sun1

    */
    arena_textureBase = Tools::TextureTools("../blender/texture/preto.bmp");
    cout << "   arena_textureBase (1/3)" << endl;
    arena_textureSide = Tools::TextureTools("../blender/texture/preto.bmp");
    cout << "   arena_textureSide (2/3)" << endl;
    arena_textureSky = Tools::TextureTools("../blender/texture/preto.bmp");
    cout << "   arena_textureSky (3/3)" << endl;
    cout << "  object_arena texture ok." << endl
         << endl;
}

/*________________________________________________________________________________________________________________________________
|Função:                                           DrawArena   / DrawBase / DrawSide                                              |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Adaptação de função passada pelo professor                                                                         |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  void DisplaySun e  void DisplayPlane                                                                                     |
|        Função do laboratório  terra sol "linha +-126 do arquivo terrasol.cpp"                                                   |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void object_arena::DrawArena()
{
    glColor3f(arena_color[0], arena_color[1], arena_color[2]);

    glMaterialfv(GL_FRONT, GL_AMBIENT, arena_matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, arena_matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, arena_matSpecular);
    glMaterialfv(GL_FRONT, GL_EMISSION, arena_matEmission);
    glMaterialfv(GL_FRONT, GL_SHININESS, arena_matShininess);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // X
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Y

    glPushMatrix();
    glTranslatef(arena_x, arena_y, arena_z);
    DrawBase(arena_textureBase, {0, 1, 0}, arena_width, arena_height, 100);

    glTranslatef(arena_width / 2, 0, arena_height / 2);
    glDisable(GL_LIGHTING);
    if (arena_side)
    {
        DrawSide(arena_textureSide, arena_width, arena_height, 100);
    }
    DrawSky(arena_textureSky, arena_height * 2);
    glEnable(GL_LIGHTING);

    glPopMatrix();
}

// baseado na função acima
void object_arena::DrawBase(GLuint a_texture, norm a_normal, GLfloat a_width, GLfloat a_height, int calc)
{
    glBindTexture(GL_TEXTURE_2D, a_texture);

    int i, j;
    GLfloat widthS = a_width / (GLfloat)calc;
    GLfloat heightS = a_height / (GLfloat)calc;
    GLfloat textureS = (GLfloat)3 / calc; // Bigger than 1, repeat
    GLfloat tj, t2j;
    GLfloat ti, t2i;
    GLfloat h, h2;
    GLfloat w, w2;
    for (i = 0; i < calc; i++)
    {
        for (j = 0; j < calc; j++)
        {
            glBegin(GL_QUADS);
            tj = (GLfloat)j * textureS;
            ti = (GLfloat)i * textureS;
            h = (GLfloat)i * heightS;
            w = (GLfloat)j * widthS;

            t2i = (GLfloat)(i + 1) * textureS;
            t2j = (GLfloat)(j + 1) * textureS;
            h2 = (GLfloat)(i + 1) * heightS;
            w2 = (GLfloat)(j + 1) * widthS;

            Tools::ntvTools(a_normal.x, a_normal.y, a_normal.z, tj, ti, w, 0, h);
            Tools::ntvTools(a_normal.x, a_normal.y, a_normal.z, tj, t2i, w, 0, h2);
            Tools::ntvTools(a_normal.x, a_normal.y, a_normal.z, t2j, t2i, w2, 0, h2);
            Tools::ntvTools(a_normal.x, a_normal.y, a_normal.z, t2j, ti, w2, 0, h);

            glEnd();
        }
    }
}

// baseado na função acima
void object_arena::DrawSide(GLuint a_texture, GLfloat a_width, GLfloat a_height, int calc)
{
    glPushMatrix();

    GLfloat widthS = a_width / (GLfloat)2;
    GLfloat heightS = a_height / (GLfloat)2;
    GLfloat aux_w = -widthS;
    GLfloat aux_h = -heightS;

    GLfloat p = (GLfloat)1.0;
    GLfloat n = (GLfloat)-1.0;

    GLfloat zero = (GLfloat)0.0;

    GLfloat textureS = 2; // Bigger than 1, repeat

    GLfloat no_mat[] = {100, 100, 100, 100};
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glBindTexture(GL_TEXTURE_2D, a_texture);

    glBegin(GL_QUADS);
    // lado 1/4

    Tools::ntvTools(n, zero, zero, zero, zero, widthS, 0, aux_h);
    Tools::ntvTools(n, zero, zero, textureS, zero, widthS, 0, heightS);
    Tools::ntvTools(n, zero, zero, textureS, p, widthS, 70, heightS);
    Tools::ntvTools(n, zero, zero, zero, p, widthS, 70, aux_h);

    // lado 2/4
    Tools::ntvTools(p, zero, zero, zero, zero, aux_w, 0, aux_h);
    Tools::ntvTools(p, zero, zero, textureS, zero, aux_w, 0, heightS);
    Tools::ntvTools(p, zero, zero, textureS, p, aux_w, 70, heightS);
    Tools::ntvTools(p, zero, zero, zero, p, aux_w, 70, aux_h);

    // lado 3/4
    Tools::ntvTools(zero, zero, n, zero, zero, aux_w, 0, heightS);
    Tools::ntvTools(zero, zero, n, textureS, zero, widthS, 0, heightS);
    Tools::ntvTools(zero, zero, n, textureS, p, widthS, 70, heightS);
    Tools::ntvTools(zero, zero, n, zero, p, aux_w, 70, heightS);

    // lado 4/4
    Tools::ntvTools(zero, zero, p, zero, zero, aux_w, 0, aux_h);
    Tools::ntvTools(zero, zero, p, textureS, zero, widthS, 0, aux_h);
    Tools::ntvTools(zero, zero, p, textureS, p, widthS, 70, aux_h);
    Tools::ntvTools(zero, zero, p, zero, p, aux_w, 70, aux_h);

    glEnd();

    glPopMatrix();
}

// void DisplayPlane (GLuint texture) - terrasol
void object_arena::DrawSky(GLuint a_texture, GLfloat a_size)
{
    glBindTexture(GL_TEXTURE_2D, a_texture);

    glPushMatrix();

    GLfloat aux_s = -a_size;
    GLfloat p = (GLfloat)1.0;
    GLfloat n = (GLfloat)-1.0;
    GLfloat zero = (GLfloat)0.0;
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            glRotatef(90, 1, 0, 0);
        }
        else if (i == 2)
        {
            glRotatef(90, 0, 0, 1);
        }
        glBegin(GL_QUADS);

        // lado 1/2
        Tools::ntvTools(zero, p, zero, zero, zero, aux_s, aux_s, aux_s);
        Tools::ntvTools(zero, p, zero, zero, p, aux_s, aux_s, a_size);
        Tools::ntvTools(zero, p, zero, p, p, a_size, aux_s, a_size);
        Tools::ntvTools(zero, p, zero, p, zero, a_size, aux_s, aux_s);

        // lado 2/2
        Tools::ntvTools(zero, n, zero, zero, zero, aux_s, a_size, aux_s);
        Tools::ntvTools(zero, n, zero, zero, p, aux_s, a_size, a_size);
        Tools::ntvTools(zero, n, zero, p, p, a_size, a_size, a_size);
        Tools::ntvTools(zero, n, zero, p, zero, a_size, a_size, aux_s);

        glEnd();
    }

    glPopMatrix();
}
