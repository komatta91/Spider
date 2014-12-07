#pragma once
#include <glm\vec3.hpp>
#include <glm\vector_relational.hpp>

#include <BaseLight.h>

class DirectionalLight
{
	BaseLight base;
	glm::vec3 direction;
public:

	DirectionalLight(BaseLight base = BaseLight(), glm::vec3 direction = glm::vec3(0, 0, 0)) : base(base)
	{
		this->direction = direction;
	}

	~DirectionalLight(void)
	{
	}

	inline BaseLight getBaseLight() { return base; }
	inline glm::vec3 getDirection() { return direction; }
};

