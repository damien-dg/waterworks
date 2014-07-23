#include "controls.h"

#include "RenderObject.h"
#include "glfw3.h"


class Renderer
{
	

	
private:

	
	std::vector<glm::vec3> renderVector;
	void render(std::vector<RenderObject> renderVector);

public:
	
	std::vector<RenderObject> objectVector;
	
	Renderer() ;
	GLFWwindow* CreateWindow(glm::vec2 size);
	RenderObject createObject(glm::vec3 position, std::vector<glm::vec3> shape);

	RenderObject createTriangle(glm::vec3 origin, float size);
	RenderObject createSquare(glm::vec3 origin, float size);
	RenderObject createRectangle(glm::vec3 origin, float length, float height, float size);

	void addToRender( std::vector<glm::vec3> v2);
	void addToObject(RenderObject obj);

	std::vector<glm::vec3> getRenderVector();
	std::vector<RenderObject> getObjectVector();
	void updateObjects(int timeElapsed);
	
};

