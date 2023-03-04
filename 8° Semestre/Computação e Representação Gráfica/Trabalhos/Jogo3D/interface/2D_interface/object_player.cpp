
#include "object_player.h"

#include "../2D_tools/tools.h"

// iniciação dos jogadores
void object_player::ReadPlayer(object_style &p_style, bool player, GLfloat p_angle, GLfloat p_x, GLfloat p_y, GLfloat p_z)
{
    // cor do jogador
    player_style = p_style;

    // coordenadas x,y,z tamanho e angulo
    player_x = p_x;
    player_y = p_y;
    player_z = p_z;
    player_size = 0.366 * 50.0;
    player_angle = p_angle;

    // modo do jogador true/false = player 1/2
    player_mode = player;

    // status de soco true/false on/off
    player_statepunch = false;

    // variaveis de controle de estado/socar/caminhar/pontuação
    player_state = 0;
    player_framepunch = 0;
    player_framewalk = 0;
    player_points = 0;

    // se for o jogador 1 irá receber a cor verde
    if (player_mode)
    {
        player_style.mat.material_ambient[1] = AMBIENT_MATERIAL;
        player_style.mat.material_diffuse[1] = DIFFUSE_MATERIAL;
        player_style.mat.material_specular[1] = SPECULAR_MATERIAL;
        player_style.mat.material_emission[1] = EMISSION_MATERIAL;
    }

    // se for jogador 2, irá receber a cor vermelha
    else
    {
        player_style.mat.material_ambient[0] = AMBIENT_MATERIAL;
        player_style.mat.material_diffuse[0] = DIFFUSE_MATERIAL;
        player_style.mat.material_specular[0] = SPECULAR_MATERIAL;
        player_style.mat.material_emission[0] = EMISSION_MATERIAL;
    }
}

// desenho dos jogadores
/*________________________________________________________________________________________________________________________________
|Função:                                           DrawStylePlayer   / DrawPlayer                                                 |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Adaptação de função passada pelo professor                                                                         |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  void desenhaJogador()                                                                                                    |
|        Função do laboratório  do soldado "linha +-144 do arquivo soldado.cpp"                                                   |
|________________________________________________________________________________________________________________________________*/
// seleção de mesh a ser desenhada
void object_player::DrawStylePlayer()
{
    // ficar parado em estado idle
    if (player_state == 0)
    {
        player_style.DrawStyle(player_style.mesh_stop);
    }

    // desenhar um passo
    else if (player_state == 1)
    {
        player_style.DrawStyle(player_style.mesh_walk[player_framewalk]);
    }

    // desenha o estado de passo de forma a criar uma situação de movimento com as pernas (em movimento)
    else if (player_state == 2)
    {
        player_style.DrawStyle(player_style.mesh_forwalk[player_framewalk]);
    }

    // desenha o estado de boxing de forma a criar uma situação de movimento com os punhos (parado)
    else if (player_state == 3)
    {
        player_style.DrawStyle(player_style.mesh_punch[player_framepunch]);
    }
}
// mesma função  do tabalho 2D adaptada para o 3d
void object_player::DrawPlayer()
{

    glPushMatrix();

    GLfloat p = (GLfloat)1.0;
    GLfloat zero = (GLfloat)0;
    GLfloat tam = 50.0;

    Tools::trsTools(player_x, player_y, player_z, player_angle, zero, p, zero, tam);

    DrawStylePlayer();
    glPopMatrix();
}

