#pragma once
#include "entity.h"

class Camera : public Entity
{

private:
	glm::mat4 projection;
	glm::vec3 clearColor;
	glm::vec3 up;
	glm::vec3 lookAt;

public:
	Camera(glm::vec3 position, glm::vec3 up, glm::vec3 lookAt);
	const glm::mat4& getProjection();
	void setProjection(const glm::mat4& proj);
	void setClearColor(const glm::vec3& color);
	const glm::vec3& getClearColor();
	void prepare();
	glm::mat4 computeViewMatrix();
	void step(float deltaTime);

};

