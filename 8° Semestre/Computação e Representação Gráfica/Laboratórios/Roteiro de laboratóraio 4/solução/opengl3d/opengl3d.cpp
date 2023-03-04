#include "../../libs/glm/glm.hpp"
#include "../../libs/imgui/imgui.h"
#include "../../libs/imgui/imgui_impl_glut.h"
#include "../../libs/imgui/imgui_impl_opengl2.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>

static int windowSize = 1000;

static bool imgui_shouldRenderMainWindow = true;
static bool imgui_shouldRenderCameraSettings = true;
static bool imgui_shouldRenderLightSettings = true;

static bool lightEnabled = true;
static bool enableCameraPerspective = true;
static bool shouldUpdateCameraRenderingMode = false;

static glm::vec3 cubeDiffuse = {1, 1, 0};
static glm::vec3 cubeSpecular = {1, 1, 1};
static glm::vec3 cubeEmission = {0, 0, 0};
static glm::vec3 cubeRotation = {0, 0, 0};

static glm::vec3 lightPosition = {0, 3, 10};

static glm::vec3 cameraPosition = {0, 2, 5};
static glm::vec3 cameraLookAt = {0, 0, 0};
static glm::vec3 cameraUp = {0, 1, 0};

static const char* shadingModes[]{"GL_SMOOTH", "GL_FLAT"};
static int selectedShadingMode = 0;

static const char* solidShapes[]{"CUBE",        "SPHERE",       "CONE",
                                 "TORUS",       "DODECAHEDRON", "OCTAHEDRON",
                                 "TETRAHEDRON", "ICOSAHEDRON",  "TEAPOT"};

static int selectedSolidShape = 0;

void init(int windowSize) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // glShadeModel (GL_FLAT);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, (GLsizei)windowSize, (GLsizei)windowSize);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //    glOrtho(-3, 3, -3 * (GLfloat)windowSize / (GLfloat)windowSize,
    //            3 * (GLfloat)windowSize / (GLfloat)windowSize, 1.0, 15.0);
    gluPerspective(50, (GLfloat)windowSize / (GLfloat)windowSize, 1, 15);
}

void imgui_display() {
    if (imgui_shouldRenderMainWindow) {
        ImGui::Begin("Debug", &imgui_shouldRenderMainWindow);
        ImGui::SliderFloat3("Cube Rotation", (float*)&cubeRotation, 0.0, 180);
        ImGui::ColorEdit3("Cube Diffuse", (float*)&cubeDiffuse);
        ImGui::ColorEdit3("Cube Specular", (float*)&cubeSpecular);
        ImGui::ColorEdit3("Cube Emission", (float*)&cubeEmission);
        ImGui::ListBox("Shading Mode", &selectedShadingMode, shadingModes,
                       IM_ARRAYSIZE(shadingModes));
        ImGui::ListBox("Solid Shape", &selectedSolidShape, solidShapes,
                       IM_ARRAYSIZE(solidShapes));
        ImGui::End();
    }
    if (imgui_shouldRenderLightSettings) {
        ImGui::Begin("Light Settings", &imgui_shouldRenderLightSettings);
        ImGui::SliderFloat3("Light Position", (float*)&lightPosition, -10, 10);
        if (ImGui::Button("Toggle Lighting")) {
            lightEnabled = !lightEnabled;
        }
        ImGui::End();
    }

    if (imgui_shouldRenderCameraSettings) {
        static bool enableInputControls = false;
        ImGui::Begin("Camera Settings", &imgui_shouldRenderCameraSettings);
        ImGui::Checkbox("Enable Input Controls", &enableInputControls);
        {
            if (enableInputControls) {
                ImGui::InputFloat3("Camera Position", (float*)&cameraPosition);
            } else {
                ImGui::SliderFloat3("Camera Position", (float*)&cameraPosition,
                                    -10, 10);
            }
        }
        {
            if (enableInputControls) {
                ImGui::InputFloat3("Camera Look At", (float*)&cameraLookAt);
            } else {
                ImGui::SliderFloat3("Camera Look At", (float*)&cameraLookAt,
                                    -10, 10);
            }
        }
        {
            if (enableInputControls) {
                ImGui::InputFloat3("Camera Up", (float*)&cameraUp);
            } else {
                ImGui::SliderFloat3("Camera Up", (float*)&cameraUp, -1, 1);
            }
        }
        ImGui::Text("Current Camera mode: %s\n",
                    enableCameraPerspective ? "Perspective" : "Orthographic");
        if (ImGui::Button("Toggle Perspective")) {
            shouldUpdateCameraRenderingMode = true;
            enableCameraPerspective = !enableCameraPerspective;
            glutPostRedisplay();
        }
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

void DrawAxes(double size) {
    GLfloat mat_ambient_r[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient_g[] = {0.0, 1.0, 0.0, 1.0};
    GLfloat mat_ambient_b[] = {0.0, 0.0, 1.0, 1.0};
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, no_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_mat);

    // x axis red
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_r);
    glColor3fv(mat_ambient_r);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();

    // y axis green
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_g);
    glColor3fv(mat_ambient_g);
    glRotatef(90, 0, 0, 1);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();

    // z axis blue
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_b);
    glColor3fv(mat_ambient_b);
    glRotatef(-90, 0, 1, 0);
    glScalef(size, size * 0.1, size * 0.1);
    glTranslatef(0.5, 0, 0); // put in one end
    glutSolidCube(1.0);
    glPopMatrix();
}

