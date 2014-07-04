#include "RenderObject.h"

#include "glfw3.h"


RenderObject::RenderObject()
{
	RenderObject::position = glm::vec3{ 0, 0, 0 };
	RenderObject::acceleration = glm::vec3{ 0, 0, 0 };
	RenderObject::velocity = glm::vec3{ 0, 0, 0 };
	RenderObject::shape = {};
	RenderObject::modelMatrix = glm::mat4(1.0f);

}

RenderObject::RenderObject(glm::vec3 position, std::vector<glm::vec3> shape)
{
	RenderObject::position = position;
	RenderObject::acceleration = glm::vec3{ 0, 0, 0 };
	RenderObject::velocity = glm::vec3{ 0, 0, 0 };
	RenderObject::shape = shape;
	RenderObject::modelMatrix = glm::mat4(1.0f);
}

glm::mat4 RenderObject::getModelMatrix(){
	return modelMatrix;
}