/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
#ifdef __WINDOWS__
#include <windows.h>  // for MS Windows
#endif
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Global variables */
char title[] = "3D Shapes";
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void RenderTableLegs()
{
   glBegin(GL_QUADS);                
      
      // Right
      glColor3f(0.5f, 0.1f, 0.5f);     
      glVertex3f(5.5f, -2.0f, 5.0f);
      glVertex3f(5.0f, -2.0f, 5.0f);
      glVertex3f(5.0f, -5.0f,  5.0f);
      glVertex3f(5.5f, -5.0f,  5.0f);

      // Left
      glColor3f(0.5f, 0.1f, 0.5f);     
      glVertex3f(5.5f, -2.0f, 4.5f);
      glVertex3f(5.0f, -2.0f, 4.5f);
      glVertex3f(5.0f, -5.0f,  4.5f);
      glVertex3f(5.5f, -5.0f,  4.5f);

      // Back
      glColor3f(0.5f, 0.1f, 0.5f); 
      glVertex3f(5.5f, -2.0f, 5.0f);
      glVertex3f(5.5f, -2.0f, 4.5f);
      glVertex3f(5.5f, -5.0f,  4.5f);
      glVertex3f(5.5f, -5.0f,  5.0f);

      // Front
      glColor3f(0.5f, 0.1f, 0.5f); 
      glVertex3f(5.0f, -2.0f, 5.0f);
      glVertex3f(5.0f, -2.0f, 4.5f);
      glVertex3f(5.0f, -5.0f,  4.5f);
      glVertex3f(5.0f, -5.0f,  5.0f);

   glEnd();
}

void RenderTable()
{ 
   glBegin(GL_QUADS);                
      
      // Top
      glColor3f(0.5f, 0.1f, 0.5f);     
      glVertex3f(10.0f, -1.0f, -2.0f);
      glVertex3f(5.0f, -1.0f, -2.0f);
      glVertex3f(5.0f, -1.0f,  5.0f);
      glVertex3f(10.0f, -1.0f,  5.0f);

      // Bottom
      glColor3f(0.5f, 0.1f, 0.5f);     
      glVertex3f(10.0f, -2.0f, -2.0f);
      glVertex3f(5.0f, -2.0f, -2.0f);
      glVertex3f(5.0f, -2.0f,  5.0f);
      glVertex3f(10.0f, -2.0f,  5.0f);

      // Right
      glColor3f(0.5f, 0.1f, 0.5f);     
      glVertex3f(10.0f, -1.0f, 5.0f);
      glVertex3f(5.0f, -1.0f, 5.0f);
      glVertex3f(5.0f, -2.0f,  5.0f);
      glVertex3f(10.0f, -2.0f,  5.0f);

      // Left
      glColor3f(0.5f, 0.1f, 0.5f);   
      glVertex3f(10.0f, -1.0f, -2.0f);
      glVertex3f(5.0f, -1.0f, -2.0f);
      glVertex3f(5.0f, -2.0f,  -2.0f);
      glVertex3f(10.0f, -2.0f,  -2.0f);

      // Front
      glColor3f(0.5f, 0.1f, 0.5f); 
      glVertex3f(5.0f, -1.0f, 5.0f);
      glVertex3f(5.0f, -1.0f, -2.0f);
      glVertex3f(5.0f, -2.0f,  -2.0f);
      glVertex3f(5.0f, -2.0f,  5.0f);

      // Back
      glColor3f(0.5f, 0.1f, 0.5f); 
      glVertex3f(10.0f, -1.0f, 5.0f);
      glVertex3f(10.0f, -1.0f, -2.0f);
      glVertex3f(10.0f, -2.0f,  -2.0f);
      glVertex3f(10.0f, -2.0f,  5.0f);
   glEnd();

   glColor3f(0.5f, 0.5f, 0.5f);

   // Drawer Knob
   glPushMatrix();
      glTranslatef(4.5f,-1.5f, 1.5f); 
      glutSolidSphere(0.3, 5, 5);
   glPopMatrix();

   //Rendering Legs
   glPushMatrix();
      //glTranslatef(0.0f, 0.0f, 0.0f); 
      RenderTableLegs();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(0.0f, 0.0f, -6.5f); 
      RenderTableLegs();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(4.5f, 0.0f, 0.0f); 
      RenderTableLegs();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(4.5f, 0.0f, -6.5f); 
      RenderTableLegs();
   glPopMatrix();
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, -45.0f);  // Move right and into the screen
   glRotatef(45, 0, 1, 0);
   //glRotatef(15, 0, 0, 1);
   //glRotatef(15, 1, 0, 0);
 
   // Bottom
   glBegin(GL_QUADS);                
      
      glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f( 10.0f, -5.0f, -10.0f);
      glVertex3f(-10.0f, -5.0f, -10.0f);
      glVertex3f(-10.0f, -5.0f,  10.0f);
      glVertex3f( 10.0f, -5.0f,  10.0f);
   glEnd();  

   // Back
   glBegin(GL_QUADS);                
      
      glColor3f(1.0f, 0.0f, 0.0f);     
      glVertex3f(10.0f, 10.0f, -10.0f);
      glVertex3f(-10.0f, 10.0f, -10.0f);
      glVertex3f(-10.0f, -5.0f, -10.0f);
      glVertex3f(10.0f, -5.0f, -10.0f);
   glEnd();  

   // Top
   glBegin(GL_QUADS);                
      
      glColor3f(0.0f, 1.0f, 0.0f);    
      glVertex3f( 10.0f, 10.0f, -10.0f);
      glVertex3f(-10.0f, 10.0f, -10.0f);
      glVertex3f(-10.0f, 10.0f,  10.0f);
      glVertex3f( 10.0f, 10.0f,  10.0f);
   glEnd();  

   // Right
   glBegin(GL_QUADS);                
      
      glColor3f(0.0f, 0.0f, 1.0f);     
      glVertex3f( 10.0f, 10.0f,  10.0f);
      glVertex3f( 10.0f, 10.0f, -10.0f);
      glVertex3f(10.0f, -5.0f, -10.0f);
      glVertex3f( 10.0f, -5.0f,  10.0f);
   glEnd();

   RenderTable();
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void processNormalKeys(unsigned char key, int x, int y) 
{
	if (key == 27 || key == 81 || key == 113)
		exit(0);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(1920, 1080);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutKeyboardFunc(processNormalKeys);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
