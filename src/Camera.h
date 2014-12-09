#pragma once
#include <glm\vec3.hpp>
#include <glm\mat4x4.hpp>

class Camera
{
public:
	Camera(glm::vec3 pos = glm::vec3(0.0f), glm::vec3 center = glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
	~Camera(void);

	void muve(glm::vec3 direction, float amount);
	glm::vec3 getLeft();
	glm::vec3 getRight();
	glm::vec3 getForward();
	glm::vec3 getBack();
	void rotateX(float amount);
	void rotateY(float amount);
	glm::mat4 lookAt();
	inline glm::vec3 getPos() { return pos; }

	static glm::vec3 yAxis;
private:
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
};

