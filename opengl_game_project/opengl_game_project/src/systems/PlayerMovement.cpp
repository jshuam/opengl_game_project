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

		spriteComponent.setActiveAnimation(ANIM_MOVEMENT_IDLE);

		if(Display::getKey() == GLFW_KEY_W && (Display::getAction() == GLFW_PRESS || Display::getAction() == GLFW_REPEAT))
		{
			transformComponent.getPosition().y += 300.0f * Display::getDeltaTime();
			spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
		}
		if(Display::getKey() == GLFW_KEY_S && (Display::getAction() == GLFW_PRESS || Display::getAction() == GLFW_REPEAT))
		{
			transformComponent.getPosition().y -= 300.0f * Display::getDeltaTime();
			spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
		}
		if(Display::getKey() == GLFW_KEY_D && (Display::getAction() == GLFW_PRESS || Display::getAction() == GLFW_REPEAT))
		{
			if(Display::getMods() & GLFW_MOD_CONTROL)
			{
				if(transformComponent.getScale().x < 0)
				{
					transformComponent.getScale().x = -transformComponent.getScale().x;
					transformComponent.getPosition().x -= 50.0f;
					transformComponent.getPosition().x -= 300.0f;
				}
				else
				{
					transformComponent.getPosition().x += 300.0f * Display::getDeltaTime();
				}
				spriteComponent.setActiveAnimation(ANIM_MOVEMENT_ROLL);
			}
			else
			{
				if(transformComponent.getScale().x < 0)
				{
					transformComponent.getScale().x = -transformComponent.getScale().x;
					transformComponent.getPosition().x -= 50.0f;
					transformComponent.getPosition().x -= 300.0f;
				}
				else
				{
					transformComponent.getPosition().x += 300.0f * Display::getDeltaTime();
				}
				spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
			}
		}
		if(Display::getKey() == GLFW_KEY_A && (Display::getAction() == GLFW_PRESS || Display::getAction() == GLFW_REPEAT))
		{
			if(Display::getMods() & GLFW_MOD_CONTROL)
			{
				if(transformComponent.getScale().x >= 0)
				{
					transformComponent.getScale().x = -transformComponent.getScale().x;
					transformComponent.getPosition().x += 50.0f;
					transformComponent.getPosition().x += 300.0f;
				}
				else
				{
					transformComponent.getPosition().x -= 300.0f * Display::getDeltaTime();
				}
				spriteComponent.setActiveAnimation(ANIM_MOVEMENT_ROLL);
			}
			else
			{
				if(transformComponent.getScale().x >= 0)
				{
					transformComponent.getScale().x = -transformComponent.getScale().x;
					transformComponent.getPosition().x += 50.0f;
					transformComponent.getPosition().x += 300.0f;
				}
				else
				{
					transformComponent.getPosition().x -= 300.0f * Display::getDeltaTime();
				}
				spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
			}
		}
	}
}
