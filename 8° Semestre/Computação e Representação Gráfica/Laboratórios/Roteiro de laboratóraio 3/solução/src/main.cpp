#include "../../libs/imgui/imgui.h"
#include "../../libs/imgui/imgui_impl_glut.h"
#include "../../libs/imgui/imgui_impl_opengl2.h"
#include "../include/alvo.h"
#include "../include/robo.h"
#include "../include/utils.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define INC_KEY 1
#define INC_KEYIDLE 0.1

// Key status
int keyStatus[256];

// Window dimensions
const GLint Width = 700;
const GLint Height = 700;

// Viewing dimensions
const GLint ViewingWidth = 500;
const GLint ViewingHeight = 500;

// Controla a animacao do robo
int animate = 0;

// Componentes do mundo virtual sendo modelado
Robo robo;         // Um rodo
Tiro* tiro = NULL; // Um tiro por vez
Alvo alvo(0, 200); // Um alvo por vez

static bool imgui_shouldRenderTransformationMatrices = false;
static bool imgui_shouldRenderMainWindow = false;

static bool shouldPreserveFramerateSpeed = true;
static GLdouble framerate = 0;

static int hits = 0;
static char str[999];
void* font = GLUT_BITMAP_9_BY_15;

void printScore(GLfloat x, GLfloat y) {
    glColor3f(1.0, 1.0, 1.0);
    char* tmpString;
    sprintf(str, "Atingido: %d", hits);
    glRasterPos2f(x, y);
    tmpString = str;
    while (*tmpString) {
        glutBitmapCharacter(font, *tmpString);
        tmpString++;
    }
}

