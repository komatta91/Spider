#include "Shader.h"

#include <iostream>
#include <ResourceLoader.h>

Shader::Shader(void) : program(0)
{
	
}


Shader::~Shader(void)
{
	glDeleteProgram(program);
}

void Shader::addVertexShader(std::string file)
{
	addShader(file, GL_VERTEX_SHADER);
}

void Shader::addFragmentShader(std::string file)
{
	addShader(file, GL_FRAGMENT_SHADER);
}

void Shader::addGeometryShader(std::string file)
{
	addShader(file, GL_GEOMETRY_SHADER);
}

void Shader::compileShader()
{
	glLinkProgram(program);
	checkProgramStatus(program);
}

void Shader::bindShader()
{
	glUseProgram(program);
}

void Shader::addShader(std::string file, int type)
{
	if (program == 0)
	{
		program = glCreateProgram();
	}
	int shader = glCreateShader(type);

	std::string code = ResourceLoader::loadShader(file);
	const char* adapter[1];
	adapter[0] = code.c_str();
	glShaderSource(shader, 1, adapter, 0);
	glCompileShader(shader);
	checkCompileStatus(shader);
	glAttachShader(program, shader);
}


void Shader::checkStatus(GLuint objectID,
				 PFNGLGETSHADERIVPROC objectPropertyGetFunc,
				 PFNGLGETSHADERINFOLOGPROC getInfiLogFunc,
				 GLenum statusType)
{
	GLint status;
	// vertexShaderID
	objectPropertyGetFunc(objectID, statusType, &status);
	if (status != GL_TRUE)
	{
		std::cout << "Error\n";
		GLint logLenght;
		objectPropertyGetFunc(objectID, GL_INFO_LOG_LENGTH, &logLenght);
		GLchar* buffer = new GLchar[logLenght];

		GLsizei bufferSize;
		getInfiLogFunc(objectID, logLenght, &bufferSize, buffer);

		std::cout << buffer << std::endl;
		delete[] buffer;
	}
}

void Shader::checkCompileStatus(GLuint shaderID)
{
	checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

void Shader::checkProgramStatus(GLuint programID)
{
	checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
}

