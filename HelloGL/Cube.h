#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"


class Cube
{
private:
	static Vertex* indexedVertices;
	static Colour* indexedColours;
	static GLushort* indices;

	static int numVertices, numColours, numIndices;

	GLfloat _rotation;

	Vector3 _position;
public:
	Cube(float _positionx, float _positiony, float _positionz);
	~Cube();

	void Draw();
	void Update();

	static bool Load(char* path);
};

