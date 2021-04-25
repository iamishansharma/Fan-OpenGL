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
GLfloat OpenDrawer = 0.0;
 
/* Initialize OpenGL Graphics */
void initGL() 
{
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

void RenderDrawer()
{
	glPushMatrix();
		glTranslatef(0.0, 0.0, OpenDrawer);
		glPushMatrix();
			glScalef(0.5, 0.05, 0.5);
			glTranslatef(0.0, -4.0, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.05, 0.25, 0.5);
			glTranslatef(4.5, -0.4, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.05, 0.25, 0.5);
			glTranslatef(-4.5, -0.4, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.5, 0.25, 0.05);
			glTranslatef(0, -0.4, 10);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.5, 0.25, 0.05);
			glTranslatef(0, -0.4, 0);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, -0.1, 0.6);
			glutSolidSphere(0.05, 5, 5);
		glPopMatrix();
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

	RenderDrawer();
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

		// Shifting Origin to Point above Piece 4 rotating and shifting back
		glTranslatef(0.0, 0.0, 0.25);
		glRotatef(-75, 0, 1, 0);
		glRotatef(LateralMovement, 0, 1, 0.0);
		glTranslatef(0.0, 0.0, -0.25);

		// Piece 4
		glPushMatrix();
			glTranslatef(0.0, 0.35, 0.35);
			glScalef(0.15, 0.1, 0.3);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0,0.35,0.65);
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
		glTranslatef(0.0, 0.15, 0.2);
		glScalef(0.2, 0.1, 0.4);
		glutSolidCube(1);
	glPopMatrix();

	// Piece 3
	glPushMatrix();
		glTranslatef(0.0, 0.25, 0.35);
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
	// Back Wall
	glPushMatrix();
		glTranslatef(0,0,-0.55);
		glScalef(4, 4, 0.05);
		glColor3f(1.0,0.0,0.0);
		glutSolidCube(1);
	glPopMatrix();

	// Bottom Floor
	glPushMatrix();
		glTranslatef(0,-2,1.5);
		glScalef(4, 0.05, 4);
		glColor3f(0.0,1.0,0.0);
		glutSolidCube(1);
	glPopMatrix();

	// Top Ceiling
	glPushMatrix();
		glTranslatef(0,2,1.5);
		glScalef(4, 0.05, 4);
		glColor3f(0.0,0.0,1.0);
		glutSolidCube(1);
	glPopMatrix();

	// Right Wall
	glPushMatrix();
		glTranslatef(2.0,0,1.5);
		glScalef(0.05, 4, 4);
		glColor3f(0.5,0.0,0.5);
		glutSolidCube(1);
	glPopMatrix();
}

void display() 
{
	GLfloat Pos[] = {0,1,0,1};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, Pos);

	glTranslatef(0,1,0);
	gluLookAt(Cx,Cy,Cz,0,0,0,0,1,0);
	//glRotatef(90,0,1,0);

	//RenderWalls();

	glTranslatef(0,-1,0);
	
	RenderTable();

	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.5);
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
		case 'h': 	startLateralMovement = startLateralMovement ? false : true; // Start Stop for Lateral Movement
					break;
		case 'u': 	FanMoveY += 0.05;	// Move Fan Up
					break;
		case 'd': 	FanMoveY -= 0.05;	// Move Fan Down
					break;
		case 'l': 	FanMoveX -= 0.05;	// Move Fan Left
					break;
		case 'r': 	FanMoveX += 0.05;	// Move Fan Right
					break;
		case 'o':   OpenDrawer = OpenDrawer == 0.0 ? 0.5 : 0.0;		// Drawer Open Close		
	}

	glutPostRedisplay();
}

static void resize(int width, int height)
{
	const float aspectRatio = (float) width / (float) height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Spin()
{
	if(startFanRotation)
	{
		if(FanRotation > 360)
			FanRotation = 0;
		else
			FanRotation += 15;
	}

	if(startLateralMovement)
	{
		if(LateralMovement > 150)
		{
			LateralForwardorBackward = false;
			LateralMovement -= 0.6;
		}
		else if(LateralMovement < 0)
		{
			LateralForwardorBackward = true;
			LateralMovement += 0.6;
		}
		else
			LateralMovement += LateralForwardorBackward ? 0.6 : -0.6;
	}
	
	glutPostRedisplay();
}
 

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);            
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	glutInitWindowSize(600, 600);   
	glutInitWindowPosition(100, 150); 
	glutCreateWindow(title);          
	glutReshapeFunc(resize);
	initGL();                       
	glutDisplayFunc(display);       
	glutKeyboardFunc(processNormalKeys);
	glutIdleFunc(Spin);
	glutMainLoop();                 
	return 0;
}
