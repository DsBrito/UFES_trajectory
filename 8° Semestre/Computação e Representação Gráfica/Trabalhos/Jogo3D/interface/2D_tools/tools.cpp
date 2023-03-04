

#include "tools.h"
#include "../3D_tools/imageloader.h"
#include "../3D_interface/object_style.h"
#include "../3D_interface/object_material.h"

// Fonte: https://matika.com.br/radianos/formula-para-converter-graus-para-radianos
double Tools::DegressToRadiansTools(GLfloat degress)
{
    return degress * (M_PI / 180);
}
// Fonte: https://matika.com.br/radianos/conversao-de-radianos-para-graus
double Tools::RadiansToDegressTools(GLfloat radians)
{
    return radians * (180 / M_PI);
}

double Tools::DistanceTools(GLfloat _xTools, GLfloat _yTools, GLfloat x_Tools, GLfloat y_Tools)
{
    return sqrt(pow(_xTools - x_Tools, 2) + pow(_yTools - y_Tools, 2));
}

void Tools::TranslateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat _tTollsX, GLfloat _tTollsY, GLfloat _tTollsZ)
{ // 3D
    _xTools += _tTollsX;
    _yTools += _tTollsY;
    _zTools += _tTollsZ;
}

void Tools::RotateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat _rTollsX, GLfloat _rTollsY, GLfloat _rTollsZ, GLfloat degress)
{
    double radians = DegressToRadiansTools(degress);
    double cosseno = cos(radians);
    double seno = sin(radians);

    GLfloat timeX = _xTools;
    GLfloat X_1 = timeX * 1;
    GLfloat X_0 = timeX * 0;
    GLfloat X_COSSENO = timeX * cosseno;
    GLfloat X_SENO = timeX * seno;

    GLfloat timeY = _yTools;
    GLfloat Y_1 = timeY * 1;
    GLfloat Y_0 = timeY * 0;
    GLfloat Y_COSSENO = timeY * 0;
    GLfloat Y_SENO = timeY * 0;

    GLfloat timeZ = _zTools;
    GLfloat Z_1 = timeZ * 1;
    GLfloat Z_0 = timeZ * 0;
    GLfloat Z_COSSENO = timeZ * cosseno;
    GLfloat Z_SENO = timeZ * seno;

    // rotação em x
    if (_rTollsX == 1 && _rTollsY == 0 && _rTollsZ == 0)
    {
        _xTools = X_1 + Y_0 + Z_0;
        _yTools = X_0 + Y_COSSENO - Z_SENO;
        _zTools = X_0 + Y_SENO + Z_COSSENO;
    }
    // rotação em y
    else if (_rTollsX == 0 && _rTollsY == 1 && _rTollsZ == 0)
    {
        _xTools = X_COSSENO + Y_0 + Z_SENO;
        _yTools = X_0 + Y_1 + Z_0;
        _zTools = -X_SENO + Y_0 + Z_COSSENO;
    }
    // rotação em z
    else if (_rTollsX == 0 && _rTollsY == 0 && _rTollsZ == 1)
    {
        _xTools = X_COSSENO - Y_SENO + Z_0;
        _yTools = X_SENO + Y_COSSENO + Z_0;
        _zTools = X_0 + Y_0 + Z_1;
    }

    // nenhuma rotação
    else
    {
        perror("NO ROTATE\n");
        exit(EXIT_FAILURE);
    }
}

void Tools::ScaleTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat _sTollsX, GLfloat _sTollsY, GLfloat _sTollsZ)
{
    _xTools *= _sTollsX;
    _yTools *= _sTollsY;
    _zTools *= _sTollsZ;
}

void Tools::LightTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat &MarkX, GLfloat &MarkY, GLfloat &MarkZ, GLfloat &angle)
{
    GLfloat p = (GLfloat)1.0;
    GLfloat n = (GLfloat)-1.0;
    GLfloat zero = (GLfloat)0.0;
    GLfloat scale = 50.0;

    ScaleTools(MarkX, MarkY, MarkZ, scale, scale, scale);
    RotateTools(MarkX, MarkY, MarkZ, zero, p, zero, angle);
    TranslateTools(MarkX, MarkY, MarkZ, _xTools, _yTools, _zTools);
}

