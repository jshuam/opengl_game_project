#pragma once

#include <GLFW/glfw3.h>

class display
{
private:
	GLFWwindow* window;
	static constexpr const unsigned int width = 1280;
	static constexpr const unsigned int height = 720;
	static constexpr const unsigned int opengl_major_version = 4;
	static constexpr const unsigned int opengl_minor_version = 4;
	static constexpr const unsigned int opengl_profile = GLFW_OPENGL_CORE_PROFILE;
	static constexpr const char* title = "OpenGL Game Project";

public:
	display();
	~display();

	bool should_close() const;
	void update() const;

};