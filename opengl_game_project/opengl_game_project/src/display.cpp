#include "display.hpp"

#include <iostream>

Display::Display()
{
	/* Initialize the library */
	if( !glfwInit() )
	{
		std::cout << "Could not initialize GLFW" << std::endl;
		std::cin.get();
		exit( -1 );
	}

	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, opengl_major_version );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, opengl_minor_version );
	glfwWindowHint( GLFW_OPENGL_PROFILE, opengl_profile );

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow( width, height, title, NULL, NULL );
	if( !window )
	{
		glfwTerminate();
		std::cout << "Could not create GLFW window" << std::endl;
		std::cin.get();
		exit( -1 );
	}

	/* Make the window's context current */
	glfwMakeContextCurrent( window );
	glfwSwapInterval( 1 );

	glfwSetWindowUserPointer( window, user_pointer );
}

Display::~Display()
{
	glfwTerminate();
}

bool Display::should_close() const
{
	return glfwWindowShouldClose( window );
}

void Display::clear() const
{
	glClear( GL_COLOR_BUFFER_BIT );
}

void Display::update() const
{
	glfwSwapBuffers( window );
	glfwPollEvents();
}