#pragma once


class Vector3
{
public:
	float x, y, z;
};

class Camera
{
public:
	Vector3 eye;
	Vector3 centre;
	Vector3 up;
};

struct Colour
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};