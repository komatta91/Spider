#include "Camera.h"
#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>

#include <iostream>

Camera::Camera(glm::vec3 pos, glm::vec3 forward, glm::vec3 up) : pos(pos), forward(forward), up(up)
{
	//forward = glm::normalize();
	up = glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f));
}

Camera::~Camera(void)
{
}


void Camera::muve(glm::vec3 direction, float amount)
{
	pos += (amount * direction);
}

glm::vec3 Camera::getLeft()
{
	return glm::normalize(glm::cross(up, forward));
}

glm::vec3 Camera::getRight()
{
	return glm::normalize(glm::cross(forward, up));
}

glm::vec3 Camera::getForward()
{
	return forward;
}

glm::vec3 Camera::getBack()
{
	return -forward;
}

void Camera::rotateX(float amount)
{
	glm::vec3 Haxis = glm::normalize(glm::cross(forward, yAxis));
	forward = glm::normalize(glm::rotate(forward, amount, yAxis));
	up = glm::normalize(glm::cross(Haxis, forward));
}

void Camera::rotateY(float amount)
{
	glm::vec3 Haxis = glm::normalize(glm::cross(forward, yAxis));
	forward = glm::normalize(glm::rotate(forward, amount, Haxis));
	up = glm::normalize(glm::cross(Haxis, forward));
}

glm::mat4 Camera::lookAt()
{
	//std::cout  << pos.x << " " << pos.y << " "<< pos.z << "    " << forward.x << " " << forward.y << " "<< forward.z  << std::endl;
	return glm::lookAt(pos, pos + forward, yAxis);
}

glm::vec3 Camera::yAxis = glm::vec3(0.0f, 1.0f, 0.0f);