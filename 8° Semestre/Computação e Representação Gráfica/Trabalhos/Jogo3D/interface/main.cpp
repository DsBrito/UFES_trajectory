/*

Centro Tecnológico Departamento de Informática
Disciplina: Computação Gráfica
Código: INF09282 e INF09284
Prof. Thiago Oliveira dos Santos

Trabalho 2D
Autor: DIONATAS SANTOS BRITO

{Simboligia utilizada}
    [True]  = Implementado
    [False] = Não Implementado
*/

/*
[True] Arena -> Assim como no trabalho curto 2D, o programa deverá criar uma arena virtual, porém desta vez em 3D. O
    plano x e y terá informações idênticas às lidas do arquivo "svg" (assim como o trabalho anterior). A altura
    da arena, z, deverá ser 2 vezes a altura do jogador escolhido.

[True] Jogador -> O jogador deverá ter cabeça, braços, corpo e pernas representados em 3D. Utilize a criatividade para
    construir o jogador! O sistema de colisão será como no trabalho anterior, porém agora o círculo do “svg”
    representará o corpo do jogador quando visto de cima. Assim como no trabalho anterior, para os
    jogadores não ocuparem o mesmo espaço, a colisão deverá ser calculada considerando um círculo
    imaginário envolvendo o jogador. Perceba que o círculo é “virtual”, ele serve apenas para calcular a
    colisão e não deve ser mostrado na tela. Os controles do jogador também permanecerão como no trabalho
    anterior.

[True] Andar -> O controle do movimento de andar será como no trabalho anterior, porém agora veremos também o efeito
    das pernas se movendo com a junta do joelho e com a do quadril. Portanto, ao movimentar os jogadores,
    as pernas deverão simular o movimento de andar de um humano. Use a criatividade!.

"fiz o soco com o teclado e não com o mouse"
[True] Dar Socos  -> O jogador poderá dar socos como no trabalho anterior e a colisão será medida com a esfera virtual
    englobando a cabeça do jogador. Ou seja, assumir que a cabeça está dentro de uma esfera para permitir o
    cálculo da colisão.

[True] Jogador Oponente -> O jogador oponente deverá se movimentar como no trabalho anterior, ou seja, de forma “aleatória“ e
    buscando a luta.

[True] Jogo em Geral -> O jogo em geral deverá seguir as funcionalidades do T2D, e.g., ganhar, perder, mostrar mensagens, etc.

[True] Aparencia do Jogo -> Deverão ser utilizados conceitos de iluminação e textura. O jogo deverá conter pelo menos um modelo de
    luz na arena (pontual ou direcional). Além disso, o jogo deverá ter um modo noturno (fazer a troca de
    modos com a tecla “n”) em que todas as luzes da arena são apagadas e cada um dos jogadores é
    iluminado por um holofote individual (representada por uma iluminação spot) vindo do teto e apontando
    para o jogador. As paredes, o chão e o teto da arena deverão ser texturizados, assim como o jogador. O
    aluno está livre para escolher as texturas e utilizar luzes adicionais. Use a criatividade!.

"Só fiz corretamente as 1 e 2 cameras"
[True] Câmeras -> O jogo deverá implementar 3 tipos de visões que poderão ser trocadas com os botões numéricos do
    teclado (1, 2 e 3). O botão 1 (opção padrão) deverá acionar uma câmera perspectiva posicionada no olho
    do jogador e olhando para frente. O botão 2 deverá acionar uma câmera relógio, ou seja, uma câmera
    perspectiva posicionada no pulso e olhando para frente e paralelamente ao braço do jogador (up
    apontando para o teto). Com essa visão, deve ser possível ver parte do braço e da luva, assim como o que
    estiver a frente da luva. O botão 3 deverá acionar uma câmera perspectiva posicionada inicialmente atrás
    do jogador (a uma distância grande suficiente para ver todo o jogador por uma terceira pessoa) e a uma
    altura superior à do jogador, e olhando para o centro do jogador (up apontando para o teto). Essa última
    câmera poderá ser rotacionada (360 graus em torno do jogador e ±60 graus para cima e para baixo)
    quando pressionado o botão direito do mouse em cima da arena. As teclas de + e – controlarão o seu
    zoom.

[True] Mini mapa -> Mapa de posição, dos jogadores. Utilizar uma câmera ortogonal para desenhar um mini mapa da arena
    descrevendo a sua posição (verde) e a posição do oponente (vermelho). O chão desse mapa deve ser
    transparente para não ofuscar a visão original do jogo (ou seja, utilizar apenas linha para representar a
    arena). Utilizar o mesmo conceito da impressão de texto no canto da tela. O mapa deve ficar fixo no canto
    inferior direito e ocupar 1/4 da largura da janela.

Bônus 1 – Visão do Oponente
[True] -> BÔNUSSSS
Implementar uma visão do oponente, ou seja, ver o jogo com os olhos do oponente. Utilizar uma janela
com 200 pixels a mais em y para mostrar essa visão constantemente durante o jogo (isto é, a janela inicial
de 500x500 será 500 por 700 se essa funcionalidade for implementada). DICA: É necessário dividir o
viewport!

Bônus 2 – Modelos Avançados
[True] -> BÔNUSSSS
Modelo utilizado -> (Alien Solider) https://www.mixamo.com/#/?page=1&type=Character
Textura utilizada -> (Zlorp) https://www.mixamo.com/#/?page=2&type=Character
Utilizar modelos avançados de jogador e suas partes (ver exemplos abaixo). O aluno está livre para
utilizar modelos 3D e suas partes feitos no Blender ou baixados da internet, ou editado com ambos. Não
pode haver grupos com modelos repetidos. A qualidade dos modelos será julgada caso a caso. Atenção,
modelos muito pesados podem deixar o jogo muito lento e isso não é desejável.

*/
#include <cmath>
#include <cstdlib>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstring>
#include <iostream>

