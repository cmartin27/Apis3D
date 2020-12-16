#include "shaderManager.h"

// Código del shader de vertices
const char* vertexShader = "\n\
#version 330 \n\
\n\
in vec4 vertex;\n\
out vec4 vertexColor; \n\
\n\
void main()\n\
{\n\
\n\
gl_Position=vertex;\n\
vertexColor=vec4(1.0f,0.0f,0.0f,1.0f);\n\
}\n\
";

// Código del shader de fragmentos
// tiene como entrada, la salida del shader de vertices (mismo nombre)
const char* fragmentShader = "\n\
#version 330 \n\
 \n\
in vec4 vertexColor; \n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
\n\
fragColor=vec4(1.0f,0.0f,0.0f,1.0f);\n\
}\n\
";

// Función que compila un trozo de código fuente
int compileShader(const char* code, GLenum shaderType)
{
	int shaderId = glCreateShader(shaderType);
	glShaderSource(shaderId,1,&code,nullptr);
	glCompileShader(shaderId);
	return shaderId;
}

int compileAndLinkShader(const char* vertexShader, const char* fragmentShader)
{
	int programId, vertexId, fragmentId;
	programId = glCreateProgram();

	// Compila los shaders
	vertexId = compileShader(vertexShader, GL_VERTEX_SHADER);
	fragmentId = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

	// Linkea los shader
	glAttachShader(programId, vertexId);
	glAttachShader(programId, fragmentId);
	glLinkProgram(programId);

	// Elimina los precompilados porque ya están linkeados en el programa
	glDetachShader(programId,vertexId);
	glDetachShader(programId,fragmentId);
	glDeleteShader(vertexId);
	glDeleteShader(fragmentId);

	return programId;
}