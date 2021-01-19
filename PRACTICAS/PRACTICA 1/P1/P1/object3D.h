#pragma once
#include "mesh3D.h"
#include "GLSLShader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "eventManager.h"

/**
 *  @file object3D.h
 *  @brief Clase Object 3D
 *
 *  Almacena los datos básicos de los objetos renderizables en nuestro motor gráfico
 *
 * @author Carmen Martín Moreno
 * @date 20/12/2020
 */

class Object3D
{
	// ATRIBUTOS
	protected:
		glm::vec3 pos;				///< Posición de nuestro objeto en coordenadas 3D
		glm::vec3 size;				///< Tamaño de nuestro objetos en coordenadas 3D
		glm::vec3 rot;				///< Ángulo de rotación de nuestro objetos en cada eje
		glm::mat4x4 modelMtx;		///< Matriz mnodelo del objeto
		Mesh3D* mesh;				///< Malla 3D del objeto
		GLSLShader* shader;			///< Shader para dibujar el objeto

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
		 *  @brief Getter de mesh
		 *  @return Malla 3D del objeto
		 */
		Mesh3D* getMesh();

		/**
		 *  @brief Getter de shader
		 *  @return Shader GLSL del objeto
		 */
		GLSLShader* getGLSLShader();

		/**
		 *  @brief Getter de modelMtx
		 *  @return Matriz modelo del objeto
		 */
		glm::mat4x4 getModelMtx();

		/**
		 *  @brief Getter de pos
		 *  @return Posición del objeto
		 */
		glm::vec3 getPos();

		/**
		 *  @brief Getter de pos
		 *  @return Tamaño del objeto
		 */
		glm::vec3 getSize();
		
		/**
		 *  @brief Getter de pos
		 *  @return Rotación del objeto con respecto a cada eje
		 */
		glm::vec3 getRot();

		/////////////////////////////////////////////////
		/// SETTERS
		/////////////////////////////////////////////////

		/**
		 *  @brief Setter de mesh
		 *  @param mesh Malla 3D del objeto
		 */
		void setMesh(Mesh3D* mesh);

		/**
		 *  @brief Setter de shader
		 *  @param shader Shader GLSL del shader
		 */
		void setGLSLShader(GLSLShader* shader);
		
		/**
		 *  @brief Setter de pos
		 *  @param pos Posición del objeto
		 */
		void setPos(glm::vec3 pos);

		/**
		 *  @brief Setter de size
		 *  @param size Tamaño del objeto
		 */
		void setSize(glm::vec3 size);

		/**
		 *  @brief Setter de rot
		 *  @param rot Rotación del objeto
		 */
		void setRot(glm::vec3 rot);

		/////////////////////////////////////////////////
		/// OTROS MÉTODOS
		/////////////////////////////////////////////////

		virtual void step() = 0;

		/**
		 *  @brief Actualiza la matriz modelo del objeto
		 */
		void computeModelMtx();

};