/*_________________s_______________________________________________________________________________________________________________
|Função:                                  Escrita em Tela                                                                         |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:    As Funções DrawDevelopedMensage, DrawPlayerPoints e DrawPlayerGameOver seguem a mesma lógica                     |
|                da função presente no lab3                                                                                       |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  ImprimePlacar(GLfloat x, GLfloat y)                                                                                      |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo main.cpp -> linha 39...)                                                                             |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/

void object_player::DrawPlayerPoints(GLfloat p_x, GLfloat p_y, GLfloat p_z, object_player &p_One, object_player &p_Two, int camera)
{
    // 3D
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    // 2D
    // glMatrixMode(GL_PROJECTION);
    // glPushMatrix();
    // glLoadIdentity();
    static char string[1000];
    void *latterFont = GLUT_BITMAP_TIMES_ROMAN_24; // fonte

    // Draw text in the x, y, z position
    glColor3f(1, 1, 1); // rgb = - - -
    // Cria a string a ser impressa
    char *pString;
    sprintf(string, "Camera: %d  ->    PlayerTwo: %d     x     PlayerOne: %d     ", camera, p_Two.getPlayerPoints(), p_One.getPlayerPoints());
    // Define a posicao onde vai comecar a imprimir

    glRasterPos3f(p_x, p_y, p_z);

    pString = string;
    while (*pString)
    {
        glutBitmapCharacter(latterFont, *pString);
        pString++;
    }
    // 3D
    glPopAttrib();

    // 2D
    // glMatrixMode(GL_PROJECTION);
    // glPopMatrix();
    // glMatrixMode(GL_MODELVIEW);
    // glPopMatrix();
}

void object_player::DrawDevelopedMensage(GLfloat p_x, GLfloat p_y, GLfloat p_z)
{
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    static char string[1000];
    void *latterFont = GLUT_BITMAP_9_BY_15;
    glColor3f(1, 1, 1);
    // Cria a string a ser impressa
    char *pString;
    sprintf(string, "[CG] 3D Boxing Game - 2022/2 - Developed by Dionatas Santos Brito");
    // Define a posicao onde vai comecar a imprimir
    // glRasterPos3f((p_x / 10 - 5), (p_y / 10), (p_z / 10));
    glRasterPos3f(p_x, p_y, p_z);

    // Imprime um caractere por vez
    pString = string;
    while (*pString)
    {
        glutBitmapCharacter(latterFont, *pString);
        pString++;
    }

    // 3d
    glPopAttrib();

    // 2d
    //  glMatrixMode(GL_PROJECTION);
    //  glPopMatrix();

    //  glMatrixMode(GL_MODELVIEW);
    // glPopMatrix();
}

void object_player::DrawPlayerGameOver(GLfloat p_x, GLfloat p_y, GLfloat p_z, object_player &player)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);

    // glPushAttrib(GL_ENABLE_BIT);
    // glDisable(GL_LIGHTING);
    // glDisable(GL_TEXTURE_2D);
    static char string[1000];
    void *latterFont = GLUT_BITMAP_TIMES_ROMAN_24;

    glColor3f(1, 1, 1);
    // Cria a string a ser impressa
    char *pString;
    if (player.getPlayerPoints() >= 10)
    {
        sprintf(string, "YOU WIN");
        // DrawPlayer();

        // DrawDevelopedMensage(0.45, 0.5, 0);
    }
    else
    {
        sprintf(string, "YOU LOSE ");
        //  DrawPlayer();

        //  DrawDevelopedMensage(0.45, 0.5, 0);
    }
    // Define a posicao onde vai comecar a imprimir
    glRasterPos3f(p_x, p_y, p_z);
    // Imprime um caractere por vez
    pString = string;
    while (*pString)
    {
        glutBitmapCharacter(latterFont, *pString);
        pString++;
    }
    // DrawDevelopedMensage(p_x - 100, p_y, p_z);
    DrawDevelopedMensage(0.05, 0.1, 0);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

/*_________________s_______________________________________________________________________________________________________________
|Função:                                  DrawMapPlayer                                                                           |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  https://stackoverflow.com/questions/35004947/opengl-draw-on-top-of-tile-map-c                                            |
|        https://stackoverflow.com/questions/15982683/mipmapping-in-opengl?rq=1                                                   |
|        https://www.gamedev.net/forums/topic/637183-how-to-create-minimap-sdlopengl/                                             |
| ________________________________________________________________________________________________________________________________|*/

