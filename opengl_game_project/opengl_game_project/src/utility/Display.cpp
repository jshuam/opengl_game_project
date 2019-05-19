#include <iostream>

#include "Display.hpp"

Display::Display()
{
	/* Initialize the library */
	if(!glfwInit())
	{
		std::cout << "Could not initialize GLFW" << std::endl;
		std::cin.get();
		exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
	glfwWindowHint(GLFW_OPENGL_PROFILE, OPENGL_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
	if(!m_window)
	{
		glfwTerminate();
		std::cout << "Could not create GLFW window" << std::endl;
		std::cin.get();
		exit(-1);
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	glfwSetWindowUserPointer(m_window, m_userPointer);
}

Display::~Display()
{
	glfwTerminate();
}

bool Display::shouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

bool Display::getKey(unsigned int key, unsigned int state)
{
	return glfwGetKey(m_window, key) == state;
}

void Display::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::update() const
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

GLFWwindow* Display::m_window;
