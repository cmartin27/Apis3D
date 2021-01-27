#include "camera.h"
#include "eventManager.h"
#include <glm/gtc/matrix_transform.hpp>

camera_t* createCamera(glm::vec3 pos, glm::vec3 lookAt, glm::vec3 up)
{
	camera_t* cam = new camera_t;
	cam->pos = pos;
	cam->lookAt = lookAt;
	cam->up = up;
	return cam;

}
// M�todo que mueve la c�mara
void moveCamera(camera_t* cam)
{
	// Actualiza posici�n de la c�mara
	if (keybEvent[GLFW_KEY_UP])
	{
		cam->pos.y += 0.001;
	}

	if (keybEvent[GLFW_KEY_DOWN])
	{
		cam->pos.y -= 0.001;
	}
	if (keybEvent[GLFW_KEY_RIGHT])
	{
		cam->pos.x += 0.001;
	}

	if (keybEvent[GLFW_KEY_LEFT])
	{
		cam->pos.x -= 0.001;
	}

	if (keybEvent[GLFW_KEY_S])
	{
		cam->pos.z += 0.001;
	}

	if (keybEvent[GLFW_KEY_W])
	{
		cam->pos.z -= 0.001;
	}

	// Actualiza punto al que mira la c�mara
	cam->lookAt = cam->pos;
	cam->lookAt.z -= 3.0f;

}

glm::mat4 computeViewMatrix(camera_t* cam)
{
	return glm::lookAt(cam->pos, cam->lookAt, cam->up);
}
