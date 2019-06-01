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

		const glm::vec2& animation = spriteComponent.getAnimation();

		auto& vertexArray = static_cast<const VertexArray&>(drawableComponent.getDrawable(VERTEX_ARRAY));
		auto& texCoords = vertexArray.getBuffer(VBO_TEX_COORD);

		float spriteWidth = spriteComponent.getWidth();
		float spriteHeight = spriteComponent.getHeight();

		float newTexCoords[4][2] =
		{
			{animation.x * spriteWidth, animation.y * spriteHeight},
			{(animation.x + 1.0f) * spriteWidth, animation.y * spriteHeight},
			{(animation.x + 1.0f) * spriteWidth, (animation.y + 1.0f) * spriteHeight},
			{animation.x * spriteWidth, (animation.y + 1.0f) * spriteHeight}
		};

		texCoords.modifyBuffer(sizeof(float) * 4 * 2, newTexCoords);
	}
}
