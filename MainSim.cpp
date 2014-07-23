
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <time.h>
#include <random>
#include "ConsoleApplication1/controls.h"
#include "ConsoleApplication1/Loader.h"
#include "ConsoleApplication1/FirstShader.hpp"
#include <gtc/type_ptr.hpp>



#define GLEW_STATIC


int main(void)
{

	

	Renderer renderer = Renderer();
	glm::vec2 vector;
	vector.x = 1280.f;
	vector.y = 720.f;
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

	

	GLFWwindow* window = (renderer.CreateWindow(vector));
	if (window == NULL)
	{ 
		
		printf("FAIL"); 
		glfwTerminate();
		return -1;

	};
	
	

	glewExperimental = GL_TRUE; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	//activate key capturing
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	//dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	
	

	//creating the traingles that will be rendered (first triangles, then we will move on to actual objects
	//render vector
	
	//individual trianges to be added to the vector
	Loader mainLoader = Loader();
	renderer.createObject(glm::vec3(1.f, 1.f, 1.f), mainLoader.loadOBJ(renderer, "C:/Users/Damien/Desktop/Suzanne.obj"));
//	RenderObject firstTriangle = renderer.createTriangle(glm::vec3(3, 3, -20), 1.f);
//	RenderObject secondTriangle = renderer.createTriangle(glm::vec3(0, 0, 0), 3.f);
//	RenderObject firstSquare = renderer.createSquare(glm::vec3(-4, -3, 0), 2.f);
//	RenderObject firstRectangle = renderer.createRectangle(glm::vec3(0, -10, 0), 400, 4, 1);
	
	renderer.objectVector.at(0).removeGravity();
//	renderer.objectVector.at(1).removeGravity();
//	renderer.objectVector.at(2).removeGravity();
//	renderer.objectVector.at(3).removeGravity();
	printf("%f, %f, %f\n", renderer.objectVector.at(0).getPosition().x, renderer.objectVector.at(0).getPosition().y, renderer.objectVector.at(0).getPosition().z);
	printf("%d\n", renderer.objectVector.at(0).rigidBody.gravImmune);
	
	//load the shaders
	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "./SimpleFragmentShader.fragmentshader");

	// This will identify our vertex buffer
	GLuint vertexbuffer;

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, renderer.getRenderVector().size() * sizeof(glm::vec3), &renderer.getRenderVector()[0], GL_STATIC_DRAW);

	//Generating Model, View and Projection matrices
	//-------------------------------------------------------------------
	// Projection matrix : 45Åã Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	//ortho option
		//glm::mat4 Projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);
	//perspective option
	glm::mat4 Projection = glm::perspective(
		65.0f,         // The horizontal Field of View, in degrees : the amount of "zoom". Think "camera lens". Usually between 90Åã (extra wide) and 30Åã (quite zoomed in)
		16.0f/9.0f, // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
		0.1f,        // Near clipping plane. Keep as big as possible, or you'll get precision issues.
		100.0f       // Far clipping plane. Keep as little as possible.
		);
	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(0, 0, 20), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

	// Model matrix : an identity matrix (model will be at the origin)

	glm::mat4 Model = glm::mat4(1.0f);  // Changes for each model !
	
	// Our ModelViewProjection : multiplication of our 3 matrices
	//-----------------------------------------------------------------------

	// Get a handle for our "MVP" uniform.
	// Only at initialisation time.
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint color = glGetUniformLocation(programID, "time");
	glm::vec3 randomColorValue = { 0.0f, 0.0f, 0.0f };
	int timeCounter = 0;
	
	typedef std::chrono::high_resolution_clock clock;
	
	int lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(clock::now().time_since_epoch()).count();
	int frameCounter = std::chrono::duration_cast<std::chrono::milliseconds>(clock::now().time_since_epoch()).count();


	do{
		
		
		int currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(clock::now().time_since_epoch()).count();
		int elapsed = currentTime - lastTime;
	
		
		
		//use the shaders

		//first, clear screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//use the shaders
		glUseProgram(programID);
		/*** 
		
		1rst attribute buffer : vertices
		
		***/
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size (3-d)
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);

		
		int offset = 0;
		computeMatricesFromInputs(window);
		View = getViewMatrix();
		Projection = getProjectionMatrix();

		//update all objects BEFORE rendering
		renderer.updateObjects(elapsed);

		//color shader
		glUniform3f(color, 1.f, 1.f, 1.f);
		for (int i = 0; i<renderer.getObjectVector().size(); i++)
		{
			//printf("DRAWING\n");
			glm::mat4 MVP = Projection * View * renderer.getObjectVector().at(i).getModelMatrix();
			// Send our transformation to the currently bound shader,
			// in the "MVP" uniform
			// For each model you render, since the MVP will be different (at least the M part)
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

			//draw each shape one by one
			glDrawArrays(GL_TRIANGLES, offset, renderer.getObjectVector().at(i).shape.size()); 
			//update the offset so the next draw call knows where to start
			offset += renderer.getObjectVector().at(i).shape.size();
		
			
		
			
		}

		timeCounter++;

		//framerate counter

		if (currentTime - frameCounter > 1000)
		{

			frameCounter = std::chrono::duration_cast<std::chrono::milliseconds>(clock::now().time_since_epoch()).count();
			printf("%d\n", timeCounter);
			timeCounter = 0;
		}

		lastTime = currentTime;
		offset = 0;

		//disable vertex attribute
		glDisableVertexAttribArray(0);
		

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window) == 0);

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);


	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
	

}


