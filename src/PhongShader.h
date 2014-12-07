#pragma once
#include <string>
#include <Shader.h>
#include <glm\glm.hpp>
#include <DirectionalLight.h>
class PhongShader :
	public Shader
{
	glm::vec3 ambientLight;
	DirectionalLight directionalLight;

	void setUniform(std::string name, DirectionalLight light);
	void setUniform(std::string name, BaseLight light);

public:
	PhongShader(glm::vec3 ambientLight = glm::vec3(0.15f, 0.15f, 0.15f));
	virtual ~PhongShader(void);
	virtual void updateUniforms(glm::mat4& worldMatrix, glm::mat4& projectedMatrix, glm::vec3& eyePos, Material& material);
	void setAmbientLight(glm::vec3 ambientLight);
	void setDirectionalLight(DirectionalLight directionalLight);

};