void object_player::DrawMapPlayer(GLfloat p_x, GLfloat p_y, GLfloat p_z, object_player &p_One, object_player &p_Two, object_arena &arena, GLfloat P_WIDTH, GLfloat P1_HEIGHT)
{
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);   // sem luz
    glDisable(GL_TEXTURE_2D); // sem textura
    glColor3f(1, 1, 1);

    GLfloat tam = 0.249;
    int nseg = 15;
    float r = 0.02;
    float angle = 2.0f * 3.1415926f;
    float theta;
    float xp;
    float yp;

    float rp = r * P_WIDTH;

    // calculando o tamanho do minimapa
    GLfloat sizeMapx = tam * P_WIDTH;   // posição x do jogador
    GLfloat sizeMapy = tam * P1_HEIGHT; // posição y do jogador

    // calculando a coordenada x1,y1 e x2,y2 do minimapa de cada jogador
    GLfloat mapXp1 = ((p_One.player_x - arena.arena_x) / arena.arena_width) * P_WIDTH;
    GLfloat mapXp2 = ((p_Two.player_x - arena.arena_x) / arena.arena_width) * P_WIDTH;

    GLfloat mapYp1 = ((p_One.player_z - arena.arena_z) / arena.arena_height) * P1_HEIGHT;
    GLfloat mapYp2 = ((p_Two.player_z - arena.arena_z) / arena.arena_height) * P1_HEIGHT;

    // dividindo a coordenada encontrada por /4 (para ocupar 1/4 da região)
    mapXp1 = (mapXp1 / 4) + p_x;
    mapYp1 = (mapYp1 / 4) + p_y;
    mapXp2 = (mapXp2 / 4) + p_x;
    mapYp2 = (mapYp2 / 4) + p_y;

    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex3f(p_x, p_y, p_z);
    glVertex3f(p_x + sizeMapx, p_y, p_z);
    glVertex3f(p_x + sizeMapx, p_y + sizeMapy, p_z);
    glVertex3f(p_x, p_y + sizeMapy, p_z);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);

    // aqui deve ser calculado a componente x e y do angulo corrente para (x1,y1)
    for (int i = 0; i < nseg; i++)
    {
        theta = angle * float(i) / float(nseg);

        xp = rp * cosf(theta);
        yp = rp * sinf(theta);

        glVertex2f(xp + mapXp1, yp + mapYp1);
    }
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);

    // aqui deve ser calculado a componente x e y do angulo corrente para (x2,y2)
    for (int i = 0; i < nseg; i++)
    {
        theta = angle * float(i) / float(nseg);

        xp = rp * cosf(theta);
        yp = rp * sinf(theta);

        glVertex2f(xp + mapXp2, yp + mapYp2);
    }
    glEnd();

    glPopAttrib();
}

// ações do jogador no ringue de luta
// controle de estado on/off do jogador
bool object_player::FixStart()
{
    if (player_framepunch == 0)
    {
        setStatePlayer(0);
        return true;
    }

    return false;
}

// controle de estado on/off do jogador para o start do jogador (no state = 3 asciona o modo de socar)
void object_player::startPunch()
{
    setPunchPlayer(false);
    setStatePlayer(3);
}
// mesma ideia do trabalho 2D
//  quando o state > 0 deve andar na mesma direção em busca da colisão
//  quando o state é < 0 deve andar na posição oposta em busca da colisão
void object_player::FixWalk(GLdouble state, object_player &player, object_arena arena)
{

    double tam = 2 * player_size;

    GLfloat pX = player.player_x;
    // GLfloat pY = player.player_y;
    GLfloat pZ = player.player_z;
    // em x
    GLfloat incX = state * WALK_ANEMY * sin(Tools::DegressToRadiansTools(player_angle));
    double playerDistanceX = Tools::DistanceTools(player_x + incX, player_z, pX, pZ);
    double playerIncX = player_x + incX;
    double playerSizeX = playerIncX + player_size;
    double arenaSizeX = arena.arena_x + player_size;
    double arenaWithX = arena.arena_x + arena.arena_width;

    // em z
    GLfloat incZ = state * WALK_ANEMY * cos(Tools::DegressToRadiansTools(player_angle));
    double playerDistanceZ = Tools::DistanceTools(player_x, player_z + incZ, pX, pZ);
    double playerIncZ = player_z + incZ;
    double playerSizeZ = playerIncZ + player_size;
    double arenaSizeZ = arena.arena_z + player_size;
    double arenaHeightZ = arena.arena_z + arena.arena_height;

    // tendo a posição X do jogador  menor que a da erena, deve incrementar em x
    if ((playerDistanceX > tam) && (playerSizeX < arenaWithX) && (playerIncX > arenaSizeX))
    {
        setXPlayer((player_x + incX));
    }

    // tendo a posição Z do jogador  menor que a da erena, deve incrementar em z
    if ((playerDistanceZ > tam) && (playerSizeZ < arenaHeightZ) && (playerIncZ > arenaSizeZ))
    {

        setZPlayer((player_z + incZ));
    }

    if (state < 0)
    {
        setStatePlayer(2);
    }
    else
    {
        setStatePlayer(1);
    }
}

