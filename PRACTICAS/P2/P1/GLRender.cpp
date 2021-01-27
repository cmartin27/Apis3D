#include "GLRender.h"
/////////////////////////////////////////////////
/// CONSTRUCTORES
/////////////////////////////////////////////////

GLRender::GLRender()
{
	//init glew
	glewInit();

	// Iniializa estados
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	
	glScissor(0, 0, 640, 480);
	// Settea el color de limpiado por defecto
	glClearColor(0, 0, 0, 1);

}

/////////////////////////////////////////////////
/// OTROS MÉTODOS
/////////////////////////////////////////////////

void GLRender::SetupMesh(Object3D* obj, int posMesh)
{
	glMeshAttribs_t glMeshAttribs;

	// Avisa a OpenGL de que necesito arrays
	glGenVertexArrays(1, &glMeshAttribs.bufferId);
	glGenBuffers(1, &glMeshAttribs.vertexArrayId);
	glGenBuffers(1, &glMeshAttribs.indexArrayId);

	// Activa el buffer
	glBindVertexArray(glMeshAttribs.bufferId);

	// Activa operaciones sobre el buffer
	glBindBuffer(GL_ARRAY_BUFFER, glMeshAttribs.vertexArrayId);		
	// Pasa vértices a GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * obj->getMesh(posMesh)->getVertList()->size() * 4,
		obj->getMesh(posMesh)->getPosVert()->data(), GL_STATIC_DRAW);
	// BUFFER DE ÍNDICES
	// Activa operaciones sobre el buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glMeshAttribs.indexArrayId);	
	// Pasa índices a GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * obj->getMesh(posMesh)->getNumTriangles() * 3,
		obj->getMesh(posMesh)->getIdxList()->data(), GL_STATIC_DRAW);

	// Almacena ids de la malla
	vMeshIds[obj->getMesh(posMesh)->getMeshID()] = glMeshAttribs;

}
void GLRender::SetupObj(Object3D* obj)
{
	for (int i = 0; i < obj->getMeshCount(); i++)
	{
		this->SetupMesh(obj, i);
	}
}


void GLRender::drawMesh(Object3D* obj, int posMesh)
{
	// Busca los buffers del objeto
	glMeshAttribs_t glMeshAttribs;
	glMeshAttribs = vMeshIds[obj->getMesh(posMesh)->getMeshID()];

	// Activa los buffers
	glBindVertexArray(glMeshAttribs.bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, glMeshAttribs.vertexArrayId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glMeshAttribs.indexArrayId);

	// Activa el shader y los atributos
	obj->getGLSLShader(posMesh)->use();
	obj->getGLSLShader(posMesh)->setupAttribs();

	// Obtiene id de la matriz MVP
	int uniformMVP = obj->getGLSLShader(posMesh)->getLocation("MVP");

	// CALCULA MATRIZ MODELO
	obj->computeModelMtx();

	// CALCULA MATRIZ VISTA
	glm::mat4 View = State::viewMatriz;
	/*
	glm::mat4 View = glm::lookAt(
		glm::vec3(0.0f,0.0f,6.0f),	 // La posición de tu cámara en el espacio mundo
		glm::vec3(0.0f,0.0f,0.0f),   // Hacia donde quieres mirar
		glm::vec3(0.0f,1.0f,0.0f)    // Vector up 
	);*/

	// CALCULA MATRIZ PROYECCION
	glm::mat4 Proj = State::projectionMatrix;
	//glm::mat4 Proj = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

	// CALCULAR LA MATRIZ MVP
	glm::mat4 MVP = glm::mat4(1.0f);
	MVP = Proj * View * obj->getModelMtx();

	// Inicializa la matriz MVP
	glUniformMatrix4fv(uniformMVP, 1, GL_FALSE, &MVP[0][0]);

	// Dibuja el objeto con shader
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}


void GLRender::drawObject(Object3D* obj)
{
	for (int i = 0; i < obj->getMeshCount(); i++)
	{
		this->drawMesh(obj, i);
	}
}

void GLRender::drawWorld(World* world)
{
	for (int i = 0; i < world->getNumObjects(); i++)
	{
		this->drawObject(world->getObject(i));
	}
	
}
