#include <combaseapi.h>

#include "Entity.hpp"

Entity::Entity()
	:
	m_entityId()
{
	CoCreateGuid(&m_entityId);
}

const GUID& Entity::getEntityId()
{
	return m_entityId;
}
