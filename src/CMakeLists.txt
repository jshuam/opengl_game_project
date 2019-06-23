set(APP_SOURCE_FILES 
    application.cpp
)
add_library(application ${APP_SOURCE_FILES})

add_subdirectory(components)
add_subdirectory(core)
add_subdirectory(entities)
add_subdirectory(gl)
add_subdirectory(interfaces)
add_subdirectory(scenes)
add_subdirectory(systems)
add_subdirectory(utility)

target_link_libraries(application utility)