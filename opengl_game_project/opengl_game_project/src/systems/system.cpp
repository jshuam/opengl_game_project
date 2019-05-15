#include "System.hpp"

void System::addEntity(const GUID& entityId)
{
	m_entities.push_back(entityId);
}
