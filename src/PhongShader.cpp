#include "PhongShader.h"


PhongShader::PhongShader(glm::vec3 ambientLight) : ambientLight(ambientLight)
{
	addVertexShader("phongVertex.vs");
	addFragmentShader("phongFragment.fs");
	compileShader();
	addUniform("directionalLight.base.intensity");
	addUniform("transform");
	addUniform("transformProjected");
	addUniform("sampler");
	addUniform("baseColor");
	addUniform("ambientLight");


	addUniform("specularIntensity");
	addUniform("specularPower");
	addUniform("eyePos");

	addUniform("directionalLight.base.color");

	addUniform("directionalLight.direction");
}


PhongShader::~PhongShader(void)
{
}

void PhongShader::updateUniforms(glm::mat4& worldMatrix, glm::mat4& projectedMatrix, glm::vec3& eyePos, Material& material)
{
	Shader::setUniform("transformProjected", projectedMatrix);//transform.getProjectionTransformation(camera.lookAt()));
	Shader::setUniform("transform", worldMatrix);
	Shader::setUniform("sampler", 0);
	Shader::setUniform("baseColor", material.getColor());
	Shader::setUniform("ambientLight", ambientLight);

	setUniform("directionalLight", directionalLight);


	Shader::setUniform("specularIntensity", material.getSpecularIntensity());
	Shader::setUniform("specularPower", material.getSpecularPower());
	Shader::setUniform("eyePos", eyePos);

	material.getTexture().bind();
}

void PhongShader::setAmbientLight(glm::vec3 ambientLight)
{
	this->ambientLight = ambientLight;
}

void PhongShader::setDirectionalLight(DirectionalLight directionalLight)
{
	this->directionalLight = directionalLight;
}

void PhongShader::setUniform(std::string name, DirectionalLight light)
{
	Shader::setUniform(name + ".direction", light.getDirection());
	setUniform(name + ".base", light.getBaseLight());

}

void PhongShader::setUniform(std::string name, BaseLight light)
{
	Shader::setUniform(name + ".color", light.getColor());
	Shader::setUniform(name + ".intensity", light.getIntensity());
	
}