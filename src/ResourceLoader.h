#pragma once
#include <string>
#include <Mesh.h>
#include <Texture.h>

class ResourceLoader
{
	ResourceLoader(void);
public:
	static std::string loadShader(std::string file);
	static void loadMesh(std::string file, Mesh& mesh);
	static void loadTexture(std::string filename, Texture& texture);
	static void generateWhiteTexture(Texture& texture);
};

