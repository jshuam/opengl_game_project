#include <combaseapi.h>

#include "entity.hpp"

Entity::Entity()
	:
	m_entityId()
{
	CoCreateGuid( &m_entityId );
}

const GUID& Entity::get_id()
{
	return m_entityId;
}
