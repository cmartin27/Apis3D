#pragma once
#include "object3D.h"
#include "world.h"

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
		 *  @param obj Objeto 3D al que pertenece la malla
		 *  @param posMesh Malla del objeto que se va a cargar
		 */
		void SetupMesh(Object3D* obj, int posMesh);

		/**
		 *  @brief Carga todas las malla 3D del objeto en GPU
		 *  @param obj Objeto 3D que se va a cargar
		 */
		void SetupObj(Object3D* obj);

		/**
		 *  @brief Dibuja por pantalla una malla
		 *  @param obj Objeto 3D al que pertenece la malla
		 *  @param posMesh Malla del objeto que se va a dibujar
		 */
		void drawMesh(Object3D* obj, int posMesh);

		/**
		 *  @brief Dibuja por pantalla un objeto 3D
		 *  @param obj Objeto 3D que se va a dibujar
		 */
		void drawObject(Object3D* obj);

		/**
		 *  @brief Dibuja por pantalla todos los los objetos del mundo desde la cámara actuva
		 *  @param world Mundo que se va a dibujar
		 */
		void drawWorld(World* world);
};

