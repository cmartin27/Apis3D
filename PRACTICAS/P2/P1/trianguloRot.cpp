#include "trianguloRot.h"


TrianguloRot::TrianguloRot(GLSLShader* shader):Object3D()
{
	// Coordenadas de los vértices por defecto
	vertex_t v1, v2, v3;
	v1.vertexID = 0;
	v1.pos = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);
	v2.vertexID = 1;
	v2.pos = glm::vec4(-0.5f, 0.0f, 0.0f, 1.0f);
	v3.vertexID = 2;
	v3.pos = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);



	// Añade los vértices a la malla
	Mesh3D* triangleMesh = new Mesh3D;
	triangleMesh->addVertex(v1);
	triangleMesh->addVertex(v2);
	triangleMesh->addVertex(v3);


	// Añade los índices de los triángulos a la malla
	triangleMesh->addTriangleIdx(v1.vertexID,v3.vertexID, v2.vertexID);

	this->addMesh(triangleMesh, shader);

}

void TrianguloRot::step(float deltaTime)
{
	
	// Obtiene el tiempo actual en segundos
	double velocity = 32.0f;      // Velocidad de 32 grados/s
	glm::vec3 rotAct = this->getRot();


	// Si se pulsa la f se gira en sentido horario
	if (keybEvent[GLFW_KEY_F])
	{
		rotAct.y -= velocity * deltaTime;
	}
	// Si se pulsa la h se gira en sentido antihorario
	if (keybEvent[GLFW_KEY_H])
	{
		rotAct.y += velocity * deltaTime;
	}

	this->setRot(rotAct);


}