#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Math.h"
#include "Physics.h"
class RenderObject
{

private:
	glm::vec3 position;
	
	glm::mat4 modelMatrix;

	

	
public:

	void updatePosition();
	void updateVelocity();

	Physics rigidBody;

	void updatePhysics();
	void updateModelMatrix();
	void printPropreties();

	glm::vec3 getPosition();

	RenderObject();
	RenderObject(glm::vec3 position, std::vector<glm::vec3> shape);

	glm::mat4 getModelMatrix(); 
	
	std::vector<glm::vec3> shape;
};

