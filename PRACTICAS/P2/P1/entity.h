#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "state.h"
#include "eventManager.h"

/**
 *  @file entity.h
 *  @brief Clase Entity
 *
 *  Datos de todo elemento del mundo
 *
 * @author Carmen Mart�n Moreno
 * @date 20/12/2020
 */
class Entity
{

	// ATRIBUTOS

	private:
		glm::vec3 pos;			 ///< Posici�n de la entidad
		glm::vec3 size;			 ///< Tama�o de la entidad
		glm::vec3 rot;			 ///< Rotaci�n de la entidad
		glm::mat4x4 modelMtx;	 ///< Matriz modelo de la entidad
		double lastStep;

	// M�TODOS
	public:
		/////////////////////////////////////////////////
		/// CONSTRUCTORES
		/////////////////////////////////////////////////

		/**
		 *  @brief Constructor por defecto
		 *  Inicializa los valores por defecto
		 */

		Entity();

		/**
		 *  @brief Destructor de la clase
		 */
		virtual ~Entity() {}

		/////////////////////////////////////////////////
		/// GETTERS
		/////////////////////////////////////////////////
		/**
		 *  @brief Getter de pos
		 *  @return Posici�n de la entidad
		 */
		glm::vec3 getPos();

		/**
		 *  @brief Getter de rot
		 *  @return Rotaci�n de la entidad
		 */
		glm::vec3 getRot();

		/**
		 *  @brief Getter de size
		 *  @return Identificador del tama�o
		 */
		glm::vec3 getSize();

		/**
		 *  @brief Getter de modelMtx
		 *  @return Matriz modelo de la matriz
		 */
		glm::mat4x4 getModelMtx();

		/**
		 *  @brief Getter de lastStep
		 *  @return �ltimo instante en el que se actualiz� la entidad
		 */
		double getLastStep();

		/////////////////////////////////////////////////
		/// SETTERS
		/////////////////////////////////////////////////


		/**
		 *  @brief Setter de la posici�n
		 *  @param pos Posici�n de la entidad
		 */
		void setPos(glm::vec3 pos);


		/**
		 *  @brief Setter de la rotaci�n
		 *  @param rot Rotaci�n de la entidad
		 */
		void setRot(glm::vec3 rot);


		/**
		 *  @brief Setter del tama�o 
		 *  @param size Tama�o de la entidad
		 */
		void setSize(glm::vec3 size);

		/**
		 *  @brief Setter del lastStep
		 *  @param stepAct Step actual
		 */
		void setLastStep(double stepAct);

		/////////////////////////////////////////////////
		/// OTROS M�TODOS
		/////////////////////////////////////////////////


		/**
		 *  @brief Calcula la matriz modelo de la entidad
		 */

		void computeModelMtx();

		virtual void step(float deltaTime) = 0;

};