#include "tinyxml/tinyxml.h"
#include "2D_tools/tools.h"

#include "2D_interface/object_mouse.h"
#include "2D_interface/object_arena.h"
#include "2D_interface/object_player.h"

#include "3D_interface/object_style.h"
#include "3D_interface/object_camera.h"

// definições de dimenções da FightField
// visão reduzida para testes
// #define P_WIDTH 500
// #define P1_HEIGHT 250
// #define P2_HEIGHT 250

// visão de apresentação (correta)   500 x 700
#define P_WIDTH 650
#define P1_HEIGHT 650
#define P2_HEIGHT 450

// variaveis principais do programa
using namespace std;

// GLdouble PlayerWidth;  // largura do jogador
// GLdouble PlayerHeight; // altura do jogador

// variaveis de sistema
object_mouse Mouse;
object_camera Camera;
object_style Style;
int keyStatus[256];
static char str[1000];

bool GameOver = false; // Controla a animacao do game

// arena
object_arena FightField; // campo de luta
bool SideOn = true;      // bordas - lados da arena
bool SideOff = false;

// jogador 1
object_player PlayerOne;
string PlayerOneColor;

// jogador 2
object_player PlayerTwo;
string PlayerTwoColor;

// controle de luz
bool LightMode = false;
bool NightMode = false;
bool DayMode = true;

bool LightSpot = false; // desenha fonte de luz
bool LightOn = true;
bool LightOff = false;

// controle de textura
bool Texture = false;
bool TextureOn = true;
bool TextureOff = false;

bool Axes = false;
bool AxesOff = false;
bool AxesOn = true;

void parseXML(TiXmlNode *root);
void drawHelp();
void changeCamera(int state);
void playerOne();
void playerTwo();

/*________________________________________________________________________________________________________________________________
|Função:                    Leitura do arquivo XML                                                                                |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo a recomendação do professor de utilizar o Tinyxml para realizar a leitura                                 |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte: Carregar XML de um arquivo                                                                                                |
|        https://www.cs.cmu.edu/~preethi/src/tinyxml/docs/tutorial0.html                                                          |
|                                                                                                                                 |
|        Parse XML                                                                                                                |
|        https://gitee.com/dustinksi/tinyxml2/blob/master/xmltest.cpp                                                             |
|        https://stackoverflow.com/questions/52543335/why-is-tinyxml2s-xmldocumentfirstchild-function-returning-null-when-attempt |
| ________________________________________________________________________________________________________________________________|*/

void readImput(char *const pfileName)
{
    // carregar o arquivo
    TiXmlDocument doc(pfileName);
    bool load = doc.LoadFile(); // elemento carregado na estrutura
    if (load)

    {
        cout << "-------------------------- READING -------------------------- " << endl
             << endl
             << "-xml : " << pfileName << endl
             << endl
             << "-------------------------- GAME START --------------------------" << endl
             << endl;
    }
    else
    {
        cout << "Failed to load the file" << pfileName << endl;
        exit(0);
    }

    TiXmlNode *root = doc.FirstChild();
    parseXML(root); // fazer o parse de XML
}

/*________________________________________________________________________________________________________________________________
|Função:                    Parse XML                                                                                             |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Foi Utilizados os seguintes códigos (Fonte) como exemplos                                                          |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  C++ (Cpp) TiXmlNode::ToElement Examples                                                                                  |
|        https://cpp.hotexamples.com/examples/-/TiXmlNode/ToElement/cpp-tixmlnode-toelement-method-examples.html                  |                                                                                                                                 |
|                                                                                                                                 |
|       Str funções                                                                                                               |
|       https://cplusplus.com/reference/cstdlib/strtod/                                                                           |
| ________________________________________________________________________________________________________________________________|*/

