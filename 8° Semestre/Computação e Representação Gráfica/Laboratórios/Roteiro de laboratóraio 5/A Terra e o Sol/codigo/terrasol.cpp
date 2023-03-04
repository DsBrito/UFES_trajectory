#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "imageloader.h"

typedef struct
{
    //Vertex coordinate
    double X;
    double Y;
    double Z;
    
    //Vertex normal 
    double nX;
    double nY;
    double nZ;
    
    //Vertex texture coordinate
    double U;
    double V;
} VERTICES;

typedef struct
{
    VERTICES * vtx;
    int numVtx;
    double radius;
} OBJ;

OBJ* objEarth;
OBJ* objSun;

//Identificadores de textura
GLuint textureEarth;
GLuint textureSun;
GLuint texturePlane;

//Cotroles de giro
double angleDay = 0;
double angleYear = 0;

//Camera controls
double camDist=50;
double camXYAngle=0;
double camXZAngle=0;
int toggleCam = 0;
int camAngle = 60;
int lastX = 0;
int lastY = 0;
int buttonDown=0;

GLuint LoadTextureRAW( const char * filename );

void RasterChars(GLfloat x, GLfloat y, GLfloat z, const char * text, double r, double g, double b)
{
    //Push to recover original attributes
    glPushAttrib(GL_ENABLE_BIT);
        glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        //Draw text in the x, y, z position
        glColor3f(r,g,b);
        glRasterPos3f(x, y, z);
        const char* tmpStr;
        tmpStr = text;
        while( *tmpStr ){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *tmpStr);
            tmpStr++;
        }
    glPopAttrib();
}

void PrintText(GLfloat x, GLfloat y, const char * text, double r, double g, double b)
{
    //Draw text considering a 2D space (disable all 3d features)
    glMatrixMode (GL_PROJECTION);
    //Push to recover original PROJECTION MATRIX
    glPushMatrix();
        glLoadIdentity ();
        glOrtho (0, 1, 0, 1, -1, 1);
        RasterChars(x, y, 0, text, r, g, b);    
    glPopMatrix();
    glMatrixMode (GL_MODELVIEW);
}

void DrawAxes()
{
    GLfloat color_r[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat color_g[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat color_b[] = { 0.0, 0.0, 1.0, 1.0 };

    glPushAttrib(GL_ENABLE_BIT);
        glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
 
        //x axis
        glPushMatrix();
            glColor3fv(color_r);
            glScalef(5, 0.3, 0.3);
            glTranslatef(0.5, 0, 0); // put in one end
            glutSolidCube(1.0);
        glPopMatrix();

        //y axis
        glPushMatrix();
            glColor3fv(color_g);
            glRotatef(90,0,0,1);
            glScalef(5, 0.3, 0.3);
            glTranslatef(0.5, 0, 0); // put in one end
            glutSolidCube(1.0);
        glPopMatrix();

        //z axis
        glPushMatrix();
            glColor3fv(color_b);
            glRotatef(-90,0,1,0);
            glScalef(5, 0.3, 0.3);
            glTranslatef(0.5, 0, 0); // put in one end
            glutSolidCube(1.0);
        glPopMatrix();
    glPopAttrib();
    
}

void DisplayEarth (GLuint texture)
{
    GLfloat materialEmission[] = { 0.10, 0.10, 0.10, 1};
    GLfloat materialColorA[] = { 0.2, 0.2, 0.2, 1};
    GLfloat materialColorD[] = { 1.0, 1.0, 1.0, 1};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1};
    GLfloat mat_shininess[] = { 100.0 };
    glColor3f(1,1,1);
 
    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialColorA);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColorD);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin (GL_TRIANGLE_STRIP);
    for ( int i = 0; i <objEarth->numVtx; i++)
    {
        glNormal3f(objEarth->vtx[i].nX, objEarth->vtx[i].nY, objEarth->vtx[i].nZ);
        glTexCoord2f (objEarth->vtx[i].U, objEarth->vtx[i].V);
        glVertex3f (objEarth->vtx[i].X, objEarth->vtx[i].Y, objEarth->vtx[i].Z);
    }
    glEnd();
}
void DisplayPlane (GLuint texture)
{
    GLfloat materialEmission[] = { 1.0, 1.0, 1.0, 1};
    GLfloat materialColorA[] = { 0.2, 0.2, 0.2, 1};
    GLfloat materialColorD[] = { 1.0, 1.0, 1.0, 1};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1};
    GLfloat mat_shininess[] = { 100.0 };
    glColor3f(1,1,1);

    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialColorA);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColorD);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT  );//X
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );//Y

    glBindTexture (GL_TEXTURE_2D, texture);
    double textureS = 1; // Bigger than 1, repeat
    glBegin (GL_QUADS);
        glNormal3f(0,1,0);
        glTexCoord2f (0, 0);
        glVertex3f (-1, 0, -1);
        glNormal3f(0,1,0);
        glTexCoord2f (0, textureS);
        glVertex3f (-1, 0, +1);
        glNormal3f(0,1,0);
        glTexCoord2f (textureS, textureS);
        glVertex3f (+1, 0, +1);
        glNormal3f(0,1,0);
        glTexCoord2f (textureS, 0);
        glVertex3f (+1, 0, -1);
    glEnd();

}

