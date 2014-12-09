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
	Material* matSpiderLeg1;
	Material* matSpiderLeg2;
	Material* matSpiderLeg3;
	Material* matSpiderHead;
	Material* matSpiderAbdomen;
	Material* matSpiderEye;

	Mesh meshSpiderAbdomen;
	Transform transSpiderAbdomen;

	Mesh meshSpiderLeg1;
	Transform transSpiderLeg11;
	Transform transSpiderLeg12;
	Transform transSpiderLeg13;
	Transform transSpiderLeg14;
	Transform transSpiderLeg15;
	Transform transSpiderLeg16;
	Transform transSpiderLeg17;
	Transform transSpiderLeg18;

	Mesh meshSpiderLeg2;
	Transform transSpiderLeg21;
	Transform transSpiderLeg22;
	Transform transSpiderLeg23;
	Transform transSpiderLeg24;
	Transform transSpiderLeg25;
	Transform transSpiderLeg26;
	Transform transSpiderLeg27;
	Transform transSpiderLeg28;

	Mesh meshSpiderLeg3;
	Transform transSpiderLeg31;
	Transform transSpiderLeg32;
	Transform transSpiderLeg33;
	Transform transSpiderLeg34;
	Transform transSpiderLeg35;
	Transform transSpiderLeg36;
	Transform transSpiderLeg37;
	Transform transSpiderLeg38;

	Transform transSpiderEye1;
	Transform transSpiderEye2;
	Transform transSpiderEye3;
	Transform transSpiderEye4;

	std::vector<std::pair<Transform, Mesh>> spider;
	Shader* shader;
	Camera camera;
};

