set(COMPONENTS_SOURCE_FILES
    BaseComponent.hpp
    DrawableComponent.cpp
    DrawableComponent.hpp
    SpriteAnimationComponent.cpp
    SpriteAnimationComponent.hpp
    SpriteComponent.cpp
    SpriteComponent.hpp
    TextComponent.cpp
    TextComponent.hpp
    TransformComponent.cpp
    TransformComponent.hpp
)
add_library(components ${COMPONENTS_SOURCE_FILES})