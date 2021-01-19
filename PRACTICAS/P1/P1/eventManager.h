#pragma once
#include <GLFW/glfw3.h>
#include <cstdio>
#include <cstdlib>

extern char keybEvent[512];
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int
	mods);