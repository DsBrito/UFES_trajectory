#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glut.h"
#include "../libs/imgui/imgui_impl_opengl2.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define TAMANHO_JANELA 500
#define MAX_SPLINE_POINTS 99

float size = 5.0;

// Pontos de controle da Spline
GLfloat ctrlpoints[MAX_SPLINE_POINTS][3] = {
    {-4.0, -4.0, 0.0}, {-2.0, 4.0, 0.0}, {2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}};

static int usedControlPoints = 4;
static bool shouldReshape = false;
static bool shouldDrawSpline = true;
static bool shouldDrawControlPoints = true;

static int mouseX = 0;
static int mouseY = 0;
static int windowSizeX = TAMANHO_JANELA;
static int windowSizeY = TAMANHO_JANELA;

static bool imgui_showCoordsWindow = false;
static bool imgui_allowCoordinateEditingOnGUI = false;
static bool imgui_exclusiveMouse = false;
static bool imgui_shouldRenderSplineControls = false;

GLfloat *draggingPoint = NULL;

void mouse(int button, int state, int x, int y);

double distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void updateSplineFunction() {
  // Definicao do polinomio com os pontos de controle
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, usedControlPoints, &ctrlpoints[0][0]);
}

void init(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glEnable(GL_MAP1_VERTEX_3);

  updateSplineFunction();

  // Muda para a matriz de projecao (aulas futuras)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // glOrtho(-size, size, -size, size, -size, size);
  glOrtho(0, 1, 1, 0, 0, 1);
}

void imgui_display() {
  if (imgui_shouldRenderSplineControls) {
    ImGui::Begin("Spline Controls (s)");
    ImGui::Checkbox("Should handle reshape", &shouldReshape);
    ImGui::SliderInt("Spline control count", &usedControlPoints, 2, 99);
    ImGui::Checkbox("Show coordinates window", &imgui_showCoordsWindow);
    ImGui::Checkbox("Allow coordinate editing on GUI",
                    &imgui_allowCoordinateEditingOnGUI);
    ImGui::Checkbox("Draw Spline", &shouldDrawSpline);
    ImGui::Checkbox("Draw ControlPoints", &shouldDrawControlPoints);
    ImGui::BeginDisabled(true);
    ImGui::Checkbox("UI has mouse", &imgui_exclusiveMouse);
    ImGui::EndDisabled();
    ImGui::Text("Mouse X: %d", mouseX);
    ImGui::Text("Mouse Y: %d", mouseY);
    ImGui::Text("Window Size X: %d", windowSizeX);
    ImGui::Text("Window Size Y: %d", windowSizeY);
    ImGui::Text("Mouse X normalized: %lf", (double)mouseX / windowSizeX);
    ImGui::Text("Mouse Y normalized: %lf", (double)mouseY / windowSizeY);
    if (draggingPoint) {
      ImGui::Text("DraggingPoint: (%lf, %lf)", draggingPoint[0],
                  draggingPoint[1]);
    } else {
      ImGui::Text("DraggingPoint: (NULL)");
    }
    ImGui::End();
  }
  if (imgui_showCoordsWindow) {
    for (int i = 0; i < usedControlPoints; i++) {
      ImGui::Begin("Control Point Coordinates");
      ImGui::Text("Point %d", i);
      ImGui::BeginDisabled(!imgui_allowCoordinateEditingOnGUI);
      ImGui::SliderFloat3("Coordinates", &ctrlpoints[i][0], -1, 1);
      ImGui::EndDisabled();
      ImGui::End();
    }
  }
}

void drawSpline() {
  if (!shouldDrawSpline)
    return;
  /* Desenha a curva aproximada por n+1 pontos. */
  int n = 30;
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_LINE_STRIP);
  for (int i = 0; i <= n; i++) {
    // Avaliacao do polinomio, retorna um vertice (equivalente a um glVertex3fv)
    glEvalCoord1f((GLfloat)i / (GLfloat)n);
  }
  glEnd();
}

