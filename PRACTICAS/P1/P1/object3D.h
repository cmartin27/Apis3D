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
 *  Almacena los datos b�sicos de los objetos renderizables en nuestro motor gr�fico
 *
 * @author Carmen Mart�n Moreno
 * @date 20/12/2020
 */

class Object3D
{
	// ATRIBUTOS
	protected:
		glm::vec3 pos;				///< Posici�n de nuestro objeto en coordenadas 3D
		glm::vec3 size;				///< Tama�o de nuestro objetos en coordenadas 3D
		glm::vec3 rot;				///< �ngulo de rotaci�n de nuestro objetos en cada eje
		glm::mat4x4 modelMtx;		///< Matriz mnodelo del objeto
		Mesh3D* mesh;				///< Malla 3D del objeto
		GLSLShader* shader;			///< Shader para dibujar el objeto

	//	M�TODOS
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
		 *  @return Posici�n del objeto
		 */
		glm::vec3 getPos();

		/**
		 *  @brief Getter de pos
		 *  @return Tama�o del objeto
		 */
		glm::vec3 getSize();
		
		/**
		 *  @brief Getter de pos
		 *  @return Rotaci�n del objeto con respecto a cada eje
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
		 *  @param pos Posici�n del objeto
		 */
		void setPos(glm::vec3 pos);

		/**
		 *  @brief Setter de size
		 *  @param size Tama�o del objeto
		 */
		void setSize(glm::vec3 size);

		/**
		 *  @brief Setter de rot
		 *  @param rot Rotaci�n del objeto
		 */
		void setRot(glm::vec3 rot);

		/////////////////////////////////////////////////
		/// OTROS M�TODOS
		/////////////////////////////////////////////////

		virtual void step() = 0;

		/**
		 *  @brief Actualiza la matriz modelo del objeto
		 */
		void computeModelMtx();

};

