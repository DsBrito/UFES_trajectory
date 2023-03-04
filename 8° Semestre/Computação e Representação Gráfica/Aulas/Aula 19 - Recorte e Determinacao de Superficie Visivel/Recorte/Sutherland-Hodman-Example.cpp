#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <stdio.h>
 
typedef struct{
    double x;
    double y;
} Point;

std::vector<Point> points;

typedef int OutCode;
 
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

//Clipping rectangle
double gxmin = 100, gymin = 100, gxmax = 400, gymax = 400;

void drawPolygon( std::vector<Point> points, float R, float G, float B)
{
     glColor3f(R,G,B);
 
     glBegin(GL_LINE_LOOP);
        for(int i = 0; i < points.size(); i++){
            glVertex2f( points[i].x, points[i].y );               
        }
     glEnd();
}

void drawRect(
        double xmin, double ymin, double xmax, double ymax, 
        float R, float G, float B)
{
     glColor3f(R,G,B);
 
     glBegin(GL_LINE_LOOP);
          glVertex2f( xmin, ymin);               
          glVertex2f( xmax, ymin);               
          glVertex2f( xmax, ymax);               
          glVertex2f( xmin, ymax);               
     glEnd();
}

// Compute the bit code for a point (x, y) using the clip rectangle
// bounded diagonally by (xmin, ymin), and (xmax, ymax)
OutCode ComputeOutCode(
        double x, double y, 
        double xmin, double ymin, double xmax, double ymax)
{
	OutCode code;
 
	code = INSIDE;          // initialised as being inside of clip window
 
	if (x < xmin)           // to the left of clip window
		code |= LEFT;
	else if (x > xmax)      // to the right of clip window
		code |= RIGHT;
	if (y < ymin)           // below the clip window
		code |= BOTTOM;
	else if (y > ymax)      // above the clip window
		code |= TOP;
 
	return code;
}
//Check whether a point p is "inside" (side of the rectangle) the line defined 
//by a chosen edge of the clipping rectangle
int isInside(
        Point p, 
        double xmin, double ymin, double xmax, double ymax, 
        int edgePlane)
{
    if (edgePlane == 1){
        return p.x < xmax;
    } else if (edgePlane == 2){
        return p.y < ymax;
    } else if (edgePlane == 3){
        return p.x > xmin;
    } else if (edgePlane == 4){
        return p.y > ymin;
    } 
        
}

//Return the intersection point between the line defined by p0 e p1 and the 
//line defined by a chosen edge of the clipping rectangle
Point intersectionPoint(
        Point p0, Point p1, 
        double xmin, double ymin, double xmax, double ymax, 
        int edgePlane)
{
    double dx = (p1.x-p0.x);
    double dy = (p1.y-p0.y);
    Point p;
    if (edgePlane == 1){
        p.x = xmax;
        p.y = p0.y + (dx != 0 ? (p.x-p0.x)*dy/dx : 0);
    } else if (edgePlane == 2){
        p.y = ymax;
        p.x = p0.x + (dy != 0 ? (p.y-p0.y)*dx/dy : 0);
    } else if (edgePlane == 3){
        p.x = xmin;
        p.y = p0.y + (dx != 0 ? (p.x-p0.x)*dy/dx : 0);
    } else if (edgePlane == 4){
        p.y = ymin;
        p.x = p0.x + (dy != 0 ? (p.y-p0.y)*dx/dy : 0);
    } 
    return p;
}

//Clip polygon formed by the points pts using a chosen edge plane from the 
// clipping rectangle
std::vector<Point> SutherlandHodgmanPerPlane(
        std::vector<Point> pts, 
        double xmin, double ymin, double xmax, double ymax, 
        int edgePlane)
{
    Point Pi, Pi_1;
    std::vector<Point> outP;
    for (int i = 0; i < pts.size(); i++){
         Pi = pts[i];
         Pi_1 = pts[(i+1)%pts.size()];
         if ( isInside(Pi, xmin, ymin, xmax, ymax, edgePlane) ){
              if ( isInside(Pi_1, xmin, ymin, xmax, ymax, edgePlane) ){
                   outP.push_back(Pi_1);
              } else {
                   Point p;
                   p = intersectionPoint(Pi, Pi_1, xmin, ymin, xmax, ymax, edgePlane);
                   outP.push_back(p);
              }
         } else {
              if ( isInside(Pi_1, xmin, ymin, xmax, ymax, edgePlane) ){
                   Point p;
                   p = intersectionPoint(Pi, Pi_1, xmin, ymin, xmax, ymax, edgePlane);
                   outP.push_back(p);
                   outP.push_back(Pi_1);
              }
         }
    }
    return outP;
}

//Clip polygon formed by the points pts using all four clipping planes 
std::vector<Point> SutherlandHodgman(
        std::vector<Point> pts, 
        double xmin, double ymin, double xmax, double ymax)
{
    Point Pi, Pi_1;
    std::vector<Point> outP;
    for (int plane = 1; plane <= 4; plane++){
        outP = SutherlandHodgmanPerPlane(pts, xmin, ymin, xmax, ymax, plane);
        pts = outP;
    }
    return outP;
}

void renderScene(void)
{
    // Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT);

    //Draw clipping rectangle
    drawRect(gxmin, gymin, gxmax, gymax, 1,1,1);

    //Draw clipped polygon
    drawPolygon(points, 1,1,0);
            
    glutSwapBuffers(); // Draw the new frame of the game.
}


void mouse_callback(int button, int state, int x, int y) 
{
    Point p;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        p.x = x;
        p.y = y;
        points.push_back(p);
    } 
    glutPostRedisplay();
}

void keyboard_callback(unsigned char key, int x, int y) 
{
    switch (key)
    {
        case '1':
             //Clip plane 1
             points = SutherlandHodgmanPerPlane(points, gxmin, gymin, gxmax, gymax, 1);
             break;
        case '2':
             //Clip plane 2
             points = SutherlandHodgmanPerPlane(points, gxmin, gymin, gxmax, gymax, 2);
             break;
        case '3':
             //Clip plane 3
             points = SutherlandHodgmanPerPlane(points, gxmin, gymin, gxmax, gymax, 3);
             break;
        case '4':
             //Clip plane 4
             points = SutherlandHodgmanPerPlane(points, gxmin, gymin, gxmax, gymax, 4);
             break;
        case '5':
             //Clip all planes
             points = SutherlandHodgman(points, gxmin, gymin, gxmax, gymax);
             break;
        case '6':
            //Clear points
             points.clear();
             break;
        case 27 :
             exit(0);
    }
    
    glutPostRedisplay();
}

void init(void)
{
    
    // The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).
 
    glMatrixMode(GL_PROJECTION); // Select the projection matrix    
    glOrtho(0,     // X coordinate of left edge             
            500,     // X coordinate of right edge            
            500,     // Y coordinate of bottom edge             
            0,     // Y coordinate of top edge             
            100,     // Z coordinate of the “near” plane            
            -100);    // Z coordinate of the “far” plane
    glMatrixMode(GL_MODELVIEW); // Select the projection matrix    
    glLoadIdentity();
       
}

int main(int argc, char *argv[])
{
    // Initialize openGL with Double buffer and RGB color without transparency.
    // Its interesting to try GLUT_SINGLE instead of GLUT_DOUBLE.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 
    // Create the window.
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Clipping");
 
    // Define callbacks.
    glutDisplayFunc(renderScene);
    glutMouseFunc(mouse_callback);
    glutKeyboardFunc(keyboard_callback);
    
    init();
 
    glutMainLoop();
 
    return 0;
}
