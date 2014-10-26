#include "Transform.h"
#include <glm\gtc\matrix_transform.hpp>

Transform::Transform(void) : translation(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f)
{
}


Transform::~Transform(void)
{
}

glm::mat4 Transform::getTransformation()
{
	glm::mat4 trans = glm::scale(glm::mat4(1.0f), scale);
	trans = glm::rotate(trans, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	trans = glm::rotate(trans, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	trans = glm::rotate(trans, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));	
	return glm::translate(trans, translation);
}