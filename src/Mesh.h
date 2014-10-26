#pragma once

#include <gl/glew.h>
#include <GL/gl.h>

#include<vector>
#include<Vertex.h>

class Mesh
{
public:
	Mesh(void);
	~Mesh(void);
	void addVertices(std::vector<Vertex> &vertices, std::vector<int> &indices);
	void draw();
private:
	unsigned int vbo;
	unsigned int ibo;
	int size;
};

