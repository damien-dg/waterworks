
#include "Math.h"
#include "RenderObject.h"
#include <vector>
#include "glfw3.h"


class Renderer
{

	std::vector<RenderObject> renderVector;
private:

	void render(std::vector<RenderObject> renderVector);

public:
		
	GLFWwindow* CreateWindow(Vector2 size);
	Renderer() ;

};

