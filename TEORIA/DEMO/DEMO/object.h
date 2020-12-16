#pragma once
#include <cstring>
#include <glm/glm.hpp>
#include <vector>

typedef struct obj_t
{
	int objId;			 // Identificador
	glm::vec3 pos;		 // Posición
	glm::vec3 rot;	     // Rotación
	glm::vec3 scal;		// Escalado
	float color[3];		 // Color
	std::vector<glm::vec4>* vertexList;	 // Lista de vértices
	std::vector<unsigned int>* vertexIdx;      // Indices de vértices
	int numVertex;		 // Número de vértices
}obj_t;

obj_t* createTriangle();