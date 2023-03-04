#include "../../libs/glm/glm.hpp"
#include "../../libs/imgui/imgui.h"
#include "../../libs/imgui/imgui_impl_glut.h"
#include "../../libs/imgui/imgui_impl_opengl2.h"
#include "objloader.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
void reshape(int w, int h);
void display();
void mouse(int button, int state, int x, int y);

static const int windowSize = 1000;

static bool imgui_shouldRenderMainWindow = true;
static bool imgui_shouldRenderCameraWindow = true;
static bool imgui_shouldRenderLightingWindow = true;

static const char* shadingModes[]{"GL_SMOOTH", "GL_FLAT"};
static int selectedShadingMode = 0;

// Malhas a serem desenhadas
static mesh soldado;
static mesh arma;

// Controles gerais
static int cameraZoom = 150;
static bool lookatToggle = true;
static bool transformacaoArmaToggle = true;
static bool armaToggle = true;
static bool coordsysToggle = true;

double camXYAngle = 0;
double camXZAngle = 0;

int lastX = 0;
int lastY = 0;
int buttonDown = 0;

static glm::fmat4 myLookAtMatrix = glm::fmat4(1);
static glm::fmat4 translateMatrix = glm::fmat4(1);

void init() {
    printf("Loading meshes...\n");
    // Carrega as meshes dos arquivos
    soldado.loadMesh("Blender/untitledc1.obj");
    arma.loadMesh("Blender/armanova1.obj");
    printf("Done!\n");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, (GLsizei)windowSize, (GLsizei)windowSize);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, (GLfloat)windowSize / (GLfloat)windowSize, 1, 1000);
    glutPostRedisplay();
}

void reshape(int w, int h) {
    //    printf("RESHAPE CALLED!\n");
    //    // Ajusta o tamanho da tela com a janela de visualizacao
    //    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    //    glMatrixMode(GL_PROJECTION);
    //    glLoadIdentity();
    //    if (w <= h)
    //        gluPerspective(45, (GLfloat)h / (GLfloat)w, 1, 1000);
    //    else
    //        gluPerspective(45, (GLfloat)w / (GLfloat)h, 1, 1000);
    //    glMatrixMode(GL_MODELVIEW);
    //    glutPostRedisplay();
}

// Funcao auxiliar para normalizar um vetor a/|a|
void normalize(float a[3])
{
    double norm = sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
    a[0] /= norm;
    a[1] /= norm;
    a[2] /= norm;
}
// Funcao auxiliar para fazer o produto vetorial entre dois vetores a x b = out
void cross(float a[3], float b[3], float out[3])
{
    out[0] = a[1]*b[2] - a[2]*b[1];
    out[1] = a[2]*b[0] - a[0]*b[2];
    out[2] = a[0]*b[1] - a[1]*b[0];
}

float dot(float a[3], float b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// Aplica a transformacao que coloca o sistema de coordendas local em uma
// posicao do mundo definida por dois pontos a e b e um vetor up. O ponto b sera
// a origem, o vetor BA = A - B sera determinara o novo y, o vetor up definira a
// orientacao do novo z em torno de BA. A matriz de transformacao no opengl eh
// armazanada transposta: m[4][4] = {Xx, Xy, Xz, 0.0, Yx, Yy, Yz, 0.0, Zx, Zy,
// Zz, 0.0, Tx, Ty, Tz, 1.0}
void ChangeCoordSys(GLdouble ax, GLdouble ay, GLdouble az, GLdouble bx,
                    GLdouble by, GLdouble bz, GLdouble upx, GLdouble upy,
                    GLdouble upz) {
    // float x[3], y[3], z[3];
    float z[3];
    float x[3];
    // COLOQUE SEU CODIGO AQUI

    float a[3] = {ax, ay, az};
    float b[3] = {bx, by, bz};
    float y[3] = {ax - bx, ay - by, az - bz};
    

    z[0] = upx;
    z[1] = upy;
    z[2] = upz;

    cross(z, y, x);
    normalize(x);
    normalize(y);
    normalize(z);

    translateMatrix[0][0] = x[0];
    translateMatrix[0][1] = x[1];
    translateMatrix[0][2] = x[2];

    translateMatrix[1][0] = y[0];
    translateMatrix[1][1] = y[1];
    translateMatrix[1][2] = y[2];

    translateMatrix[2][0] = z[0];
    translateMatrix[2][1] = z[1];
    translateMatrix[2][2] = z[2];


    translateMatrix[3][0] = bx;
    translateMatrix[3][1] = by;
    translateMatrix[3][2] = bz;

    glMultMatrixf(&translateMatrix[0][0]);
}

void DrawAxes(double size) {
    GLfloat mat_ambient_r[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient_g[] = {0.0, 1.0, 0.0, 1.0};
    GLfloat mat_ambient_b[] = {0.0, 0.0, 1.0, 1.0};
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, no_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_mat);

    // x axis
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_r);
    glColor3fv(mat_ambient_r);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();

    // y axis
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_g);
    glColor3fv(mat_ambient_g);
    glRotatef(90, 0, 0, 1);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();

    // z axis
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_b);
    glColor3fv(mat_ambient_b);
    glRotatef(-90, 0, 1, 0);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();
}

