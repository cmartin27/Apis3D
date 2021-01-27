#pragma once
#include <glm/glm.hpp>
typedef struct camera_t
{
	glm::vec3 pos;    // Posici�n de la c�mara
	glm::vec3 lookAt; // Hacia donde est� mirando
	glm::vec3 up;	  // Hacia donde est� "arriba" en la c�mara
}camera_t;

// Constructor
camera_t* createCamera(glm::vec3 pos, glm::vec3 lookAt, glm::vec3 up);
// M�todo que mueve la c�mara
void moveCamera(camera_t* cam);
// Calcula la matriz de vista
glm::mat4 computeViewMatrix(camera_t* cam);
