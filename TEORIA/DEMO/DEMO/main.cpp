#include <cstdlib>
#include <cstdio>
#include <string>
#include "render.h"
#include "shaderManager.h"
#include "eventManager.h"
#include "camera.h"

/*
float triangle[3][4] = { {0.0f, 0.5f, 0.0f,1.0f}, {-0.5f,0.0f,0.0f,1.0f}, {0.5f,0.0f,0.0f,1.0f} };

float color[3] = { 1.0f,1.0f,1.0f };

float matrixIdentity[4][4] = { {1.0f,0.0f,0.0f,0.0f}, 
							   {0.0f,1.0f,0.0f,0.0f},
							   {0.0f,0.0f,1.0f,0.0f},
							   {0.0f,0.0f,0.0f,1.0f} };

void moveTriangle()
{
	float distancia = 0.001f;
	float matrixT[4][4];
	memcpy(matrixT, matrixIdentity, sizeof(float) * 16);
	if (keybEvent[GLFW_KEY_A])
	{
		matrixT[0][3] = -distancia;
	}
	if (keybEvent[GLFW_KEY_D])
	{
		matrixT[0][3] = distancia;
	}



	// Aplica transformación
	for (int i = 0; i < 3; i++)
	{
		float result[4] = { 0,0,0,0 };
		for (int fil = 0; fil < 4; fil++)
		{
			for (int col = 0; col < 4; col++)
			{
				result[fil] += matrixT[fil][col] * triangle[i][col];
			}
		}
		memcpy(triangle[i], result, sizeof(float) * 4);
	}
	
}

void drawTriangle()
{
	// Añadimos una matriz (matriz modelo)
	glPushMatrix();
	// Cargamos la matriz identidad
	glLoadIdentity();
	
	// Activa el dibujado
	glBegin(GL_TRIANGLES);
		
		// Dibuja vértices
		for (int i = 0; i < 3; i++)
		{
			// Indica color de cada vértice
			glColor3fv(color);
			// Indica coordenadas de cada vértice
			glVertex3f(triangle[i][0], 
					   triangle[i][1],
					   triangle[i][2]);
		}

	
	// Desactiva el dibujado
	glEnd();
	// Quita la matriz
	glPopMatrix();
}*/

int main(int argc, char** argv)
{
	// INICIALIZA GLFW
	glfwInit();			
	// Crea la ventana
	GLFWwindow* window = glfwCreateWindow(640, 480, "Prueba APIS3D", nullptr, nullptr); 
	// Fija la ventana como principal
	glfwMakeContextCurrent(window);
	// Desactiva reescalado de ventana
	// ctrl + click sobre GLFW_RESIZABLE para ver las propiedades de la ventana
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); 
	// Set Callback
	glfwSetKeyCallback(window, keyCallback);


	// INICIALIZA GLEW
	glewInit();

	// Settea el color de limpiado por defecto
	glClearColor(0, 0, 0, 1);


	// INICIALIZA OBJETO

	camera_t* cam = createCamera(glm::vec3(0.0f,0.0f,1.0f), 
								 glm::vec3(0.0f,0.0f,0.0f),
							     glm::vec3(0.0f,1.0f,0.0f));
	// Crea estrctura del objeto en CPU
	obj_t* triangle = createTriangle();
	// Carga objeto en GPU
	uploadObj(triangle);

	// Crea shader
	int shaderId = compileAndLinkShader(vertexShader, fragmentShader);
	setShaderID(triangle, shaderId);

	// Bucle de renderizado
	while (!glfwWindowShouldClose(window))
	{
		// Update de camara
		moveCamera(cam);

		// Update de objetos
		moveTriangle(triangle);

		// Limpia buffer de color
		glClear(GL_COLOR_BUFFER_BIT);

		// Dibuja objeto
		drawObj(triangle,shaderId,cam);

		glfwSwapBuffers(window); // Muestra por pantalla lo que hemos dibujado
		glfwPollEvents();		 // Escucha el resto de eventos que ocurranxc
	}


	glfwTerminate();	// Libera recursos
	return 0;

}