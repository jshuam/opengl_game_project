#include "SpriteAnimationSystem.hpp"
#include "../entities/EntityManager.hpp"
#include "../components/DrawableComponent.hpp"
#include "../components/SpriteComponent.hpp"

void SpriteAnimationSystem::update() const
{
	for(auto& entity : m_entities)
	{
		auto& drawableComponent = EntityManager::getComponent<DrawableComponent>(entity);
		auto& spriteComponent = EntityManager::getComponent<SpriteComponent>(entity);

		auto& animations = spriteComponent.getAnimations();

		auto& vertexArray = static_cast<const VertexArray&>(drawableComponent.getDrawable(VERTEX_ARRAY));
		auto& texCoords = vertexArray.getBuffer(VBO_TEX_COORD);

		auto& firstAnimation = animations[0];

		float spriteWidth = 7.0f / 50.0f;
		float spriteHeight = 11.0f / 37.0f;

		float newTexCoords[4][2] =
		{
			{firstAnimation.x - 1.0f * spriteWidth, firstAnimation.y * spriteHeight},
			{firstAnimation.x * spriteWidth, firstAnimation.y * spriteHeight},
			{firstAnimation.x * spriteWidth, firstAnimation.y + 1.0f * spriteHeight},
			{firstAnimation.x - 1.0f * spriteWidth, firstAnimation.y + 1.0f * spriteHeight}
		};

		texCoords.modifyBuffer(sizeof(float) * 4 * 2, newTexCoords);
	}
}
