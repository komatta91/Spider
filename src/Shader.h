#pragma once
#include <GL\glew.h>
#include <string>
class Shader
{
public:
	Shader(void);
	~Shader(void);
	void addVertexShader(std::string file);
	void addFragmentShader(std::string file);
	void addGeometryShader(std::string file);
	void compileShader();
	void bindShader();
private:
	int program;
	void addShader(std::string file, int type);
	void checkStatus(GLuint objectID,
				 PFNGLGETSHADERIVPROC objectPropertyGetFunc,
				 PFNGLGETSHADERINFOLOGPROC getInfiLogFunc,
				 GLenum statusType);
	void checkCompileStatus(GLuint shaderID);
	void checkProgramStatus(GLuint programID);
};

