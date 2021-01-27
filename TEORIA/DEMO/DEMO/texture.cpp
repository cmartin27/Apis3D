#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

texture_t* createTexture(const char* filename)
{
	texture_t* text = new texture_t;
	// Carga datos
	unsigned char* data = stbi_load(filename, &text->w, &text->h, nullptr, STBI_rgb_alpha);
	// Paso 1: Genera la textura en OpenGL
	glGenTextures(1, &text->textID);
	// Paso 2: Activa la textura
	glBindTexture(GL_TEXTURE_2D, text->textID);

	// Paso 3: Fija parámetros
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Paso 4: Carga de la imagen (de CPU a GPU)
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, text->w, text->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	// Paso 5: Generar mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);

	// Libera datos
	stbi_image_free(data);
	return text;
}