/*_________________s_______________________________________________________________________________________________________________
|Função:                                  FixLight                                                                                |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:    Função que desenha o ponto de luz na direção X sob a cabeça dos jogadores                                        |
|                da função presente no lab4                                                                                       |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Baseado em uma fração da função do Display() do laboratório do soldado                                                   |
|        onde é definido e desenhado a fonte de luz +- linha 197 - 237 do arquivo "soldado.cpp"                                   |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void object_player::FixLight(bool &LightMode, bool &LightSpot, object_player &p_One, object_player &p_Two, object_arena &arena)
{
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    GLfloat lightAmbient[] = {0, 0, 0, 1};
    GLfloat lightDiffuse[] = {80, 80, 80, 80};
    GLfloat lightSpecular[] = {80, 80, 80, 80};

    if (LightMode)
    {

        // para o jogador um
        pos position1 = p_One.getLightPosition();
        pos mark1 = p_One.getLightMark();
        GLfloat lightPosition1[] = {position1.x, position1.y, position1.z, 1};
        GLfloat lightMark1[] = {mark1.x - position1.x, mark1.y - position1.y, mark1.z - position1.z};
        Tools::Light1Tools(lightPosition1, lightMark1, lightAmbient, lightDiffuse, lightSpecular);

        //  para o jogador dois
        pos position2 = p_Two.getLightPosition();
        pos mark2 = p_Two.getLightMark();
        GLfloat lightPosition2[] = {position2.x, position2.y, position2.z, 1};
        GLfloat lightMark2[] = {mark2.x - position2.x, mark2.y - position2.y, mark2.z - position2.z};
        Tools::Light2Tools(lightPosition2, lightMark2, lightAmbient, lightDiffuse, lightSpecular);

        // desenhando o icone da luz sob a cabeça do jogador on/off
        if (LightSpot)
        {
            Tools::LightHead2Tools(lightPosition1[0], lightPosition1[1], lightPosition1[2], lightPosition2[0], lightPosition2[1], lightPosition2[2]);
        }
    }
    else
    {
        // iluminação normal da arena
        GLfloat lightPosition0[] = {arena.arena_x + (arena.arena_width / 2), 2 * 120, arena.arena_z + (arena.arena_height / 2), 1};

        Tools::Light0Tools(lightPosition0, lightAmbient, lightDiffuse, lightSpecular);

        // desenhando o icone da luz sob a cabeça do jogador on/off
        if (LightSpot)
        {
            Tools::LightHeadTools(lightPosition0[0], lightPosition0[1], lightPosition0[2]);
        }
    }
}

/*________________________________________________________________________________________________________________________________
|Função:                                  Auxiliar de Rotação                                                                     |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:    Funcão retirada do lab3  adaptada para o 3d com o FixWalk dependendo do estado                                   |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut)                                           |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo robo.cpp -> linha 126...)                                                                            |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/

void object_player::FixVelAngular(GLdouble state, object_player &player, object_arena arena)
{
    // se o state é positivo e maior que zero, deve andar positivamente/na mesma direção
    if (state > 0)
        FixWalk(state * 0.1, player, arena);

    // se o state é negativo, deve andar negativamente/na direção oposta
    FixWalk(-state * 0.1, player, arena);

    player_angle += state * 0.05; // velocidade angular atual: 0.05
}

/*________________________________________________________________________________________________________________________________
|Função:                                  FixFrame                                                                                |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:    Frames a serem desenhados na tela de acordo com o state que ele pertence                                         |
|                   state 0 = estado idle parado                                                                                  |
|                   state 1 ou 2  = estado de caminhar                                                                            |
|                   state 3 = estado de socar                                                                                     |
| ________________________________________________________________________________________________________________________________|*/
void object_player::FixFrame()
{
    if (player_state == 0)
    {
        setFrameWalkPlayer(0);
        setFramePunchPlayer(0);
    }
    else if (player_state == 1 || player_state == 2)
    {
        setFrameWalkPlayer((player_framewalk + 1));
        setFrameWalkPlayer((player_framewalk % WALK_PERCENT));
    }
    else if (player_state == 3)
    {
        setFramePunchPlayer((player_framepunch + 1));
        setFramePunchPlayer((player_framepunch % PUNCH_PERCENT));
    }
}

