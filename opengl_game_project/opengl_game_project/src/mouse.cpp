#include "mouse.h"

#include <iostream>

mouse::mouse( const display& display )
{
	glfwSetCursorPosCallback( display.get_window(), cursor_position_callback );
	glfwSetMouseButtonCallback( display.get_window(), mouse_button_callback );
}

void mouse::cursor_position_callback( GLFWwindow* window, double x_pos, double y_pos )
{
}

void mouse::mouse_button_callback( GLFWwindow* window, int button, int action, int mods )
{
	if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE )
	{
		double x_pos, y_pos;
		glfwGetCursorPos( window, &x_pos, &y_pos );
		std::cout << "Mouse Clicked At: " << x_pos << " X " << y_pos << " Y" << std::endl;
	}
}
