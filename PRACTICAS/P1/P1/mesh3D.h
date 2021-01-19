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
 * @author Carmen Martín Moreno
 * @date 20/12/2020
 */

class Mesh3D
{
	// ATRIBUTOS

	private:

		static glm::uint32 idGenerator;		    ///< Generador de id únicos para la malla
		glm::uint32 meshID;						///< Identificador de la malla
		glm::vec3 colorRGB;						///< Color básico de la malla
		std::vector<vertex_t>* vVertList;		///< Lista de vértices
		std::vector<glm::int32>* vIdxList;		///< Lista de índices de vértices
		int numTriangles;						///< Número de triángulos

	// MÉTODOS
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
		 *  @return Lista de vértices de la malla
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
		 *  vértices de la malla
		 */
		std::vector<glm::int32>* getIdxList();
		/**
		 *  @brief Getter de colorRGB
		 *  @return Color básico de la malla
		 */
		glm::vec3 getColorRGB();

		/**
		 *  @brief Getter de numTriangles
		 *  @return Número de triángulos de la malla
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
		/// OTROS MÉTODOS
		/////////////////////////////////////////////////

		/**
		 *  @brief Método para añadir vértices a la malla
		 *  @param vert Vértice que se va a añadir a la malla
		 */
		void addVertex(vertex_t vert);

		/**
		 *  @brief Método para añadir un nuevo vértice a la malla
		 *  @param id Índice del nuevo vértice de la malla
		 */
		void addIdx(glm::int32 id);

		/**
		 *  @brief Método para añadir un nuevo tríangulo a la malla
		 *  @param v1 Índice de un vértice del triángulo 
		 *  @param v2 Índice de un vértice del triángulo 
		 *  @param v3 Índice de un vértice del triángulo 
		 */
		void addTriangleIdx(glm::int32 v1, glm::int32 v2, glm::int32 v3);

};