void parseXML(TiXmlNode *root)
{
    GLfloat playerx;
    string color = "green"; // PlayerOne = green,  PlayerTwo = red (para trocar jogador basta inverter as cores)
    TiXmlNode *node;

    //~~ analogia for(p=lista->primeiro;p!=NULL;p=p->proximo){
    for (node = root->FirstChild(); node != nullptr; node = node->NextSibling())
    {
        TiXmlElement *copy = node->ToElement();
        if (copy == NULL)
            cout << "Falied! the node is null " << endl;

        else
        {
            string str = (copy->Value());
            const char *ch_prt = str.c_str();
            // arena
            if (strcmp(copy->Value(), "rect") == 0)
            {

                FightField.ReadArena(strtof(copy->Attribute("x"), NULL), 0, strtof(copy->Attribute("y"), NULL), strtof(copy->Attribute("height"), NULL), strtof(copy->Attribute("width"), NULL));
                cout << "[FightField] <" << ch_prt << " x=" << copy->Attribute("x") << " y=" << copy->Attribute("y") << " width=" << copy->Attribute("width") << " height=" << copy->Attribute("height") << "/>" << endl;
            }
            else if (strcmp(copy->Value(), "circle") == 0)
            {
                playerx = FightField.arena_z + (FightField.arena_z + FightField.arena_height) - strtof(copy->Attribute("cy"), NULL);

                if (strcmp(color.c_str(), copy->Attribute("fill")) == 0)
                {

                    PlayerOne.ReadPlayer(Style, true, 0, strtof(copy->Attribute("cx"), NULL), 0, playerx);
                    cout << "[PlayerOne] <" << ch_prt << " x=" << copy->Attribute("cx") << " y=" << copy->Attribute("cy") << " r=" << copy->Attribute("r") << " fill=" << copy->Attribute("fill") << "/>" << endl;
                    PlayerOneColor = copy->Attribute("fill"); // true
                }
                else
                {

                    PlayerTwo.ReadPlayer(Style, false, 0, strtof(copy->Attribute("cx"), NULL), 0, playerx);
                    cout << "[PlayerTwo] <" << ch_prt << " x=" << copy->Attribute("cx") << " y=" << copy->Attribute("cy") << " r=" << copy->Attribute("r") << " fill=" << copy->Attribute("fill") << "/>"
                         << endl;
                    PlayerTwoColor = copy->Attribute("fill");
                }
            }
        }
    }

    // graus
    double degrees = Tools::RadiansToDegressTools(atan2(PlayerOne.player_x - PlayerTwo.player_x, PlayerOne.player_z - PlayerTwo.player_z));
    PlayerOne.player_angle = degrees + 180;
    PlayerTwo.player_angle = degrees;
}

/*________________________________________________________________________________________________________________________________
|Função:                    Pressionamento de um botão/tecla                                                                      |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo funções dadas em laboratório com pequenas modificações                                                    |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte: laboratórios e trabalho 2                                                                                                 |
|        Função do laboratório do Robô (lab3)                                                                                     |
| ________________________________________________________________________________________________________________________________|*/

void keyPress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        keyStatus[(int)('a')] = 1;
        cout << "log: a - giro para esquerda." << endl;

        break;
    case 'd':
    case 'D':
        keyStatus[(int)('d')] = 1;
        cout << "log: d - giro para direita." << endl;

        break;
    case 'w':
    case 'W':
        keyStatus[(int)('w')] = 1;
        cout << "log: w - passo para frente." << endl;

        break;
    case 's':
    case 'S':
        keyStatus[(int)('s')] = 1;
        cout << "log: s - passo para trás." << endl;

        break;
    case 'x':
    case 'X':
        keyStatus[(int)('x')] = 1;
        cout << "log: x - Socar." << endl;

        break;
    case 't':
        if (Texture == true)
        {
            Texture = TextureOff;
            cout << "log: t - Texture On." << endl;
            glEnable(GL_TEXTURE_2D);
        }
        else
        {
            Texture = TextureOn;
            cout << "log: t - Texture Off." << endl;
            glDisable(GL_TEXTURE_2D);
        }
        break;

    case 'p':
        if (LightSpot == true)
        {
            LightSpot = LightOff;
            cout << "log: p - Light Spot Off." << endl;
        }
        else
        {
            LightSpot = LightOn;
            cout << "log: p - Light Spot On." << endl;
        }
        break;
    case 'm':
        if (FightField.arena_side == true)
        {
            FightField.arena_side = SideOff;
            cout << "log: m - Arena Side Off." << endl;
        }
        else
        {
            FightField.arena_side = SideOn;
            cout << "log: m - Arena Side On." << endl;
        }
        break;
    case 'e':
        if (Axes == false)
        {
            Axes = AxesOn;
            cout << "log: e - Axes On." << endl;
        }
        else
        {
            Axes = AxesOff;
            cout << "log: e - Axes Off." << endl;
        }
        break;
    case 'n':
    case 'N':
        if (LightMode == true)
        {
            LightMode = NightMode;
            cout << "log: n - Night Mode Off." << endl;
        }
        else
        {
            LightMode = DayMode;
            cout << "log: n - Night Mode On." << endl;
        }

        break;
    case 'h':
    case 'H':
        drawHelp();

        break;
    case '1':
        changeCamera(1);
        cout << "log: 1 - Camera 1 On." << endl;
        break;
    case '2':
        changeCamera(2);
        cout << "log: 2 - Camera 2 On." << endl;
        break;
    case '3':
        Camera.camera_size = 3 * 50.0;
        Camera.camera_angleXY = +20;
        Camera.camera_angleXZ = 270 - PlayerOne.player_angle;
        changeCamera(3);
        cout << "log: 3 - Camera 3 On." << endl;

        break;
    case '+':
        Camera.camera_size += 10;
        cout << "log: + - Zoom +10 ." << endl;

        break;
    case '-':
        Camera.camera_size -= 10;
        cout << "log: - - Zoom -10 ." << endl;

        break;
    case 27:
        exit(0);
    case ' ':
        keyStatus[(int)(' ')] = !keyStatus[(int)(' ')];

        PlayerTwo.player_state = 0;
        if (keyStatus[(int)(' ')] == ' ')
            cout << "log: - walk PlayerTwo On/Off." << endl;

        break;
    default:
        break;
    }
    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________
