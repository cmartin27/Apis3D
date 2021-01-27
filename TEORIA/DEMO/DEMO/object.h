#pragma once
#include <cstring>
#include <glm/glm.hpp>
#include <vector>
#include "texture.h"

typedef struct vertex_t
{
	glm::vec4 pos;
	glm::vec2 textCoord;
}vertex_t;

typedef struct material_t
{
	texture_t* text;		// Textura
	int shaderID;			// Id del shader
}material_t;

typedef struct mesh_t
{
	std::vector<vertex_t>* vertexList;	 // Lista de v�rtices
	std::vector<unsigned int>* vertexIdx;      // Indices de v�rtices
	int numVertex;		 // N�mero de v�rtices
};
typedef struct obj_t
{
	int objId;			 // Identificador
	glm::vec3 pos;		 // Posici�n
	glm::vec3 rot;	     // Rotaci�n
	glm::vec3 scal;		 // Escalado
	float color[3];		 // Color
	mesh_t* mesh;        // Malla del objeto
	material_t* mat;     // Material del objeto

}obj_t;




obj_t* createTriangle();
void setShaderID(obj_t* obj, unsigned int shaderId);
void moveTriangle(obj_t* obj);