void drawControlPoints() {
  /* Desenha os pontos de controle. */
  if (!shouldDrawControlPoints)
    return;
  glPointSize(5.0);
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_POINTS);
  for (int i = 0; i < usedControlPoints; i++)
    glVertex3fv(&ctrlpoints[i][0]);
  glEnd();
}

void drawUI() {
  ImGui_ImplOpenGL2_NewFrame();
  ImGui_ImplGLUT_NewFrame();

  imgui_display();

  ImGui::Render();
  ImGuiIO &io = ImGui::GetIO();
  glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
  ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  if (!imgui_exclusiveMouse) {
    glutMouseFunc(mouse);
  }

  updateSplineFunction();
  drawSpline();
  drawControlPoints();
  drawUI();

  glutSwapBuffers();
  glutPostRedisplay();
}

void reshape(int w, int h) {
  windowSizeX = w;
  windowSizeY = h;
  // Define a porcao visivel da janela
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);

  // Muda para a matriz de projecao (aulas futuras)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (shouldReshape) {
    // Controla o redimensionamento da janela mantendo o aspect ration do objeto
    if (w <= h)
      glOrtho(-size, size, -size * (GLfloat)h / (GLfloat)w,
              size * (GLfloat)h / (GLfloat)w, -size, size);
    else
      glOrtho(-size * (GLfloat)w / (GLfloat)h, size * (GLfloat)w / (GLfloat)h,
              -size, size, -size, size);
  }

  // Muda para a matriz de trasformacoes (aulas futuras)
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  ImGui_ImplGLUT_ReshapeFunc(w, h);
}

void mouse(int button, int state, int x, int y) {
  if (imgui_exclusiveMouse) {
    ImGui_ImplGLUT_MouseFunc(button, state, x, y);
    return;
  }

  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      // Arrasta o ponto de controle
      for (int i = 0; i < usedControlPoints; i++) {
        if (distance((double)x / windowSizeX, (double)y / windowSizeY,
                     ctrlpoints[i][0], ctrlpoints[i][1]) < 0.1) {
          draggingPoint = ctrlpoints[i];
          break;
        }
      }
    } else if (state == GLUT_UP) {
      draggingPoint = NULL;
    }
  }
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  // case 27:
  //    exit(0);
  //    break;
  case 'r':
    shouldReshape = !shouldReshape;
    break;
  case 'c':
    imgui_showCoordsWindow = !imgui_showCoordsWindow;
    break;
  case 'e':
    imgui_allowCoordinateEditingOnGUI = !imgui_allowCoordinateEditingOnGUI;
    break;
  case 's':
    imgui_shouldRenderSplineControls = !imgui_shouldRenderSplineControls;
    break;
  case 'm':
    imgui_exclusiveMouse = !imgui_exclusiveMouse;
    break;
  }
}

void imgui_init() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  ImGui::StyleColorsDark();
  ImGui_ImplGLUT_Init();
  ImGui_ImplGLUT_InstallFuncs();
  ImGui_ImplOpenGL2_Init();
}

void initSplinePoints() {
  for (int i = 0; i < 4; i++) {
    ctrlpoints[i][0] = 1 - abs(ctrlpoints[i][0] / size);
    ctrlpoints[i][1] = 1 - abs(ctrlpoints[i][1] / size);
  }
  for (int i = 4; i < MAX_SPLINE_POINTS; i++) {
    ctrlpoints[i][0] = 0;
    ctrlpoints[i][1] = 0;
    ctrlpoints[i][2] = 0;
  }
}

void passiveMouse(int x, int y) {
  mouseX = x;
  mouseY = y;
}

void motion(int x, int y) {
  if (draggingPoint) {
    draggingPoint[0] = (double)x / windowSizeX;
    draggingPoint[1] = (double)y / windowSizeY;
  }
  ImGui_ImplGLUT_MotionFunc(x, y);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(TAMANHO_JANELA, TAMANHO_JANELA);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  initSplinePoints();
  init();
  glutDisplayFunc(display);
  imgui_init();
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutPassiveMotionFunc(passiveMouse);
  glutMotionFunc(motion);
  // glutReshapeFunc(reshape);

  glutMainLoop();
  return 0;
}
