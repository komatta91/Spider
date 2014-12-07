#pragma once
#include <glm\vec3.hpp>
#include <glm\mat4x4.hpp>
#include <GL\glew.h>
#include <string>
#include <map>
#include <Material.h>
class Shader
{
public:
	Shader(void);
	virtual ~Shader(void);
	void addVertexShader(std::string file);
	void addFragmentShader(std::string file);
	void addGeometryShader(std::string file);
	void compileShader();
	virtual void updateUniforms(glm::mat4& worldMatrix, glm::mat4& projectedMatrix, glm::vec3& eyePos, Material& material) = 0;
	void bindShader();
	void addUniform(std::string name);
	void setUniform(std::string name, int value);
	void setUniform(std::string name, float value);
	void setUniform(std::string name, glm::vec3 value);
	void setUniform(std::string name, glm::mat4 value);
private:
	int program;
	std::map<std::string, int> uniforms;

	void addShader(std::string file, int type);
	void checkStatus(GLuint objectID,
				 PFNGLGETSHADERIVPROC objectPropertyGetFunc,
				 PFNGLGETSHADERINFOLOGPROC getInfiLogFunc,
				 GLenum statusType);
	void checkCompileStatus(GLuint shaderID);
	void checkProgramStatus(GLuint programID);
};

