#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

double spin = 0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
//   glShadeModel (GL_FLAT);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void display(void)
{
   GLfloat position[] = { 0.0, 0.00, 0.0, 1.0 };

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix ();
        glTranslatef (0.0, 0.0, -5.0);

        glPushMatrix ();
            glRotated ((GLdouble) spin, 0.0, 0.0, 1.0);
            glTranslatef (0.0, 1.0, 1.5);
            glLightfv (GL_LIGHT0, GL_POSITION, position);

            glDisable (GL_LIGHTING);
            glColor3f (0.0, 1.0, 1.0);
            glutWireCube (0.1);
            glEnable (GL_LIGHTING);
        glPopMatrix ();

        glutSolidTorus (0.275, 0.45, 20, 25);
   glPopMatrix ();
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void idle()
{
    static GLdouble previousTime = 0;
    GLdouble currentTime;
    GLdouble timeDiference;
    int spinInt;
    double spinDbl;
    double speed = 0.1;
    
    // Elapsed time from the initiation of the game.
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    timeDiference = currentTime - previousTime; // Elapsed time from the previous frame.
    previousTime = currentTime; //Update previous time

    spinDbl = spin + speed*timeDiference;
    spinInt = (int)(spin + speed*timeDiference); 
    spin = spinInt%360 + (spinDbl-(int)spinInt);
    
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutIdleFunc(idle);
   glutMainLoop();
   return 0;
}