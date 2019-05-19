#include <iostream>

#include "Mouse.hpp"

glm::vec2 Mouse::m_position;

Mouse::Mouse(const Display& display)
{
	glfwSetCursorPosCallback(display.getWindow(), cursorPositionCallback);
	glfwSetMouseButtonCallback(display.getWindow(), mouseButtonCallback);
}

void Mouse::cursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
	m_position.x = (float) xPos;
	m_position.y = (float) yPos;
}

void Mouse::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		std::cout << "Mouse Clicked At: " << xPos << " X " << yPos << " Y" << std::endl;
	}
}

bool Mouse::cursorWithin(glm::vec4 bounds)
{
	return m_position.x >= bounds.x && m_position.x <= bounds.z && m_position.y >= bounds.y && m_position.y <= bounds.w;
}
