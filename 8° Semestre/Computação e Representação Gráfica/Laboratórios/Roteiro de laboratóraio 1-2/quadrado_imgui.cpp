#include "../libs/imgui/imgui.h"
#include "../libs/imgui/imgui_impl_glut.h"
#include "../libs/imgui/imgui_impl_opengl2.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

#define TAMANHO_JANELA 500

static ImVec4 clear_color = ImVec4(0.0f, 1.0f, 1.0f, 1.00f);
static ImVec4 square_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

static ImVec2 bot_left = ImVec2(0.25, 0.25);
static ImVec2 top_left = ImVec2(0.25, 0.75);
static ImVec2 top_right = ImVec2(0.75, 0.75);
static ImVec2 bot_right = ImVec2(0.75, 0.25);

static bool shouldClear = true;

static const char *items[]{
    "GL_POLYGON",        "GL_QUADS",        "GL_LINES",
    "GL_LINE_STRIP",     "GL_LINE_LOOP",    "GL_TRIANGLES",
    "GL_TRIANGLE_STRIP", "GL_TRIANGLE_FAN", "GL_QUAD_STRIP"};
static int selectedItem = 0;

void imgui_display() {
  {
    float fBotLeft[2] = {bot_left.x, bot_left.y};
    float fTopLeft[2] = {top_left.x, top_left.y};
    float fTopRight[2] = {top_right.x, top_right.y};
    float fBotRight[2] = {bot_right.x, bot_right.y};
    ImGui::Begin("Controls");
    ImGui::ColorEdit3("Square Color", (float *)&square_color);
    ImGui::ColorEdit3("Background Color", (float *)&clear_color);
    ImGui::Text("Rectangle coordinates [X, Y]");
    ImGui::SliderFloat2("Bottom Left", &fBotLeft[0], 0.0f, 1.0f);
    ImGui::SliderFloat2("Top Left", &fTopLeft[0], 0.0f, 1.0f);
    ImGui::SliderFloat2("Top Right", &fTopRight[0], 0.0f, 1.0f);
    ImGui::SliderFloat2("Bottom Right", &fBotRight[0], 0.0f, 1.0f);
    ImGui::Checkbox("Clear background?", &shouldClear);

    ImGui::ListBox("Rectangle draw mode", &selectedItem, items,
                   IM_ARRAYSIZE(items));

    ImGui::End();
    bot_left.x = fBotLeft[0];
    bot_left.y = fBotLeft[1];

    top_left.x = fTopLeft[0];
    top_left.y = fTopLeft[1];

    top_right.x = fTopRight[0];
    top_right.y = fTopRight[1];

    bot_right.x = fBotRight[0];
    bot_right.y = fBotRight[1];
  }
}

void drawSquare() {
  /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
  glColor4f(square_color.x, square_color.y, square_color.z, square_color.w);
  /* Desenhar um polígono branco (retângulo) */
  switch (selectedItem) {
  case 0:
    glBegin(GL_POLYGON);
    break;
  case 1:
    glBegin(GL_QUADS);
    break;
  case 2:
    glBegin(GL_LINES);
    break;
  case 3:
    glBegin(GL_LINE_STRIP);
    break;
  case 4:
    glBegin(GL_LINE_LOOP);
    break;
  case 5:
    glBegin(GL_TRIANGLES);
    break;
  case 6:
    glBegin(GL_TRIANGLE_STRIP);
    break;
  case 7:
    glBegin(GL_TRIANGLE_FAN);
    break;
  case 8:
    glBegin(GL_QUAD_STRIP);
    break;
  default:
    glBegin(GL_POLYGON);
    break;
  }
  glVertex3f(bot_left.x, bot_left.y, 0.0);
  glVertex3f(bot_right.x, bot_right.y, 0.0);
  glVertex3f(top_right.x, top_right.y, 0.0);
  glVertex3f(top_left.x, top_left.y, 0.0);
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
  /* Limpar todos os pixels  */
  glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
  if (shouldClear) {
    glClear(GL_COLOR_BUFFER_BIT);
  }

  drawSquare();
  drawUI();

  /* Desenhar no frame buffer! */
  glutSwapBuffers(); // Funcao apropriada para janela double buffer
  glutPostRedisplay();
}

void init(void) {
  /* selecionar cor de fundo (preto) */
  glClearColor(0.0, 0.0, 0.0, 0.0);

  /* inicializar sistema de visualizacao */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(TAMANHO_JANELA, TAMANHO_JANELA);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("hello world");
  init();
  glutDisplayFunc(display);

  imgui_init();

  glutMainLoop();

  ImGui_ImplOpenGL2_Shutdown();
  ImGui_ImplGLUT_Shutdown();
  ImGui::DestroyContext();

  return 0;
}
