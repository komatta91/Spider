



#include<string>
#include<iostream>

#include<Window.h>
#include<Core.h>
#include<Game.h>


namespace {
	static int WIDTH = 800;
	static int HEIGHT = 600;
	static std::string TITLE = "Tetris";
}




int main(int argc, char* argv[])
{
	Window window;
	Game game;
	window.createWindow(WIDTH, HEIGHT, TITLE);
	Core core(&window, &game);
	core.start();
	system("pause");
	return 0;
}


