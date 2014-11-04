#pragma once
#include <windows.h>
#include <gl\glew.h>
#include <GL\GL.h>


class Texture
{
	unsigned int id;
public:
	Texture(int id = 0) : id(id) {};
	~Texture(void) { glDeleteTextures(1, &id); }
	inline int getID() { return id; }
	inline void setID(int id) { this->id = id; };
	void bind();
};

