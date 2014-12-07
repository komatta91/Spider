#include "Mesh.h"
#include <glm\glm.hpp>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))


Mesh::Mesh(void) : vbo(0)
{
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void Mesh::addVertices(std::vector<Vertex> &vertices, std::vector<int> &indices, bool _calcNormals)
{
	if (_calcNormals)
	{
		calcNormals(vertices, indices);
	}

	size = indices.size();
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//std::vector<float> onlyVertices;
	//for (Vertex& v : vertices) {  onlyVertices.push_back(v.getPos().x); onlyVertices.push_back(v.getPos().y);onlyVertices.push_back(v.getPos()v.getPos().z; }
	//void* addr = &vertices[0];

	//float* test = &vertices[0];

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), &indices[0], GL_STATIC_DRAW);
}

void Mesh::draw()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);


	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//int temp = 12;
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), BUFFER_OFFSET(0));
	glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(Vertex), BUFFER_OFFSET(12));
	glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), BUFFER_OFFSET(20));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}

void Mesh::calcNormals(std::vector<Vertex> &vertices, std::vector<int> &indices)
{
	//TODO do zmiany obliczanie normalnych
	for (int i = 0; i < indices.size(); i += 3)
	{
		int i0 = indices[i];
		int i1 = indices[i + 1];
		int i2 = indices[i + 2];

		glm::vec3 p0 = vertices[i0].getPos();
		glm::vec3 p1 = vertices[i1].getPos();
		glm::vec3 p2 = vertices[i2].getPos();

		glm::vec3 t1 = p1 - p0;

		glm::vec3 t2 = p2 - p0;

		//glm::vec3 normal =  glm::normalize(glm::cross(t2, t1));

		glm::vec3 normal =  glm::cross(t2, t1);

		vertices[i0].setNormal(vertices[i0].getNormal() + normal);
		vertices[i1].setNormal(vertices[i1].getNormal() + normal);
		vertices[i2].setNormal(vertices[i1].getNormal() + normal);
	}

	for (int i = 0; i < vertices.size(); ++i)
	{
		vertices[i].setNormal(glm::normalize(vertices[i].getPos()));
		//vertices[i].setNormal(glm::normalize(vertices[i].getNormal()));
	}
}
