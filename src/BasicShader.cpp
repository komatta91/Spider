#include "BasicShader.h"


BasicShader::BasicShader(void)
{
	addVertexShader("baseVertex.vs");
	addFragmentShader("baseFragment.fs");
	compileShader();

	addUniform("transform");
	addUniform("sampler");
	addUniform("color");
}


BasicShader::~BasicShader(void)
{
}

void BasicShader::updateUniforms(glm::mat4& worldMatrix, glm::mat4& projectedMatrix, Material& material)
{
	setUniform("transform", projectedMatrix);
	setUniform("sampler", 0);
	setUniform("color", material.getColor());

	material.getTexture().bind();
}
