#include "display.h"

#include <iostream>

display::display()
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

display::~display()
{
	glfwTerminate();
}

bool display::should_close() const
{
	return glfwWindowShouldClose( window );
}

void display::update() const
{
	glfwSwapBuffers( window );
	glfwPollEvents();
}

void display::set_renderer( renderer* renderer )
{
	game_renderer = renderer;
}
