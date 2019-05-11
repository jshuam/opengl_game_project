#include "entity_manager.hpp"

std::map<GUID, std::unique_ptr<Entity>, GUIDComparator> EntityManager::entities;

void EntityManager::create_entity( std::unique_ptr<Entity> entity )
{
	entities.insert( { entity->get_id(), std::move( entity ) } );
}
