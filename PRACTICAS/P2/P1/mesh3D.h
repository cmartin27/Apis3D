#pragma once
#include <glm/glm.hpp>
#include <vector>


typedef struct vertex_t
{
	int vertexID;
	glm::vec4 pos;
}vertex_t;

/**
 *  @file mesh3d.h 
 *  @brief Clase Mesh3D
 * 
 *  Almacena los datos necesarios para dibujar una malla en nuestro motor de render.
 * 
 * @author Carmen Mart�n Moreno
 * @date 20/12/2020
 */

class Mesh3D
{
	// ATRIBUTOS

	private:

		static glm::uint32 idGenerator;		    ///< Generador de id �nicos para la malla
		glm::uint32 meshID;						///< Identificador de la malla
		glm::vec3 colorRGB;						///< Color b�sico de la malla
		std::vector<vertex_t>* vVertList;		///< Lista de v�rtices
		std::vector<glm::int32>* vIdxList;		///< Lista de �ndices de v�rtices
		int numTriangles;						///< N�mero de tri�ngulos

	// M�TODOS
	public:


		/////////////////////////////////////////////////
		/// CONSTRUCTORES
		/////////////////////////////////////////////////

		/**
		 *  @brief Constructor por defecto
		 *  Inicializa los valores por defecto
		 */
		Mesh3D();

		/////////////////////////////////////////////////
		/// GETTERS
		/////////////////////////////////////////////////

		/**
		 *  @brief Getter de meshID
		 *  @return Identificador de la malla
		 */
		glm::uint32 getMeshID();

		/**
		 *  @brief Getter de vVertList
		 *  @return Lista de v�rtices de la malla
		 */
		std::vector<vertex_t>* getVertList();

		/**
		 *  @brief Getter de las posiciones de vVertList
		 *  @return Posiciones de los vertices de la malla
		 */
		std::vector<glm::vec4>* getPosVert();

		/**
		 *  @brief Getter de vIdxList
		 *  @return Lista con los indentificadores de los 
		 *  v�rtices de la malla
		 */
		std::vector<glm::int32>* getIdxList();
		/**
		 *  @brief Getter de colorRGB
		 *  @return Color b�sico de la malla
		 */
		glm::vec3 getColorRGB();

		/**
		 *  @brief Getter de numTriangles
		 *  @return N�mero de tri�ngulos de la malla
		 */
		int  getNumTriangles();
		/////////////////////////////////////////////////
		/// SETTERS
		/////////////////////////////////////////////////

		/**
		 *  @brief Setter de colorRGB
		 *  @param r Componente roja del color
		 *  @param g Componente verde del color
		 *  @param b Componente azul del color
		 *  @pre Las componente del color deben estar en [0,1]
		 */

		void setColorRGB(float r, float g, float b);

		/////////////////////////////////////////////////
		/// OTROS M�TODOS
		/////////////////////////////////////////////////

		/**
		 *  @brief M�todo para a�adir v�rtices a la malla
		 *  @param vert V�rtice que se va a a�adir a la malla
		 */
		void addVertex(vertex_t vert);

		/**
		 *  @brief M�todo para a�adir un nuevo v�rtice a la malla
		 *  @param id �ndice del nuevo v�rtice de la malla
		 */
		void addIdx(glm::int32 id);

		/**
		 *  @brief M�todo para a�adir un nuevo tr�angulo a la malla
		 *  @param v1 �ndice de un v�rtice del tri�ngulo 
		 *  @param v2 �ndice de un v�rtice del tri�ngulo 
		 *  @param v3 �ndice de un v�rtice del tri�ngulo 
		 */
		void addTriangleIdx(glm::int32 v1, glm::int32 v2, glm::int32 v3);

};

