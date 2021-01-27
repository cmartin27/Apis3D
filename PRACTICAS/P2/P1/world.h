#pragma once
#include <vector>
#include "object3D.h"
#include "camera.h"

class World
{
private:
	std::vector<Object3D*> objectList;
	std::vector<Camera*> cameraList;
	size_t cameraActive;
public:
	void addObject(Object3D* obj);
	void addCamera(Camera* cam);
	void removeObject(Object3D* obj);
	void removeCamera(Camera* cam);
	size_t getNumObjects();
	size_t getNumCameras();
	Object3D* getObject(size_t index);
	Camera* getCamera(size_t index);
	void update(float deltaTime);
	void setActiveCamera(size_t index);
	size_t getActiveCamera();

};

