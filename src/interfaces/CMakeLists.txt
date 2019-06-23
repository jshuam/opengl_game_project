set(INTERFACES_SOURCE_FILES
    IComponent.cpp
    IComponent.hpp
    IRenderer.cpp
    IRenderer.hpp
    ISystem.cpp
    ISystem.hpp
)
add_library(interfaces ${INTERFACES_SOURCE_FILES})

target_link_libraries(interfaces gl)