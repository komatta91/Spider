#pragma once
#include <glm\vec3.hpp>

class BaseLight
{
	glm::vec3 color;
	float intensity;
public:

	BaseLight(glm::vec3 color = glm::vec3(1,1,1), float intensity = 0) : color(color), intensity(intensity)
	{
	}

	~BaseLight(void)
	{
	}

	glm::vec3 getColor() { return color; }
	float getIntensity() { return intensity; }
};

