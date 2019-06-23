set(OBJECTS_SOURCE_FILES
    Program.cpp
    Program.hpp
    Shader.cpp
    Shader.hpp
)
add_library(objects ${OBJECTS_SOURCE_FILES})

target_link_libraries(objects drawables)