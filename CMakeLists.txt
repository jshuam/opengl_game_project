cmake_minimum_required(VERSION 3.13.4 FATAL_ERROR)
project(OpenGLGameProject)

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)

find_package(GLEW 2.1 REQUIRED)
if(NOT GLEW_FOUND)
    message("ERROR: GLEW not found")
endif(NOT GLEW_FOUND)

find_package(X11 REQUIRED)
if(NOT X11_FOUND)
    message("ERROR: X11 not found")
endif(NOT X11_FOUND)

set(DEPENDENCIES GL GLEW glfw X11)
set (CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(include)