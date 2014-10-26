#pragma once

#include <GameKeyMapper.h>
#include <Mesh.h>
#include <Shader.h>

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
	Shader shader;
};