void imgui_display() {
    if (imgui_shouldRenderMainWindow) {
        GLfloat tiroX = 0, tiroY = 0, gVel = 0, gAng = 0;
        if (tiro) {
            tiro->GetPos(tiroX, tiroY);
            tiro->getDirectionAng(gAng);
            tiro->getVel(gVel);
        }
        ImGui::Begin("Robô", &imgui_shouldRenderMainWindow);
        ImGui::Text("Framerate: %.2f", framerate);
        ImGui::Text("Posição: %f, %f", robo.ObtemX(), robo.ObtemY());
        ImGui::Text("Tiro:\n\tx: %f\n\ty: %f\n\ttheta: %f\n\tvel:%f\n\t", tiroX,
                    tiroY, gAng, gVel);
        ImGui::Text("Theta1: %f", robo.ObtemTheta1());
        ImGui::Text("Theta2: %f", robo.ObtemTheta2());
        ImGui::Text("Theta3: %f", robo.ObtemTheta3());
        ImGui::Checkbox("Show Transformations",
                        &imgui_shouldRenderTransformationMatrices);
        ImGui::Checkbox("Preserve Framerate Speed",
                        &shouldPreserveFramerateSpeed);
        ImGui::End();
    }

    if (imgui_shouldRenderTransformationMatrices) {
        ImGui::Begin("Transformation Matrices",
                     &imgui_shouldRenderTransformationMatrices);
        ImGui::BeginTabBar("Transformation Tabs");
        std::vector<std::string> availableMatrices = Utils::getIDs();

        for (std::string id : availableMatrices) {
            if (ImGui::BeginTabItem(id.c_str())) {
                float* transfMatrix = Utils::get(id);
                ImGui::Text("%f, %f, %f, %f", transfMatrix[0], transfMatrix[1],
                            transfMatrix[2], transfMatrix[3]);
                ImGui::Text("%f, %f, %f, %f", transfMatrix[4], transfMatrix[5],
                            transfMatrix[6], transfMatrix[7]);
                ImGui::Text("%f, %f, %f, %f", transfMatrix[8], transfMatrix[9],
                            transfMatrix[10], transfMatrix[11]);
                ImGui::Text("%f, %f, %f, %f", transfMatrix[12],
                            transfMatrix[13], transfMatrix[14],
                            transfMatrix[15]);
                ImGui::EndTabItem();
            }
        }

        ImGui::EndTabBar();

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

void renderScene(void) {
    // Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT);

    Utils::getIDs();

    robo.Desenha();

    if (tiro)
        tiro->Desenha();

    alvo.Desenha();

    printScore(-240, -240);

    drawUI();

    glutSwapBuffers(); // Desenha the new frame of the game.
    glutPostRedisplay();
}

void keyPress(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        animate = !animate;
        break;
    case 'a':
    case 'A':
        keyStatus[(int)('a')] = 1; // Using keyStatus trick
        break;
    case 'd':
    case 'D':
        keyStatus[(int)('d')] = 1; // Using keyStatus trick
        break;
    case 'f':
    case 'F':
        robo.RodaBraco1(-INC_KEY); // Without keyStatus trick
        break;
    case 'r':
    case 'R':
        robo.RodaBraco1(+INC_KEY); // Without keyStatus trick
        break;
    case 'g':
    case 'G':
        robo.RodaBraco2(-INC_KEY); // Without keyStatus trick
        break;
    case 't':
    case 'T':
        robo.RodaBraco2(+INC_KEY); // Without keyStatus trick
        break;
    case 'h':
    case 'H':
        robo.RodaBraco3(-INC_KEY); // Without keyStatus trick
        break;
    case 'y':
    case 'Y':
        robo.RodaBraco3(+INC_KEY); // Without keyStatus trick
        break;
    case ' ':
        if (!tiro)
            tiro = robo.Atira();
        break;
    case '9':
        imgui_shouldRenderTransformationMatrices =
            !imgui_shouldRenderTransformationMatrices;
        break;
    case '0':
        imgui_shouldRenderMainWindow = !imgui_shouldRenderMainWindow;
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
    ImGui_ImplGLUT_KeyboardFunc(key, x, y);
}

void keyup(unsigned char key, int x, int y) {
    keyStatus[(int)(key)] = 0;
    glutPostRedisplay();
    ImGui_ImplGLUT_KeyboardUpFunc(key, x, y);
}

void ResetKeyStatus() {
    int i;
    // Initialize keyStatus
    for (i = 0; i < 256; i++)
        keyStatus[i] = 0;
}

void init(void) {
    ResetKeyStatus();
    // The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).

    glMatrixMode(GL_PROJECTION);  // Select the projection matrix
    glOrtho(-(ViewingWidth / 2),  // X coordinate of left edge
            (ViewingWidth / 2),   // X coordinate of right edge
            -(ViewingHeight / 2), // Y coordinate of bottom edge
            (ViewingHeight / 2),  // Y coordinate of top edge
            -100,                 // Z coordinate of the “near” plane
            100);                 // Z coordinate of the “far” plane
    glMatrixMode(GL_MODELVIEW);   // Select the projection matrix
    glLoadIdentity();
}

void idle(void) {
    static GLdouble prevTime = glutGet(GLUT_ELAPSED_TIME);
    GLdouble curTime, deltaTime;
    curTime = glutGet(GLUT_ELAPSED_TIME);
    deltaTime = curTime - prevTime;
    prevTime = curTime;
    framerate = 1.0 / deltaTime * 1000;

    double inc = INC_KEYIDLE;
    if (!shouldPreserveFramerateSpeed) {
        deltaTime = 1;
    }
    // Treat keyPress
    if (keyStatus[(int)('a')]) {
        robo.MoveEmX(-inc, deltaTime);
    }
    if (keyStatus[(int)('d')]) {
        robo.MoveEmX(inc, deltaTime);
    }

    // Trata o tiro (soh permite um tiro por vez)
    // Poderia usar uma lista para tratar varios tiros
    if (tiro) {
        tiro->Move(deltaTime);

        // Trata colisao
        if (alvo.Atingido(tiro)) {
            hits++;
            alvo.Recria(rand() % 500 - 250, 200);
            delete tiro;
            tiro = NULL;
            return;
        }
        if (!tiro->Valido()) {
            delete tiro;
            tiro = NULL;
        }
    }

    // Control animation
    if (animate) {
        static int dir = 1;
        if (robo.ObtemX() > (ViewingWidth / 2)) {
            dir *= -1;
        } else if (robo.ObtemX() < -(ViewingWidth / 2)) {
            dir *= -1;
        }
        robo.MoveEmX(dir * INC_KEYIDLE, deltaTime);
    }

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

int main(int argc, char* argv[]) {
    // Initialize openGL with Double buffer and RGB color without transparency.
    // Its interesting to try GLUT_SINGLE instead of GLUT_DOUBLE.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Create the window.
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("Tranformations 2D");

    init();
    imgui_init();

    // Define callbacks.
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyPress);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyup);

    glutMainLoop();

    return 0;
}
