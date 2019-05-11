#pragma once

#include "entity.hpp"

#include <combaseapi.h>
#include <initguid.h>
#include <guiddef.h>
#include <map>
#include <memory.h>
#include "..\utils.hpp"

class EntityManager
{
private:
	static std::map<GUID, std::unique_ptr<Entity>, GUIDComparator> entities;

public:
	EntityManager() = delete;

	static void create_entity( std::unique_ptr<Entity> entity );

	template<typename T>
	static std::unique_ptr<Component<T>>& get_component( const GUID& entity_id, unsigned int component_id )
	{
		return entities[entity_id]->get_component( component_id );
	}
};
