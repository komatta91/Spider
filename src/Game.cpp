#include "Game.h"

#define MEANER_AND_LEANER
#include <windows.h>
#include <GL/gl.h>
#include <freeglut/freeglut.h>

#include <KeyInput.h>
#include <GameKeyMapper.h>
#include <GameAction.h>
#include <glm\glm.hpp>

#include <iostream>


#include <vector>
#include <Vertex.h>
#include <glm\vec3.hpp>

Game::Game(void)
{
	KeyInput::getInstance().initialize(&gameKeyMapper, gameKeyMapper.getMaxActon());
}

void Game::init()
{
	std::vector<Vertex> data;
	data.push_back(Vertex(glm::vec3(-1.0f, -1.0f, 0)));
	data.push_back(Vertex(glm::vec3(+0.0f, +1.0f, 0)));
	data.push_back(Vertex(glm::vec3(+1.0f, -1.0f, 0)));
	mesh.addVertices(data);

	shader.addVertexShader("baseVertex.vs");
	shader.addFragmentShader("baseFragment.fs");
	shader.compileShader();
}


Game::~Game(void)
{
}

void Game::input()
{

	if (KeyInput::getInstance().actionsStarted(GameAction::Accelerate))
	{
		std::cout << "Accelerate started\n";
	}
	if (KeyInput::getInstance().actionsHot(GameAction::Accelerate))
	{
		std::cout << "Accelerate\n";
	}
	if (KeyInput::getInstance().actionsEnded(GameAction::Accelerate))
	{
		std::cout << "Accelerate ended\n";
	}
}
void Game::update()
{
}
void Game::render()
{
	shader.bindShader();
	mesh.draw();
}
