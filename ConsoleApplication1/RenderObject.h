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

	Physics rigidBody;
	std::vector<glm::vec3> shape;
	

	RenderObject();
	RenderObject(glm::vec3 position, std::vector<glm::vec3> shape);


	glm::mat4 getModelMatrix();
	glm::vec3 getPosition();

	void updatePosition(int timeElapsed);
	void updateVelocity(int timeElpased);
	void updatePhysics(int timeElapsed);
	void updateModelMatrix();
	void printPropreties();
	void removeGravity();

	
};

