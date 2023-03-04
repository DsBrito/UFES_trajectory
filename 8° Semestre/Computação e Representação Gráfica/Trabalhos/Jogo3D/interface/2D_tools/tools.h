

#ifndef TOOLS_H
#define TOOLS_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

class Tools
{
public:
    // funções de ferramentas auxiliares
    static GLuint TextureTools(const char *filename);

    static double DegressToRadiansTools(GLfloat degress);
    static double RadiansToDegressTools(GLfloat radians);
    static void trsTools(GLfloat &t_X, GLfloat &t_Y, GLfloat &t_Z, GLfloat &r_Angle, GLfloat &r_X, GLfloat &r_Y, GLfloat &r_Z, GLfloat &s_tam);
    static void LightTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat &MarkX, GLfloat &MarkY, GLfloat &MarkZ, GLfloat &angle);
    static void ntvTools(GLfloat &n_X, GLfloat &n_Y, GLfloat &n_Z, GLfloat &t_One, GLfloat &t_Two, GLfloat &v_One, int num, GLfloat &v_Two);
    static double DistanceTools(GLfloat _xTools, GLfloat _yTools, GLfloat x_Tools, GLfloat y_Tools);
    //    static double MagnitudeTools(GLfloat _xTools, GLfloat x_Tools);

    //  static void TranslateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat _tTollsX, GLfloat _tTollsY); //2D
    static void TranslateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat _tTollsX, GLfloat _tTollsY, GLfloat _tTollsZ); // 3D

    //  static void RotateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat degress);//2D
    static void RotateTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat _rTollsX, GLfloat _rTollsY, GLfloat _rTollsZ, GLfloat degress);

    static void ScaleTools(GLfloat &_xTools, GLfloat &_yTools, GLfloat &_zTools, GLfloat _sTollsX, GLfloat _sTollsY, GLfloat _sTollsZ);

    static void LightHeadTools(GLfloat light0, GLfloat light1, GLfloat light2);
    static void LightHead2Tools(GLfloat light1_0, GLfloat light1_1, GLfloat light1_2, GLfloat light2_0, GLfloat light2_1, GLfloat light2_2);

    // as 3 fontes de luz ( 0 = arena, 1 e 2 = jogadores)
    static void Light0Tools(GLfloat *l_position0, GLfloat *l_ambiente, GLfloat *l_diffuse, GLfloat *l_specular);
    static void Light1Tools(GLfloat *l_position1, GLfloat *l_mark1, GLfloat *l_ambiente, GLfloat *l_diffuse, GLfloat *l_specular);
    static void Light2Tools(GLfloat *l_position2, GLfloat *l_mark2, GLfloat *l_ambiente, GLfloat *l_diffuse, GLfloat *l_specular);
};

#endif //  TOOLS_H
