#include "EntityManager.hpp"

std::map<uuid_t, std::unique_ptr<Entity>, GUIDComparator> EntityManager::m_entities;

void EntityManager::createEntity(std::unique_ptr<Entity> entity)
{
    m_entities.emplace(entity->getEntityId(), std::move(entity));
}
