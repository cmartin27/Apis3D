#include <cstdlib>
#include <cstdio>
#include <string>
#include <GLFW/glfw3.h>
#include "eventManager.h"


float triangle[3][3] = { {0.0f, 0.5f, 0.0f}, {-0.5f,0.0f,0.0f}, {0.5f,0.0f,0.0f} };

float color[3] = { 1.0f,1.0f,1.0f };

float matrixIdentity[3][3] = { {1,0,0}, {0,1,0},{0,0,1}};

void moveTriangle()
{
	float matrixT[3][3];
	memcpy(matrixT, matrixIdentity, sizeof(float) * 9);
	if (keybEvent[GLFW_KEY_A])
	{
		matrixT[0][2] = -0.01;
	}
	if (keybEvent[GLFW_KEY_D])
	{
		matrixT[0][2] = 0.01;
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
}

int main(int argc, char** argv)
{
	glfwInit();			// Inicializa GLFW
	// Crea la ventana
	GLFWwindow* window = glfwCreateWindow(640, 480, "Prueba APIS3D", nullptr, nullptr); 
	// Fija la ventana como principal
	glfwMakeContextCurrent(window);
	// Desactiva reescalado de ventana
	// ctrl + click sobre GLFW_RESIZABLE para ver las propiedades de la ventana
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); 
	// Set Callback
	glfwSetKeyCallback(window, keyCallback);

	// Settea el color de limpiado por defecto
	glClearColor(0, 0, 0, 1);

	// Bucle de renderizado
	while (!glfwWindowShouldClose(window))
	{
		// Limpia buffer de color
		glClear(GL_COLOR_BUFFER_BIT);
		drawTriangle();
		glfwSwapBuffers(window); // Muestra por pantalla lo que hemos dibujado
		glfwPollEvents();		 // Escucha el resto de eventos que ocurran
	}


	glfwTerminate();	// Libera recursos
	return 0;

}