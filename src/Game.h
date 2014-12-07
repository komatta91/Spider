#pragma once

#include <GameKeyMapper.h>
#include <Mesh.h>
#include <Shader.h>
#include <Transform.h>
#include <Camera.h>
#include <Material.h>

#include <vector>

class Game
{
	GameKeyMapper gameKeyMapper;
public:
	Game(void);
	~Game(void);
	virtual void init();
	virtual void input();
	virtual void update();
	virtual void render();

	void createSpider();
	void drawSpider();
private:
	Mesh meshFloor;
	Transform transFloor;
	Material* matFloor;

	Mesh meshSky;
	Transform transSky;
	Material* matSky;

	Mesh meshSpiderHead;
	Transform transSpiderHead;
	Material* matSpider;

	Mesh meshSpiderAbdomen;
	Transform transSpiderAbdomen;
	//Material* matSpider;

	std::vector<std::pair<Transform, Mesh>> spider;



	Shader* shader;
	
	
	Camera camera;
	//Texture texture;
	
	
};

