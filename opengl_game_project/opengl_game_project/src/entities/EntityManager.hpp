#pragma once

#include <guiddef.h>
#include <map>
#include <memory>

#include "../utility/Utils.hpp"
#include "Entity.hpp"

class EntityManager
{
public:
	EntityManager() = delete;
	static void createEntity(std::unique_ptr<Entity> entity);

	template<typename T>
	static T& getComponent(const GUID& entityId)
	{
		return m_entities[entityId]->getComponent<T>();
	}

private:
	static std::map<GUID, std::unique_ptr<Entity>, GUIDComparator> m_entities;
};
