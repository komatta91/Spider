#pragma once
#include <Shader.h>
#include <glm\glm.hpp>

class PhongShader :
	public Shader
{
	glm::vec3 ambientLight;
public:
	PhongShader(glm::vec3 ambientLight = glm::vec3(0.15f, 0.15f, 0.15f));
	virtual ~PhongShader(void);
	virtual void updateUniforms(glm::mat4& worldMatrix, glm::mat4& projectedMatrix, Material& material);
	void setAmbientLight(glm::vec3 ambientLight);
};

