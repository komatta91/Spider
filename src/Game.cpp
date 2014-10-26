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
#include <glm\gtx\fast_trigonometry.hpp>

#include <Timer.h>

Game::Game(void)
{
	KeyInput::getInstance().initialize(&gameKeyMapper, gameKeyMapper.getMaxActon());
}

void Game::init()
{
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(glm::vec3(-1.0f, -1.0f, +0.0f)));
	vertices.push_back(Vertex(glm::vec3(+0.0f, +1.0f, +0.0f)));
	vertices.push_back(Vertex(glm::vec3(+1.0f, -1.0f, +0.0f)));
	vertices.push_back(Vertex(glm::vec3(+0.0f, -1.0f, +1.0f)));

	std::vector<int> indices;
	indices.push_back(0); indices.push_back(1); indices.push_back(3);
	indices.push_back(3); indices.push_back(1); indices.push_back(2);
	indices.push_back(2); indices.push_back(1); indices.push_back(0);
	indices.push_back(0); indices.push_back(2); indices.push_back(3);


	mesh.addVertices(vertices, indices);

	shader.addVertexShader("baseVertex.vs");
	shader.addFragmentShader("baseFragment.fs");
	shader.compileShader();

	shader.addUniform("transform");
	
}


Game::~Game(void)
{
}

static float scale = 0.0f;

void Game::input()
{
	KeyInput::getInstance().update();
	
	if (KeyInput::getInstance().actionsStarted(GameAction::Accelerate))
	{
		
	}
	if (KeyInput::getInstance().actionsHot(GameAction::Accelerate))
	{
		//std::cout << "Accelerate\n";
		scale = scale += Timer::getInstance().deltaTime();
		
	}
	if (KeyInput::getInstance().actionsEnded(GameAction::Accelerate))
	{
		//shader.setUniform("scale", scale -= Timer::getInstance().deltaTime() * 10);
	}
}
void Game::update()
{
	transform.setTranslation(glm::sin(scale), 0.0f, 0.0f);
	transform.setScale(glm::abs(glm::sin(scale)), glm::abs(glm::sin(scale)), glm::abs(glm::sin(scale)));
	transform.setRotation(0, glm::sin(scale) * 180, glm::sin(scale) * 180);
}
void Game::render()
{
	shader.bindShader();
	shader.setUniform("transform", transform.getTransformation());
	mesh.draw();
}
