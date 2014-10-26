#include "RenderUtil.h"

#include <GL\glew.h>
#include <GL\gl.h>
#include <freeglut\freeglut.h>


void RenderUtil::initGraphics()
{
	
	glewInit();	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glFrontFace(GL_CW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_FRAMEBUFFER_SRGB);
}

void RenderUtil::clearScrean()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

const GLubyte * RenderUtil::openGlVersion()
{
	return glGetString(GL_VERSION);
}