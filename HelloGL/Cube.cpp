#include "Cube.h"
#include "HelloGL.h"
#include <iostream>
#include <fstream>

Vertex* Cube::indexedVertices = nullptr;
Colour* Cube::indexedColours = nullptr;
GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColours = 0;
int Cube::numIndices = 0;

Cube::Cube(Mesh* mesh, float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	
}

bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}
	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; ++i)
	{
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;

	}
	inFile >> numColours;
	indexedColours = new Colour[numColours];
	for (int i = 0; i < numColours; ++i)
	{
		inFile >> indexedColours[i].r;
		inFile >> indexedColours[i].g;
		inFile >> indexedColours[i].b;

	}
	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; ++i)
	{
		inFile >> indices[i];

	}

	inFile.close();
	return true;
}

void Cube::Draw()
{
	{
		if (_mesh->Vertices != nullptr && _mesh->Colours != nullptr && _mesh->Indices != nullptr)
		{
			glPushMatrix();
			glBegin(GL_TRIANGLES);

			for (int i = 0; i < 36; ++i)
			{
				glColor3fv(&_mesh->Vertices[_mesh->Indices[i]].r);
				glVertex3f(_mesh->Vertices[_mesh->Indices[i]].x, _mesh->Vertices[_mesh->Indices[i]].y, _mesh->Vertices[_mesh->Indices[i]].z);
			}

			glEnd();
			glPopMatrix();
			glLoadIdentity();
			glTranslatef(_position.x, _position.y, _position.z);
		}
		
	}

}

void Cube::Update()
{
	
}



Cube::~Cube(void)
{

}