/*________________________________________________________________________________________________________________________________
|Função:                                  FixPunch                                                                                |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:    Semelhante a FixPunch do trabalho 2D, ,entretanto, ao invés do mouse para socar, irá ser usado o teclado         |
|                Quando entrar na distancia de contato com o adversário irá adicionar um ponto no placar do jogador que           |
|                esta realizando a ação                                                                                           |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Baseado na função FixPunch do Trabalho 2                                                                                 |
|        Função do laboratório do Robô (lab3)                                                                                     |
| ________________________________________________________________________________________________________________________________|*/
bool object_player::FixPunch(object_player &player)
{
    // pega a posição da mão
    pos hand = getHandPosition();

    // calculando as distancias -> mãos, jogadores, entre as mãos e jogadores
    GLfloat hand_distance = Tools::DistanceTools(hand.x, hand.z, player.player_x, player.player_z);
    GLfloat player_distance = Tools::DistanceTools(player_x, player_z, player.player_x, player.player_z);
    GLfloat player_handDistance = Tools::DistanceTools(player_x, player_z, hand.x, hand.z);
    if (hand_distance < player_size)
    {
        if (!player_statepunch)
        {
            setPointsPlayer((player_points + 1));
            setPunchPlayer(true);
            return 1;
        }
        if (player_distance < player_handDistance)
        {
            player.player_x = hand.x;
            player.player_z = hand.z;
        }
    }
    return 0;
}

// função para auxiliar na arena de luta, quando a mão de um lutador estiver realizando a ação de socar, o oponente irá ficar na cor branca
void object_player::ChangeToWhiteColor(object_player &p, GLfloat &r, GLfloat &g, GLfloat &b)
{

    p.player_style.mat.material_ambient[0] = 0;
    p.player_style.mat.material_diffuse[0] = 0;
    p.player_style.mat.material_specular[0] = 0;
    p.player_style.mat.material_emission[0] = 0;

    p.player_style.mat.material_ambient[1] = 0;
    p.player_style.mat.material_diffuse[1] = 0;
    p.player_style.mat.material_specular[1] = 0;
    p.player_style.mat.material_emission[1] = 0;
}

// função para auxiliar na arena de luta, quando o lutador não estiver sofrendo dano, ele irá possuir a cor normal (a cor lida anteriormente na função parseXML )
void object_player::ChangeToNormalColor(object_player &p, string color)
{
    const char *ch_prt = color.c_str();

    if (strcmp(color.c_str(), "red") == 0)

    {
        // printf("ch_prt vermelho = %s\n", ch_prt);

        p.player_style.mat.material_ambient[0] = AMBIENT_MATERIAL;
        p.player_style.mat.material_diffuse[0] = DIFFUSE_MATERIAL;
        p.player_style.mat.material_specular[0] = SPECULAR_MATERIAL;
        p.player_style.mat.material_emission[0] = EMISSION_MATERIAL;
    }
    if (strcmp(color.c_str(), "green") == 0)

    {
        // printf("ch_prt green = %s\n", ch_prt);

        p.player_style.mat.material_ambient[1] = AMBIENT_MATERIAL;
        p.player_style.mat.material_diffuse[1] = DIFFUSE_MATERIAL;
        p.player_style.mat.material_specular[1] = SPECULAR_MATERIAL;
        p.player_style.mat.material_emission[1] = EMISSION_MATERIAL;
    }
}

// gets auxiliares
int object_player::getPlayerPoints() const
{
    return player_points;
}

// função GETS do tipo  POS

// gets de luz
POS object_player::getLightPosition()
{
    // posição das luzes = (0,0,2.8)

    GLfloat objx = 0;
    GLfloat objz = 0;
    GLfloat objy = 2.8;

    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos light = {objx, objy, objz};
    return light;
}
POS object_player::getLightMark()
{ // posição das luzes = (0,0,0)

    GLfloat objx = 0;
    GLfloat objy = 0;
    GLfloat objz = 0;
    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos light = {objx, objy, objz};
    return light;
}

