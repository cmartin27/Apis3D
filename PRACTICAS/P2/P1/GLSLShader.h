#pragma once
#include <glm/glm.hpp>
#include <map>
#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#include <fstream>
#include <iostream>

/**
 *  @file GLSLShader.h
 *  @brief Clase GLSLShader
 *
 *  Almacena los datos necesarios para cargar un shader GLSL.
 *
 * @author Carmen Mart�n Moreno
 * @date 20/12/2020
 */

class GLSLShader
{
	// ATRIBUTOS
	private:
		glm::uint32 programID;										///< Identificador del programa
		std::map<std::string, glm::uint32> vShaderAttribs;			///< Variables uniform del shader
		std::string infoLog;										///> Log de errores
	
	// M�TODOS
	public:
		/////////////////////////////////////////////////
		/// CONSTRUCTORES
		/////////////////////////////////////////////////

		/**
		 *  @brief Constructor vacio
		 *  Inicializa los atributos vacios
		 */
		GLSLShader();

		/**
		 *  @brief Constructor con par�metros
		 *  Inicializa los atributos recibiendo por par�metros los nombres de los ficheros
		 *  que se compilar�n para cargar el shader
		 */
		GLSLShader(std::string vertexPrg, std::string fragPrg);

		/////////////////////////////////////////////////
		/// GETTERS
		/////////////////////////////////////////////////

		/**
		 *  @brief Getter de getID
		 *  @return Identificador de OpenGL del programa
		 */
		glm::uint32 getID();

		/**
		 *  @brief Getter de error
		 *  @return Errores generados al compilar o enlazar
		 */
		std::string getError();


		/**
		 *  @brief Getter de la localizaci�n de una variable uniform
		 *  @param name Nombre de la variable uniform que se va a localizar
		 *  @return Localizaci�n de una varuable uniform del shader
		 */
		glm::uint32 getLocation(std::string name);

		/**
		 *  @brief Getter de la localizaci�n de una variable attrib
		 *  @param name Nombre de la variable attrib que se va a localizar
		 *  @return Localizaci�n de una varuable attrib del shader
		 */
		glm::uint32 getLocationAttrib(std::string name);
		/////////////////////////////////////////////////
		/// SETTERS
		/////////////////////////////////////////////////		


		/**
		 *  @brief Setter de una variable uniform de tipo int
		 *  @param loc Localizaci�n de la variable uniform a settear
		 *  @param val Valor de la variable uniform
		 */
		void setInt(glm::uint32 loc, int val);

		/**
		 *  @brief Setter de una variable uniform de tipo float
		 *  @param loc Localizaci�n de la variable uniform a settear
		 *  @param val Valor de la variable uniform
		 */
		void setFloat(glm::uint32 loc, float val);

		/**
		 *  @brief Setter de una variable uniform de tipo vec3
		 *  @param loc Localizaci�n de la variable uniform a settear
		 *  @param val Valor de la variable uniform
		 */
		void setVec3(glm::uint32 loc, const glm::vec3& val);

		/**
		 *  @brief Setter de una variable uniform de tipo vec4
		 *  @param loc Localizaci�n de la variable uniform a settear
		 *  @param val Valor de la variable uniform
		 */
		void setVec4(glm::uint32 loc, const glm::vec4& val);

		/**
		 *  @brief Setter de una variable uniform de tipo mat4
		 *  @param loc Localizaci�n de la variable uniform a settear
		 *  @param val Valor de la variable uniform
		 */
		void setMatrix (glm::uint32 loc, const glm::mat4& val);


		/////////////////////////////////////////////////
		/// OTROS M�TODOS
		/////////////////////////////////////////////////

		/**
		 *  @brief Activa el uso del programa
		 */
		void use();

		/**
		 *  @brief Activa la escritura de las variables attribute y especifica su formato
		 */
		void setupAttribs();

		/**
		 *  @brief Lectura y procesado de un fichero de shader
		 *  @param namePrg nombre del fichero que contiene el shader
		 *  @return C�digo del shader
		 */
		std::string leeShader(std::string namePrg);

		/**
		 *  @brief Compila un shader
		 *  @param code C�digo del shader que se va a compilar
		 *  @param shaderType Tipo del shader
		 *  @return Identificador de OpenGL del shader
		 */
		int compileShader(const char* code, GLenum shaderType);

		/**
		 *  @brief Compila y enlaza un shader
		 *  @param vertexShader C�digo del shader de v�rtices
		 *  @param fragmentShader C�digo del shader de fragmentos
		 *  @return Identificador de OpenGL del programa
		 */
		void compileAndLinkShader(const char* vertexShader, const char* fragmentShader);

		/**
		 *  @brief Tratamiento de errores para compilaci�n de shaders
		 *  @param shaderID Identificador de OpenGL del shader
		 */
		void checkShaderError(GLint shaderID);

		/**
		 *  @brief Tratamiento de errores para enlace de shaders
		 */
		void checkLinkError();
};

