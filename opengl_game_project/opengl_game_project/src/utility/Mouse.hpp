#pragma once

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

#include "Display.hpp"

class Mouse
{
public:
	Mouse(const Display& display);
	static bool cursorWithin(glm::vec4 bounds);

private:
	static void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

private:
	static glm::vec2 m_position;
};
