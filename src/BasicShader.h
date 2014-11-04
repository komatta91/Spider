#pragma once
#include <shader.h>
class BasicShader :
	public Shader
{
public:
	BasicShader(void);
	virtual ~BasicShader(void);
	virtual void updateUniforms(glm::mat4& worldMatrix, glm::mat4& projectedMatrix, Material& material);
};

