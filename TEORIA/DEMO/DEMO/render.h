#pragma once
#include "object.h"
#include <map>
#define GLEW_STATIC
#include<GL/glew.h>
#include <GLFW/glfw3.h>


typedef struct boIDs_t
{
	unsigned int id;
	unsigned int vbo;
	unsigned int idxbo;

}boIDs_t;

void uploadObj(obj_t* obj);
void deleteObj(obj_t* obj);
void drawObj(obj_t* obj,int shader);