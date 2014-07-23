#include "Renderer.h"
#include <stdlib.h>
#include <stdio.h>
#include <random>





//class that will take care of creating the window and rendering all of the objects on the screen


Renderer::Renderer(){

	renderVector = {};
	objectVector = {};
	
}



//adds the object to the list of objects kept in memory
void Renderer::addToObject(RenderObject obj){
	
	objectVector.push_back(obj);

}

//adds an object to the vector sent to the buffer (list of traingles to draw)
void Renderer::addToRender(std::vector<glm::vec3> v2){

	renderVector.reserve(renderVector.size() + v2.size());
	renderVector.insert(renderVector.end(), v2.begin(), v2.end());

}

/**creates a window**/
GLFWwindow* Renderer::CreateWindow(glm::vec2 size){
	
	GLFWwindow *window;
	window = glfwCreateWindow(size.x, size.y, "Simple example", NULL, NULL);
	glfwMakeContextCurrent(window);
	return window;
}

/**creates an equilateral traingle at given position and size**/
RenderObject Renderer::createTriangle(glm::vec3 origin, float size){

	float r = size / 2;
	return createObject(origin,		{
									glm::vec3(origin.x - 0.866f*size, origin.y - r, origin.z),
									glm::vec3(origin.x, origin.y + size, origin.z), 
									glm::vec3(origin.x + 0.866f*size, origin.y - r, origin.z) 
									}
						);
	
}
/**creates a square at given position and size**/

RenderObject Renderer::createSquare(glm::vec3 origin, float size) {
	float r = size / 2;
	return createObject(origin, { 
								glm::vec3(origin.x - r, origin.y - r, origin.z),
								glm::vec3(origin.x - r, origin.y + r, origin.z), 
								glm::vec3(origin.x + r, origin.y + r, origin.z),
								glm::vec3(origin.x + r, origin.y + r, origin.z), 
								glm::vec3(origin.x + r, origin.y - r, origin.z),
								glm::vec3(origin.x - r, origin.y - r, origin.z)
								}
						);
}
/**creates an quilateral traingle at given position and size**/
RenderObject Renderer::createRectangle(glm::vec3 origin, float length, float height, float size)
{

	float l = size * length / 2;
	float h = size * height / 2;
	return createObject (origin,	{	
									glm::vec3(origin.x - l, origin.y - h, origin.z),
									glm::vec3(origin.x - l, origin.y + h, origin.z),
									glm::vec3(origin.x + l, origin.y + h, origin.z),
									glm::vec3(origin.x + l, origin.y + h, origin.z),
									glm::vec3(origin.x + l, origin.y - h, origin.z),
									glm::vec3(origin.x - l, origin.y - h, origin.z) 
									}
						);
	
}

/**return vector of vertices to be rendered**/
std::vector<glm::vec3> Renderer::getRenderVector()
{
	return renderVector;
}

std::vector<RenderObject> Renderer::getObjectVector()
{
	return objectVector;
}

RenderObject Renderer::createObject(glm::vec3 position, std::vector<glm::vec3> shape)
{
	RenderObject newObject = RenderObject(position, shape);
	addToObject(newObject);
	addToRender(newObject.shape);
	return newObject;
}

/**updates objects within the object vector**/
void Renderer::updateObjects(int timeElapsed){

	

	for (int i = 0; i < objectVector.size(); i++){
		
		objectVector.at(i).updatePhysics(timeElapsed);
		objectVector.at(i).updateModelMatrix();

	}
}








