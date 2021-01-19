#include "object3D.h"


/////////////////////////////////////////////////
/// CONSTRUCTORES
/////////////////////////////////////////////////

Object3D::Object3D()
{
	this->mesh = new Mesh3D();
	this->pos = glm::vec3(0.0f);
	this->size = glm::vec3(1.0f);
	this->rot = glm::vec3(0.0f);
	this->computeModelMtx();
}


/////////////////////////////////////////////////
/// GETTERS
/////////////////////////////////////////////////

Mesh3D* Object3D::getMesh()
{
	return this->mesh;
}

GLSLShader* Object3D::getGLSLShader()
{
	return this->shader;
}

glm::mat4x4 Object3D::getModelMtx() 
{
	return this->modelMtx;
}

glm::vec3 Object3D::getPos()
{
	return this->pos;
}

glm::vec3 Object3D::getSize()
{
	return this->size;
}

glm::vec3 Object3D::getRot()
{
	return this->rot;
}


/////////////////////////////////////////////////
/// SETTERS
/////////////////////////////////////////////////
void Object3D::setMesh(Mesh3D* mesh)
{
	this->mesh = mesh;
}

void Object3D::setGLSLShader(GLSLShader* shader)
{
	this->shader = shader;
}

void Object3D::setPos(glm::vec3 pos)
{
	this->pos = pos;
}

void Object3D::setSize(glm::vec3 size)
{
	this->size = size;
}

void Object3D::setRot(glm::vec3 rot)
{
	this->rot = rot;
}

/////////////////////////////////////////////////
/// OTROS MÉTODOS
/////////////////////////////////////////////////

void Object3D::computeModelMtx()
{

	// CALCULA MATRIZ MODELO

	// Aplica translación
	glm::mat4 Model = glm::translate(glm::mat4(1.0f), this->pos);

	// Aplica rotación con respecto al eje y
	Model = glm::rotate(Model, this->rot.y, glm::vec3(0.0f, 1.0f, 0.0f));

	// Aplica escalado
	Model = glm::scale(Model, this->size);

	this->modelMtx = Model;
}

