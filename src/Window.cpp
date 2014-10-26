#include "Window.h"

#define MEANER_AND_LEANER
#include <windows.h>
#include <GL/gl.h>
#include <freeglut/freeglut.h>

namespace
{
bool closeRequested = true;
}

Window::Window() //: windowID(0)
{
	closeRequested = false;
}


void Window::onClosing()
{
	closeRequested = true;
}



void Window::createWindow(int width, int height, std::string title) 
{
	int argc = 1; 
	char a = '1';
	char* argv[] = {&a};
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowPosition( 0, 0 );
	glutInitWindowSize(width, height);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutCreateWindow( title.c_str() );
	//glutDisplayFunc( render );
	glutWMCloseFunc( onClosing );

}

void Window::render()
{
	glutSwapBuffers();
	glutMainLoopEvent();
}

bool Window::isCloseRequested()
{
	return closeRequested;
}