void DisplaySun (GLuint textureSun)
{
    GLfloat materialEmission[] = { 1.00, 1.00, 0.00, 1};
    GLfloat materialColor[] = { 1.0, 1.0, 0.0, 1};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1};
    GLfloat mat_shininess[] = { 50.0 };
    glColor3f(1,1,0);

    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

    glBindTexture (GL_TEXTURE_2D, textureSun);
    glBegin (GL_TRIANGLE_STRIP);
    for ( int i = 0; i <objSun->numVtx; i++)
    {
        glNormal3f(objSun->vtx[i].nX, objSun->vtx[i].nY, objSun->vtx[i].nZ);
        glTexCoord2f (objSun->vtx[i].U, objSun->vtx[i].V);
        glVertex3f (objSun->vtx[i].X, objSun->vtx[i].Y, objSun->vtx[i].Z);
    }
    glEnd();

}

void crossProduct(
        double uX, double uY, double uZ, 
        double vX, double vY, double vZ, 
        double &oX, double &oY, double &oZ)
{
    oX = uY*vZ - uZ*vY;
    oY = uZ*vX - uX*vZ;
    oZ = uX*vY - uY*vX;
    double norm = sqrt(oX*oX+oY*oY+oZ*oZ);
    oX /= norm;
    oY /= norm;
    oZ /= norm;
}

