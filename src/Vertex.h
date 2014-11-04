#pragma once
#include <glm\vec3.hpp>
#include <glm\vec2.hpp>

class Vertex
{
public:
	Vertex(glm::vec3 pos) : pos(pos), textCord(0.0f)  {}
	Vertex(glm::vec3 pos, glm::vec2 textCord) : pos(pos), textCord(textCord) {}
	Vertex(glm::vec3 pos, glm::vec2 textCord, glm::vec3 normal) : pos(pos), textCord(textCord), normal(normal) {}
	Vertex(float x = 0.0f, float y = 0.0f, float z = 0.0f) { pos = glm::vec3(z, y ,z); }
	inline void setPos(glm::vec3 pos) { this->pos = pos; }
	inline glm::vec3 getPos() { return pos; }
	inline glm::vec2 getTextCord() { return textCord; }

	inline void setNormal(glm::vec3 normal) { this->normal = normal; }
	inline glm::vec3 getNormal() { return normal; }
private:
	glm::vec3 pos;
	glm::vec2 textCord;
	glm::vec3 normal;
};




