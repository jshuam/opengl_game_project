set(ENTITIES_SOURCE_FILES
    Entity.cpp
    Entity.hpp
    EntityManager.cpp
    EntityManager.hpp
)
add_library(entities ${ENTITIES_SOURCE_FILES})

target_link_libraries(entities core)

