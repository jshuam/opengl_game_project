set(GL_SOURCE_FILES
    GLDrawable.hpp
    GLObject.hpp
)
add_library(gl ${GL_SOURCE_FILES})

add_subdirectory(drawables)
add_subdirectory(objects)

target_link_libraries(gl objects)