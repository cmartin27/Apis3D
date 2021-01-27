#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, glm::vec3 lookAt):Entity()
{
	this->setPos(position);
	this->lookAt = lookAt;
	this->up = up;
	this->clearColor = glm::vec3(0, 0, 0);
	this->projection = glm::mat4();
}

const glm::mat4& Camera::getProjection()
{
	return projection;
}
void Camera::setProjection(const glm::mat4& proj)
{
	this->projection = proj;
}
void Camera::setClearColor(const glm::vec3& color)
{
	this->clearColor = color;
}
const glm::vec3& Camera::getClearColor()
{
	return clearColor;
}
void Camera::prepare()
{
	State::viewMatriz = glm::lookAt(this->getPos(), this->lookAt, this->up);
	State::projectionMatrix = this->projection;
	glClearColor(this->clearColor.r,this->clearColor.g, this->clearColor.b, 1.0f);
	// Limpia buffer de color y profundidad
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
void Camera::step(float deltaTime)
{
	glm::vec3 posAct = this->getPos();
	float velocity = 0.0001f;      // Velocidad de movimiento

	// Actualiza posición de la cámara
	if (keybEvent[GLFW_KEY_UP])
	{
		posAct.y += velocity * deltaTime;
	}

	if (keybEvent[GLFW_KEY_DOWN])
	{
		posAct.y -= velocity * deltaTime;
	}
	if (keybEvent[GLFW_KEY_RIGHT])
	{
		posAct.x += velocity * deltaTime;
	}

	if (keybEvent[GLFW_KEY_LEFT])
	{
		posAct.x -= velocity * deltaTime;
	}

	if (keybEvent[GLFW_KEY_S])
	{
		posAct.z += velocity * deltaTime;
	}

	if (keybEvent[GLFW_KEY_W])
	{
		posAct.z -= velocity * deltaTime;
	}
	this->setPos(posAct);

	// Actualiza punto al que mira la cámara
	this->lookAt = this->getPos();
	this->lookAt.z -= 3.0f;
}

glm::mat4 Camera::computeViewMatrix()
{
	return glm::lookAt(this->getPos(), this->lookAt, this->up);
}