#include "renderer.hpp"
#include "..\components\drawable.hpp"
#include "..\entities\entity_manager.hpp"
#include "..\entities\entity_manager.hpp"

void Renderer::add_entity( const GUID& entity_id )
{
	entities.push_back( entity_id );
}

void Renderer::update() const
{
	for( const auto& entity : entities )
	{
		auto& drawable_component = EntityManager::get_component<Drawable>( entity );

		for( auto& drawable : drawable_component.get_drawables() )
		{
			drawable->bind();
		}

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
	}
}