OBJ * CreateSphere (double R, double space) 
{
    OBJ *obj = new OBJ;
    
    obj->numVtx = (180 / space) * 
                  (2 + 360 / (2*space)) * 4;
    obj->vtx = new VERTICES[ obj->numVtx ];
    obj->radius = R;

    int n;
    double vR, lVR;
    double hR, lHR;
    double norm;
    n = 0;
    for( vR = 0; vR <= 180-space; vR+=space){
        for(hR = 0; hR <= 360+2*space; hR+=2*space)
        {
            lVR = vR;
            lHR = hR;
            obj->vtx[n].X = R * 
                    sin(lHR / 180 * M_PI) * 
                    sin(lVR / 180 * M_PI);
            obj->vtx[n].Y = R * 
                    cos(lHR / 180 * M_PI) * 
                    sin(lVR / 180 * M_PI);
            obj->vtx[n].Z = R * 
                    cos(lVR / 180 * M_PI);
            obj->vtx[n].V = lVR / 180;
            obj->vtx[n].U = lHR / 360;
            norm = sqrt(
                    obj->vtx[n].X*obj->vtx[n].X+
                    obj->vtx[n].Y*obj->vtx[n].Y+
                    obj->vtx[n].Z*obj->vtx[n].Z);
            obj->vtx[n].nX = obj->vtx[n].X/norm;
            obj->vtx[n].nY = obj->vtx[n].Y/norm;
            obj->vtx[n].nZ = obj->vtx[n].Z/norm;
            n++;

            lVR = vR + space;
            lHR = hR;
            obj->vtx[n].X = R * sin(lHR / 180 * M_PI) * sin(lVR / 180 * M_PI);
            obj->vtx[n].Y = R * cos(lHR / 180 * M_PI) * sin(lVR / 180 * M_PI);
            obj->vtx[n].Z = R * cos(lVR / 180 * M_PI);
            obj->vtx[n].V = lVR / 180;
            obj->vtx[n].U = lHR / 360;
            norm = sqrt(obj->vtx[n].X*obj->vtx[n].X+obj->vtx[n].Y*obj->vtx[n].Y+obj->vtx[n].Z*obj->vtx[n].Z);
            obj->vtx[n].nX = obj->vtx[n].X/norm;
            obj->vtx[n].nY = obj->vtx[n].Y/norm;
            obj->vtx[n].nZ = obj->vtx[n].Z/norm;
            n++;

            lVR = vR;
            lHR = hR + space;
            obj->vtx[n].X = R * sin(lHR / 180 * M_PI) * sin(lVR / 180 * M_PI);
            obj->vtx[n].Y = R * cos(lHR / 180 * M_PI) * sin(lVR / 180 * M_PI);
            obj->vtx[n].Z = R * cos(lVR / 180 * M_PI);
            obj->vtx[n].V = lVR / 180;
            obj->vtx[n].U = lHR / 360;
            norm = sqrt(obj->vtx[n].X*obj->vtx[n].X+obj->vtx[n].Y*obj->vtx[n].Y+obj->vtx[n].Z*obj->vtx[n].Z);
            obj->vtx[n].nX = obj->vtx[n].X/norm;
            obj->vtx[n].nY = obj->vtx[n].Y/norm;
            obj->vtx[n].nZ = obj->vtx[n].Z/norm;
            n++;

            lVR = vR + space;
            lHR = hR + space;
            obj->vtx[n].X = R * sin(lHR / 180 * M_PI) * sin(lVR / 180 * M_PI);
            obj->vtx[n].Y = R * cos(lHR / 180 * M_PI) * sin(lVR / 180 * M_PI);
            obj->vtx[n].Z = R * cos(lVR / 180 * M_PI);
            obj->vtx[n].V = lVR / 180;
            obj->vtx[n].U = lHR / 360;
            norm = sqrt(obj->vtx[n].X*obj->vtx[n].X+obj->vtx[n].Y*obj->vtx[n].Y+obj->vtx[n].Z*obj->vtx[n].Z);
            obj->vtx[n].nX = obj->vtx[n].X/norm;
            obj->vtx[n].nY = obj->vtx[n].Y/norm;
            obj->vtx[n].nZ = obj->vtx[n].Z/norm;
            n++;
        }
    }
    return obj;
}

void display (void) {
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (toggleCam == 0){
        PrintText(0.1, 0.1, "Movable Camera", 0,1,0);
        glTranslatef(0,0,-camDist);
        glRotatef(camXZAngle,1,0,0);
        glRotatef(camXYAngle,0,1,0);
    } else if (toggleCam == 1){
        PrintText(0.1, 0.1, "Static Camera at a Distance", 0,1,0);
        gluLookAt(10,10,50, 0,0,0, 0,1,0);
    } else if (toggleCam == 2){
        PrintText(0.1, 0.1, "Sun Camera", 0,1,0);
        gluLookAt(0,0,0, -sin(angleYear/180*M_PI),0,-cos(angleYear/180*M_PI), 0,1,0);
    }

    GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glPushMatrix();
        glScalef(70,70,1);
        glTranslatef(0,0,-12);
        glRotatef(90,1,0,0);
        DisplayPlane (texturePlane);
    glPopMatrix();
    
    if (toggleCam != 2){
        DrawAxes();
        glPushMatrix();
            glRotatef(90,1,0,0);
            DisplaySun(textureSun);
        glPopMatrix();
        RasterChars(0, objSun->radius, 0, "Sun",  0, 1, 0);
    }   
    
    glPushMatrix();
        glRotatef(angleYear,0,1,0);

        glTranslatef(0,0,-10);
        RasterChars(0, objEarth->radius, 0, "Earth",  0, 1, 0);

        glRotatef(angleDay,0,1,0);
        glRotatef(90,1,0,0);
        DisplayEarth(textureEarth);
    glPopMatrix();

    glutSwapBuffers();
}
void init (void) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glShadeModel (GL_SMOOTH);

    glDepthFunc(GL_LEQUAL);

    textureEarth = LoadTextureRAW( "earth.bmp" );
    textureSun = LoadTextureRAW( "sun1.bmp" );
    texturePlane = LoadTextureRAW( "stars1.bmp" );
            
    objEarth = CreateSphere(3, 10);
    objSun = CreateSphere(3, 10);
    glEnable(GL_LIGHT0);
}

