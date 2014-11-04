#pragma once

#include <GameKeyMapper.h>
#include <Mesh.h>
#include <Shader.h>
#include <Transform.h>
#include <Camera.h>
#include <Material.h>

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
private:
	Mesh mesh;
	Shader* shader;
	Transform transform;
	Camera camera;
	//Texture texture;
	Material* material;
};

