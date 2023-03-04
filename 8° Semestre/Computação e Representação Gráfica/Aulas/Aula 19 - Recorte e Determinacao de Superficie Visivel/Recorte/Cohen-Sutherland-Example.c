#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
 

typedef int OutCode;
 
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

double gx0=0, gy0=0, gx1=500, gy1=500;


void drawRect(double xmin, double ymin, double xmax, double ymax, float R, float G, float B)
{
     glColor3f(R,G,B);
 
     glBegin(GL_LINE_LOOP);
          glVertex2f( xmin, ymin);               
          glVertex2f( xmax, ymin);               
          glVertex2f( xmax, ymax);               
          glVertex2f( xmin, ymax);               
     glEnd();
}

void lineSegment(double x0, double y0, double x1, double y1, float R, float G, float B)
{
     glColor3f(R,G,B);
 
     glBegin(GL_LINES);
          glVertex2f( x0, y0);               // Top Left
          glVertex2f( x1, y1);               // Bottom Left
     glEnd();
}

// Compute the bit code for a point (x, y) using the clip rectangle
// bounded diagonally by (xmin, ymin), and (xmax, ymax)
OutCode ComputeOutCode(double x, double y, double xmin, double ymin, double xmax, double ymax)
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
 
// Cohen–Sutherland clipping algorithm clips a line from
// P0 = (x0, y0) to P1 = (x1, y1) against a rectangle with 
// diagonal from (xmin, ymin) to (xmax, ymax).
int CohenSutherlandLineClipAndDraw(
        double *lx0, double *ly0, 
        double *lx1, double *ly1, 
        double xmin, double ymin, double xmax, double ymax)
{
        double x0 = *lx0, y0 = *ly0; 
        double x1 = *lx1, y1 = *ly1;
        
	// compute outcodes for P0, P1, and whatever point lies outside the clip rectangle
	OutCode outcode0 = ComputeOutCode(x0, y0, xmin, ymin, xmax, ymax);
	OutCode outcode1 = ComputeOutCode(x1, y1, xmin, ymin, xmax, ymax);
	int accept = 0;
 
	while (1) {
		if (!(outcode0 | outcode1)) { // Bitwise OR is 0. Trivially accept and get out of loop
			accept = 1;
			break;
		} else if (outcode0 & outcode1) { // Bitwise AND is not 0. Trivially reject and get out of loop
			break;
        } else {
			// failed both tests, so calculate the line segment to clip
			// from an outside point to an intersection with clip edge
			double x, y;
 
			// At least one endpoint is outside the clip rectangle; pick it.
			OutCode outcodeOut = outcode0 ? outcode0 : outcode1;
 
			// Now find the intersection point;
			// use formulas y = y0 + slope * (x - x0), x = x0 + (1 / slope) * (y - y0)
			if (outcodeOut & TOP) {           // point is above the clip rectangle
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			} else if (outcodeOut & BOTTOM) { // point is below the clip rectangle
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			} else if (outcodeOut & RIGHT) {  // point is to the right of clip rectangle
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			} else if (outcodeOut & LEFT) {   // point is to the left of clip rectangle
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}
 
			// Now we move outside point to intersection point to clip
			// and get ready for next pass.
			if (outcodeOut == outcode0) {
				x0 = x;
				y0 = y;
				outcode0 = ComputeOutCode(x0, y0, xmin, ymin, xmax, ymax);
			} else {
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1, xmin, ymin, xmax, ymax);
			}
		}
	}
	if (accept) {
               *lx0 = x0;
               *ly0 = y0; 
               *lx1 = x1;
               *ly1 = y1;
               
               return 1;
	}
        
        return 0;
}

void renderScene(void)
{
    double x0 = gx0, y0 = gy0, x1 = gx1, y1 = gy1;
    double xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    
    // Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT);

    //Draw complete line in red
    lineSegment(x0, y0, x1, y1, 1,0,0);
    //Draw clipping rectangle in white
    drawRect(xmin, ymin, xmax, ymax, 1,1,1);
    
    //Clip line
    int rtn = CohenSutherlandLineClipAndDraw( &x0, &y0, &x1, &y1, xmin, ymin, xmax, ymax);
    //Draw clipped line in green, if it was not rejected
    if (rtn) 
        lineSegment(x0, y0, x1, y1, 0,1,0);

    glutSwapBuffers(); // Draw the new frame of the game.
}


void mouse_callback(int button, int state, int x, int y) 
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        gx0 = x;
        gy0 = y;
    } 
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        gx1 = x;
        gy1 = y;
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
            0,     // Z coordinate of the “near” plane            
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
    
    init();
 
    glutMainLoop();
 
    return 0;
}
