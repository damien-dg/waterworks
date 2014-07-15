#include "physics.h"



Physics::Physics()
{

	velocity = { 0.0f, 0.0f, 0.0f };
	acceleration = { 0.0f, 0.0f, 0.0f };
	inverseMass = 1.0f;
	gravImmune = false;

}
glm::vec3 Physics::calculatePosition(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration)
{
	return  (position + (velocity*time) + (acceleration * time * time * 0.5f));
}
void Physics::updateVelocity(){
	
	velocity = velocity + (acceleration * time);
}
void Physics::updateAcceleration(glm::vec3 newAcc){
	acceleration = newAcc;
}

void Physics::zeroG(){
	gravImmune = true;
}