|Função:                   Aux- Pressionamento de um botão/tecla                                                                  |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo funções dadas em laboratório                                                                              |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte: keyup (unsigned char key, int x, int y)                                                                                   |
|        Função dos laboratórios e do trabalho 2                                                                                  |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void keyup(unsigned char key, int x, int y)
{
    if (key != ' ')
    {
        keyStatus[(int)(key)] = 0;
    }
    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________
|Função:                                    resetKeyStatus                                                                        |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo funções dadas em laboratório                                                                              |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  ResetKeyStatus()                                                                                                         |
|       Função dos laboratórios e do trabalho 2                                                                                   |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void resetKeyStatus()
{
    for (int i = 0; i < 256; i++)
    {
        keyStatus[i] = 0;
    }
}

/*________________________________________________________________________________________________________________________________
|Função:                                            motion                                                                        |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo funções dadas em laboratório                                                                              |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  motion(int x, int y)                                                                                                     |
|        Função baseada nos laboratórios e no trabalho 2                                                                          |
| ________________________________________________________________________________________________________________________________|*/

void motion(int x, int y)
{
    if (!Mouse.mouse_state || (Camera.camera_state != 0 && Camera.camera_state != 3))
    {
        return;
    }

    Camera.camera_angleXZ += x - Mouse.mouse_positionX;
    Camera.camera_angleXZ = (int)Camera.camera_angleXZ % CAMERA_PERCENT;

    if (Camera.camera_angleXY + y - Mouse.mouse_positionY > -60 && Camera.camera_angleXY + y - Mouse.mouse_positionY < 60)
    {
        Camera.camera_angleXY += y - Mouse.mouse_positionY;
    }

    Mouse.mouse_positionX = x;
    Mouse.mouse_positionY = y;

    // para xy
    GLdouble cossenoXY = cos(Tools::DegressToRadiansTools(Camera.camera_angleXY));
    GLdouble senoXY = sin(Tools::DegressToRadiansTools(Camera.camera_angleXY));

    // para xz
    GLdouble senoXZ = sin(Tools::DegressToRadiansTools(Camera.camera_angleXZ));
    GLdouble cossenoXZ = cos(Tools::DegressToRadiansTools(Camera.camera_angleXZ));

    Camera.camera_middleX = cossenoXY * cossenoXZ;
    Camera.camera_middleY = senoXZ;
    Camera.camera_middleZ = senoXY * cossenoXZ;
}

/*________________________________________________________________________________________________________________________________
|Função:                                                    mouseFunc                                                             |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo funções dadas em laboratório                                                                              |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  retirada do laboratório do soldado, arquivo soldado.cpp +- linha234                                                      |
| ________________________________________________________________________________________________________________________________|*/

void mouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        Mouse.mouse_positionX = x;
        Mouse.mouse_positionY = y;
        Mouse.mouse_state = 1;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        Mouse.mouse_state = 0;
    }
}

/*________________________________________________________________________________________________________________________________
|Função:                                            Init                                                                         |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo funções dadas em laboratório                                                                              |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte: baseado nas funções init dos laboratórios                                                                                 |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/

void init(char *const fileName)
{
    FightField.ReadTexture(); // ler a arena
    Style.ReadStyle();        // ler o style - modo do jogador

    readImput(fileName); // ler o arquivo arena.svg
    Mouse.mouse_state = 0;
    resetKeyStatus();

    // 3d enable
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

    glDepthFunc(GL_LEQUAL);
    changeCamera(1);
}

/*________________________________________________________________________________________________________________________________
|Função:                                          Display                                                                         |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Display que desenha ambos os jogadores na arena                                                                    |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  baseadaa nas funções display dos laboratórios                                                                            |
| ________________________________________________________________________________________________________________________________|*/

