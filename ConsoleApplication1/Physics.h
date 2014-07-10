#include "glm.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <ctime>

class Physics{

	

private:

	float inverseMass;
	float damping;
	

public:

	Physics();
	float time = 0.33333f;
	glm::vec3 velocity;
	glm::vec3 acceleration;

	glm::vec3 calculatePosition(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration);
	void updateVelocity();
	void updateAcceleration(glm::vec3);
	
	 
};