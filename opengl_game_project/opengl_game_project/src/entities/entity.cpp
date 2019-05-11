#include "entity.hpp"
#include <combaseapi.h>

Entity::Entity()
	:
	id()
{
	CoCreateGuid( &id );
}

const GUID& Entity::get_id()
{
	return id;
}
