#include "GLSLShader.h"


/////////////////////////////////////////////////
/// CONSTRUCTORES
/////////////////////////////////////////////////

GLSLShader::GLSLShader(std::string vertexPrg, std::string fragPrg)
{
	std::string vertexShader = leeShader(vertexPrg);
	std::string fragmentShader = leeShader(fragPrg);
	this->programID = 0;
	this->infoLog = "";
	this->compileAndLinkShader(vertexShader.c_str(), fragmentShader.c_str());
	//this->compileAndLinkShader(vertexShader, fragmentShader);
	this->vShaderAttribs["MVP"] = getLocation("MVP");
}

/////////////////////////////////////////////////
/// GETTERS
/////////////////////////////////////////////////


glm::uint32 GLSLShader::getID()
{
	return this->programID;
}


std::string GLSLShader::getError()
{
	return this->infoLog;
}


glm::uint32 GLSLShader::getLocation(std::string name)
{
	return glGetUniformLocation(this->programID, name.c_str());
}

glm::uint32 GLSLShader::getLocationAttrib(std::string name)
{
	return glGetAttribLocation(this->programID, name.c_str());
}
/////////////////////////////////////////////////
/// SETTERS
/////////////////////////////////////////////////		


void GLSLShader::setInt(glm::uint32 loc, int val)
{
	glUniform1i(loc, val);
}


void GLSLShader::setFloat(glm::uint32 loc, float val)
{
	glUniform1f(loc, val);
}


void GLSLShader::setVec3(glm::uint32 loc, const glm::vec3& val)
{
	glUniform3fv(loc,1,&val[0]);
}


void GLSLShader::setVec4(glm::uint32 loc, const glm::vec4& val)
{
	glUniform4fv(loc, 1, &val[0]);
}


void GLSLShader::setMatrix(glm::uint32 loc, const glm::mat4& val)
{
	glUniformMatrix4fv(loc, 1, GL_FALSE, &val[0][0]);
}


/////////////////////////////////////////////////
/// OTROS MÉTODOS
/////////////////////////////////////////////////


void GLSLShader::use()
{
	glUseProgram(this->programID);
}

void GLSLShader::setupAttribs()
{
	int vertexLocation = getLocationAttrib("vertex");
	glEnableVertexAttribArray(vertexLocation);
	glVertexAttribPointer(vertexLocation, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
}

std::string GLSLShader::leeShader(std::string namePrg)
{
	// Inicialización de variables
	std::ifstream f(namePrg); 		// Flujo de entrada para leer el archivo "namePrg"
	std::string code;				// Código fuente del shader
	char token;				// String auxiliar para procesar datos

	// Comprueba si se puede abrir el archivo
	if (!f)
	{
		std::cerr << "ERROR. NO SE PUEDE ABRIR " << namePrg << std::endl;
	}

	// Procesa archivo
	while (!f.eof())
	{
		f.get(token);
		code += token;
	//	code.append(&token);
	}

	// Cierra el archivo procesado
	f.close();						
	return code;

}

void GLSLShader::checkShaderError(GLint shaderID)
{
	GLint success = 1;
	char* shaderError = new char[1024];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderID, 1024, nullptr, shaderError);
		this->infoLog.append("Error en shader\n");
		this->infoLog.append(shaderError);
		this->infoLog.append("\n");
	}
}

void GLSLShader::checkLinkError()
{
	GLint success = 1;
	char* linkError = new char[1024];
	glGetProgramiv(this->programID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->programID, 1024, nullptr, linkError);
		this->infoLog.append("Error en programa al linkar\n");
		this->infoLog.append(linkError);
		this->infoLog.append("\n");
	}
}

int GLSLShader::compileShader(const char* code, GLenum shaderType)
{
	int shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &code, nullptr);
	glCompileShader(shaderID);
	checkShaderError(shaderID);
	return shaderID;
}

void GLSLShader::compileAndLinkShader(const char* vertexShader, const char* fragmentShader)
{
	int vertexID, fragmentID;
	this->programID = glCreateProgram();

	// Compila los shaders
	vertexID = compileShader(vertexShader, GL_VERTEX_SHADER);
	fragmentID = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

	// Linkea los shader
	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
	glLinkProgram(programID);
	checkLinkError();

	// Elimina los precompilados porque ya están linkeados en el programa
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}