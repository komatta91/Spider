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

#include <GeometryGenerator.h>

Game::Game(void)
{
	KeyInput::getInstance().initialize(&gameKeyMapper, gameKeyMapper.getMaxActon());
}

void Game::init()
{
	//glm::vec3 res = gl( glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	shader = new PhongShader();

	//vertices.push_back(Vertex(glm::vec3(-1.0f, -1.0f, 0.5773f), glm::vec2(1.0f, 0.0f)));
	//vertices.push_back(Vertex(glm::vec3(0.0f, -1.0f, -1.15475f), glm::vec2(1.0f, 1.0f)));
	//vertices.push_back(Vertex(glm::vec3(1.0f, -1.0f, 0.5773f), glm::vec2(1.0f, 0.0f)));
	//vertices.push_back(Vertex(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)));
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
	//indices.push_back(0); indices.push_back(3); indices.push_back(1);
	//indices.push_back(1); indices.push_back(3); indices.push_back(2);
	//indices.push_back(2); indices.push_back(3); indices.push_back(0);
	//indices.push_back(0); indices.push_back(1); indices.push_back(2);

	transSky.setProjection(0.1f, 1000.0f, 800.0f, 600.0f, 70.0f); 
	transFloor.setProjection(0.1f, 1000.0f, 800.0f, 600.0f, 70.0f);
	transSpiderHead.setProjection(0.1f, 1000.0f, 800.0f, 600.0f, 70.0f);
	transSpiderAbdomen.setProjection(0.1f, 1000.0f, 800.0f, 600.0f, 70.0f);

	GeometryGenerator generator;
	GeometryGenerator::MeshData data;
	std::vector<Vertex> vertices;
	std::vector<int> indices;
	
	//generator.CreateBox(1, 1, 1, data);
	//generator.CreateGeosphere(300, 1000, data);
	generator.CreateGrid(200,200,2,2,data);
	for(int i = 0; i < data.Vertices.size(); ++i)
	{
		Vertex v(data.Vertices[i].Position, data.Vertices[i].TexC, data.Vertices[i].Normal);
		vertices.push_back(v);
	}
	for (int i = 0; i < data.Indices.size(); ++i)
	{
		indices.push_back(data.Indices[i]);
	}

	meshFloor.addVertices(vertices, indices);

	data = GeometryGenerator::MeshData();
	vertices.clear();
	indices.clear();

	generator.CreateSphere(100, 100, 100, data);
	for(int i = 0; i < data.Vertices.size(); ++i)
	{
		Vertex v(data.Vertices[i].Position, data.Vertices[i].TexC, data.Vertices[i].Normal);
		vertices.push_back(v);
	}
	for (int i = 0; i < data.Indices.size(); ++i)
	{
		indices.push_back(data.Indices[i]);
	}

	meshSky.addVertices(vertices, indices);


	data = GeometryGenerator::MeshData();
	vertices.clear();
	indices.clear();

	generator.CreateGeosphere(10, 10, data);
	for(int i = 0; i < data.Vertices.size(); ++i)
	{
		Vertex v(data.Vertices[i].Position, data.Vertices[i].TexC, data.Vertices[i].Normal);
		vertices.push_back(v);
	}
	for (int i = 0; i < data.Indices.size(); ++i)
	{
		indices.push_back(data.Indices[i]);
	}

	meshSpiderHead.addVertices(vertices, indices);

	data = GeometryGenerator::MeshData();
	vertices.clear();
	indices.clear();

	generator.CreateGeosphere(10, 10, data);
	for(int i = 0; i < data.Vertices.size(); ++i)
	{
		Vertex v(data.Vertices[i].Position, data.Vertices[i].TexC, data.Vertices[i].Normal);
		vertices.push_back(v);
	}
	for (int i = 0; i < data.Indices.size(); ++i)
	{
		indices.push_back(data.Indices[i]);
	}

	meshSpiderHead.addVertices(vertices, indices);

	//SpideaA
	data = GeometryGenerator::MeshData();
	vertices.clear();
	indices.clear();

	generator.CreateGeosphere(10, 10, data);
	for(int i = 0; i < data.Vertices.size(); ++i)
	{
		Vertex v(data.Vertices[i].Position, data.Vertices[i].TexC, data.Vertices[i].Normal);
		vertices.push_back(v);
	}
	for (int i = 0; i < data.Indices.size(); ++i)
	{
		indices.push_back(data.Indices[i]);
	}

	meshSpiderAbdomen.addVertices(vertices, indices);

	//parse(mesh, data);

	//ResourceLoader::loadMesh("cube.obj", mesh);
	//std::cout << sizeof(Vertex);

	//float test[3] = { 1.0f, 2.0f, 3.0f };

	//std::cout << sizeof(test);

	
	//Mesh temp;
	//temp.addVertices(vertices, indices);
	//mesh = temp;
	//
	glm::vec3 color(1.0f, 1.0f, 1.0f);
	static_cast<PhongShader*>(shader)->setAmbientLight(glm::vec3(0.2f, 0.2f, 0.2f));

	BaseLight base(glm::vec3(1,1,1), 0.3);
	//DirectionalLight light(base, glm::vec3(0.49,-0.51,-0.710));
	DirectionalLight light(base, glm::vec3( 0, -1, 0));
	static_cast<PhongShader*>(shader)->setDirectionalLight(light);

	matFloor = new Material("podloga.bmp", color, 1, 128);
	matSky = new Material("chmury.bmp", color);
	matSpider = new Material("white.bmp", color);
	camera.muve(glm::vec3(0,1,40), 1.5);
	
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
	scale += Timer::getInstance().deltaTime();

	//transSky.setTranslation(0.0f, 0.0f, 0);
	//transform2.setScale(0.45f, 0.45f, 0.45f);
	//transSky.setRotation(0, 0, 180);

	transFloor.setTranslation(0.0f, -5.0f, 0);
	//transform.setScale(0.45f, 0.45f, 0.45f);
	
	transSpiderHead.setTranslation(0.0f, 5.0f, 0);
	transSpiderHead.setScale(0.8f, 0.6f, 1.3f);
	//transSpider.setRotation(0, 0, 180);

	transSpiderAbdomen.setTranslation(1.0f, 8.0f, 20);
	transSpiderAbdomen.setScale(1.1f, 1.1f, 1.6f);
	//transSpiderAbdomen.setRotation(0, 0, 180);

	//BaseLight base(glm::vec3(1,1,1), 1);
	//DirectionalLight light(base, camera.getForward());
	//static_cast<PhongShader*>(shader)->setDirectionalLight(light);

	camera.muve(additionPos, Timer::getInstance().deltaTime() * 10);
	camera.rotateX(amountX * 100);
	camera.rotateY(amountY * 100);
	//camera.turn(additioncenter, Timer::getInstance().deltaTime());
}
void Game::render()
{
	shader->bindShader();
	
	//glm::mat4 res = camera.lookAt();
	shader->updateUniforms(transFloor.getTransformation(), transFloor.getProjectionTransformation(camera.lookAt()), camera.getPos(), *matFloor);
	//shader.setUniform("transform", transform.getProjectionTransformation(glm::mat4(1.0f)));
	meshFloor.draw();

	shader->updateUniforms(transSky.getTransformation(), transSky.getProjectionTransformation(camera.lookAt()), camera.getPos(), *matSky);
	meshSky.draw();

	shader->updateUniforms(transSpiderHead.getTransformation(), transSpiderHead.getProjectionTransformation(camera.lookAt()), camera.getForward(), *matSpider);
	meshSpiderHead.draw();

	shader->updateUniforms(transSpiderAbdomen.getTransformation(), transSpiderAbdomen.getProjectionTransformation(camera.lookAt()), camera.getForward(), *matSpider);
	meshSpiderAbdomen.draw();
}
