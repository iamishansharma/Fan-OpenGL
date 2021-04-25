/*
 * 
 */
#ifdef __WINDOWS__
#include <windows.h>  // for MS Windows
#endif
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
 
/* Global variables */
char title[] = "Assignment 2 - Ishan Sharma 2016B2A70773P";
GLfloat Cx = 0;
GLfloat Cy = 0;
GLfloat Cz = 3;
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glEnable(GL_DEPTH_TEST);   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-1,1,-1,1,2,100);
   glMatrixMode(GL_MODELVIEW);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
}

void RenderTableLegs()
{
   glPushMatrix();
      glScalef(0.05, 1, 0.05);
      glutSolidCube(1);
   glPopMatrix();
}

void RenderTable()
{ 
   glPushMatrix();
      glScalef(1, 0.05, 1);
      glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-0.5, -0.525, -0.5);
      RenderTableLegs();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(0.5, -0.525, -0.5);
      RenderTableLegs();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(0.5, -0.525, 0.5);
      RenderTableLegs();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(-0.5, -0.525, 0.5);
      RenderTableLegs();
   glPopMatrix();
}
 
void RenderFan()
{
   
}

void RenderWalls()
{
   glPushMatrix();
      glTranslatef(0,0,-2);
      glScalef(25.0, 25.0, 0.05);
      glColor3f(1.0,0.0,0.0);
      glutSolidCube(1);
   glPopMatrix();
}

void display() 
{
   GLfloat Pos[] = {0,1,0,1};
   //GLfloat Col[] = {1,0,0,1};

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   glLightfv(GL_LIGHT0, GL_POSITION, Pos);
   //glLightfv(GL_LIGHT0, GL_DIFFUSE, Col);

   gluLookAt(Cx,Cy,Cz,0,0,0,0,1,0);

   // glLoadIdentity();
   //glTranslatef(0.0, 0.0, -5);

   RenderTable();
   RenderWalls();
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void processNormalKeys(unsigned char key, int x, int y) 
{
   switch(key)
   {
      case 'x': Cx = Cx - 0.5;
                  break;
      case 'X': Cx = Cx + 0.5;
                  break;
      case 'y': Cy = Cy - 0.5;
                  break;
      case 'Y': Cy = Cy + 0.5;
                  break;
      case 'z': Cz = Cz - 0.5;
                  break;
      case 'Z': Cz = Cz + 0.5;
                  break;
      case 27:
      case 'q':
      case 'Q':   exit(0);
                  break;
   }

   glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height) 
{  
   
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // Enable double buffered mode
   glutInitWindowSize(600, 600);   // Set the window's initial width & height
   glutInitWindowPosition(100, 150); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   //glutReshapeFunc(reshape);
   initGL();                       // Our own OpenGL initialization
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutKeyboardFunc(processNormalKeys);
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
