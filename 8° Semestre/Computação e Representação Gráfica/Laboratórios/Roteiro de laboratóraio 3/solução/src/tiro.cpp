#include "../include/tiro.h"
#include <cstdio>
#include <math.h>
#define DISTANCIA_MAX 500

void Tiro::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B) {
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        glVertex2f(radius * cos(i * M_PI / 180), radius * sin(i * M_PI / 180));
    }
    glEnd();
}

void Tiro::DesenhaTiro(GLfloat x, GLfloat y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    DesenhaCirc(radiusTiro, 1, 1, 1);
    glPopMatrix();
}

void Tiro::Move(GLdouble deltaTime) {
    gX += gVel * sin(-gDirectionAng * M_PI / 180) * deltaTime;
    gY += gVel * cos(-gDirectionAng * M_PI / 180) * deltaTime;
}

Tiro::~Tiro() {}

bool Tiro::Valido() { return DISTANCIA_MAX > sqrt(pow(gX, 2) + pow(gY, 2)); }
