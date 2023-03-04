
#ifndef OBJECT_PLAYER_H
#define OBJECT_PLAYER_H

#define AMBIENT_MATERIAL 0.2
#define DIFFUSE_MATERIAL 30
#define SPECULAR_MATERIAL 30
#define EMISSION_MATERIAL 0.3

#define WALK_PERCENT 24
#define PUNCH_PERCENT 43

#define WALK_VELOCITY 0.05 // velocidade de movimento linear player 1
#define WALK_ANEMY 0.08    // velocidade de movimento linear player 2

#include "../3D_interface/object_style.h"
#include "../3D_interface/object_material.h"

#include "object_arena.h"

class object_player
{

private:
    // variaveis pertinentes de um jogador (modo.soco,frames)
    bool player_mode{};
    bool player_statepunch{};

    int player_framewalk{};
    int player_framepunch{};

public:
    // iniciação dos jogadores
    object_style player_style; // cor jogador no universo 3D
    GLfloat player_x{};
    GLfloat player_y{};
    GLfloat player_z{};
    GLfloat player_size{};
    GLfloat player_angle{};
    // estado
    int player_state{};

    // placar
    int player_points{};

    void ReadPlayer(object_style &p_style, bool player, GLfloat p_angle, GLfloat p_x, GLfloat p_y, GLfloat p_z); // void ReadPlayer(GLfloat p_x, GLfloat p_y, GLfloat p_theta, GLfloat p_radius, const string &color); no 2d

    // desenho do jogador
    void DrawPlayer(); // mesma função do trabalho 2D
    void DrawStylePlayer();

    // desenho do placar
    void DrawPlayerPoints(GLfloat p_x, GLfloat p_y, GLfloat p_z, object_player &p_One, object_player &p_Two, int camera);
    void DrawPlayerGameOver(GLfloat p_x, GLfloat p_y, GLfloat p_z, object_player &player);
    void DrawDevelopedMensage(GLfloat p_x, GLfloat p_y, GLfloat p_z);

    // desenho do mapa da arena
    void DrawMapPlayer(GLfloat p_x, GLfloat p_y, GLfloat p_z, object_player &p_One, object_player &p_Two, object_arena &arena, GLfloat P_WIDTH, GLfloat P1_HEIGHT);

    // ações do jogador no ringue de luta
    void FixWalk(GLdouble state, object_player &player, object_arena arena); // void FixWalk(GLdouble state, object_player &player, object_arena &arena);  no 2d
    bool FixPunch(object_player &player);
    void FixVelAngular(GLdouble state, object_player &player, object_arena arena); // void FixVelAngular(GLdouble state) no 2d
    void ChangeToWhiteColor(object_player &p, GLfloat &r, GLfloat &g, GLfloat &b);
    void ChangeToNormalColor(object_player &player, string color);

    bool FixStart();
    void FixFrame();
    void FixLight(bool &LightMode, bool &LightSpot, object_player &p_One, object_player &p_Two, object_arena &arena);
    void startPunch();

    // sets auxiliares
    void setPointsPlayer(GLfloat newPoint);
    void setXPlayer(GLfloat newPlayerX);
    void setYPlayer(GLfloat newPlayerY);
    void setZPlayer(GLfloat newPlayerZ);
    void setStatePlayer(GLfloat newPlayerState);
    void setPunchPlayer(bool newPunchState);
    void setFrameWalkPlayer(GLfloat newFrameWalk);
    void setFramePunchPlayer(GLfloat newFramePunch);

    // gets auxiliares
    int getPlayerPoints() const;
    POS getLightPosition(); // const
    POS getLightMark();
    POS getPerspectiveMark();
    POS getPunchPosition();
    POS getPunchMark();
    POS getGripUp();
    POS getEyePosition();
    POS getEyeMark();
    POS getHandPosition();
};

#endif // T3_object_player_H
