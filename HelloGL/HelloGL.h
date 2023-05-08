#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"

#define REFRESHRATE 16




class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void DrawPolygon();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void DrawIndexedCube();

	Camera* camera;

	Cube* cube[200];

	

	


private:
	float rotation;
};


