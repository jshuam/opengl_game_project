#pragma once

#include <GLFW/glfw3.h>

class Display
{
public:
	Display();
	~Display();

	bool shouldClose() const;
	void clear() const;
	void update() const;

	static inline GLFWwindow* getWindow() { return m_window; }
	static inline int getWidth() { return m_width; }
	static inline int getHeight() { return m_height; }

	static void calculateDeltaTime();
	static float getDeltaTime();

private:
	static constexpr const unsigned int OPENGL_MAJOR_VERSION = 4;
	static constexpr const unsigned int OPENGL_MINOR_VERSION = 4;
	static constexpr const unsigned int OPENGL_PROFILE = GLFW_OPENGL_CORE_PROFILE;

	static constexpr const int m_width = 1280;
	static constexpr const int m_height = 720;
	static constexpr const char* m_title = "OpenGL Game Project";
	static float oldDeltaTime;
	static float newDeltaTime;
	static float deltaTime;
	static GLFWwindow* m_window;
};
