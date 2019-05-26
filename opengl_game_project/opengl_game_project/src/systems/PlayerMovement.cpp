#include "../components/SpriteComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../entities/EntityManager.hpp"
#include "../utility/Display.hpp"
#include "PlayerMovement.hpp"

void PlayerMovement::update() const
{
	for(auto& entity : m_entities)
	{
		auto& spriteComponent = EntityManager::getComponent<SpriteComponent>(entity);
		auto& transformComponent = EntityManager::getComponent<TransformComponent>(entity);

		if(Display::getKey(GLFW_KEY_W, GLFW_PRESS))
		{
			transformComponent.getPosition().y += 300.0f * Display::getDeltaTime();
		}
		if(Display::getKey(GLFW_KEY_S, GLFW_PRESS))
		{
			transformComponent.getPosition().y -= 300.0f * Display::getDeltaTime();
		}
		if(Display::getKey(GLFW_KEY_D, GLFW_PRESS))
		{
			transformComponent.getPosition().x += 300.0f * Display::getDeltaTime();
			spriteComponent.setActiveAnimation(ANIM_MOVEMENT_FORWARD);
		}
		if(Display::getKey(GLFW_KEY_A, GLFW_PRESS))
		{
			transformComponent.getPosition().x -= 300.0f * Display::getDeltaTime();
			spriteComponent.setActiveAnimation(ANIM_MOVEMENT_BACKWARD);
		}
	}
}
