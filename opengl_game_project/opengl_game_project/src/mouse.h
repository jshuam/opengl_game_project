#pragma once

#include "display.h"

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class Mouse
{
public:
	Mouse( const display& display );

	static bool cursor_within( glm::vec4 bounds );

private:
	static void cursor_position_callback( GLFWwindow* window, double x_pos, double y_pos );
	static void mouse_button_callback( GLFWwindow* window, int button, int action, int mods );

	static glm::vec2 position;
};