


#include <GL/glut.h>
#include "object_player.h"

using namespace std;

/*________________________________________________________________________________________________________________________________
|Função:                                  Auxiliar de Rotação                                                                     |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:    Funções IfRightHandCollision, IfRightHandCollision e FixPlayerCollision retirada/baseada no lab3                 |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Tiro* Robo::Atira()                                                                                                      |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo robo.cpp -> linha 138...)                                                                            |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/
//colide quando o nariz de um jogador encosta na barreira do outro jogador
void object_player :: FixPlayerCollision(GLfloat &incX, GLfloat &incY, object_player &player, GLdouble state) const{
   
//calcula colisão do jogador
    GLfloat normalX;
    GLfloat normalY;
    double calculation;

    bool collision=Tools::DistanceTools(gX_head + incX, gY_head + incY, player.getHeadX(), player.getHeadY()) <= getBarrier() + player.getRadius();
    if (collision) {
        GLfloat normalX = getHeadX() - player.getHeadX();
        GLfloat normalY = getHeadY() - player.getHeadY();
        double calculation = Tools::MagnitudeTools(normalX, normalY);

        normalX /= calculation;
        normalY /= calculation;

        incX += state * 0.5 * normalX;
        incY += state * 0.5 * normalY;
       // cout<< "players collided in x: "<< normalX <<  "and y: " << normalY << endl;
    }

}

bool object_player ::IfRightHandCollision(object_player &player){


    GLfloat newHandX = 0;
    GLfloat newHandY = 0;
    
    Tools:: FixHandTools(gX_head, gY_head, gTheta_Head, newHandX, newHandY, gX_rightHand, gY_rightHand, gX_rightForearm, gX_rightArm, gY_rightArm, gY_rightForearm, gTheta_rightForearm, gTheta_rightArmAngle, gRotation_rightForearm, gRotation_rightArm);
    
    setRightGripX(newHandX);
    setRightGripY(newHandY);
    
    //return Tools::DistanceTools(player.gX_head, player.gY_head, gX_rightGrip, gX_rightGrip) < getHandSize() + player.getRadius();
    return Tools::DistanceTools(player.gX_head, player.gY_head, newHandX, newHandY) < getHandSize() + player.getRadius();
}

bool object_player :: IfLeftHandCollision(object_player &player){
  
    GLfloat newHandX = 0;
    GLfloat newHandY = 0;
    
    Tools:: FixHandTools(gX_head, gY_head, gTheta_Head, newHandX, newHandY, gX_leftHand, gY_leftHand, gX_leftForearm, gX_leftArm, gY_leftArm, gY_leftForearm, gTheta_leftForearm, gTheta_leftArmAngle, gRotation_leftForearm, gRotation_leftArm);
 
    setLeftGripX(newHandX);
    setLeftGripY(newHandY);
  
    //return Tools::DistanceTools(player.gX_head, player.gY_head, gX_leftGrip, gY_leftGrip) < getHandSize() + player.getRadius();
    return Tools::DistanceTools(player.gX_head, player.gY_head, newHandX, newHandY) < getHandSize() + player.getRadius();
}

//colisao entre o joador e a arena
void  object_player ::FixArenaCollision(object_arena &FightField, GLfloat &incX, GLfloat &incY) const{
    if (getHeadX() + incX + getRadius() >= FightField.arena_x + FightField.arena_width || getHeadX() + incX - getRadius() <= FightField.arena_x) {
        incX = 0;
    }
    if (getHeadY() + incY + getRadius() >= FightField.arena_y + FightField.arena_height || getHeadY() + incY - getRadius() <= FightField.arena_y) {
        incY = 0;
    }
}

//desenha formas que vão compor os lutadores
void  object_player :: DrawObjects(GLfloat p_radius,  const string &p_color){
//circulos    
    circle_head = new object_circle(p_radius,p_color);    //cabeça
    circle_nose = new object_circle(p_radius * 0.2, p_color);    //nariz
    circle_leftHand = new object_circle(p_radius * 0.4, 1,0,1); //mao esquerda
    circle_rightHand = new object_circle(p_radius * 0.4, 1, 0, 1); //mao direita

//retangulos
    recltangle_leftArm = new object_rectangle(p_radius * 2.2, p_radius * 0.25, 0, 0, 0);  //braço esquerdo
    recltangle_rightArm = new object_rectangle(p_radius * 2.2, p_radius * 0.25, 0, 0, 0); //braço direiro
    rectangle_leftForearm = new object_rectangle(p_radius * 2, p_radius * 0.25, 0, 0, 0); //antebraço esquerdo
    rectangle_rightForearm = new object_rectangle(p_radius * 2, p_radius * 0.25, 0, 0, 0);//antebraço direito
}

//iniciação dos jogadores
void object_player:: ReadPlayer(GLfloat p_x, GLfloat p_y, GLfloat p_theta, GLfloat p_radius, const string &color){

//cabeça   
    gX_head = p_x;
    gY_head = p_y;
    gTheta_Head = p_theta;

//nariz
    gX_nose = p_radius * 1.01;
    gY_nose = 0;

//mãos
    gX_leftHand = 0;
    gY_leftHand = p_radius * 2;
    gX_rightHand = 0;
    gY_rightHand = p_radius * 2;

//braço
    gX_leftArm = 0;
    gY_leftArm = +p_radius;
    gTheta_leftArmAngle = +30;
    gRotation_leftArm = 0;

    gX_rightArm = 0;
    gY_rightArm = -p_radius;
    gTheta_rightArmAngle = 150;
    gRotation_rightArm = 0;

//punho (vai ser setado na colisão)

//antebraço
    gX_leftForearm = 0;
    gY_leftForearm = p_radius * 2.2;
    gTheta_leftForearm = -110;
    gRotation_leftForearm = 0;

    gX_rightForearm = 0;
    gY_rightForearm = p_radius * 2.2;
    gTheta_rightForearm = +110;
    gRotation_rightForearm = 0;
//placar
    points =0;
    DrawObjects( p_radius,color);


}
/*________________________________________________________________________________________________________________________________
|Função:                                  Auxiliar de Rotação                                                                     |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:    Fungão retirada do lab3                                                                                          | 
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut)                                           |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo robo.cpp -> linha 126...)                                                                            |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/
void object_player::FixVelAngular(GLdouble state) {
    gTheta_Head += state * 0.2; //velocidade angular
}

//desenhos 

//Area do jogo
void object_player ::DrawGameArea(){
    
    glPushMatrix();

    GLfloat d_Rotation =0;
    Tools::trTools(gX_head, gY_head,gTheta_Head, d_Rotation);


    DrawPlayerHeadCommand();
    DrawPlayerNose();

    DrawPlayerLeftArm();
    DrawPlayerRightArm();

//LEMBRAR DE ATIVAR/DESCOMENTAR A FUNÇÃO ABAIXO PARA MOSTRAR A BARREIRA EM VOLTA DO LUTADOR
    //DrawGameBarrier();

    glPopMatrix(); 
}
    
//barreira
void  object_player ::DrawGameBarrier() const{
    glPushMatrix();
    Tools::CircleTraceTools( getRadius() * 2);

    glEnd();
    glPopMatrix();

}
 
//comandos de desenho
void object_player::DrawPlayerHeadCommand() {
    circle_head->DrawCircle();
}
void object_player::DrawPlayerNoseCommand() {
    circle_nose->DrawCircle();
}
void object_player::DrawRightArmCommand() {
    recltangle_rightArm->DrawRectangle();
}
void object_player::DrawRightForearmCommand() {
    rectangle_rightForearm->DrawRectangle();
}
void object_player::DrawRightHandCommand() {
    circle_rightHand->DrawCircle();
}
void object_player::DrawLeftArmCommand() {
    recltangle_leftArm->DrawRectangle();
}
void object_player::DrawLeftForearmCommand() {
    rectangle_leftForearm->DrawRectangle();
}
void object_player::DrawLeftHandCommand() {
    circle_leftHand->DrawCircle();
}
void object_player::DrawPlayerNose() {
    glPushMatrix();

   Tools::tTools(gX_nose, gY_nose);

    DrawPlayerNoseCommand();

    glPopMatrix();
}

/*________________________________________________________________________________________________________________________________
|Função:                                  Desenha Braços                                                                          |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:    As Funções DrawPlayerRightArm e DrawPlayerLeftArm e DrawPlayerGameOver seguem a mesma lógica                     | 
|                da função DesenhaBraco presente no lab3                                                                          |
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)                                       |
|        Função do laboratório do Robô (lab3)                                                                                     |
|                                                                                                                                 |
|        Meu Github (arquivo robo.cpp -> linha 43...)                                                                             |
|        https://github.com/DsBrito/Opengl-Robo--Tiro                                                                             |
| ________________________________________________________________________________________________________________________________|*/
void object_player::DrawPlayerRightArm() {
    glPushMatrix();

    Tools::trTools(gX_rightArm,gY_rightArm, gTheta_rightArmAngle, gRotation_rightArm);
    DrawRightArmCommand();



   Tools::trTools(gX_rightForearm,gY_rightForearm, gTheta_rightForearm, gRotation_rightForearm);
    DrawRightForearmCommand();

   Tools::tTools(gX_rightHand, gY_rightHand);
    DrawRightHandCommand();

    glPopMatrix();
}
void object_player::DrawPlayerLeftArm() {
    glPushMatrix();

    Tools::trTools(gX_leftArm,gY_leftArm, gTheta_leftArmAngle, gRotation_leftArm);


    DrawLeftArmCommand();
    Tools::trTools(gX_leftForearm,gY_leftForearm, gTheta_leftForearm, gRotation_leftForearm);


    DrawLeftForearmCommand();

    Tools::tTools(gX_leftHand, gY_leftHand);
    circle_leftHand->DrawCircle();


    glPopMatrix();
}


