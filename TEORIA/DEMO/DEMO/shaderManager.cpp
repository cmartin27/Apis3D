#include "shaderManager.h"

// Código del shader de vertices
// Se ejecuta una vez por cada vértice
const char* vertexShader = "\n\
#version 330 \n\
uniform mat4 MVP;\n\
in vec4 vpos;\n\
in vec2 vtex;\n\
out vec4 vertexColor;\n\
out vec2 ftex; \n\
\n\
void main()\n\
{\n\
\n\
gl_Position=MVP*vpos;\n\
vertexColor=vec4(1.0f,0.0f,0.0f,1.0f);\n\
ftex=vtex;\n\
}\n\
";

// Código del shader de fragmentos
// tiene como entrada, la salida del shader de vertices (mismo nombre)
const char* fragmentShader = "\n\
#version 330 \n\
 \n\
uniform sampler2D texSampler;\n\
in vec2 ftext;\n\
in vec4 vertexColor; \n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
\n\
fragColor=vertexColor;\n\
/*fragColor=texture2D(texSampler,ftex);*/\n\
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