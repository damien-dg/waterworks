#include "RenderObject.h"

#include "glfw3.h"


RenderObject::RenderObject()
{
	RenderObject::rigidBody = Physics();
	RenderObject::position = glm::vec3{ 0.f, 0.f, 0.f };
	RenderObject::shape = {};
	RenderObject::modelMatrix = glm::mat4(1.0f);

}

RenderObject::RenderObject(glm::vec3 position, std::vector<glm::vec3> shape)
{
	RenderObject::rigidBody = Physics();
	RenderObject::position = position;
	RenderObject::shape = shape;
	RenderObject::modelMatrix = glm::mat4(1.0f);
}

glm::mat4 RenderObject::getModelMatrix(){
	return modelMatrix;
}

void RenderObject::updatePosition(int timeElapsed){
	
	position = rigidBody.calculatePosition(position, rigidBody.velocity, rigidBody.acceleration, timeElapsed);

}

void RenderObject::updateVelocity(int timeElapsed){

	rigidBody.updateVelocity(timeElapsed);
	
}

void RenderObject::updatePhysics(int timeElapsed){
	if (!rigidBody.gravImmune){
		
		rigidBody.updateAcceleration(glm::vec3{ 0.f, -10.00f, 0.f });
	}
	updateVelocity(timeElapsed);
	updatePosition(timeElapsed);

}

void RenderObject::updateModelMatrix(){
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f),rigidBody.velocity);
	modelMatrix = translationMatrix;
}

glm::vec3 RenderObject::getPosition(){

	return position;
}

void RenderObject::printPropreties(){
	printf("Acceleration: %f, %f, %f\n", rigidBody.acceleration.x, rigidBody.acceleration.y, rigidBody.acceleration.z);
	printf("Velocity: %f, %f, %f\n", rigidBody.velocity.x, rigidBody.velocity.y, rigidBody.velocity.z);


}

void RenderObject::removeGravity(){
	rigidBody.zeroG();
}