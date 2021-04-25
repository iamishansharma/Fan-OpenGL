/*
 * 
 */
#ifdef __WINDOWS__
#include <windows.h>  // for MS Windows
#endif
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include <math.h>
 
/* Global variables */
char title[] = "Assignment 2 - Ishan Sharma 2016B2A70773P";
GLfloat Cx = 0;
GLfloat Cy = 0;
GLfloat Cz = 3;
GLfloat FanRotation = 0;
GLfloat FanMoveX = 0;
GLfloat FanMoveY = 0;
GLfloat LateralMovement = 0;
bool LateralForwardorBackward = true;
bool startFanRotation = false;
bool startLateralMovement = false;
 
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

	//glColorMaterial(GL_FRONT, GL_DIFFUSE);
	//glEnable(GL_COLOR_MATERIAL);
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

void FanBlades()
{
	glPushMatrix();
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(-0.15, 0.25, 0.0);
			glVertex3f(0.15, 0.25, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(120, 0, 0, 1);
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(-0.15, 0.25, 0.0);
			glVertex3f(0.15, 0.25, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(240, 0, 0, 1);
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(-0.15, 0.25, 0.0);
			glVertex3f(0.15, 0.25, 0.0);
		glEnd();
	glPopMatrix();
}

void RotatingBody(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC)
{	
	glPushMatrix();
		glRotatef(-75, 0, 1, 0);
		glRotatef(LateralMovement, 0, 1, 0);
		// Piece 4
		glPushMatrix();
			glTranslatef(0.0, 0.35, 0.15);
			glScalef(0.15, 0.1, 0.3);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0,0.35,0.45);
			glRotatef(180,0,1,0);
			float tStep = (3.14) / (float)uiSlices;	
			float sStep = (3.14) / (float)uiStacks;	
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
			for(float t = -3.14/2; t <= (3.14/2)+.0001; t += tStep)	
			{		
				glBegin(GL_TRIANGLE_STRIP);		
				for(float s = -3.14; s <= 3.14+.0001; s += sStep)		
				{			
					glVertex3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));			
					glVertex3f(fA * cos(t+tStep) * cos(s), fB * cos(t+tStep) * sin(s), fC * sin(t+tStep));		
				}		
				glEnd();	
			}
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			glutSolidSphere(0.05, 5, 5);

			glPushMatrix();
				glRotatef(FanRotation, 0, 0, 1);
				FanBlades();
			glPopMatrix();

		glPopMatrix();

	glPopMatrix();
} 

void RenderFan()
{
	glTranslatef(0.0, 0.5, 0);

	// Piece 1
	glPushMatrix();
		glScalef(0.2, 0.4, 0.1);
		glutSolidCube(1);
	glPopMatrix();

	// Piece 2
	glPushMatrix();
		glTranslatef(0.0, 0.15, 0.1);
		glScalef(0.2, 0.1, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	// Piece 3
	glPushMatrix();
		glTranslatef(0.0, 0.25, 0.15);
		glScalef(0.1, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glRotatef(0,0,1,0);
		RotatingBody(15, 2, 0.35, 0.35, 0.15);
	glPopMatrix();
}

void RenderWalls()
{

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

	//glLoadIdentity();
	//glTranslatef(0.0, -1, 0.0);

	RenderTable();

	glPushMatrix();
		glTranslatef(FanMoveX, FanMoveY, 0);
		RenderFan();
	glPopMatrix();
 
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
		
		case 's':	startFanRotation = true; 		// Fan Blades Rotation Start
					break;
		case 't': 	startFanRotation = false;		// Fan Blades Rotation Stop
					break;
		case 'h': 	startLateralMovement = true;	// Lateral movement start
					break;
		case 'j': 	startLateralMovement = false;	// Lateral movement stop
					break;
		case 'u': 	FanMoveY += 0.05;	// Move Fan Up
					break;
		case 'd': 	FanMoveY -= 0.05;	// Move Fan Down
					break;
		case 'l': 	FanMoveX -= 0.05;	// Move Fan Left
					break;
		case 'r': 	FanMoveX += 0.05;	// Move Fan Right
					break;
	}

	glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height) 
{  
	
}

void Spin()
{
	if(startFanRotation)
	{
		if(FanRotation > 360)
			FanRotation = 0;
		else
			FanRotation += 10;
	}

	if(startLateralMovement)
	{
		if(LateralMovement > 150)
			LateralMovement = 0;
		else
			LateralMovement += 0.6;
	}
	
	glutPostRedisplay();
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Enable double buffered mode
	glutInitWindowSize(600, 600);   // Set the window's initial width & height
	glutInitWindowPosition(100, 150); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	//glutReshapeFunc(reshape);
	initGL();                       // Our own OpenGL initialization
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutKeyboardFunc(processNormalKeys);
	glutIdleFunc(Spin);
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