// get de eyes - Auxilia no modo de camera dos olhos
POS object_player::getEyePosition()
{
    // posição dos olhos = (996,996,996)

    GLfloat objx = player_style.mesh_stop.vertsPos[996].x;
    GLfloat objy = player_style.mesh_stop.vertsPos[996].y;
    GLfloat objz = player_style.mesh_stop.vertsPos[996].z;

    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos eye = {objx, objy, objz};
    return eye;
}
POS object_player::getEyeMark()
{
    // posição dos olhos = (996,996,996)
    GLfloat objx = player_style.mesh_stop.vertsPos[996].x;
    GLfloat objy = player_style.mesh_stop.vertsPos[996].y;
    GLfloat objz = player_style.mesh_stop.vertsPos[996].z + 0.2;

    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos eye = {objx, objy, objz};
    return eye;
}

// gets de perspectiva
POS object_player::getPerspectiveMark()
{
    // posição perspectiva = 010

    GLfloat objx = 0;
    GLfloat objy = 1;
    GLfloat objz = 0;
    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos perspective = {objx, objy, objz};
    return perspective;
}

// get de punch - Auxilia no modo de camera dos punhos
POS object_player::getPunchPosition()
{ // VERTEX PICKING - T FOR TRACE
  // posição dos braços = (20998,20998,20998)

    GLfloat objx = player_style.mesh_punch[player_framepunch].vertsPos[20998].x;
    GLfloat objy = player_style.mesh_punch[player_framepunch].vertsPos[20998].y;
    GLfloat objz = player_style.mesh_punch[player_framepunch].vertsPos[20998].z;

    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos punch = {objx, objy, objz};
    return punch;
}
POS object_player::getPunchMark()
{
    // posição dos braços = (20998,20998,20998)

    GLfloat objx = player_style.mesh_punch[player_framepunch].vertsPos[20998].x;
    GLfloat objy = player_style.mesh_punch[player_framepunch].vertsPos[20998].y;
    GLfloat objz = player_style.mesh_punch[player_framepunch].vertsPos[20998].z + 0.2;

    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos punch = {objx, objy, objz};
    return punch;
}

// get de grip - Auxilia no modo de camera dos braços
POS object_player::getGripUp()
{
    // posição dos braços = (20998,20998,20998)

    GLfloat objx = player_style.mesh_punch[player_framepunch].vertsNorm[20998].x;
    GLfloat objy = player_style.mesh_punch[player_framepunch].vertsNorm[20998].y;
    GLfloat objz = player_style.mesh_punch[player_framepunch].vertsNorm[20998].z;

    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos up = {0, 1, 0};
    return up;
}

POS object_player::getHandPosition()
{
    // posição das mãos  = (22074,22074,22074)
    GLfloat objx = player_style.mesh_punch[player_framepunch].vertsPos[22074].x;
    GLfloat objy = player_style.mesh_punch[player_framepunch].vertsPos[22074].y;
    GLfloat objz = player_style.mesh_punch[player_framepunch].vertsPos[22074].z;

    Tools::LightTools(player_x, player_y, player_z, objx, objy, objz, player_angle);

    pos hand = {objx, objy, objz};
    return hand;
}

// sets auxiliares
void object_player::setStatePlayer(GLfloat newPlayerState)
{
    player_state = newPlayerState;
};

void object_player::setPunchPlayer(bool newPunchState)
{
    player_statepunch = newPunchState;
}

void object_player::setFrameWalkPlayer(GLfloat newFrameWalk)
{
    player_framewalk = newFrameWalk;
}
void object_player::setFramePunchPlayer(GLfloat newFramePunch)
{
    player_framepunch = newFramePunch;
}

void object_player::setPointsPlayer(GLfloat newPoint)
{
    player_points = newPoint;
}
void object_player::setXPlayer(GLfloat newPlayerX)
{
    player_x = newPlayerX;
}
void object_player::setYPlayer(GLfloat newPlayerY)
{
    player_y = newPlayerY;
}
void object_player::setZPlayer(GLfloat newPlayerZ)
{
    player_z = newPlayerZ;
}
