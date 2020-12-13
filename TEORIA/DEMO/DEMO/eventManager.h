#pragma once
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cstdio>

// Variable que almacena el estado de las teclas:
// 0: liberada
// 1: presionada

extern bool keybEvent[512];
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
