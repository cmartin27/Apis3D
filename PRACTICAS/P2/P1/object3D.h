#pragma once
#include "mesh3D.h"
#include "GLSLShader.h"
#include "entity.h"

/**
 *  @file object3D.h
 *  @brief Clase Object 3D
 *
 *  Almacena los datos básicos de los objetos renderizables en nuestro motor gráfico
 *
 * @author Carmen Martín Moreno
 * @date 20/12/2020
 */

class Object3D : public Entity
{
	// ATRIBUTOS
	protected:
		std::vector<Mesh3D*> meshList;			///< Lista de Mallas 3D del objeto
		std::vector <GLSLShader*> shaderList;	///< Lista de shaders para dibujar las mallas del objeto

	//	MÉTODOS
	public:
		/////////////////////////////////////////////////
		/// CONSTRUCTORES
		/////////////////////////////////////////////////
		/**
		 *  @brief Constructor por defecto
		 *  Inicializa los valores por defecto
		 */
		Object3D();

		/////////////////////////////////////////////////
		/// GETTERS
		/////////////////////////////////////////////////

		/**
		 *  @brief Getter de la lista de mallas
		 *  @return Lista de mallas 3D del objeto
		 */
		std::vector<Mesh3D*> getMeshList();

		/**
		 *  @brief Getter de una mesh concreta
		 *  @param meshID Identificador de la malla (posición de la lista)
		 *  @return Malla 3D del objeto
		 */
		Mesh3D* getMesh(int meshID);

		/**
		 *  @brief Getter del número de mallas del objeto
		 *  @return Número de elementos de meshList
		 */
		int getMeshCount();

		/**
		 *  @brief Getter de la lista de shaders
		 *  @return Lista de Shaders GLSL del objeto
		 */
		std::vector<GLSLShader*> getGLSLShaderList();

		/**
		 *  @brief Getter de un shader concreto
		 *  @param shaderID Identificador del shader (posición de la lista)
		 *  @return Shader GLSL de la malla
		 */
		GLSLShader* getGLSLShader(int shaderID);

		/**
		 *  @brief Getter del número de shaders del objeto
		 *  @return Número de elementos de shaderList
		 */
		int getShaderCount();


		/////////////////////////////////////////////////
		/// SETTERS
		/////////////////////////////////////////////////

		/**
		 *  @brief Setter de una mesh
		 *  @param mesh Malla 3D del objeto
		 *  @param meshID Identificador de la malla
		 */
		void setMesh(Mesh3D* mesh, int meshID);

		/**
		 *  @brief Setter de la lista de mallas
		 *  @param meshList Lista de Mallas 3D del objeto
		 */
		void setMeshList(std::vector<Mesh3D*> meshList);

		/**
		 *  @brief Setter de un shader
		 *  @param shaderID Identificador del shader
		 *  @param shader Shader GLSL del shader
		 */
		void setGLSLShader(GLSLShader* shader, int shaderID);

		/**
		 *  @brief Setter de la lista de shaders
		 *  @param shaderList Lista de shaders del objeto
		 */
		void setGLSLShaderList(std::vector<GLSLShader*> shaderList);
	

		/////////////////////////////////////////////////
		/// OTROS MÉTODOS
		/////////////////////////////////////////////////



		/**
		 *  @brief Añade una nueva malla al objeto
		 *  @param mesh Nueva malla del objeto
		 *  @param shader Shader utilizado para pintar esa malla
		 */
		void addMesh(Mesh3D* mesh, GLSLShader* shader);

};

