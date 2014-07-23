#include "glfw3.h"
#include "controls.h"




glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}
glm::mat4 getViewMatrix(){
	
	return ViewMatrix;
		
}

// Initial position : on + Z
glm::vec3 position = glm::vec3(0, 0, 20);
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;

void computeMatricesFromInputs(GLFWwindow * window){

	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);
	lastTime = currentTime;
	float speed = 3.0f;
	
	
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
		);
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
		);
	glm::vec3 up = glm::cross(right, direction);

	

	//move up
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
		position -= up * deltaTime * speed;
	}
	// Move down
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
		position += up * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){

	//	ProjectionMatrix = glm::ortho(-10.0f - deltaTime, 10.0f + deltaTime, -10.0f - deltaTime, 10.0f + deltaTime, 0.1f, 100.0f);
		

	}
	ProjectionMatrix = glm::perspective(20.0f,
										16.0f / 9.0f,
										0.1f,
										100.0f);
	//glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);
	ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
		);
	lastTime = currentTime;

}