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
	bool gravImmune;
	int time = 0;
	glm::vec3 velocity;
	glm::vec3 acceleration;

	Physics();
	
	glm::vec3 calculatePosition(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, int frameTime);
	void updateVelocity(int frameTime);
	void updateAcceleration(glm::vec3);
	void zeroG();
	void setTime(int newTime);
};