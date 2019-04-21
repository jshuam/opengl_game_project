#pragma once

#include "Display.h"

#include <GLFW/glfw3.h>

class Mouse
{
public:
	Mouse( const Display& display );

private:
	static void cursor_position_callback( GLFWwindow* window, double x_pos, double y_pos );
	static void mouse_button_callback( GLFWwindow* window, int button, int action, int mods );
};