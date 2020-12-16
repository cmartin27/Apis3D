#include "eventManager.h"


char keybEvent[512];
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
	switch (action) 
	{
		case GLFW_PRESS:
			printf("Tecla apretada %d\n", key);
			keybEvent[key] = true;
			break;
		case GLFW_RELEASE:
			printf("Tecla liberada %d\n", key);
			keybEvent[key] = false;
			break;
		default:
			break;

	}


}