#include "system.hpp"

void System::add_entity( const GUID& entity_id )
{
	entities.push_back( entity_id );
}
