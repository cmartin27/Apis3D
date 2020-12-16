#pragma once
#include "render.h"


int compileShader(const char* code, GLenum shaderType);
int compileAndLinkShader(const char* vertexShader, const char* fragmentShader); 
extern const char* vertexShader;
extern const char* fragmentShader;