void changeCamera(int angle, int w, int h)
{
    glMatrixMode (GL_PROJECTION);

    glLoadIdentity ();

    gluPerspective (angle, 
            (GLfloat)w / (GLfloat)h, 1, 150.0);

    glMatrixMode (GL_MODELVIEW);
}

void reshape (int w, int h) {

    glViewport (0, 0, (GLsizei)w, (GLsizei)h);

    changeCamera(camAngle, w, h);
}

void mouse_callback(int button, int state, int x, int y) 
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lastX = x;
        lastY = y;
        buttonDown = 1;
    } 
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        buttonDown = 0;
    }
}

void mouse_motion(int x, int y)
{
    if (!buttonDown)
        return;
    
    camXYAngle += x - lastX;
    camXZAngle += y - lastY;
    
    camXYAngle = (int)camXYAngle % 360;
    camXZAngle = (int)camXZAngle % 360;
    
    lastX = x;
    lastY = y;
}

void idle()
{
    angleDay+=0.05;
    angleYear+=0.01;
    
    if (angleDay > 360) angleDay = 0;
    else if (angleDay < 0) angleDay = 360;

    if (angleYear > 360) angleYear = 0;
    else if (angleYear < 0) angleYear = 360;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    static bool textureEnebled = true;
    static bool lightingEnebled = true;
    static bool smoothEnebled = true;
    switch (key) {
        case '1':
            toggleCam = 0;
            break;
        case '2':
            toggleCam = 1;
            break;
        case '3':
            toggleCam = 2;
            break;
        case 't':
            if ( textureEnebled ){
                glDisable( GL_TEXTURE_2D );
            }else{
                glEnable( GL_TEXTURE_2D );
            }
            textureEnebled = !textureEnebled; 
            break;
        case 'l':
            if ( lightingEnebled ){
                glDisable( GL_LIGHTING );
            }else{
                glEnable( GL_LIGHTING );
            }
            lightingEnebled = !lightingEnebled; 
            break;
        case 's':
            if ( smoothEnebled ){
                glShadeModel (GL_FLAT);
            }else{
                glShadeModel (GL_SMOOTH);
            }
            smoothEnebled = !smoothEnebled; 
            break;
        case '+':
        {
            int inc = camAngle >= 180 ? 0 : 1;
            camAngle += inc;
            changeCamera(camAngle, 
                    glutGet(GLUT_WINDOW_WIDTH), 
                    glutGet(GLUT_WINDOW_HEIGHT));
            break;
        }
        case '-':
        {
            int inc = camAngle <= 5 ? 0 : 1;
            camAngle -= inc;
            changeCamera(camAngle, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
            break;
        }
        case 27:
            exit(0);
            break;
    }
}

int main (int argc, char **argv) {

    glutInit (&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize (500, 500);

    glutInitWindowPosition (100, 100);

    glutCreateWindow ("A Terra e o Sol");

    init();

    glutDisplayFunc (idle);

    glutIdleFunc (display);

    glutReshapeFunc (reshape);
    
    glutKeyboardFunc(keyboard);
    
    glutMotionFunc(mouse_motion);
    glutMouseFunc(mouse_callback);

    glutMainLoop ();

    return 0;
}
GLuint LoadTextureRAW( const char * filename )
{

    GLuint texture;
    
    Image* image = loadBMP(filename);

    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
//    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                             0,                            //0 for now
                             GL_RGB,                       //Format OpenGL uses for image
                             image->width, image->height,  //Width and height
                             0,                            //The border of the image
                             GL_RGB, //GL_RGB, because pixels are stored in RGB format
                             GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                                               //as unsigned numbers
                             image->pixels);               //The actual pixel data
    delete image;

    return texture;
}