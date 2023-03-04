#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#define TAMANHO_JANELA 500

float size = 5.0;
int amostra = 30;
int escolha = 0;
int set = 0;

//Pontos de controle da Spline
GLfloat ctrlpoints[4][3] = {
        { -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
        {2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}};

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);

   //Definicao do polinomio com os pontos de controle
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);

   //Muda para a matriz de projecao (aulas futuras)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-size, size, -size, size, -size, size);
}

void display(void)
{
   int i;

   glClear(GL_COLOR_BUFFER_BIT);

   /* Desenha a curva aproximada por n+1 pontos. */
   int n = amostra;
   glColor3f(1.0, 1.0, 1.0);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= n; i++){
        //Avaliacao do polinomio, retorna um vertice (equivalente a um glVertex3fv)
        glEvalCoord1f((GLfloat) i/(GLfloat)n);
      }
   glEnd();

   /* Desenha os pontos de controle. */
   glPointSize(5.0);
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POINTS);
      for (i = 0; i < 4; i++)
         glVertex3fv(&ctrlpoints[i][0]);
   glEnd();

   glutSwapBuffers();
}

void reshape(int w, int h)
{
   //Define a porcao visivel da janela
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);

   //Muda para a matriz de projecao (aulas futuras)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   //Controla o redimensionamento da janela mantendo o aspect ration do objeto
   if (w <= h)
      glOrtho(-size, size, -size*(GLfloat)h/(GLfloat)w,
               size*(GLfloat)h/(GLfloat)w, -size, size);
   else
      glOrtho(-size*(GLfloat)w/(GLfloat)h,
               size*(GLfloat)w/(GLfloat)h, -size, size, -size, size);

   //Muda para a matriz de trasformacoes (aulas futuras)
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void escolhe(int button, int state,int x, int y){
  float a,b;
  a = -250 + (float)x;
  b = 250 - (float)y;
  b = b/50;
  a = a/50;
  float comparapositx[4];
  float comparaposity[4];
  for(int i = 0; i < 4 ; i++ ){
    comparapositx[i] = a - ctrlpoints[i][0];
    comparaposity[i]= b - ctrlpoints[i][1];
    if(comparapositx[i] < 0){
      comparapositx[i] = comparapositx[i]*-1;
    }
    if(comparaposity[i] < 0){
      comparaposity[i] = comparaposity[i]*-1;
    }
    if(comparapositx[i] < 0.1 && comparaposity[i] < 0.1){
      escolha = i;
      set = 1;
    }
    printf("%d\n", escolha);
}
if(state == GLUT_UP){
  set = 0;
}
}
void arrasta(int x , int y){
    float a,b;
    a = -250 + (float)x;
    b = 250 - (float)y;
    b = b/50;
    a = a/50;
    /*float comparapositx[4];
    float comparaposity[4];
    for(int i = 0; i < 4 ; i++ ){
      if(a > 5.0 || a < -5.0 || b > 5.0 || b < -5.0){
        break;
      }
      comparapositx[i] = a - ctrlpoints[i][0];
      comparaposity[i]= b - ctrlpoints[i][1];
      if(comparapositx[i] < 0){
        comparapositx[i] = comparapositx[i]*-1;
      }
      if(comparaposity[i] < 0){
        comparaposity[i] = comparaposity[i]*-1;
      }
      if(comparapositx[i] < 0.1 && comparaposity[i] < 0.1){
        ctrlpoints[i][0] = a;
        ctrlpoints[i][1] = b;
      }
    }*/
    if(set==1){
    ctrlpoints[escolha][0] = a;
    ctrlpoints[escolha][1] = b;
  }


    //printf("%d,%d posicao inteiro \n  %f,%f posicao float ajustada\n", x,y,a,b);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
    //display();
    glutPostRedisplay();


}
void teclado (unsigned char key, int x, int y){
    if(key == '-'){
        if(amostra > 2){
          amostra --;
        }
    }
    else if( key == '+'){
      if(amostra < 100){
        amostra++;
      }
    }
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutMouseFunc(escolhe);
   glutMotionFunc(arrasta);
   glutKeyboardFunc(teclado);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
