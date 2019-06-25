#pragma once

#include <map>
#include <memory>

#include "../utility/UUID.hpp"
#include "../utility/Utils.hpp"
#include "Entity.hpp"

class EntityManager
{
public:
    EntityManager() = delete;
    static void createEntity(std::unique_ptr<Entity> entity);

    template <typename T>
    static T& getComponent(const UUID& entityId)
    {
        return m_entities[entityId]->getComponent<T>();
    }

private:
    static std::map<UUID, std::unique_ptr<Entity>> m_entities;
};
