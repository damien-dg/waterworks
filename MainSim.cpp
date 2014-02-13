
#include "glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include "ConsoleApplication1/Renderer.h"


int main(void)
{
	Renderer renderer = Renderer::Renderer();
	Vector2 vector;
	vector.x = 640.f;
	vector.y = 480.f;
	glfwInit();
	if ((renderer.CreateWindow(vector)) == NULL)
	{ 
		
		printf("FAIL"); 
		
	};
	

}
