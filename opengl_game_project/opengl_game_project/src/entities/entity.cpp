#include "entity.h"

void Entity::update()
{
	for( auto& system : systems )
	{
		system.update();
	}
}
