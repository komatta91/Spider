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
	glm::mat4 scaleM = glm::scale(glm::mat4(1.0f), scale);
	
	glm::mat4 rotationM = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	rotationM = glm::rotate(rotationM, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	rotationM = glm::rotate(rotationM, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));	
	
	glm::mat4 translateM = glm::translate(glm::mat4(1.0f), translation);

	return translateM  * rotationM * scaleM;
}

glm::mat4 Transform::getProjectionTransformation(glm::mat4 lookAt)
{

	glm::mat4 perspective = glm::perspective(fov, width/height, zNear, zFar);

	glm::mat4 perspective2 = glm::mat4(1.0f);//glm::perspective(fov, width/height, zNear, zFar);

	return   perspective * lookAt * getTransformation();//* perspective;
}

void Transform::setProjection(float zNearin, float zFarin, float widthin, float heightin, float fovin)
{
	zNear = zNearin;
	zFar = zFarin;
	width = widthin;
	height = heightin;
	fov = fovin;
}