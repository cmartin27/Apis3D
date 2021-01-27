#include "object3D.h"


/////////////////////////////////////////////////
/// CONSTRUCTORES
/////////////////////////////////////////////////

Object3D::Object3D():Entity()
{
	std::vector<Mesh3D*> empty;
	this->meshList = empty;
}


/////////////////////////////////////////////////
/// GETTERS
/////////////////////////////////////////////////

std::vector<Mesh3D*> Object3D::getMeshList()
{
	return this->meshList;
}

Mesh3D* Object3D::getMesh(int meshID)
{
	return this->meshList[meshID];
}

int Object3D::getMeshCount()
{
	return (int)this->meshList.size();
}

std::vector<GLSLShader*> Object3D::getGLSLShaderList()
{
	return this->shaderList;
}

GLSLShader* Object3D::getGLSLShader(int shaderID)
{
	return this->shaderList[shaderID];
}

int Object3D::getShaderCount()
{
	return (int)this->shaderList.size();
}


/////////////////////////////////////////////////
/// SETTERS
/////////////////////////////////////////////////

void Object3D::setMesh(Mesh3D* mesh, int meshID)
{
	this->meshList[meshID] = mesh;
}
void Object3D::setMeshList(std::vector<Mesh3D*> meshList)
{
	this->meshList = meshList;
}
void Object3D::setGLSLShader(GLSLShader* shader, int shaderID)
{
	this->shaderList[shaderID] = shader;
}
void Object3D::setGLSLShaderList(std::vector<GLSLShader*> shaderList)
{
	this->shaderList = shaderList;
}



/////////////////////////////////////////////////
/// OTROS MÉTODOS
/////////////////////////////////////////////////


void Object3D::addMesh(Mesh3D* mesh, GLSLShader* shader)
{
	this->meshList.push_back(mesh);
	this->shaderList.push_back(shader);
}