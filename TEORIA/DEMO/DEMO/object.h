#pragma once
#include <cstring>
#include <glm/glm.hpp>
#include <vector>

typedef struct obj_t
{
	int objId;			 // Identificador
	glm::vec3 pos;		 // Posici�n
	glm::vec3 rot;	     // Rotaci�n
	glm::vec3 scal;		// Escalado
	float color[3];		 // Color
	std::vector<glm::vec4>* vertexList;	 // Lista de v�rtices
	std::vector<unsigned int>* vertexIdx;      // Indices de v�rtices
	int numVertex;		 // N�mero de v�rtices
}obj_t;

obj_t* createTriangle();