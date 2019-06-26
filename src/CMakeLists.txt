cmake_minimum_required(VERSION 3.13.4 FATAL_ERROR)
find_program(CMAKE_C_COMPILER NAMES $ENV{CC} gcc PATHS ENV PATH NO_DEFAULT_PATH)
find_program(CMAKE_CXX_COMPILER NAMES $ENV{CXX} g++ PATHS ENV PATH NO_DEFAULT_PATH)
project(OpenGLGameProject C CXX)

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

find_package(PkgConfig REQUIRED)
if(NOT PKG_CONFIG_FOUND)
    message("ERROR: pkg-config not found")
endif(NOT PKG_CONFIG_FOUND)

pkg_check_modules(UUID REQUIRED uuid)
if(NOT UUID_FOUND)
    message("ERROR: uuid not found")
endif(NOT UUID_FOUND)

pkg_check_modules(GLFW REQUIRED glfw3)
if(NOT GLFW_FOUND)
    message("ERROR: GLFW not found")
endif(NOT GLFW_FOUND)

pkg_check_modules(FREETYPE REQUIRED freetype2)
if(NOT FREETYPE_FOUND)
    message("ERROR: freetype2 not found")
endif(NOT FREETYPE_FOUND)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDES ../include ../include/freetype2 ${UUID_INCLUDE_DIRS} ${FREETYPE_INCLUDE_DIRS})
set(DEPENDENCIES GL GLEW glfw X11 ${UUID_LIBRARIES} ${FREETYPE_LIBRARIES})

set(APP_SOURCE_FILES 
    application.cpp
)
add_executable(OpenGLGameProject ${APP_SOURCE_FILES})

include_directories(${INCLUDES})

add_subdirectory(components)
add_subdirectory(core)
add_subdirectory(entities)
add_subdirectory(gl)
add_subdirectory(interfaces)
add_subdirectory(scenes)
add_subdirectory(systems)
add_subdirectory(utility)

target_link_libraries(OpenGLGameProject scenes systems utility interfaces core entities components gl ${DEPENDENCIES})