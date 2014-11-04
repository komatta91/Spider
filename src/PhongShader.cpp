#include "PhongShader.h"


PhongShader::PhongShader(glm::vec3 ambientLight) : ambientLight(ambientLight)
{
	addVertexShader("phongVertex.vs");
	addFragmentShader("phongFragment.fs");
	compileShader();

	addUniform("transform");
	addUniform("sampler");
	addUniform("baseColor");
	addUniform("ambientLight");
}


PhongShader::~PhongShader(void)
{
}

void PhongShader::updateUniforms(glm::mat4& worldMatrix, glm::mat4& projectedMatrix, Material& material)
{
	setUniform("transform", projectedMatrix);//transform.getProjectionTransformation(camera.lookAt()));
	setUniform("sampler", 0);
	setUniform("baseColor", material.getColor());
	setUniform("ambientLight", ambientLight);
	material.getTexture().bind();
}

void PhongShader::setAmbientLight(glm::vec3 ambientLight)
{
	this->ambientLight = ambientLight;
}