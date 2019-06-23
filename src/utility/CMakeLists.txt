set(UTILITY_SOURCE_FILES
    Display.cpp
    Display.hpp
    Font.cpp
    Font.hpp
    Keyboard.hpp
    Mouse.cpp
    Mouse.hpp
    Utils.hpp
)
add_library(utility ${UTILITY_SOURCE_FILES})

target_link_libraries(utility systems)