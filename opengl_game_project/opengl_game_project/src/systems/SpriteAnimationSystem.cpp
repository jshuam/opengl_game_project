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
		auto& dAnimations = animations.getAnimations(ANIM_MOVEMENT_FORWARD);

		auto& vertexArray = static_cast<const VertexArray&>(drawableComponent.getDrawable(VERTEX_ARRAY));
		auto& texCoords = vertexArray.getBuffer(VBO_TEX_COORD);

		auto& firstAnimation = dAnimations[0];

		float spriteWidth = 50.0f / 7.0f;
		float spriteHeight = 37.0f / 11.0f;

		float newTexCoords[4][2] =
		{
			{firstAnimation.x, firstAnimation.y},
			{firstAnimation.x + spriteWidth, firstAnimation.y},
			{firstAnimation.x + spriteWidth, firstAnimation.y + spriteHeight},
			{firstAnimation.x, firstAnimation.y + spriteHeight}
		};

		texCoords.modifyBuffer(sizeof(float) * 4 * 2, newTexCoords);
	}
}