// ALTERE AQUI - SEU CODIGO AQUI
// Usar meshlab para obter os pontos abaixo
int pontoArmaAponta = 4275;
int pontoPosicaoArma = 2910;
int up[3] = {0, 1, 0};
void desenhaJogador() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    // Translada para o centro do soldado para facilitar a rotacao da camera
    glTranslatef(0, -50, 0);

    soldado.draw();

    if (transformacaoArmaToggle) {
        // ChangeCoordSys(0, 0, 0, 1, 1, 1, 0, 1, 0);
               ChangeCoordSys(soldado.vertsPos[pontoArmaAponta].x,
                              soldado.vertsPos[pontoArmaAponta].y,
                              soldado.vertsPos[pontoArmaAponta].z,
                              soldado.vertsPos[pontoPosicaoArma].x,
                              soldado.vertsPos[pontoPosicaoArma].y,
                              soldado.vertsPos[pontoPosicaoArma].z, up[0],
                              up[1], up[2]);
    }

    if (coordsysToggle == 1)
        DrawAxes(10);
    if (armaToggle == 1)
        arma.draw();
    glPopMatrix();
}

// Aplica a transformacao que modifica o mundo virtual para deixa-lo como se
// tivesse sendo visto da posicao determinada por eye (eyex, eyey, eyez)
// olhando para center (centerx, centery, centerz)
// e orientada em torno do vetor direcional por up (upx, upy, upz)
// A matriz de transformacao no opengl eh armazanada transposta:
// m[4][4] = {Xx, Xy, Xz, 0.0, Yx, Yy, Yz, 0.0, Zx, Zy, Zz, 0.0, Tx, Ty,
// Tz, 1.0}
void MygluLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx,
                 GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy,
                 GLdouble upz) {
    //    float forward[3], side[3], up[3];

    // COLOQUE SEU CODIGO AQUI
    glm::mat4* modelview = &myLookAtMatrix;

    glm::vec3 eye = {eyex, eyey, eyez};
    glm::vec3 look = {centerx, centery, centerz};
    glm::vec3 up = {upx, upy, upz};

    //...

    glMultMatrixf(&myLookAtMatrix[0][0]);
}

void imgui_display() {
    if (imgui_shouldRenderMainWindow) {
        ImGui::Begin("Debug", &imgui_shouldRenderMainWindow);
        ImGui::Text("myLookAt matrix: ");
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", myLookAtMatrix[0][0],
                    myLookAtMatrix[0][1], myLookAtMatrix[0][2],
                    myLookAtMatrix[0][3]);
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", myLookAtMatrix[1][0],
                    myLookAtMatrix[1][1], myLookAtMatrix[1][2],
                    myLookAtMatrix[1][3]);
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", myLookAtMatrix[2][0],
                    myLookAtMatrix[2][1], myLookAtMatrix[2][2],
                    myLookAtMatrix[2][3]);
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", myLookAtMatrix[3][0],
                    myLookAtMatrix[3][1], myLookAtMatrix[3][2],
                    myLookAtMatrix[3][3]);

        ImGui::Text("translate matrix: ");
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", translateMatrix[0][0],
                    translateMatrix[1][0], translateMatrix[2][0],
                    translateMatrix[3][0]);
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", translateMatrix[0][1],
                    translateMatrix[1][1], translateMatrix[2][1],
                    translateMatrix[3][1]);
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", translateMatrix[0][2],
                    translateMatrix[1][2], translateMatrix[2][2],
                    translateMatrix[3][2]);
        ImGui::Text("\t%03.2f %03.2f %03.2f %03.2f\n", translateMatrix[0][3],
                    translateMatrix[1][3], translateMatrix[2][3],
                    translateMatrix[3][3]);
        ImGui::End();
    }
    if (imgui_shouldRenderCameraWindow) {
        ImGui::Begin("Camera", &imgui_shouldRenderCameraWindow);
        ImGui::Text("Camera XY angle: %.3lf", camXYAngle);
        ImGui::Text("Camera XZ angle: %.3lf", camXZAngle);
        ImGui::End();
    }
    if (imgui_shouldRenderLightingWindow) {
        ImGui::Begin("Lighting", &imgui_shouldRenderLightingWindow);
        ImGui::ListBox("Shading Mode", &selectedShadingMode, shadingModes,
                       IM_ARRAYSIZE(shadingModes));
        ImGui::Checkbox("LookAt enabled", &lookatToggle);
        ImGui::Checkbox("TransfGun toggle", &transformacaoArmaToggle);
        ImGui::Checkbox("CoordSys toggle", &coordsysToggle);
        ImGui::Checkbox("Arma toggle", &armaToggle);
        ImGui::End();
    }
}

