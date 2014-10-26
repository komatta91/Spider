#pragma once

class Window;
class Game;
class Core
{
public:
	Core(Window* window, Game* game);
	~Core(void);
public:
	void start();
	void stop();
private:
	void run();
	void render();
	void cleanUp();

	bool running;
	Window* window;
	Game* game;
};

