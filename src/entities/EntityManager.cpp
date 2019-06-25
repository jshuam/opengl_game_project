#include "EntityManager.hpp"

std::map<UUID, std::unique_ptr<Entity>> EntityManager::m_entities;

void EntityManager::createEntity(std::unique_ptr<Entity> entity)
{
    m_entities.insert({ entity->getEntityId(), std::move(entity) });
}
