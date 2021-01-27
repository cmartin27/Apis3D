#pragma once
#define GLEW_STATIC
#include<GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct texture_t
{
	unsigned int textID;	// Identificador
	int w;					// Ancho
	int h;					// Alto
}texture_t;


// Generación y activación de textura
texture_t* createTexture(const char* filename);

