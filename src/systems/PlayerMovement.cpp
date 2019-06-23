#include "PlayerMovement.hpp"
#include "../components/SpriteComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../entities/EntityManager.hpp"
#include "../utility/Display.hpp"
#include "../utility/Keyboard.hpp"

void PlayerMovement::update() const
{
    for (auto& entity : m_entities)
    {
        auto& spriteComponent = EntityManager::getComponent<SpriteComponent>(entity);
        auto& transformComponent = EntityManager::getComponent<TransformComponent>(entity);

        spriteComponent.setActiveAnimation(ANIM_MOVEMENT_IDLE);

        if (Keyboard::getKeyPress(GLFW_KEY_W))
        {
            transformComponent.getPosition().y += 300.0f * Display::getDeltaTime();
            spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
        }
        if (Keyboard::getKeyPress(GLFW_KEY_S))
        {
            transformComponent.getPosition().y -= 300.0f * Display::getDeltaTime();
            spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
        }
        if (Keyboard::getKeyPress(GLFW_KEY_D))
        {
            transformComponent.getPosition().x += 300.0f * Display::getDeltaTime();
            spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
        }
        if (Keyboard::getKeyPress(GLFW_KEY_A))
        {
            transformComponent.getPosition().x -= 300.0f * Display::getDeltaTime();
            spriteComponent.setActiveAnimation(ANIM_MOVEMENT_HORIZONTAL);
        }
        if (Keyboard::getKeyPress(GLFW_KEY_LEFT_CONTROL))
            spriteComponent.setActiveAnimation(ANIM_MOVEMENT_ROLL);
    }
}
