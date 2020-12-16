#include "render.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
std::map<int, boIDs_t> vboList;  // Lista que almacena objetos segun indices

/* Función que copia datos de CPU a GPU*/
void uploadObj(obj_t* obj)
{
	// Variables
	boIDs_t boIds;

	// Avisa a OpenGL de que necesito arrays
	glGenVertexArrays(1, &boIds.id);
	glGenBuffers(1, &boIds.vbo);					// Genera un buffer
	glGenBuffers(1, &boIds.idxbo);					// Genera un buffer
	// Activa el buffer
	glBindVertexArray(boIds.id);


	// Crea un buffer de vértices
	glBindBuffer(GL_ARRAY_BUFFER, boIds.vbo);		// Activa operaciones sobre el buffer
	// Pasa vértices a GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * 4, obj->vertexList->data(), GL_STATIC_DRAW); // size: num_vertices * coord_vertices
	

	// Crea un buffer de índices

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, boIds.idxbo);	// Activa operaciones sobre el buffer
	// Pasa índices a GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*1*3, obj->vertexIdx->data(), GL_STATIC_DRAW); // size: num_triangulos*vertices_triangulos

	
	vboList[obj->objId] = boIds;


}



void deleteObj(obj_t* obj)
{
	boIDs_t boIds;
	boIds = vboList[obj->objId];
	// Borra buffer de vértices
	glDeleteBuffers(1, &boIds.vbo);
	// Borra buffer de índices
	glDeleteBuffers(1, &boIds.idxbo);
	
	glDeleteVertexArrays(1, &boIds.id);
}
// Dibuja objeto sin shaders
/*
void drawObj(obj_t* obj)
{
	// Busca los buffers del objeto
	boIDs_t boIds;
	boIds = vboList[obj->objId];
	int idVertices = 0; // get variable from shader

	// Habilia los arrays de atributos
	glEnableVertexAttribArray(idVertices);

	// Activa los buffers
	glBindVertexArray(boIds.id);
	glBindBuffer(GL_ARRAY_BUFFER, boIds.vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, boIds.idxbo);

	// Describe el array de datos
	// 0: posición de la variable
	// 4: Agrupaciones de 4 vértices
	// GL_FLOAT: Tipo de vértices
	glVertexAttribPointer(idVertices, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	// Asigna color
	glColor3f(1.0f,1.0f,1.0f);
	// Dibuja el objeto
	glDrawArrays(GL_TRIANGLES, 0, 3); // 0: primera posicion, 3: numero de indices
}*/

// Dibuja objeto con shaders
void drawObj(obj_t* obj, int shader)
{
	// Busca los buffers del objeto
	boIDs_t boIds;
	boIds = vboList[obj->objId];
	int idVertices = 0; // get variable from shader


	// Activa los buffers
	glBindVertexArray(boIds.id);
	glBindBuffer(GL_ARRAY_BUFFER, boIds.vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, boIds.idxbo);

	// Describe el array de datos
	// 0: posición de la variable
	// 4: Agrupaciones de 4 vértices
	// GL_FLOAT: Tipo de vértices

	glUseProgram(shader);
	// Habilia los arrays de atributos
	glEnableVertexAttribArray(idVertices);
	glVertexAttribPointer(idVertices, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	// Asigna color
	//glColor3f(1.0f,1.0f,1.0f);
	// Dibuja el objeto sin shader
	//glDrawArrays(GL_TRIANGLES, 0, 3); // 0: primera posicion, 3: numero de indices
	// Dibuja el objeto con shader
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}
