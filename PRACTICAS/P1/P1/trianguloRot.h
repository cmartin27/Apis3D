#pragma once
#include "object3D.h"


/**
 *  @file trianguloRot.h
 *  @brief Clase TrianguloRot
 *
 *  Objeto3D formado por un triángulo que rota con respecto a su propio eje y
 *
 * @author Carmen Martín Moreno
 * @date 20/12/2020
 */
class TrianguloRot : public Object3D
{
	// ATRIBUTOS
private:
	double lastStep;		// Instante de tiempo en el que se ejecuto la última actualización
public:
	// MÉTODOS
	/**
	 *  @brief Constructor por defecto
	 *  Inicializa un triángulo con los valores por defecto
	 */
	TrianguloRot();
	
	/**
	 *  @brief Método que actualiza la rotación del triángulo
	 */
	void step();

};

