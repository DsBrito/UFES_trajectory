#include "../include/robo.h"
#include "../include/utils.h"
#include <cmath>

/**
 * @brief Desenha um retângulo do robô
 * @param height Altura do retângulo
 * @param width Largura do retângulo
 * @param R Cor vermelha do retângulo
 * @param G Cor verde do retângulo
 * @param B Cor azul do retângulo
 */
void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G,
                       GLfloat B) {
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    // clang-format off
        glVertex2f(-width/2, 0);
        glVertex2f(width/2, 0);
        glVertex2f(width/2, height);
        glVertex2f(-width/2, height);
    // clang-format on
    glEnd();
}

void Robo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B) {
    glColor3f(R, G, B);
    glPointSize(4);
    glBegin(GL_POINTS);
    for (int i = 0; i < 360; i += 20) {
        glVertex2f(radius * cos(i * M_PI / 180), radius * sin(i * M_PI / 180));
    }
    glEnd();
}

void Robo::DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat R,
                       GLfloat G, GLfloat B) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(thetaWheel, 0, 0, 1);
    DesenhaCirc(radiusWheel, R, G, B);
    glPopMatrix();
}

void Robo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2,
                        GLfloat theta3) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(theta1, 0, 0, 1);
    DesenhaRect(paddleHeight, paddleWidth, 0, 0, 1);
    glPushMatrix();
    glTranslatef(0, paddleHeight, 0);
    glRotatef(theta2, 0, 0, 1);
    DesenhaRect(paddleHeight, paddleWidth, 1, 1, 0);
    glPushMatrix();
    glTranslatef(0, paddleHeight, 0);
    glRotatef(theta3, 0, 0, 1);
    DesenhaRect(paddleHeight, paddleWidth, 0, 1, 0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void Robo::DesenhaRobo(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1,
                       GLfloat theta2, GLfloat theta3) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    Robo::DesenhaRect(baseHeight, baseWidth, 1, 0, 0);
    Robo::DesenhaBraco(0, baseHeight, theta1, theta2, theta3);
    Robo::DesenhaRoda(-baseWidth / 2, 0, thetaWheel, 0, 0, 1);
    Robo::DesenhaRoda(baseWidth / 2, 0, thetaWheel, 0, 0, 1);
    glPopMatrix();
}

void Robo::RodaBraco1(GLfloat inc) { gTheta1 += inc; }

void Robo::RodaBraco2(GLfloat inc) { gTheta2 += inc; }

void Robo::RodaBraco3(GLfloat inc) { gTheta3 += inc; }

void Robo::MoveEmX(GLfloat dx, GLdouble deltaTime) {
    gX += dx * deltaTime;
    gThetaWheel -= (180 * dx * deltaTime) / (M_PI * radiusWheel);
}

// Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat& xOut,
                 GLfloat& yOut) {}

Tiro* Robo::Atira() {
    int radius = paddleHeight;
    int totalAngle = gTheta1 + gTheta2 + gTheta3;
    int firstX = gX + radius * sin(-gTheta1 * M_PI / 180);
    int firstY = gY + baseHeight + radius * cos(-gTheta1 * M_PI / 180);
    int secondX = firstX + (radius)*sin(-(gTheta1 + gTheta2) * M_PI / 180);
    int secondY = firstY + (radius)*cos(-(gTheta1 + gTheta2) * M_PI / 180);
    int thirdX = secondX + radius * sin(-totalAngle * M_PI / 180);
    int thirdY = secondY + radius * cos(-totalAngle * M_PI / 180);
    return new Tiro(thirdX, thirdY, totalAngle);
}
