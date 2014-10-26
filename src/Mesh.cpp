#include "Mesh.h"

Mesh::Mesh(void) : vbo(0)
{
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &vbo);
}

void Mesh::addVertices(std::vector<Vertex> &vertices)
{
	size = vertices.size();
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_DYNAMIC_DRAW);
}

void Mesh::draw()
{
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0);

	glDrawArrays(GL_TRIANGLES, 0, size);

	glDisableVertexAttribArray(0);
}