/*________________________________________________________________________________________________________________________________
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
void  object_player::DrawDevelopedMensage(GLfloat x, GLfloat y) {
    static char string[1000];
    void *latterFont = GLUT_BITMAP_9_BY_15;
    glColor3f(1, 1, 1);
    //Cria a string a ser impressa
    char *pString;
    sprintf(string, "[CG] Boxing Game - 2022/2 - Developed by Dionatas Santos Brito");
    //Define a posicao onde vai comecar a imprimir
    glRasterPos2f(x/10-5, y/10);
    //Imprime um caractere por vez
    pString = string;
    while (*pString ) {
        glutBitmapCharacter(latterFont, *pString);
        pString++;
    }

}
void object_player:: DrawPlayerPoints(GLfloat p_x, GLfloat p_y,object_player &p_One,object_player &p_Two){
    static char string[1000];
    void *latterFont = GLUT_BITMAP_TIMES_ROMAN_24;
    glColor3f(1, 1, 1);
    //Cria a string a ser impressa
    char *pString;
    sprintf(string, "PlayerTwo: %d                                                     PlayerOne: %d", p_Two.getPlayerPoints(), p_One.getPlayerPoints());
    //Define a posicao onde vai comecar a imprimir
    glRasterPos2f(p_x, p_y);
    //Imprime um caractere por vez
    pString = string;
    while (*pString) {
        glutBitmapCharacter(latterFont, *pString);
        pString++;
    }    
}
void  object_player::DrawPlayerGameOver(GLfloat x, GLfloat y, object_player &player) {
    static char string[1000];
    void *latterFont = GLUT_BITMAP_TIMES_ROMAN_24;
    glColor3f(1, 1, 1);
    //Cria a string a ser impressa
    char *pString;
    if(player.getPlayerPoints() >= 10) {
        sprintf(string, "YOU WON");
    } else {
        sprintf(string, "YOU LOST ");
    }
    //Define a posicao onde vai comecar a imprimir
    glRasterPos2f(x, y);
    //Imprime um caractere por vez
    pString = string;
    while (*pString ) {
        glutBitmapCharacter(latterFont, *pString);
        pString++;
    }
    DrawDevelopedMensage(x,y);

}
//ações do jogador no ringue de luta
//quando o state > 0 deve andar na mesma direção em busca da colisão
//quando o state é < 0 deve andar na posição oposta em busca da colisão 
void object_player::FixWalk(GLdouble state, object_player &player, object_arena &FightField){
    GLfloat incX = (state * 0.5 * cos(Tools::DegressToRadiansTools(gTheta_Head)));
    GLfloat incY = (state * 0.5 * sin(Tools::DegressToRadiansTools(gTheta_Head)));
    if(state >0){ 
        FixPlayerCollision( incX, incY, player, state);
    }
    else{
        FixPlayerCollision( incX, incY, player, -state);
    }
 
    FixArenaCollision(FightField, incX, incY);
    gX_head += incX;
    gY_head += incY;

}
    
    

/*________________________________________________________________________________________________________________________________
|Função:                       Tratamento de colisão do soco (ação de socar)                                                      |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:  Seguindo algumas pesquisas/videos encontrados no youtube juntamente com os labs                                    | 
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  Criando jogo em C/C++ (SDL e OpenGL) - #8 Colisão simples (hora da magia)                                                |
|        https://www.youtube.com/watch?v=44dqr0o0xow&list=PLX8OaXR9nVyGrgitLda4wpio8n_VDHu5U&index=11                             |
|                                                                                                                                 |
|       Criando jogo em C/C++ (SLD e OpenGL) - #10 Colisão com os blocos                                                          |
|       https://www.youtube.com/watch?v=Sxs8eVXJe8E&list=PLX8OaXR9nVyGrgitLda4wpio8n_VDHu5U&index=13                              |
|                                                                                                                                 | 
|       OpenGL/ C++ Game Tutorial part 17: Mouse button clicks                                                                    |
|       https://www.youtube.com/watch?v=mfaD2e28Irk&list=PLKMRBwuMXxOoFlCWZfu9hheZ7ZSC2IEr3&index=18                              |
|                                                                                                                                 |
|       OpenGL/ C++ Game Tutorial part 22: Collision detection                                                                    |
|       https://www.youtube.com/watch?v=QSyZQ33fU5w&list=PLKMRBwuMXxOoFlCWZfu9hheZ7ZSC2IEr3&index=23                              |
|                                                                                                                                 |
|      Programação de Jogos | C++ | DirectX | Aula 10 - Detecção de Colisão | Bounding Box | Sistema                              |
|      https://www.youtube.com/watch?v=XsplhuxuC4U                                                                                |
|_________________________________________________________________________________________________________________________________|*/
bool  object_player::FixPunch(GLdouble state, object_mouse &mouse, object_arena &FightField, object_player &player){
    GLfloat arenaWidthPercent = (FightField.arena_width / 2);
    GLfloat mousePercent = (mouse.mouse_movedX - mouse.mouse_clickX);
    GLfloat rotationPlayerPercent = mousePercent / arenaWidthPercent;
    GLfloat rotArm = 130 * rotationPlayerPercent;
    GLfloat rotForearm = -45 * rotationPlayerPercent;
    GLfloat stateArm =  0.8 * state;
    GLfloat stateForearm = 0.8 * state;

    //gRotation_rightArm e gRotation_rightForearm
    if (mouse.mouse_button == 0 && mouse.mouse_state == 0 && mouse.mouse_movedX - mouse.mouse_clickX <= FightField.arena_width / 2) {
        if(rotArm >=0)
            gRotation_rightArm = rotArm; 
        if(rotArm <0)
            gRotation_rightArm =0;

        if( rotForearm<= 0)
            gRotation_rightForearm = rotForearm;
        if(rotForearm >=0)
            gRotation_rightForearm =0;
    }

    //rotArm e gRotation_leftForearm
    if (mouse.mouse_button == 0 && mouse.mouse_state == 0 && -(mouse.mouse_movedX - mouse.mouse_clickX) <= FightField.arena_width / 2) {
        if( rotArm <= 0)
            gRotation_leftArm = rotArm;
        if (rotArm > 0)
            gRotation_leftArm = 0;

        if (rotForearm >= 0)
            gRotation_leftForearm =rotForearm; 
        if(rotForearm <0)
            gRotation_leftForearm = 0;
    }

    //gRotation_rightArm
    if (mouse.mouse_state == 1 && (gRotation_rightArm > 0 || gRotation_rightForearm < 0)) {
        if(gRotation_rightArm - stateArm >= 0 )
            gRotation_rightArm = gRotation_rightArm - stateArm;
        if (gRotation_rightArm - stateArm < 0)
            gRotation_rightArm = 0;

        if(gRotation_rightForearm + stateForearm  <= 0)
            gRotation_rightForearm = gRotation_rightForearm + stateForearm;
        if (gRotation_rightForearm + stateForearm > 0)
            gRotation_rightForearm = 0;

    }

    //gRotation_leftForearm
    if (mouse.mouse_state == 1 && (gRotation_leftArm < 0 || gRotation_leftForearm > 0)) {
        if(gRotation_leftArm + stateArm <= 0)
            gRotation_leftArm = gRotation_leftArm + stateArm;
        if(gRotation_leftArm + stateArm > 0)
            gRotation_leftArm = 0;

        if(gRotation_leftForearm - stateForearm >= 0)
            gRotation_leftForearm = gRotation_leftForearm - stateForearm;
        if (gRotation_leftForearm - stateForearm < 0)
            gRotation_leftForearm = 0;
    }

    if ((IfRightHandCollision(player) || IfLeftHandCollision(player)) && mouse.mouse_state == 0) {
        mouse.mouse_state = 1;
        points++;
        return 1;
    }
    return 0;
}

