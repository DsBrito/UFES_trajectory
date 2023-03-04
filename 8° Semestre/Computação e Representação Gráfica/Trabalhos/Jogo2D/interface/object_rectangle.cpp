
#include "object_rectangle.h"


object_rectangle::object_rectangle() {}

object_rectangle::object_rectangle(GLfloat r_height, GLfloat r_width, GLfloat r_R, GLfloat r_G, GLfloat r_B) {
    retangle_height = r_height;
    retangle_width = r_width;
    retangle_R = r_R;
    retangle_G = r_G;
    retangle_B = r_B;
}

/*________________________________________________________________________________________________________________________________
|Função:                                        desenha retangulo                                                                 |
|---------------------------------------------------------------------------------------------------------------------------------|                                                        
|Comentários:  Seguindo funções dadas em laboratório                                                                              | 
|---------------------------------------------------------------------------------------------------------------------------------|
|Fonte:  display(void) do arquivo quadrado.cpp dado no lab1                                                                       |    
|        Função do laboratório (lab1)     quadrado.cpp -> linha 13..                                                              |
|                                                                                                                                 |
| ________________________________________________________________________________________________________________________________|*/
void object_rectangle::DrawRectangle(){

  /* Limpar todos os pixels  */
  //glClear (GL_COLOR_BUFFER_BIT);

  /* Define cor dos vértices com os valores R, G e B */
  glColor3f (retangle_R, retangle_G, retangle_B);
  /* Desenhar um polígono branco (retângulo) */
    glBegin(GL_POLYGON);
    glVertex2f((retangle_width/2), 0.0 );
    glVertex2f((retangle_width/2), retangle_height );
    glVertex2f(-(retangle_width/2), retangle_height);
    glVertex2f(-(retangle_width/2),0);
    glEnd();
  
}