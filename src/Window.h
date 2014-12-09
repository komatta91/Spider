#pragma once

#include <string>

class Window
{
public:
	Window();
	void createWindow(int width, int height, std::string title);
	void render();
	bool isCloseRequested();

private:
	static void onClosing();
};


