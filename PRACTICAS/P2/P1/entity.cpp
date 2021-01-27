#include "entity.h"
/////////////////////////////////////////////////
/// CONSTRUCTORES
/////////////////////////////////////////////////

/**
 *  @brief Constructor por defecto
 *  Inicializa los valores por defecto
 */

Entity::Entity()
{
	this->pos = glm::vec3(0.0f);
	this->size = glm::vec3(1.0f);
	this->rot = glm::vec3(0.0f);
	this->computeModelMtx();
}


/////////////////////////////////////////////////
/// GETTERS
/////////////////////////////////////////////////
/**
 *  @brief Getter de pos
 *  @return Posición de la entidad
 */
glm::vec3 Entity::getPos()
{
	return this->pos;
}

/**
 *  @brief Getter de rot
 *  @return Rotación de la entidad
 */
glm::vec3 Entity::getRot()
{
	return this->rot;
}

/**
 *  @brief Getter de size
 *  @return Identificador del tamaño
 */
glm::vec3 Entity::getSize()
{
	return this->size;
}

/**
 *  @brief Getter de modelMtx
 *  @return Matriz modelo de la matriz
 */
glm::mat4x4 Entity::getModelMtx()
{
	return this->modelMtx;
}

double Entity::getLastStep()
{
	return this->lastStep;
}

/////////////////////////////////////////////////
/// SETTERS
/////////////////////////////////////////////////



void Entity::setPos(glm::vec3 pos)
{
	this->pos = pos;
}



void Entity::setRot(glm::vec3 rot)
{
	this->rot = rot;
}


void Entity::setSize(glm::vec3 size)
{
	this->size = size;
}

void Entity::setLastStep(double stepAct)
{
	this->lastStep = stepAct;
}
/////////////////////////////////////////////////
/// OTROS MÉTODOS
/////////////////////////////////////////////////


/**
 *  @brief Calcula la matriz modelo de la entidad
 */

void Entity::computeModelMtx()
{

	// CALCULA MATRIZ MODELO

	// Aplica translación. Argumentos: matriz identidad, vector de translacion
	glm::mat4 Model = glm::translate(glm::mat4(1.0f), this->pos);

	// Aplica rotación con respecto a eje y. Argumentos: matriz de tranlación, 
	// angulo de rotación, vector director del eje de rotación (normalizado)
	Model = glm::rotate(Model, this->rot.y, glm::vec3(0.0f, 1.0f, 0.0f));

	// Aplica escalado
	Model = glm::scale(Model, this->size);

	this->modelMtx = Model;

}