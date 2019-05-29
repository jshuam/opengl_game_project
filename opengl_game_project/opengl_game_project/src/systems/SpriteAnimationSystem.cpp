#include "SpriteAnimationSystem.hpp"
#include "../entities/EntityManager.hpp"
#include "../components/DrawableComponent.hpp"
#include "../components/SpriteComponent.hpp"
#include "../components/TransformComponent.hpp"

void SpriteAnimationSystem::update() const
{
	for(auto& entity : m_entities)
	{
		auto& drawableComponent = EntityManager::getComponent<DrawableComponent>(entity);
		auto& spriteComponent = EntityManager::getComponent<SpriteComponent>(entity);
		auto& transformComponent = EntityManager::getComponent<TransformComponent>(entity);

		auto& animations = spriteComponent.getAnimations();

		auto& vertexArray = static_cast<const VertexArray&>(drawableComponent.getDrawable(VERTEX_ARRAY));
		auto& texCoords = vertexArray.getBuffer(VBO_TEX_COORD);

		auto& firstAnimation = animations[0];

		float spriteWidth = 50.0f / 350.0f;
		float spriteHeight = 37.0f / 407.0f;

		float newTexCoords[4][2] =
		{
			{firstAnimation.x * spriteWidth, firstAnimation.y * spriteHeight},
			{(firstAnimation.x + 1.0f) * spriteWidth, firstAnimation.y * spriteHeight},
			{(firstAnimation.x + 1.0f) * spriteWidth, (firstAnimation.y + 1.0f) * spriteHeight},
			{firstAnimation.x * spriteWidth, (firstAnimation.y + 1.0f) * spriteHeight}
		};

		texCoords.modifyBuffer(sizeof(float) * 4 * 2, newTexCoords);

		if(spriteComponent.getActiveAnimation() == ANIM_MOVEMENT_BACKWARD)
		{
			transformComponent.getScale().x = -transformComponent.getScale().x;
		}
	}
}
