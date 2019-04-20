#pragma once

#include "display.h"

#include <GLFW/glfw3.h>

class mouse
{
public:
	mouse( const display& display );

private:
	static void cursor_position_callback( GLFWwindow* window, double x_pos, double y_pos );
	static void mouse_button_callback( GLFWwindow* window, int button, int action, int mods );
};