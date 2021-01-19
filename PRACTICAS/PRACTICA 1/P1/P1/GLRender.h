#pragma once
#include "object3D.h"

typedef struct glMeshAttribs_t
{
	GLuint bufferId;
	GLuint indexArrayId;
	GLuint vertexArrayId;
} glMeshAttribs_t;


/**
 *  @file GLRender.h
 *  @brief Clase GL Render
 *
 *  Almacena los datos básicos  para iniciar y dibujar objetos en OpenGL
 *
 * @author Carmen Martín Moreno
 * @date 20/12/2020
 */

class GLRender
{	// ATRIBUTOS
	private:
		std::map<glm::uint32, glMeshAttribs_t> vMeshIds;			///< Lista de mallas cargadas en GPU

	// MÉTODOS
	public:
		/////////////////////////////////////////////////
		/// CONSTRUCTORES
		/////////////////////////////////////////////////

		/**
		 *  @brief Constructor por defecto
		 *  Inicializa OpenGL y las librerías extra necesarias
		 */
		GLRender();

		/////////////////////////////////////////////////
		/// OTROS MÉTODOS
		/////////////////////////////////////////////////

		/**
		 *  @brief Carga la malla 3D del objeto en GPU
		 *  @param obj Objeto 3D que se va a cargar
		 */
		void SetupObj(Object3D* obj);

		/**
		 *  @brief Dibuja por pantalla un objeto 3D
		 *  @param obj Objeto 3D que se va a cargar
		 */
		void drawObject(Object3D* obj);
};

