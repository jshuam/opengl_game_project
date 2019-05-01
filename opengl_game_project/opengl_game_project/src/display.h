#pragma once

#include <GLFW/glfw3.h>


class Display
{
private:
	GLFWwindow* window;
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

	inline GLFWwindow* get_window() const { return window; }
	static inline int get_width() { return width; }
	static inline int get_height() { return height; }

};