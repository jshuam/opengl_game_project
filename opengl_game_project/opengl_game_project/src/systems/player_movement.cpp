#include "player_movement.hpp"
#include "../components/Transform.hpp"
#include "../entities/entity_manager.hpp"
#include "../display.hpp"

void PlayerMovement::update() const
{
	for( auto& entity : entities )
	{
		auto& transform_component = EntityManager::get_component<Transform>( entity );

		if( Display::get_key( GLFW_KEY_W, GLFW_PRESS ) )
		{
			transform_component.get_position().y += 5.0f;
		}
		if( Display::get_key( GLFW_KEY_S, GLFW_PRESS ) )
		{
			transform_component.get_position().y -= 5.0f;
		}
		if( Display::get_key( GLFW_KEY_D, GLFW_PRESS ) )
		{
			transform_component.get_position().x += 5.0f;
		}
		if( Display::get_key( GLFW_KEY_A, GLFW_PRESS ) )
		{
			transform_component.get_position().x -= 5.0f;
		}
	}
}
