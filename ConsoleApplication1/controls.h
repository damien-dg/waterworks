#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "glfw3.h"

glm::mat4 getProjectionMatrix();
glm::mat4 getViewMatrix();
void computeMatricesFromInputs(GLFWwindow * window);