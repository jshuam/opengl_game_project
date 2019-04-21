#pragma once

#include "Renderer.h"

#include <GLFW/glfw3.h>


class Display
{
private:
	GLFWwindow* window;
	Renderer* renderer;
	void* user_pointer;
	static constexpr const int width = 1280;
	static constexpr const int height = 720;
	static constexpr const unsigned int opengl_major_version = 4;
	static constexpr const unsigned int opengl_minor_version = 4;
	static constexpr const unsigned int opengl_profile = GLFW_OPENGL_CORE_PROFILE;
	static constexpr const char* title = "OpenGL Game Project";

public:
	Display();
	~Display();

	bool should_close() const;
	void clear() const;
	void update() const;
	void set_renderer( Renderer* Renderer );

	inline GLFWwindow* get_window() const { return window; }
	inline int get_width() const { return width; }
	inline int get_height() const { return height; }

};