#pragma once

#include "renderer.h"

#include <GLFW/glfw3.h>


class display
{
private:
	GLFWwindow* window;
	renderer* game_renderer;
	void* user_pointer;
	static constexpr const int width = 1280;
	static constexpr const int height = 720;
	static constexpr const unsigned int opengl_major_version = 4;
	static constexpr const unsigned int opengl_minor_version = 4;
	static constexpr const unsigned int opengl_profile = GLFW_OPENGL_CORE_PROFILE;
	static constexpr const char* title = "OpenGL Game Project";

public:
	display();
	~display();

	bool should_close() const;
	void update() const;
	void set_renderer( renderer* renderer );

	inline int get_width() const { return width; }
	inline int get_height() const { return height; }

};