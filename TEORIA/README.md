# Tema 2: GLFW y OpenGL
## GLFW

Librería complementraria a OpenGL que nos ayuda a crear ventanas, manejar eventos,..

### Inicialización

	int glfwInit();       // Inicializa la libreria, devuelve GLFW_TRUE O GLWF_FALSE
	void glfwTerminate(); // Antes de salir, desaloja recursos de GLFW

### Manejo de Ventana

	GLFWwindow* glfwCreateWindow(int width, int height, const char* title,  // Crea una ventana
		GLFWmonitor* monitor, GLFWwindow* share); 

- width: Ancho de la ventana
- height: Altura de la ventana
- title: Titulo de la ventana
- monitor: Tipo de ventana. `glfwGetPrimaryMonitor()` abre la ventana en pantalla completa del monitor principal, `nullptr` abre ventana emergente.
- share: valor siempre `nullptr`

```
	void glfwMakeContextCurrent(GLFWwindow* window); // Pone una ventana como principal, la 	
						         // que OpenGL utiliza para renderizar
	void glfwSetWindowTitle(GLFWwindow* window, const char* title); // Cambia el titulo de una ventana

	void glfwGetWindowSize(GLFWwindow* window, int* width, int* height); // Devuelve el tamaño de la ventana
	void glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);  	             // Añade propiedades a la ventana.
									     // GLFW_RESIZABLE: escalado de la ventana
									     // GLFW_FOCUSED: fija ventana delante del
									     //  resto y no permite sacar ratón
	 								     // GLFW_DECORATED: quita el marco de la ventana
```
### Bucle de renderizado

	// Bucle infinito mientras no se cierre la ventana
	while(!glfwWindowShouldClose(window))
	{
		// bucle de renderizado
		glfwSwapBuffer(GLFWwindow* window); // Muestra por pantalla lo que hemos dibujado
	}

### Entrada de datos

- Callbacks. Escucha los eventos que están ocurriendo y ejecuta. Se ejecutan en un hilo paralelo. Almaceno todos los eventos que hayan ocurrido y actuó según la información recogida.
	- Teclas
		- Get: `void nombreCallback(GLFWwindow* window, int key, int scancode, int action,int mods)`
			- window: ventana donde se ejecuta el callback
			- key: tecla con valor en GLFW. Ej: `GLWF_KEY_ESC`
			- scancode: tecla con valor ascii
			- action: accion que se ha producido. Ej: `GLFW_PRESS, GLFW_RELEASE, GLFW_REPEAT`
			- mods: da información adicional como si está pulsando el ctrl, mayus, etc. Ej: `GLFW_MOD_SHIFT, GLFW_MOD_ALT`
		- Set: `GLFWkeyfun glfwSetKeyCallback(GLFWwindow* window, GLFWkeyfun cbfun)`
			- window: ventana sobre la que quiero poner el callback
			- cbfun: la función que quiero que se ejecute
	- Ratón (para saber posición exacta del ratón, mejor polling)
		- Get: `void nombreCallback(GLFWwindow* window,double xpos, double ypos)`
			- window: ventana donde se ejecuta el callback
			- xpos: posición x del cursor
			- ypos: posición y del cursor
		- Set: `GLFWcursorposfun glfwSetCursorPosCallback(GLFWwindow* window, GLFWcursorposfun cbfun)`
			- window: ventana sobre la que quiero poner el callback
			- cbfun: la función que quiero que se ejecute
	- Teclas de ratón
		- Get: `void nombreCallback(GLFWwindow* window, int button, int action,int mods)`
			- window: ventana donde se ejecuta el callback
			- button: botón del ratón. Ej: `GLWF_MOUSE_BUTTON_LEFT,GLWF_MOUSE_BUTTON_MIDDLE`
			- action: accion que se ha producido. Ej: `GLFW_PRESS, GLFW_RELEASE`
			- mods: da información adicional como si está pulsando el ctrl, mayus, etc. Ej: `GLFW_MOD_SHIFT, GLFW_MOD_ALT`
		- Set: `GLFWmousebuttonfun glfwSetMouseButtonCallback(GLFWwindow* window, GLFWmousebuttonfun cbfun)`
			- window: ventana sobre la que quiero poner el callback
			- cbfun: la función que quiero que se ejecute

