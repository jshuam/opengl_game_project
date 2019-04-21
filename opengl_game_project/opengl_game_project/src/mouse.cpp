#include "Mouse.h"

#include <iostream>

Mouse::Mouse( const Display& display )
{
	glfwSetCursorPosCallback( display.get_window(), cursor_position_callback );
	glfwSetMouseButtonCallback( display.get_window(), mouse_button_callback );
}

void Mouse::cursor_position_callback( GLFWwindow* window, double x_pos, double y_pos )
{
}

void Mouse::mouse_button_callback( GLFWwindow* window, int button, int action, int mods )
{
	if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE )
	{
		double x_pos, y_pos;
		glfwGetCursorPos( window, &x_pos, &y_pos );
		std::cout << "Mouse Clicked At: " << x_pos << " X " << y_pos << " Y" << std::endl;
	}
}