void DrawObj(double size) {
    //    GLfloat materialEmission[] = {0.00, 0.00, 0.00, 1.0};
    //    GLfloat materialColor[] = {1.0, 1.0, 0.0, 1.0};
    //    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    //    GLfloat mat_shininess[] = {128};

    GLfloat matEmission[] = {cubeEmission.r, cubeEmission.g, cubeEmission.b,
                             1.0};

    GLfloat matDiffuse[] = {cubeDiffuse.r, cubeDiffuse.g, cubeDiffuse.b, 1.0};

    GLfloat matSpecular[] = {cubeSpecular.r, cubeSpecular.g, cubeSpecular.b,
                             1.0};

    GLfloat matShininess[] = {128};

    glRotatef(cubeRotation.x, 1, 0, 0);
    glRotatef(cubeRotation.y, 0, 1, 0);
    glRotatef(cubeRotation.z, 0, 0, 1);

    glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matDiffuse);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
    glColor3f(1, 0, 0);
    switch (selectedSolidShape) {
    case 0:
        glutSolidCube(size);
        break;
    case 1:
        glutSolidSphere(size, 20, 20);
        break;
    case 2:
        glutSolidCone(size, size * 2, 20, 20);
        break;
    case 3:
        glutSolidTorus(size, size * 2, 20, 20);
        break;
    case 4:
        glutSolidDodecahedron();
        break;
    case 5:
        glutSolidOctahedron();
        break;
    case 6:
        glutSolidTetrahedron();
        break;
    case 7:
        glutSolidIcosahedron();
        break;
    case 8:
        glutSolidTeapot(size);
        break;
    default:
        break;
    }
    //   glutSolidSphere(size, 20, 10);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (shouldUpdateCameraRenderingMode) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        shouldUpdateCameraRenderingMode = false;
        if (enableCameraPerspective) {
            gluPerspective(50, (GLfloat)windowSize / (GLfloat)windowSize, 1,
                           15);
        } else {
            glOrtho(-3, 3, -3 * (GLfloat)windowSize / (GLfloat)windowSize,
                    3 * (GLfloat)windowSize / (GLfloat)windowSize, 1.0, 15.0);
        }
    }

    if (lightEnabled) {
        glEnable(GL_LIGHTING);
    } else {
        glDisable(GL_LIGHTING);
    }

    switch (selectedShadingMode) {
    case 0:
        glShadeModel(GL_SMOOTH);
        break;
    case 1:
        glShadeModel(GL_FLAT);
        break;
    default:
        break;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z,
              cameraLookAt.x, cameraLookAt.y, cameraLookAt.z, cameraUp.x,
              cameraUp.y, cameraUp.z);
    //    gluLookAt(
    //        cameraPosition.x, cameraPosition.y, cameraPosition.z,
    //        cameraPosition.x + cameraLookAt.x, cameraPosition.y +
    //        cameraLookAt.y, cameraPosition.z + cameraLookAt.z, cameraUp.x,
    //        cameraUp.y, cameraUp.z);
    //    GLfloat light_position[] = {0.0, 3.0, 10.0, 1.0};
    GLfloat lPosition[] = {lightPosition.x, lightPosition.y, lightPosition.z,
                           1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lPosition);

    DrawAxes(1.5);

    DrawObj(1.0);

    drawUI();

    glutPostRedisplay();
    glutSwapBuffers();
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
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init(windowSize);
    imgui_init();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
