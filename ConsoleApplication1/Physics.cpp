#include "physics.h"



Physics::Physics()
{

	velocity = { 0.0f, 0.0f, 0.0f };
	acceleration = { 0.0f, 0.0f, 0.0f };
	inverseMass = 1.0f;
	gravImmune = false;

}
glm::vec3 Physics::calculatePosition(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, int frameTime)
{
	
	return  (position + (velocity*float(frameTime) / 1000.f) + (acceleration * float(frameTime) / 1000.f  * float(frameTime) / 1000.f  * 0.5f));

}
void Physics::updateVelocity(int frameTime){
	
	velocity = velocity + (acceleration * float(frameTime)/1000.f );
}
void Physics::updateAcceleration(glm::vec3 newAcc){
	acceleration = newAcc;
}

void Physics::zeroG(){
	gravImmune = true;
}

void Physics::setTime(int newTime){
	time = newTime;
}