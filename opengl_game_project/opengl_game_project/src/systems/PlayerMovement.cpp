#include "PlayerMovement.hpp"
#include "../components/Transform.hpp"
#include "../entities/EntityManager.hpp"
#include "../Display.hpp"

void PlayerMovement::update() const
{
	for(auto& entity : m_entities)
	{
		auto& transformComponent = EntityManager::getComponent<Transform>(entity);

		if(Display::getKey(GLFW_KEY_W, GLFW_PRESS))
		{
			transformComponent.getPosition().y += 5.0f;
		}
		if(Display::getKey(GLFW_KEY_S, GLFW_PRESS))
		{
			transformComponent.getPosition().y -= 5.0f;
		}
		if(Display::getKey(GLFW_KEY_D, GLFW_PRESS))
		{
			transformComponent.getPosition().x += 5.0f;
		}
		if(Display::getKey(GLFW_KEY_A, GLFW_PRESS))
		{
			transformComponent.getPosition().x -= 5.0f;
		}
	}
}