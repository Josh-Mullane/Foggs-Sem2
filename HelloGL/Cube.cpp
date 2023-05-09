#include "Cube.h"
#include "HelloGL.h"
Cube::Cube(float _positionx, float _positiony, float _positionz)
{
	_position.x = _positionx;
	_position.y = _positiony;
	_position.z = _positionz;

	
}



void Cube::Draw()
{
	{
		glPushMatrix();
		glBegin(GL_TRIANGLES);

		for (int i = 0; i < 36; ++i)
		{
			glColor3fv(&indexedColours[indices[i]].r);
			glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
		}
		
		glEnd();
		glPopMatrix();
		glLoadIdentity();
		glTranslatef(_position.x, _position.y, _position.z);
	}

}

void Cube::Update()
{
	
}

Vertex Cube::indexedVertices[] = { 1,1,1, -1,1,1,
									 -1,-1,1, 1,-1,1,
									 1,-1,-1, 1,1,-1,
									 -1,1,-1, -1,-1,-1 };

Colour Cube::indexedColours[] = { 1,1,1, 1,1,0,
									 1,0,0, 1,0,1,
									 0,0,1, 0,1,1,
									 0,1,0, 0,0,0 };

GLushort Cube::indices[] = { 0,1,2, 2,3,0,
							   0,3,4, 4,5,0,
							   0,5,6, 6,1,0,
							   1,6,7, 7,2,1,
							   7,4,3, 3,2,7,
							   4,7,6, 6,5,4 };

Cube::~Cube(void)
{

}