#pragma once
#include "object3D.h"


/**
 *  @file trianguloRot.h
 *  @brief Clase TrianguloRot
 *
 *  Objeto3D formado por un tri�ngulo que rota con respecto a su propio eje y
 *
 * @author Carmen Mart�n Moreno
 * @date 20/12/2020
 */
class TrianguloRot : public Object3D
{
	// ATRIBUTOS
private:
	double lastStep;		// Instante de tiempo en el que se ejecuto la �ltima actualizaci�n
public:
	// M�TODOS
	/**
	 *  @brief Constructor por defecto
	 *  Inicializa un tri�ngulo con los valores por defecto
	 */
	TrianguloRot();
	
	/**
	 *  @brief M�todo que actualiza la rotaci�n del tri�ngulo
	 */
	void step();

};

