#pragma once
#include <glm/glm.hpp>
typedef struct camera_t
{
	glm::vec3 pos;    // Posición de la cámara
	glm::vec3 lookAt; // Hacia donde está mirando
	glm::vec3 up;	  // Hacia donde está "arriba" en la cámara
}camera_t;

// Constructor
camera_t* createCamera(glm::vec3 pos, glm::vec3 lookAt, glm::vec3 up);
// Método que mueve la cámara
void moveCamera(camera_t* cam);
// Calcula la matriz de vista
glm::mat4 computeViewMatrix(camera_t* cam);
