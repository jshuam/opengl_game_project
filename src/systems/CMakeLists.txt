set(SYSTEMS_SOURCE_FILES
    FontRenderer.cpp
    FontRenderer.hpp
    PlayerMovement.cpp
    PlayerMovement.hpp
    SpriteAnimationSystem.cpp
    SpriteAnimationSystem.hpp
)
add_library(systems ${SYSTEMS_SOURCE_FILES})