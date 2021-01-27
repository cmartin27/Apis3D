#include "mesh3D.h"



/////////////////////////////////////////////////
/// CONSTRUCTORES
/////////////////////////////////////////////////
Mesh3D::Mesh3D()
{
	this->meshID = idGenerator;
	idGenerator++;
	this->vVertList = new std::vector<vertex_t>();
	this->vIdxList = new std::vector<glm::int32>();
	this->colorRGB = glm::vec3(1.0f, 1.0f, 1.0f);
	this->numTriangles = 0;
}

/////////////////////////////////////////////////
/// GETTERS
/////////////////////////////////////////////////

glm::uint32 Mesh3D::getMeshID()
{
	return this->meshID;
}

std::vector<vertex_t>* Mesh3D::getVertList()
{
	return this->vVertList;
}


std::vector<glm::int32>* Mesh3D::getIdxList()
{
	return this->vIdxList;
}

glm::vec3 Mesh3D::getColorRGB()
{
	return this->colorRGB;
}

int Mesh3D::getNumTriangles()
{
	return this->numTriangles;
}

std::vector<glm::vec4>* Mesh3D::getPosVert()
{
	std::vector<glm::vec4>* posiciones =  new std::vector<glm::vec4>();

	for (int i= 0; i < vVertList->size(); i++)
	{
		posiciones->push_back(this->vVertList->data()[i].pos);
	}

	return posiciones;
}
/////////////////////////////////////////////////
/// SETTERS
/////////////////////////////////////////////////

void Mesh3D::setColorRGB(float r, float g, float b)
{
	this->colorRGB = glm::vec3(r, g, b);
}

/////////////////////////////////////////////////
/// OTROS MÉTODOS
/////////////////////////////////////////////////

void Mesh3D::addVertex(vertex_t vert)
{
	this->vVertList->push_back(vert);
}

void Mesh3D::addIdx(glm::int32 id)
{
	this->vIdxList->push_back(id);
}

void Mesh3D::addTriangleIdx(glm::int32 v1, glm::int32 v2, glm::int32 v3)
{
	this->addIdx(v1);
	this->addIdx(v2);
	this->addIdx(v3);
	this->numTriangles++;
}

