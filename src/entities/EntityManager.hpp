#pragma once

#include <map>
#include <memory>
#include <uuid/uuid.h>

#include "../utility/Utils.hpp"
#include "Entity.hpp"

class EntityManager
{
public:
    EntityManager() = delete;
    static void createEntity(std::unique_ptr<Entity> entity);

    template <typename T>
    static T& getComponent(const uuid_t& entityId)
    {
        return m_entities.at(entityId)->getComponent<T>();
    }

private:
    static std::map<uuid_t, std::unique_ptr<Entity>, GUIDComparator> m_entities;
};
