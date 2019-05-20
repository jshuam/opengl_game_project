#include "ISystem.hpp"

void ISystem::addEntity(const GUID& entityId)
{
	m_entities.push_back(entityId);
}
