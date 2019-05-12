#include "EntityManager.hpp"

std::map<GUID, std::unique_ptr<Entity>, GUIDComparator> EntityManager::m_entities;

void EntityManager::createEntity(std::unique_ptr<Entity> entity)
{
	m_entities.insert({entity->getEntityId(), std::move(entity)});
}