//função para auxiliar na arena de luta, quando a mão de um lutador estiver realizando a ação de socar, o oponente irá ficar na cor branca
void object_player:: ChangeToWhiteColor(object_player &p, GLfloat &r,GLfloat &g,GLfloat &b,GLfloat &n_r,GLfloat &n_g,GLfloat &n_b){

    circle_head->circle_R = r;
    circle_head->circle_G = g;
    circle_head->circle_B = b;

    circle_nose-> circle_R=n_r;
    circle_nose-> circle_G=n_g;
    circle_nose-> circle_B=n_b;
}

//função para auxiliar na arena de luta, quando o lutador não estiver sofrendo dano, ele irá possuir a cor normal (a cor lida anteriormente na função parseXML )
void object_player::ChangeToNormalColor(object_player &player, std::string color){

    circle_head-> circle_R =color == "red";
    circle_head-> circle_G = color == "green";
    circle_head-> circle_B =color == "blue";

    circle_nose-> circle_R=color == "red";
    circle_nose-> circle_G =color == "green";
    circle_nose-> circle_B=color == "blue";
}


//sets auxiliares
void object_player:: setTheta(GLfloat _theta){
    gTheta_Head = _theta;
}
void object_player:: setLeftGripX(GLfloat newLeftGripPositionX){
    gX_leftGrip = newLeftGripPositionX;

};
void object_player:: setLeftGripY(GLfloat newLeftGripPositionY){
    gY_leftGrip = newLeftGripPositionY;

};
void object_player:: setRightGripX(GLfloat newRightGripPositionX){
    gX_rightGrip = newRightGripPositionX;

};
void object_player:: setRightGripY(GLfloat newRightGripPositionY){
    gY_rightGrip = newRightGripPositionY;

};


//gets auxiliares
int  object_player::getPlayerPoints() const {
    return points;
}  
GLfloat  object_player::getHeadX() const {
    return gX_head;
}
GLfloat  object_player::getHeadY() const{
    return gY_head;
}
GLfloat  object_player::getRadius() const{
    return circle_head->circle_radius;
}
GLfloat  object_player::getHandSize() const{
    return getRadius() * 0.4;
}
GLfloat  object_player::getBarrier()  const {
    return getRadius() * 2 ;
}



