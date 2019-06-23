#include <iostream>

#include "Display.hpp"

GLFWwindow* Display::m_window;
float Display::oldDeltaTime = glfwGetTime();
float Display::newDeltaTime = 0;
float Display::deltaTime = 0;

Display::Display()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "Could not initialize GLFW" << std::endl;
        std::cin.get();
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, OPENGL_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        std::cout << "Could not create GLFW window" << std::endl;
        std::cin.get();
        exit(-1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
}

Display::~Display()
{
    glfwTerminate();
}

bool Display::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

void Display::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.25, 0.5, 0.25, 1);
}

void Display::update() const
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Display::calculateDeltaTime()
{
    newDeltaTime = glfwGetTime();
    deltaTime = newDeltaTime - oldDeltaTime;
    oldDeltaTime = newDeltaTime;
}

float Display::getDeltaTime()
{
    return deltaTime;
}
