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
```
void glBufferData GLenum target, GLsizeiptr size,		// Pasa datos de la CPU a la GPU
const GLvoid * data, GLenum usage)
```
- `target`. El id del buffer.
- `size`. Tamaño del buffer (`sizeof(float)*num_vertices`).
- `data`. Los datos que se quieren traspasar
- `usage`. Permite aprovechar la caché para dibujar:
	- `GL_STATIC_DRAW`. Si la malla no se va a modifciar nunca.
	- `GL_DYNAMIC_DRAW`. Si la malla se va a modificar. Ej: objetos que se pueden romper.
	- `GL_STREAM_DRAW`. Punto intermedio entre ambas. Ej: personajes que cambian de aspecto.

```
void glDrawArrays(GLenum mode, GLint first, GLsizei count) // Dibuja vértices (Solo funciona si no se utilizan shaders)
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices) // Con shaders
```
- `mode`. Primitiva que se va a dibujar.
- `first`. Primer índice que se va a dibujar.
- `count`. Número de elementos que se van a dibujar.
- `type`. Formato en que están definidos los índices (`GL_UNSIGNED_SHORT/GL_UNSIGNED_INT`).
- `indices`. Podemos redefinir el array de indices (si están cargados previamente, nullptr).

### Pintado

Primitivas de dibujado:
- `GL_POINTS`. Dibuja vértices como puntos.
- `GL_TRIANGLES`. Dibuja grupos de 3 vértices como triángulos.
- `GL_TRIANGLES_STIP`. Dibuja grupo de vértices como triángulos. Por cada nuevo vértice lo conecta con los dos anteriores.
- `GL_TRIANGLE_LOOP`. Dibuja grupo de vértices como triángulos. Por cada nuevo vértice lo conecta con el anterior y el primero (abanico).
- `GL_LINES`. Dibuja parejas de vértices como líneas.
- `GL_LINE_STRIP`. Dibuja conjunto de puntos como línas (sin conectar el primero con el último).
- `GL_LINE_LOOP`. Dibuja conjunto de puntos como línas (conecta el primero con el último).
- `GL_POLYGON`. Dibuja conjunto de vértices como un único polígono, hay que poner los vértices en orden con sus adyacentes.

Opciones para recortar el frame buffer de salida (viewpoert):
- `glViewport(GLint x, GLint y, GLsizei width, GLsizei height)`. Indica el espacio donde se vuelca el buffer de salida. Si no quiero aberraciones, mejor ajustarlo al tamaño de la ventana: (x,y)=(0,0) y ancho/alto el de la ventana.
- `void glScissor GLint x, GLint y, GLsizei width, GLsizei height)`. Hay que habilitarlo con `GL_SCISSOR_TEST` y excluye las partes del viewport que quedan fuera.
- `void glClearColor GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)`. Define el color para limpiar el buffer de salida.
- `void glClear GLbitfield mask)`. Limpia los buffers con el color definido. Tipos de buffer: `GL_COLOR_BUFFER_BIT` (buffer de color), `GL_DEPTH_BUFFER_BIT` (buffer de profundidad) y `GL_STENCIL_BUFFER_BIT` (buffer de recortado)

## GLM

Librería matemática para C++ que nos ayuda a escribir shaders. Opera en radianes

### GLM:mat4

Tipo de dato que almacena matrices 4x4 de floats. Funciones principales:
- `mat4 make_mat4( float* arr)`. Constructor de matriz 4x4 a partir de vector de 16 elementos.
- `float* value_ptr ( mat4& mat)`. Puntero a un vector con los 16 elementos de la matriz.
- `mat4 inverse (mat4 m)` Devuelve la inversa de la matriz dada.
- `mat4 transpose (mat4 m)` Devuelve la traspuesta de la matriz dada.
- `mat4 frustum (float left, float right, float bottom, float top, float near, float far)` Devuelve una matriz con perspectiva con el volumen de proyección indicado por los parámetros.
- `mat4 perspective (float fovy, float aspect, float near, float far)`. Devuelve una matriz con perspectiva con el volumen de proyección calculado a partir de los parámetros.
- `mat4 ortho (float left, float right, float bottom, float top, float near, float far)`. Devuelve una matriz de proyección ortogonal con el volumen de proyección indicado por los parámetros.
 - `mat4 lookAt (vec3 eye , vec3 center, vec3 up)`.Construye una matriz de vista con el observador colocado en la posición eye , mirando hacia la posición center, y con el eje up de su sistema de coordenadas apuntando hacia arriba.
- `mat4 rotate (mat4 m, float angle , vec3 axis)`. Devuelve una matriz con la matriz m rotada el número de radianes indicados por angle en torno al vector axis.
- `mat4 scale (mat4 m, vec3 v)`. Devuelve una matriz con la matriz m escalada por los factores de escala indicados por v.
- `mat4 translate (mat4 m, vec v)`. Devuelve una matriz con la matriz m trasladada por el vector v.

### Quat

Tipo de dato que almacena quaterniones. Funciones principales:
- `quat (float w, float x, float y, float z)`. Constructor, por defecto (1,0,0,0).
- `quat (vec3 euler)`. Constructor a partir de una rotación de euler.
- `vec3 eulerAngles(quat q)`Representación euler de un cuaternión
- `angleAxis (float angle , vec3 axis)`. Cuaternión a paritr de rotación en torno a un eje.
- `float angle (quat q)`. Ángulo de rotación de un cuaterninón
- `vec3 axis( quat q)`. Eje de rotación de un cuaternión
- `quat slerp (quat q1, quat q2, float a)`.Interpolación esférica linal entre dos cuaterniones.

### vec2, vec3 y vec4

Tipo de dato que almacena vectores de 2,3 y 4 coordenadas respectivamente. vec2 se suele utilizar para coordenadas de textura, vec3 para factores de escala XYZ o posiciones en el espacio euclídeo y vec4 para vectores en el espacio proyectivo o colores RGBA. Funciones principales:
- `vec4.x/vec4.r/vec4.s`. Accede a la primera coordenada del vector.
- `vec4.y/vec4.g/vec4.t`. Accede a la segunda coordenada del vector.
- `vec4.z/vec4.b/vec4.p`. Accede a la tercera coordenada del vector.
- `vec4.w/vec4.a/vec4.q`. Accede a la cuarta coordenada del vector.
- `vec3 cross (vec3 a, vec3 b)`. Producto vectorial.
- `float dot (vec3 a, vec3 b)`. Producto escalar.
- `float length (vec3 v)`. Longitud del vector.
- `vec3 normalize (vec3 v)`.Vector v normalizado.
- `vec3 mix (vec3 a, vec3 b, float f)`.Interpolación lineal entre b y 1 con factor f.
Se puede acceder a las coordenadas de un vector con la notación {x,
y, z, w}, {r, g, b, a}, o {s, t, p, q}.