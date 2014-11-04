#pragma once
#include<glm\glm.hpp>
class Transform
{
public:
	Transform(void);
	~Transform(void);
	glm::mat4 getTransformation();
	glm::mat4 getProjectionTransformation(glm::mat4 lookAt);
	inline void setTranslation(glm::vec3 translation) { this->translation = translation; }
	inline void setTranslation(float x, float y, float z) { translation = glm::vec3(x, y, z); }
	inline glm::vec3 getTranslation() { return translation;}
	inline void setRotation(glm::vec3 rotation) { this->rotation = rotation; }
	inline void setRotation(float x, float y, float z) { rotation = glm::vec3(x, y, z); }
	inline glm::vec3 getRotation() { return rotation;}
	inline void setScale(glm::vec3 scale) { this->scale = scale; }
	inline void setScale(float x, float y, float z) { scale = glm::vec3(x, y, z); }
	inline glm::vec3 getScale() { return scale;}
	void setProjection(float zNear, float zFar, float width, float height, float fov);
private:
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
	float zNear;
	float zFar;
	float width;
	float height;
	float fov;
};

