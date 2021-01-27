#include "world.h"

void World::addObject(Object3D* obj)
{
	this->objectList.push_back(obj);
}

void World::addCamera(Camera* cam)
{
	this->cameraList.push_back(cam);
}

void World::removeObject(Object3D* obj)
{
	std::vector<Object3D*>::iterator it = find(this->objectList.begin(), this->objectList.end(), obj);
	this->objectList.erase(it);
}

void World::removeCamera(Camera* cam)
{
	std::vector<Camera*>::iterator it = find(this->cameraList.begin(), this->cameraList.end(), cam);
	this->cameraList.erase(it);
}

size_t World::getNumObjects()
{
	return this->objectList.size();
}
size_t World::getNumCameras()
{
	return this->cameraList.size();
}

Object3D* World::getObject(size_t index)
{
	return this->objectList[index];

}
Camera* World::getCamera(size_t index)
{
	return this->cameraList[index];
}

void World::update(float deltaTime)
{
	// Obtiene el tiempo actual en segundos
	float newTime = glfwGetTime();

	for (std::vector<Object3D*>::size_type i = 0; i != objectList.size(); i++) {
	
			this->objectList[i]->step(newTime);
	}

	for (std::vector<Camera*>::size_type i = 0; i != cameraList.size(); i++) {

		this->cameraList[i]->step(newTime);
	}

	State::projectionMatrix = this->cameraList[this->cameraActive]->getProjection();
	State::viewMatriz = this->cameraList[this->cameraActive]->computeViewMatrix();
}

void World::setActiveCamera(size_t index)
{
	this->cameraActive = index;
}

size_t World::getActiveCamera()
{
	return this->cameraActive;
}