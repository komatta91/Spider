#pragma once
#include <glm/vec3.hpp>

class Vertex
{
public:
	Vertex(glm::vec3 pos) : pos(pos) {}
	inline void setPos(glm::vec3 pos) { this->pos = pos; }
	inline glm::vec3 getPos() { return pos; }
private:
	glm::vec3 pos;
};

