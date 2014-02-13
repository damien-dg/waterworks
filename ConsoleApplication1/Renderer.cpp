#include "Renderer.h"
#include "glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <vector>
#include "RenderObject.h"






//class that will take care of creating the window and rendering all of the objects on the screen


Renderer::Renderer(){

	renderVector = {};
	
}

//loops through all objects in render array and updates them
void Renderer::render(std::vector<RenderObject> renderVector){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < renderVector.size; i++){
		//remember to make draw function
		//renderVector.at(i).draw
	}

}

//creates a window
GLFWwindow* Renderer::CreateWindow(Vector2 size){
	
	GLFWwindow *window;
	window = glfwCreateWindow(size.x, size.y, "Simple example", NULL, NULL);
	return window;
}







