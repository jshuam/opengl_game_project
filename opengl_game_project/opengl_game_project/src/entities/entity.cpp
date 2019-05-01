#include "entity.h"

void Entity::update()
{
	for( auto& system : systems )
	{
		system.update();
	}
}

void Entity::add_component( Component&& component )
{
	components.emplace_back( std::move( component ) );
}
