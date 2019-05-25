#include "PlayerMovement.hpp"
#include "../components/TransformComponent.hpp"
#include "../entities/EntityManager.hpp"
#include "../utility/Display.hpp"

void PlayerMovement::update() const
{
	for(auto& entity : m_entities)
	{
		auto& transformComponent = EntityManager::getComponent<Transform>(entity);

		if(Display::getKey(GLFW_KEY_W, GLFW_PRESS))
		{
			transformComponent.getPosition().y += 50.0f * Display::getDeltaTime();
		}
		if(Display::getKey(GLFW_KEY_S, GLFW_PRESS))
		{
			transformComponent.getPosition().y -= 50.0f * Display::getDeltaTime();
		}
		if(Display::getKey(GLFW_KEY_D, GLFW_PRESS))
		{
			transformComponent.getPosition().x += 50.0f * Display::getDeltaTime();
		}
		if(Display::getKey(GLFW_KEY_A, GLFW_PRESS))
		{
			transformComponent.getPosition().x -= 50.0f * Display::getDeltaTime();
		}
	}
}