void display()
{
    glClearColor(0.4, 0.6, 6.0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    playerOne();
    playerTwo();

    glutSwapBuffers();
}

/*________________________________________________________________________________________________________________________________
|Função:                                              Idle                                                                        |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Seguindo funções dadas em laboratório e fazendo pequenas modificações nela para se adequar ao problema             |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Baseado na função Idle do trabalho 2 e dos laboratórios                                                                  |
|        Função do laboratório do Robô (lab3)                                                                                     |
| ________________________________________________________________________________________________________________________________|*/

void idle()
{
    static GLdouble previousTime = glutGet(GLUT_ELAPSED_TIME);
    static bool inc = true;

    GLdouble currentTime, timeDifference; // Pega o tempo que passou do inicio da aplicacao
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    timeDifference = currentTime - previousTime; // Calcula o tempo decorrido desde de a ultima frame.
    previousTime = currentTime;                  // Atualiza o tempo do ultimo frame ocorrido

    static GLdouble previousTimePunch = glutGet(GLUT_ELAPSED_TIME);
    GLdouble timeDifferencePunch = currentTime - previousTimePunch;

    if (keyStatus[(int)(' ')])
    {
        if (PlayerTwo.FixStart())
        {
            if (timeDifferencePunch > 2500)
            {
                PlayerTwo.startPunch();
                previousTimePunch = currentTime;
            }
            else
            {
                PlayerTwo.FixWalk(0.5 * timeDifference, PlayerOne, FightField);
                PlayerTwo.player_angle = Tools::RadiansToDegressTools(atan2(PlayerOne.player_x - PlayerTwo.player_x, PlayerOne.player_z - PlayerTwo.player_z));
            }
        }
        else
        {
            if ((PlayerOne.getPlayerPoints() < 10) && (PlayerTwo.getPlayerPoints() < 10))
            {
                // PlayerTwo.FixPunch(PlayerOne);
                if (PlayerTwo.FixPunch(PlayerOne))
                {
                    cout << ">>> movimento: - O PlayerTwo (" << PlayerTwoColor.c_str() << ") acertou o PlayerOne (" << PlayerOneColor.c_str() << ") -> Placar PlayerOne(" << PlayerOne.getPlayerPoints() << ") x PlayerTwo(" << PlayerTwo.getPlayerPoints() << ")" << endl;
                    GLfloat branco = 1;
                    PlayerTwo.ChangeToWhiteColor(PlayerOne, branco, branco, branco);
                }
                else
                {
                    PlayerTwo.ChangeToNormalColor(PlayerOne, PlayerOneColor);
                }
            }
        }
    }

    if (PlayerOne.FixStart())
    {
        if (keyStatus[(int)('w')])
        {
            PlayerOne.FixWalk(timeDifference, PlayerTwo, FightField);
            // MouseOne.mouse_state = 1;
        }
        if (keyStatus[(int)('s')])
        {
            PlayerOne.FixWalk(-timeDifference, PlayerTwo, FightField);
            // MouseOne.mouse_state = 1;
        }
        if (keyStatus[(int)('a')])
        {
            PlayerOne.FixVelAngular(timeDifference, PlayerTwo, FightField);
            // MouseOne.mouse_state = 1;
        }
        if (keyStatus[(int)('d')])
        {
            PlayerOne.FixVelAngular(-timeDifference, PlayerTwo, FightField);
            // MouseOne.mouse_state = 1;
        }
        if (keyStatus[(int)('x')])
        {
            PlayerOne.startPunch();
        }
    }
    else
    {
        if ((PlayerOne.getPlayerPoints() < 10) && (PlayerTwo.getPlayerPoints() < 10))
        {

            if (PlayerOne.FixPunch(PlayerTwo))
            {
                cout << ">>> movimento: - O PlayerOne (" << PlayerOneColor.c_str() << ") acertou o PlayerTwo (" << PlayerTwoColor.c_str() << ") -> Placar PlayerOne(" << PlayerOne.getPlayerPoints() << ") x PlayerTwo(" << PlayerTwo.getPlayerPoints() << ")" << endl;
                GLfloat branco = 1;
                PlayerOne.ChangeToWhiteColor(PlayerTwo, branco, branco, branco);
            }
            else
            {
                PlayerOne.ChangeToNormalColor(PlayerTwo, PlayerTwoColor);
            }
        }
    }

    PlayerOne.FixFrame();
    PlayerTwo.FixFrame();
    glutPostRedisplay();
}

/*________________________________________________________________________________________________________________________________
|Função:                    drawAxes                                                                                             |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Função passada pelo professor                                                                                      |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:                                                                                                                           |
|        Retirada do arquivo soldado.cpp do laboratório do soldado                                                                |                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/

void drawAxes(double size, GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat color_r[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat color_g[] = {0.0, 1.0, 0.0, 1.0};
    GLfloat color_b[] = {0.0, 0.0, 1.0, 1.0};

    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(x, y, z);

    // x axis
    glPushMatrix();
    glColor3fv(color_r);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();

    // y axis
    glPushMatrix();
    glColor3fv(color_g);
    glRotatef(90, 0, 0, 1);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();

    // z axis
    glPushMatrix();
    glColor3fv(color_b);
    glRotatef(-90, 0, 1, 0);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glPopAttrib();
}

// desenha a area de jogo com as cameras adequadas

/*________________________________________________________________________________________________________________________________
|Função:                    drawGame                                                                                             |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Função que desenha na tela a camera/placar/minimapa = interface do jogo                                            |
|                Camera 1 = visão dos olhos do jogador                                                                            |
|                Camera 2 = visão de camera reloógio, localizada no punho do jogador                                              |
|                Camera 3 = visão pespectiva atrás do jogador                                                                     |
|                Minimapa = miniatura da arena representando os jogadores como circulos.                                          |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:                                                                                                                           |
|       baseada no trabalho 2   e laboratórios                                                                                     |                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void drawGame()
{
    int camera = 1;
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, P_WIDTH, 0, P1_HEIGHT, -1, 1);

    if (Camera.camera_state == 1)
    {
        camera = 1;
        // sprintf(str, "Camera 1");
    }
    else if (Camera.camera_state == 2)
    {
        camera = 2;
        // sprintf(str, "Camera 2");
    }
    else if (Camera.camera_state == 3)
    {
        camera = 3; // sprintf(str, "Camera 3");
    }

    PlayerOne.DrawPlayerPoints(0.1 * P_WIDTH, 0.9 * P1_HEIGHT, 0, PlayerOne, PlayerTwo, camera);

    PlayerOne.DrawMapPlayer(0.749 * P_WIDTH, 0.01 * P1_HEIGHT, 0, PlayerOne, PlayerTwo, FightField, P_WIDTH, P1_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

// escreve os atalhos na linha de comando
void drawHelp()
{
    cout << endl
         << "######################### HELP #########################" << endl;
    cout << "# tecla: espaço - PlayerTwo On/Off.                    #" << endl;
    cout << "# tecla: 1 - Camera 1 On.                              #" << endl;
    cout << "# tecla: 2 - Camera 2 On.                              #" << endl;
    cout << "# tecla: 3 - Camera 3 On.                              #" << endl;
    cout << "# tecla: w - Passo para frente.                        #" << endl;
    cout << "# tecla: a - Giro para esquerda.                       #" << endl;
    cout << "# tecla: d - Giro para direita.                        #" << endl;
    cout << "# tecla: s - Passo para trás.                          #" << endl;
    cout << "# tecla: x - Socar.                                    #" << endl;
    cout << "# tecla: e - Axes On/Off.                              #" << endl;
    cout << "# tecla: n - Night Mode On/Off.                        #" << endl;
    cout << "# tecla: t - Texture On/Off.                           #" << endl;
    cout << "# tecla: p - Light Spot On/Off.                        #" << endl;
    cout << "# tecla: m - Arena Side On/Off.                        #" << endl;
    cout << "# tecla: h - Help.                                     #" << endl;
    cout << "######################### HELP #########################" << endl
         << endl;
}

/*________________________________________________________________________________________________________________________________
|Função:                    changeCamera                                                                                          |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Função que desenha na tela a camera/placar/minimapa = interface do jogo                                            |
|                Camera 1 = visão dos olhos do jogador                                                                            |
|                Camera 2 = visão de camera reloógio, localizada no punho do jogador                                              |
|                Camera 3 = visão pespectiva atrás do jogador                                                                     |
|                Minimapa = miniatura da arena representando os jogadores como circulos.                                          |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:                                                                                                                           |
|       baseada na função "changeCamera" do laboratório terrasol e no trabalho 2                                                  |                                                                                                                                 |
|                                                                                                                                 |
|       Alguns videos do youtube que usei como base para a criação das cameras:                                                   |
|           Diário OpenGL 12 # Classe Camera C++ -> https://www.youtube.com/watch?v=vXVq3GvFVSA                                   |
|           OpenGL - Up Vector Camera vs Look At Point -> https://www.youtube.com/watch?v=P6pJHrA9Avs                             |
|           OpenGL - camera movement -> https://www.youtube.com/watch?v=AWM4CUfffos                                               |
|           OpenGL Tutorial 8 - Camera -> https://www.youtube.com/watch?v=86_pQCKOIPk                                             |
|           Diario OpenGL 11 # Projeção de Perspectiva -> https://www.youtube.com/watch?v=m7WQkT3dXPw                             |
|           Moving The Camera // OpenGL Beginners Series -> https://www.youtube.com/watch?v=zUpJ2vx3wes                           |
|           Camera/View Space // OpenGL Beginners Series -> https://www.youtube.com/watch?v=q5jOLztcvsM                           |
|________________________________________________________________________________________________________________________________|*/

void changeCamera(int state)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // visão dos olhos do jogador
    if (state == 1) // direção dos olhos
    {
        gluPerspective(45, (GLfloat)P_WIDTH / (GLfloat)P1_HEIGHT, 15, 10000);

        pos eye = PlayerOne.getEyePosition();
        pos mark = PlayerOne.getEyeMark();

        Camera.ReadCamera(1, eye.x, eye.y, eye.z, mark.x, mark.y, mark.z, 0, 1, 0);
    }
    // visão de camera reloógio, localizada no punho do jogador
    else if (state == 2) // direção dos punhos
    {
        gluPerspective(45, (GLfloat)P_WIDTH / (GLfloat)P1_HEIGHT, 3, 10000);

        pos punch = PlayerOne.getPunchPosition();
        pos mark = PlayerOne.getPunchMark();
        pos grip = PlayerOne.getGripUp();
        Camera.ReadCamera(2, punch.x, punch.y, punch.z, mark.x, mark.y, mark.z, grip.x, grip.y, grip.z);
    }
    // visão pespectiva atrás do jogador
    else if (state == 3)
    {
        gluPerspective(45, (GLfloat)P_WIDTH / (GLfloat)P1_HEIGHT, 1, 10000);

        // para xy
        GLdouble cossenoXY = cos(Tools::DegressToRadiansTools(Camera.camera_angleXY));
        GLdouble senoXY = sin(Tools::DegressToRadiansTools(Camera.camera_angleXY));

        // para xz
        GLdouble senoXZ = sin(Tools::DegressToRadiansTools(Camera.camera_angleXZ));
        GLdouble cossenoXZ = cos(Tools::DegressToRadiansTools(Camera.camera_angleXZ));

        pos mark = PlayerOne.getPerspectiveMark(); // modo perspectivo - visão do jogador

        Camera.camera_state = 3;

        Camera.camera_middleX = mark.x;
        Camera.camera_middleY = mark.y;
        Camera.camera_middleZ = mark.z;

        Camera.camera_eyeX = Camera.camera_size * cossenoXY * cossenoXZ;
        Camera.camera_eyeY = Camera.camera_size * senoXZ;
        Camera.camera_eyeZ = Camera.camera_size * senoXY * cossenoXZ;
    }
}