- Polling. Pregunta si ha ocurrido cierto evento y ejecuta.
	- Procesa evento si hay pendientes: `void glfwPollEvents()`
	- Procesa los eventos o espera hasta que haya: `void glfwWaitEvents()`
	- Polling de teclado: `int glfwGetKey(GLFWwindow* window, int key)`. Pregunta estado (`GLFW_PRESS,GLFW_RELLEASE,...`) de la tecla `key`.
	- Polling de posición del ratón. 
		-	`void glfwGetCuyrsorPos(GLFWwindow* window, double* xpos, double* ypos)`. Devuelve la posición del cursor.
		- 	`void glfwSetCuyrsorPos(GLFWwindow* window, double xpos, double ypos)`. Fija la posición del cursor. 
	- Polling de los botones del ratón: `int glfwGetMouseButton(GLFWwindow* window, int button)`. Pregunta estado (`GLFW_PRESS,GLFW_RELLEASE,...`) del botón `button`.

### Gestión del tiempo

Dependiendo de la tarjeta gráfica, el número de fps por defecto puede variar. Las consecuencias de esto pueden ser notables. Por ejemplo: si tengo una función que mueve dos unidades un objeto a la derecha cuando se pulsa una tecla, si el programa se ejecuta a 60 fps el objeto se moverá 120 unidades, pero si el programa se ejecuta a 24 fps solo se moverá 48.

Para solucionar esto, especificamos los movimientos en unidades por segundo. La distancia se calculará según la fórmula del movimiento rectilíneo uniforme

	float velocidad = 120; 							   
	// En el Bucle de renderizado
	float newTime = static_cast<float>(glfwGetTime()); // Instante de tiempo actual
	float deltaTime = newTime - lastTime; 		   // Calcula el tiempo desde el último frame
	float d = velocidad * deltaTime; 		   // Calcula distancia del movimiento
	float lasTime = newTime; 		 	   // Actuliza el tiempo del último frame

## OpenGL

OpenGl nos da un cauce gráfico ya implementado. Nos permite agrupar vértices, polígonos,... Las transofrmaciones se realizar mediante operaciones con matrices, y para dibujar aplica las matrices MVP. Aunque el perfil de compatibilidad de OpenGL incluye funciones para el manejo de matrices, utilizaremos la librería GML y pasaremos los datos a shaders. Las funciones de OpenGL empiezan con `gl` y terminan con el tipo de parámetro que queremos. Ej: `glUniform1i`, `glUniform3f`,...

OpenGL dibuja con dos elementos básicos:
- Vértices. Definen la forma del objeto. Para definir la topología debemos indicar como se conectan los vértices entre sí, normalmente con triángulos.
- Texturas. Definen el aspecto del objeto.

### Estados

Para activar/desactivar estados del cauce: `glEnable/glDisable`

- GL_BLEND: Mezcla los valores de color (activa transparencia).
- GL_DEPTH_TEST. Comprueba la profundidad en el pintado. Comprueba si un objeto está por delante de otro, y elimina el que no se ve.
- GL_SCISSOR_TEST. Clipping, elimina todo lo que esté fuera del prisma de visión.
- GL_TEXTURE_CUBE_MAP_SEAMLESS. Aplica operaciones de texturas.

### Buffers

Para definir la geometría de los objetos vamos a utilizar buffers (un array), concretamente el Vertex Buffer Objects (VBO). Las funciones para manejar VBO:

	void glGenBuffers(GLsizei n, Gluint* buffers) 			// Reserva memoria en la tarjeta gráfica
	void glDeleteBuffers(GLsizei n, const Gluint* buffers)		// Libera memoria en la tarjeta gráfica
	void glBindBuffer(GLenum target, Gluint buffer)			// Enlaza un buffer previamente generado con su tipo
- `target`. Tipos de buffer:
	- `GL_ARRAY_BUFFER`. Contiene información de vértices (coordenaas, color, normales,...)
	- `GL_ELEMENT_ARRAY_BUFFER`. Índices de los vértices con los que se forma la geometría de los objetos.

