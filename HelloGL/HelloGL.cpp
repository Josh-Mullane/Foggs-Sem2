#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;

	GLUTCallbacks::Init(this);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	DrawPolygon();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();


}

void HelloGL::Update()
{
	glutPostRedisplay();
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;

	/*Sleep(10);*/
}



void HelloGL::DrawPolygon()
{
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 0.5f;
	if (key == 'a')
		rotation -= 0.5f;


}

HelloGL::~HelloGL(void)
{

}

