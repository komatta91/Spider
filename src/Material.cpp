#include "Material.h"
#include <ResourceLoader.h>


Material::Material(std::string filename, glm::vec3 color) : color(color)
{
	ResourceLoader::loadTexture(filename, texture);
}

Material::Material(glm::vec3 color) : color(color)
{
	ResourceLoader::generateWhiteTexture(texture);
}


Material::~Material(void)
{
}

Texture& Material::getTexture()
{
	return texture;
}



glm::vec3 Material::getColor()
{
	return color;
}



