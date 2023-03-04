#include "../include/alvo.h"
#include <cstdio>
#include <math.h>

void Alvo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B) {
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        glVertex2f(radius * cos(i * M_PI / 180), radius * sin(i * M_PI / 180));
    }
    glEnd();
}

void Alvo::DesenhaAlvo(GLfloat x, GLfloat y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    switch (this->gColor) {
    case 0:
        DesenhaCirc(radiusAlvo, 1.0, 0.0, 0.0);
        break;
    case 1:
        DesenhaCirc(radiusAlvo, 0.0, 1.0, 0.0);
        break;
    case 2:
        DesenhaCirc(radiusAlvo, 0.0, 0.0, 1.0);
        break;
    default:
        DesenhaCirc(radiusAlvo, 1.0, 1.0, 1.0);
        break;
    }
    glPopMatrix();
}

void Alvo::Recria(GLfloat x, GLfloat y) {
    this->gX = x;
    this->gY = y;
    this->gColor = this->gColor == 2 ? 0 : this->gColor + 1;
}

bool Alvo::Atingido(Tiro* tiro) {
    GLfloat posx, posy;
    tiro->GetPos(posx, posy);
    GLfloat dist = sqrt(pow(posx - this->gX, 2) + pow(posy - this->gY, 2));
    return dist < radiusAlvo;
}
