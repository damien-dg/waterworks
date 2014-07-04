#include "controls.h"

#include "RenderObject.h"
#include "glfw3.h"


class Renderer
{
	

	
private:

	std::vector<RenderObject> objectVector;
	std::vector<glm::vec3> renderVector;
	void render(std::vector<RenderObject> renderVector);

public:
	

	GLFWwindow* CreateWindow(glm::vec2 size);
	Renderer() ;
	
	std::vector<glm::vec3> createTriangle(glm::vec3 origin, float size);
	void addToRender( std::vector<glm::vec3> v2);
	void addToObject(RenderObject obj);

	std::vector<glm::vec3> getRenderVector();
	std::vector<RenderObject> getObjectVector();

	RenderObject createObject(glm::vec3 position, std::vector<glm::vec3> shape);
};

