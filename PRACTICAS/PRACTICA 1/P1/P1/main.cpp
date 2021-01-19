#include "GLRender.h"
#include "eventManager.h"
#include "trianguloRot.h"

// Inicializa el generador de identificadores de Mallas
glm::uint32 Mesh3D::idGenerator = 0;

int main(int argc, char** argv)
{
	// INICIALIZA GLFW
	glfwInit();
	// Crea la ventana
	GLFWwindow* window = glfwCreateWindow(640, 480, "PRACTICA 1 APIS3D", nullptr, nullptr);
	// Fija la ventana como principal
	glfwMakeContextCurrent(window);
	// Desactiva reescalado de ventana
	// ctrl + click sobre GLFW_RESIZABLE para ver las propiedades de la ventana
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	// Set Callback
	glfwSetKeyCallback(window, keyCallback);

	// INICIALIZA RENDER
	GLRender render = GLRender();

	// INICIALIZA SHADER
	GLSLShader shader = GLSLShader("vertexShader", "fragmentShader");

	std::vector<TrianguloRot>* triangles = new std::vector<TrianguloRot>;
	for (float z = 0.0f; z >= -6.0f; z -= 3.0)
	{
		for (float x = -3.0f; x <= 3.0f; x += 3.0f)
		{
			// Crea estrctura del objeto en CPU
			TrianguloRot triangle = TrianguloRot();
			// Fija Shader
			triangle.setGLSLShader(&shader);
			// Fija Posición
			triangle.setPos(glm::vec3(x, 0.0f, z));
			// Carga objeto en GPU
			render.SetupObj(&triangle);
			triangles->push_back(triangle);
		}
	}


	// Bucle de renderizado
	while (!glfwWindowShouldClose(window))
	{

		// Limpia buffer de color y profundidad
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		// Update de objetos
		for (int i = 0; i < triangles->size(); i++) {
			triangles->data()[i].step();
			render.drawObject(&triangles->data()[i]);
		}

		glfwSwapBuffers(window); // Muestra por pantalla lo que hemos dibujado
		glfwPollEvents();		 // Escucha el resto de eventos que ocurranxc
	}

	glfwTerminate();	// Libera recursos
	return 0;

}