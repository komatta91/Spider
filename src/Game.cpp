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

#include <ResourceLoader.h>

#include <PhongShader.h>
#include <BasicShader.h>

#include <glm\mat4x4.hpp>

Game::Game(void)
{
	KeyInput::getInstance().initialize(&gameKeyMapper, gameKeyMapper.getMaxActon());
}

void Game::init()
{
	//glm::vec3 res = gl( glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	shader = new PhongShader();

	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(glm::vec3(-1.0f, -1.0f, 0.5773f), glm::vec2(1.0f, 0.0f)));
	vertices.push_back(Vertex(glm::vec3(0.0f, -1.0f, -1.15475f), glm::vec2(1.0f, 1.0f)));
	vertices.push_back(Vertex(glm::vec3(1.0f, -1.0f, 0.5773f), glm::vec2(1.0f, 0.0f)));
	vertices.push_back(Vertex(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)));
	/*
Vertex Vertices[4] = { Vertex(Vector3f(-1.0f, -1.0f, 0.5773f), Vector2f(0.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, -1.0f, -1.15475f), Vector2f(0.5f, 0.0f)),
                           Vertex(Vector3f(1.0f, -1.0f, 0.5773f),  Vector2f(1.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, 1.0f, 0.0f),      Vector2f(0.5f, 1.0f)) };

						    unsigned int Indices[] = { 0, 3, 1,
                               1, 3, 2,
                               2, 3, 0,
                               0, 1, 2 };
	*/

	std::vector<int> indices;
	indices.push_back(0); indices.push_back(3); indices.push_back(1);
	indices.push_back(1); indices.push_back(3); indices.push_back(2);
	indices.push_back(2); indices.push_back(3); indices.push_back(0);
	indices.push_back(0); indices.push_back(1); indices.push_back(2);

	transform.Transform::setProjection(0.1f, 1000.0f, 800.0f, 600.0f, 70.0f); 


	//ResourceLoader::loadMesh("cube.obj", mesh);
	//std::cout << sizeof(Vertex);

	//float test[3] = { 1.0f, 2.0f, 3.0f };

	//std::cout << sizeof(test);

	
	//Mesh temp;
	//temp.addVertices(vertices, indices);
	//mesh = temp;
	mesh.addVertices(vertices, indices, true);

	glm::vec3 color(1.0f, 1.0f, 1.0f);
	static_cast<PhongShader*>(shader)->setAmbientLight(glm::vec3(0.5f, 0.5f, 1.0f));
	material = new Material("kotek.bmp", color);
	//material = new Material(color);
}


Game::~Game(void)
{
	if (shader)
	{
		delete shader;
	}
}

static float scale = 0.0f;
glm::vec3 additionPos(0.0f);
float amountX = 0;
float amountY = 0;

void Game::input()
{
	additionPos = glm::vec3(0.0f);
	amountX = 0;
	amountY = 0;
	KeyInput::getInstance().update();
	if (KeyInput::getInstance().actionsHot(GameAction::FORWARD))
	{
		additionPos += camera.getForward();
	}
	if (KeyInput::getInstance().actionsHot(GameAction::LEFT))
	{
		additionPos += camera.getLeft();
	}
	if (KeyInput::getInstance().actionsHot(GameAction::RIGHT))
	{
		additionPos += camera.getRight();
	}
	if (KeyInput::getInstance().actionsHot(GameAction::BACK))
	{
		additionPos += camera.getBack();
	}

	if (KeyInput::getInstance().actionsHot(GameAction::ROTATE_DOWN))
	{
		amountY -= Timer::getInstance().deltaTime();
	}
	if (KeyInput::getInstance().actionsHot(GameAction::ROTATE_LEFT))
	{
		amountX += Timer::getInstance().deltaTime();
	}
	if (KeyInput::getInstance().actionsHot(GameAction::ROTATE_RIGHT))
	{
		amountX -= Timer::getInstance().deltaTime();
	}
	if (KeyInput::getInstance().actionsHot(GameAction::ROTATE_UP))
	{
		amountY += Timer::getInstance().deltaTime();
	}
}
void Game::update()
{
	//std::cout << (glm::sin(scale) * - 100) << std::endl;
	transform.setTranslation(0.0f, 0.0f, -5);
	transform.setScale(0.45f, 0.45f, 0.45f);
	//transform.setRotation(0, glm::sin(scale) * 180, 0.0f);

	camera.muve(additionPos, Timer::getInstance().deltaTime() * 10);
	camera.rotateX(amountX * 100);
	camera.rotateY(amountY * 100);
	//camera.turn(additioncenter, Timer::getInstance().deltaTime());
}
void Game::render()
{
	shader->bindShader();
	
	//glm::mat4 res = camera.lookAt();
 	shader->updateUniforms(transform.getTransformation(), transform.getProjectionTransformation(camera.lookAt()), *material);
	//shader.setUniform("transform", transform.getProjectionTransformation(glm::mat4(1.0f)));
	mesh.draw();
}
