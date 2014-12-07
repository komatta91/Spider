#pragma once

#include <string>
#include <Texture.h>
#include <glm\vec3.hpp>

class Material
{
	Texture texture;
	glm::vec3 color;
	float specularIntensity;
	float specularPower;
public:
	Material(std::string filename, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f), float specularIntensity = 2, float specularPower = 32);
	Material(glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));
	~Material(void);

	Texture& getTexture();
	void setTexture(Texture texture);
	glm::vec3 getColor();
	void setColor(glm::vec3 color);

	inline float getSpecularIntensity() { return specularIntensity; }
	inline float getSpecularPower() { return specularPower; }
};

