#pragma once

#include <GLFW/glfw3.h>

class Display
{
public:
	Display();
	~Display();

	bool shouldClose() const;
	static bool getKey(unsigned int key, unsigned int state);
	void clear() const;
	void update() const;

	inline GLFWwindow* getWindow() const { return m_window; }
	static inline int getWidth() { return m_width; }
	static inline int getHeight() { return m_height; }

private:
	static constexpr const unsigned int OPENGL_MAJOR_VERSION = 4;
	static constexpr const unsigned int OPENGL_MINOR_VERSION = 4;
	static constexpr const unsigned int OPENGL_PROFILE = GLFW_OPENGL_CORE_PROFILE;

	static constexpr const int m_width = 1280;
	static constexpr const int m_height = 720;
	static constexpr const char* m_title = "OpenGL Game Project";
	static GLFWwindow* m_window;
	void* m_userPointer;
};
