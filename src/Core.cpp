#include "Core.h"
#include <Window.h>
#include <Timer.h>
#include <Game.h>
#include <KeyInput.h>
#include <RenderUtil.h>
#include <iostream>

Core::Core(Window* window, Game* game) : running(false), window(window), game(game)
{
}


Core::~Core(void)
{
}

void Core::start()
{
	if (!running)
	{
		std::cout << "OpenGL version: " << RenderUtil::openGlVersion() << std::endl;
		RenderUtil::initGraphics();
		Timer::getInstance().reset();
		Timer::getInstance().start();
		running = true;
		game->init();
		run();
	}
}

void Core::stop()
{
	running = false;
}

void Core::run()
{
	while(running)
	{
		Timer::getInstance().tick();
		KeyInput::getInstance().update();
		game->input();
		game->update();
		render();
		if (window->isCloseRequested())
		{
			stop();
		}
	}

}

void Core::render()
{
	RenderUtil::clearScrean();
	game->render();
	
	window->render();
}

void Core::cleanUp()
{

}
