#pragma once
#include <string>

class ResourceLoader
{
	ResourceLoader(void);
public:
	static std::string loadShader(std::string file);
};

