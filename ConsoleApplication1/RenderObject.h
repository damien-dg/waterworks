#pragma once
#include "glm.hpp"
#include "Math.h"
class RenderObject
{

private:
	glm::vec3 position;
	glm::vec3 velocity;
	glm::mat4 modelMatrix;
	
public:

	RenderObject();
	RenderObject(glm::vec3 position, std::vector<glm::vec3> shape);
	glm::mat4 getModelMatrix(); 
	glm::vec3 acceleration;
	std::vector<glm::vec3> shape;
};