/*________________________________________________________________________________________________________________________________
|Função:                                           TextureTools                                                                    |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Adaptação de função passada pelo professor                                                                         |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  bool meshes::loadTexture(string path){                                                                                   |
|        Função do laboratório  "codigo- Animacao de Modelos "linha +-63 do arquivo objloader.cpp"                                |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
GLuint Tools::TextureTools(const char *filename)
{
    GLuint texture;

    Image *image = Image::loadBMP(filename);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,               // Always GL_TEXTURE_2D
                 0,                           // 0 for now
                 GL_RGB,                      // Format OpenGL uses for image
                 image->width, image->height, // Width and height
                 0,                           // The border of the image
                 GL_RGB,                      // GL_RGB, because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE,            // GL_UNSIGNED_BYTE, because pixels are stored
                 // as unsigned numbers
                 image->pixels); // The actual pixel data
    delete image;

    return texture;
}

// Função auxiliar
void Tools::ntvTools(GLfloat &n_X, GLfloat &n_Y, GLfloat &n_Z, GLfloat &t_One, GLfloat &t_Two, GLfloat &v_One, int num, GLfloat &v_Two)
{

    glNormal3f(n_X, n_Y, n_Z);
    glTexCoord2f(t_One, t_Two);
    glVertex3f(v_One, num, v_Two);
}

// Função auxiliar que faz  Translate e Rotate
void Tools::trsTools(GLfloat &t_X, GLfloat &t_Y, GLfloat &t_Z, GLfloat &r_Angle, GLfloat &r_X, GLfloat &r_Y, GLfloat &r_Z, GLfloat &s_tam)
{

    glTranslatef(t_X, t_Y, t_Z);
    glRotatef(r_Angle, r_X, r_Y, r_Z);
    glScalef(s_tam, s_tam, s_tam);
}

void Tools::LightHead2Tools(GLfloat light1_0, GLfloat light1_1, GLfloat light1_2, GLfloat light2_0, GLfloat light2_1, GLfloat light2_2)
{
    glDisable(GL_LIGHTING);
    glPointSize(15);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex3f(light1_0, light1_1, light1_2);
    glVertex3f(light2_0, light2_1, light2_2);
    glEnd();
    glEnable(GL_LIGHTING);
}

void Tools::LightHeadTools(GLfloat light0, GLfloat light1, GLfloat light2)
{
    glDisable(GL_LIGHTING);
    glPointSize(15);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex3f(light0, light1, light2);
    glEnd();
    glEnable(GL_LIGHTING);
}

void Tools::Light0Tools(GLfloat *l_position0, GLfloat *l_ambiente, GLfloat *l_diffuse, GLfloat *l_specular)
{
    GLfloat l_cut[] = {180};
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, l_position0);
    glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, l_cut);
    glLightfv(GL_LIGHT0, GL_AMBIENT, l_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, l_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, l_specular);
}
void Tools::Light1Tools(GLfloat *l_position1, GLfloat *l_mark1, GLfloat *l_ambiente, GLfloat *l_diffuse, GLfloat *l_specular)
{
    GLfloat l_cut[] = {35};

    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, l_position1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l_mark1);
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, l_cut);
    glLightfv(GL_LIGHT1, GL_AMBIENT, l_ambiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, l_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, l_specular);
}
void Tools::Light2Tools(GLfloat *l_position2, GLfloat *l_mark2, GLfloat *l_ambiente, GLfloat *l_diffuse, GLfloat *l_specular)
{
    GLfloat l_cut[] = {35};
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_POSITION, l_position2);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_mark2);
    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, l_cut);
    glLightfv(GL_LIGHT2, GL_AMBIENT, l_ambiente);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, l_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, l_specular);
}