#include "object.h"
#include "eventManager.h"

obj_t* createTriangle()
{
	static int idGenerator = 0;
	// DATOS DEL OBJETO

	// Vértices del objeto
	/*
	float triangle[3][4] = { {0.0f, 0.5f, 0.0f,1.0f},
							{-0.5f,0.0f,0.0f,1.0f},
							{0.5f,0.0f,0.0f,1.0f} };*/

	// Índices del objeto
	//int idxList[3] = { 0,2,1 };
	// Color del triángulo
	float color[3] = { 1.0f,1.0f,1.0f };
	// Desplazamiento del objeto
	//float desplazamiento[4] = { 0.0f,0.0f,0.0f,0.0f };
	glm::vec3 desplazamiento(0.0f, 0.0f, 0.0f);

	// ESTRUCTURA DEL OBJETO

	// Crea estructura del objeto
	obj_t* newObj = new obj_t[1];

	// Asigna el id de manera única
	newObj->objId = idGenerator;
	idGenerator++;

	// Creamos la malla del objeto
	newObj->mesh = new mesh_t;

	// Asigna color
	memcpy(newObj->color, color, sizeof(float) * 3);

	// Asignalos datos de los índices
	newObj->mesh->vertexIdx = new std::vector<unsigned int>();
	newObj->mesh->vertexIdx->push_back(0);
	newObj->mesh->vertexIdx->push_back(2);
	newObj->mesh->vertexIdx->push_back(1);
	//memcpy(newObj->vertexIdx, idxList, sizeof(int) * 3);

	// Asigna los datos de vértices
	newObj->mesh->numVertex = 3;
	newObj->mesh->vertexList = new std::vector<vertex_t>();
	newObj->mesh->vertexList->push_back(vertex_t{ glm::vec4(0.0f, 0.5f, 0.0f, 1.0f), glm::vec2(0.5f,1.0f) });
	newObj->mesh->vertexList->push_back(vertex_t{ glm::vec4(-0.5f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f,0.0f) });
	newObj->mesh->vertexList->push_back(vertex_t{ glm::vec4(0.5f, 0.0f, 0.0f, 1.0f), glm::vec2(1.0,0.0f) });
	//memcpy(newObj->vertexList, triangle, sizeof(float) * 3 * 4);

	// Almacena desplazamiento desde el origen del objeto
	//newObj->pos = desplazamiento;
	newObj->pos[0] = newObj->pos[1] = 0.0f;
	newObj->pos[2] = -5.0f;
	newObj->rot[0] = newObj->rot[1] = newObj->rot[2] = 0.0f;
	newObj->scal[0] = newObj->scal[1] = newObj->scal[2] = 1.0f;


	//memcpy(newObj->pos, desplazamiento, sizeof(int) * 4);

	// CREAMOS EL MATERIAL
	newObj->mat = new material_t;
	newObj->mat->text = createTexture("DATA/top.png");

	// Devuelve el objeto
	return newObj;
}

void moveTriangle(obj_t* obj)
{
	float distancia = 0.0001f;
	// Translacción derecha e izquierda
	if (keybEvent[GLFW_KEY_A])
	{
		obj->pos.x -= distancia;
	}
	if (keybEvent[GLFW_KEY_D])
	{
		obj->pos.x += distancia;
	}

	if (keybEvent[GLFW_KEY_F])
	{
		//printf("Rotacion antes: %f\n", obj->rot.y);
		obj->rot.y -= 0.001;
		//printf("Rotacion despues: %f\n", obj->rot.y);
	}
	if (keybEvent[GLFW_KEY_H])
	{
		obj->rot.y += 0.001;
	}
}

void setShaderID(obj_t* obj, unsigned int shaderId)
{
	obj->mat->shaderID = shaderId;
}