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

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static inline int getKey() { return m_currentKey; }
	static inline int getAction() { return m_currentKeyAction; }
	static inline int getMods() { return m_currentKeyModifiers; }

	inline GLFWwindow* getWindow() const { return m_window; }
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
	void* m_userPointer;
	static int m_currentKey;
	static int m_currentKeyAction;
	static int m_currentKeyModifiers;
};