void drawUI() {
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplGLUT_NewFrame();

    imgui_display();

    ImGui::Render();
    ImGuiIO& io = ImGui::GetIO();
    glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

void display(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (selectedShadingMode == 0)
        glShadeModel(GL_SMOOTH);
    else
        glShadeModel(GL_FLAT);

    // Controla camera
    if (lookatToggle) {
        // Limpa a cor com azulado
        glClearColor(0.30, 0.30, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Utiliza uma esfera de raio cameraZoom para guiar a posicao da camera
        // baseada em dois angulos (do plano XZ e do plano XY)
        gluLookAt(cameraZoom * sin(camXZAngle * M_PI / 180) *
                      cos((camXYAngle * M_PI / 180)),
                  cameraZoom * sin((camXYAngle * M_PI / 180)),
                  cameraZoom * cos(camXZAngle * M_PI / 180) *
                      cos((camXYAngle * M_PI / 180)),
                  0, 0, 0, 0, 1, 0);
    } else {
        // Limpa a cor com azulado
        glClearColor(1.0, 0.30, 0.30, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        MygluLookAt(cameraZoom * sin(camXZAngle * M_PI / 180) *
                        cos((camXYAngle * M_PI / 180)),
                    cameraZoom * sin((camXYAngle * M_PI / 180)),
                    cameraZoom * cos(camXZAngle * M_PI / 180) *
                        cos((camXYAngle * M_PI / 180)),
                    0, 0, 0, 0, 1, 0);
    }

    desenhaJogador();

    // Define e desenha a fonte de luz
    GLfloat light_position[] = {10, 10, 50, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glDisable(GL_LIGHTING);
    glPointSize(15);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex3f(light_position[0], light_position[1], light_position[2]);
    glEnd();
    glEnable(GL_LIGHTING);

    drawUI();
    glutPostRedisplay();
    glutSwapBuffers();
}

void keyPress(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        transformacaoArmaToggle = 1;
        break;
    case '2':
        transformacaoArmaToggle = 2;
        break;
    case 'a':
        armaToggle = !armaToggle;
        break;
    case 'c':
        coordsysToggle = !coordsysToggle;
        break;
    case 'm':
        lookatToggle = !lookatToggle;
        break;
    case '+':
        cameraZoom++;
        break;
    case '-':
        cameraZoom--;
        break;
        //    case 27:
        //        exit(0);
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    ImGui_ImplGLUT_MouseFunc(button, state, x, y);
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        lastX = x;
        lastY = y;
        buttonDown = 1;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        buttonDown = 0;
    }
    if (button == 3) {
        cameraZoom -= 10;
    }
    if (button == 4) {
        cameraZoom += 10;
    }
    glutPostRedisplay();
}

void mouse_motion(int x, int y) {
    ImGui_ImplGLUT_MotionFunc(x, y);

    if (!buttonDown)
        return;

    camXZAngle -= x - lastX;
    camXYAngle += y - lastY;

    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

void imgui_init() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGLUT_Init();
    ImGui_ImplGLUT_InstallFuncs();
    ImGui_ImplOpenGL2_Init();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowSize, windowSize);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Soldado com Arma");

    init();
    imgui_init();

    glutDisplayFunc(display);
    //    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);
    glutMotionFunc(mouse_motion);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
