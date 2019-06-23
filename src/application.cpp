#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

#include "scenes/SceneManager.hpp"
#include "scenes/TestScene.hpp"
#include "utility/Display.hpp"
#include "utility/Mouse.hpp"
#include "utility/Utils.hpp"

int main(void)
{
    Display display;
    Mouse mouse(display);
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        std::cin.get();
    }

/* Setup callback functions */
#if _DEBUG
    if (glDebugMessageCallback != NULL)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(glCheckErrors, nullptr);
    }
#endif

    TestScene testScene;

    SceneManager::addScene(&testScene);
    SceneManager::setActiveScene(0);

    while (!display.shouldClose())
    {
        Display::calculateDeltaTime();
        display.clear();

        SceneManager::processScene();

        display.update();
    }

    return 0;
}
