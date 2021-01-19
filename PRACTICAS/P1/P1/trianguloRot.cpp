#include "trianguloRot.h"


TrianguloRot::TrianguloRot():Object3D()
{
	// Coordenadas de los vértices por defecto
	vertex_t v1, v2,v3;
	v1.vertexID = 0;
	v1.pos = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);
	v2.vertexID = 1;
	v2.pos = glm::vec4(-0.5f, 0.0f, 0.0f, 1.0f);
	v3.vertexID = 2;
	v3.pos = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);

	// Añade los vértices a la malla
	this->mesh->addVertex(v1);
	this->mesh->addVertex(v2);
	this->mesh->addVertex(v3);

	// Añade los índices de los triángulos a la malla
	this->mesh->addTriangleIdx(v1.vertexID,v3.vertexID, v2.vertexID);
	this->lastStep = -1;
}

void TrianguloRot::step()
{
	// Obtiene el tiempo actual en segundos
	float newTime = glfwGetTime();
	double velocity = 32.0f;      // Velocidad de 32 grados/s

	// Calcula la diferencia de tiempos
	double deltaTime = newTime - lastStep;

	// Si se pulsa la f se gira en sentido horario
	if (keybEvent[GLFW_KEY_F])
	{
		this->rot.y -= velocity * deltaTime;
	}
	// Si se pulsa la h se gira en sentido antihorario
	if (keybEvent[GLFW_KEY_H])
	{
		this->rot.y += velocity * deltaTime;
	}

	// Actualiza el instante de tiempo
	lastStep = newTime;

}