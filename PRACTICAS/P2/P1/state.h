#pragma once
#include "GLSLShader.h"
#include <glm/glm.hpp>
/**
 *  @file state.h
 *  @brief Clase State
 *
 *  Almacena los datos generales del estado del motor
 *
 * @author Carmen Martín Moreno
 * @date 24/01/2021
 */
class State
{
public:
	// ATRIBUTOS
	static GLSLShader defaultShader;			// Shader por defecto para pintar elementos
	static glm::mat4 projectionMatrix;			// Matriz de proyección
	static glm::mat4 viewMatriz;				// Matriz de vista
	static glm::mat4 modelMatrix;				// Matriz del modelo

	State(){  };

};

