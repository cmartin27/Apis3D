#include "GLRender.h"
#include "eventManager.h"
#include "trianguloRot.h"
#include "camera.h"

// INICIALIZACIÓN DE VARIABLES ESTÁTICAS

// Inicializa el generador de identificadores de Mallas
glm::uint32 Mesh3D::idGenerator = 0;
// Inicializa el shader por defecrto
GLSLShader State::defaultShader = GLSLShader();

glm::mat4 State::viewMatriz = lookAt(
	glm::vec3(0.0f, 0.0f, 6.0f),	 // La posición de tu cámara en el espacio mundo
	glm::vec3(0.0f, 0.0f, 0.0f),    // Hacia donde quieres mirar
	glm::vec3(0.0f, 1.0f, 0.0f)     // Vector up 
);

glm::mat4 State::projectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

int main(int argc, char** argv)
{
	float newStep =-1,
		lastStep = -1,
		deltaTime = -1;
	// INICIALIZA GLFW
	glfwInit();
	// Crea la ventana
	GLFWwindow* window = glfwCreateWindow(640, 480, "PRACTICA 2 APIS3D", nullptr, nullptr);
	// Fija la ventana como principal
	glfwMakeContextCurrent(window);
	// Desactiva reescalado de ventana
	// ctrl + click sobre GLFW_RESIZABLE para ver las propiedades de la ventana
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	// Set Callback
	glfwSetKeyCallback(window, keyCallback);

	// INICIALIZA RENDER
	GLRender render = GLRender();

	// INICIALIZA ESTADO
	State estado;
	estado.defaultShader = GLSLShader("vertexShader", "fragmentShader");

	// INICIALIZA MUNDO
	
	World world = World();
	
	Camera cam = Camera(glm::vec3(0.0f, 0.0f, 8.0f), 
						glm::vec3(0.0f, 1.0f, 0.0f), 
						glm::vec3(0.0f, 0.0f, 0.0f));
	cam.setProjection(State::projectionMatrix);
	cam.prepare();
	world.addCamera(&cam);
	world.setActiveCamera(0);
	
	// Crea estrctura del objeto en CPU

	for (float z = 0.0f; z >= -6.0f; z -= 3.0)
	{
		for (float x = -3.0f; x <= 3.0f; x += 3.0f)
		{
			TrianguloRot* triangle = new TrianguloRot();
			// Fija Posición
			triangle->setPos(glm::vec3(x, 0.0f, z));
			// Carga objeto en GPU
			render.SetupObj(triangle);
			world.addObject(triangle);
		}
	}
	/*
	
	GLSLShader shader = GLSLShader("vertexShader", "fragmentShader");
	std::vector<TrianguloRot>* triangles = new std::vector<TrianguloRot>;
	for (float z = 0.0f; z >= -6.0f; z -= 3.0)
	{
		for (float x = -3.0f; x <= 3.0f; x += 3.0f)
		{
			// Crea estrctura del objeto en CPU
			TrianguloRot triangle = TrianguloRot();
			// Fija Shader
			triangle.setGLSLShader(&shader,0);
			// Fija Posición
			triangle.setPos(glm::vec3(x, 0.0f, z));
			// Carga objeto en GPU
			render.SetupObj(&triangle);
			triangles->push_back(triangle);
		}
	}*/


	// Bucle de renderizado
	while (!glfwWindowShouldClose(window))
	{
		// Limpia buffer de color y profundidad
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		
		newStep = glfwGetTime();
		deltaTime = newStep - lastStep;
		
		// Update de objetos
		world.update(deltaTime);
		render.drawWorld(&world);
		
		// Update de objetos
		/*
		for (int i = 0; i < triangles->size(); i++) {
			triangles->data()[i].step(deltaTime);
			render.drawObject(&triangles->data()[i]);
		}*/
		lastStep = newStep;
		glfwSwapBuffers(window); // Muestra por pantalla lo que hemos dibujado
		glfwPollEvents();		 // Escucha el resto de eventos que ocurranxc
	}

	glfwTerminate();	// Libera recursos
	return 0;

}