/*________________________________________________________________________________________________________________________________
|Função:                    playerOne                                                                                             |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Função que controla a camera de visão dos jogadores                                                                |
|                Camera 1 = visão dos olhos do jogador                                                                            |
|                Camera 2 = visão de camera reloógio, localizada no punho do jogador                                              |
|                Camera 3 = visão pespectiva atrás do jogador                                                                     |
|               Enquanto for diferente de fim de jogo, irá mostrar a visão do oponente na parte superior da janela de jogo        |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:                                                                                                                           |
|        baseada nas funções "reshape, display, MygluLookAt" do laboratório do soldado.cpp                                        |                                                                                                                                 |
|        camera 1/2/3 = baseado na função "MygluLookAt" do arquivo soldado.cpp do laboratório do soldado                          |
|       https://docplayer.com.br/75115418-Computacao-grafica-opengl-05-3d.html                                                    |
|       utilizei como estudo de cameras, os mesmos videos da função a cima (me deu ideia para os modos de cameras)                |
|________________________________________________________________________________________________________________________________|*/

void playerOne()
{
    changeCamera(Camera.camera_state);
    glViewport(0, 0, P_WIDTH, P1_HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // camera 1 -> possui a posição do alvo (mark) e dos olhos (eye)
    if (Camera.camera_state == 1)
    {
        pos eye = PlayerOne.getEyePosition();
        pos mark = PlayerOne.getEyeMark();
        Camera.ReadCamera(1, eye.x, eye.y, eye.z, mark.x, mark.y, mark.z, 0, 1, 0);

        gluLookAt(Camera.camera_eyeX, Camera.camera_eyeY, Camera.camera_eyeZ, Camera.camera_middleX, Camera.camera_middleY, Camera.camera_middleZ, Camera.camera_onX,
                  Camera.camera_onY, Camera.camera_onZ);
    }
    // camera 2 -> possui a posição do alvo (mark), dos punhos (grip) e do soco (punch)
    // deve acompanhar o punho do jogador, "visão de camera relógio"
    // utilizei a ideia de camera em movimento dos videos da função a cima
    else if (Camera.camera_state == 2)
    {
        pos punch = PlayerOne.getPunchPosition(); // eye
        pos mark = PlayerOne.getPunchMark();      // midle
        pos grip = PlayerOne.getGripUp();         // up
        Camera.ReadCamera(2, punch.x, punch.y, punch.z, mark.x, mark.y, mark.z, grip.x, grip.y, grip.z);

        gluLookAt(Camera.camera_eyeX, Camera.camera_eyeY, Camera.camera_eyeZ, Camera.camera_middleX, Camera.camera_middleY, Camera.camera_middleZ, Camera.camera_onX,
                  Camera.camera_onY, Camera.camera_onZ);
    }
    // camera 3 -> possui posição do alvo (mark)
    // deve rotacionar com o mouse
    // utilizei a ideia dos videos da função a cima + os laboratótios
    else if (Camera.camera_state == 3)
    {
        pos mark = PlayerOne.getPerspectiveMark();

        // para xy
        GLdouble cossenoXY = cos(Tools::DegressToRadiansTools(Camera.camera_angleXY));
        GLdouble senoXY = sin(Tools::DegressToRadiansTools(Camera.camera_angleXY));

        // para xz
        GLdouble senoXZ = sin(Tools::DegressToRadiansTools(Camera.camera_angleXZ));
        GLdouble cossenoXZ = cos(Tools::DegressToRadiansTools(Camera.camera_angleXZ));

        Camera.camera_state = 3;

        Camera.camera_middleX = mark.x;
        Camera.camera_middleY = mark.y;
        Camera.camera_middleZ = mark.z;

        Camera.camera_eyeX = Camera.camera_size * cossenoXZ * cossenoXY + mark.x;
        Camera.camera_eyeY = Camera.camera_size * senoXY + mark.y;
        Camera.camera_eyeZ = Camera.camera_size * senoXZ * cossenoXY + mark.z;

        gluLookAt(Camera.camera_eyeX, Camera.camera_eyeY, Camera.camera_eyeZ, Camera.camera_middleX, Camera.camera_middleY, Camera.camera_middleZ, Camera.camera_onX,
                  Camera.camera_onY, Camera.camera_onZ);
    }

    PlayerOne.FixLight(LightMode, LightSpot, PlayerOne, PlayerTwo, FightField);

    if (Axes)
    {
        drawAxes(50, FightField.arena_x, 0, FightField.arena_z);
    }

    GameOver = PlayerOne.player_points >= 10 || PlayerTwo.player_points >= 10;

    if (!GameOver)
    {
        drawGame();
        PlayerOne.DrawPlayer();
        PlayerTwo.DrawPlayer();
        FightField.DrawArena();
    }
    else
    {
        PlayerOne.DrawPlayerGameOver(0.3, 0.97, 0, PlayerOne);
        // DrawPlayerGameOver( p_x,  p_y, GLfloat p_z, object_player &player)
        // showGameOver(0.45, 0.5);
    }
}

/*________________________________________________________________________________________________________________________________
|Função:                    player Two -> BONUS #2                                                                                |
|---------------------------------------------------------------------------------------------------------------------------------|
|Comentários:  Bonus 2, visão do oponente                                                                                         |
|                Mesmo efeito da camera 1 do playerOne                                                                            |
|                Enquanto for diferente de fim de jogo, irá mostrar a visão do oponente na parte superior da janela de jogo       |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:                                                                                                                           |
|       baseada nas funções "reshape, display" do laboratório do soldado.cpp                                                      |                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void playerTwo()
{
    glViewport(0, P1_HEIGHT, P_WIDTH, P2_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (GLfloat)P_WIDTH / (GLfloat)P2_HEIGHT, 15, 10000); // retirado da função "reshape" do laboratório do soldado (arquivo soldado.cpp)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // camera 1
    pos eye = PlayerTwo.getEyePosition();
    pos mark = PlayerTwo.getEyeMark();
    gluLookAt(eye.x, eye.y, eye.z, mark.x, mark.y, mark.z, 0, 1, 0); // retirado da função "display" do laboratório do soldado (aquivo soldado.cpp)

    PlayerTwo.FixLight(LightMode, LightSpot, PlayerOne, PlayerTwo, FightField);

    if (!GameOver)
    {
        PlayerOne.DrawPlayer();
        PlayerTwo.DrawPlayer();
        FightField.DrawArena();
    }
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(P_WIDTH, P1_HEIGHT + P2_HEIGHT); // x,y
    glutInitWindowPosition(1100, 100);
    glutCreateWindow("Trabalho 3D - Luta Boxe");

    if (argc < 2)
    {
        cout << "Nao foi encontrado o aquivo arena_x.svg" << endl;
        return 0;
    }
    init(argv[1]);

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutKeyboardFunc(keyPress);
    glutKeyboardUpFunc(keyup);

    glutMotionFunc(motion);
    glutMouseFunc(mouseFunc);
    drawHelp();
    glutMainLoop();

    return 0;
}