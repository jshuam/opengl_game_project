set(SCENES_SOURCE_FILES
    Scene.hpp
    SceneManager.cpp
    SceneManager.hpp
    TestScene.cpp
    TestScene.hpp
)
add_library(scenes ${SCENES_SOURCE_FILES})

target_link_libraries(scenes interfaces)