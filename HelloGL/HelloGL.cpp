#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);

	glutInit(&argc, argv);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(Display);
	glutMainLoop();
}

void HelloGL::Display()
{

}

HelloGL::~HelloGL(void)
{

}