#pragma once

#include "GLFW/glfw3.h"

#include "Display.hpp"

class Keyboard
{
public:
	static bool getKeyPress(int key) { return getKeyState(key, GLFW_PRESS); };
	static bool getKeyRelease(int key) { return getKeyState(key, GLFW_RELEASE); };
	static bool getKeyState(int key, int state) { return glfwGetKey(Display::getWindow(), key) == state; }
};