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
	void addVertices(std::vector<Vertex> &vertices, std::vector<int> &indices, bool calcNormals = false);
	void draw();
private:
	void calcNormals(std::vector<Vertex> &vertices, std::vector<int> &indices);

	unsigned int vbo;
	unsigned int ibo;
	int size;
};

