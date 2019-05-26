#pragma once

#include "../gl/drawables/texture.hpp"
#include "BaseComponent.hpp"
#include "SpriteAnimationComponent.hpp"

class SpriteComponent : public BaseComponent<SpriteComponent>
{
public:
	SpriteComponent(Texture spriteSheet, SpriteAnimationComponent animations);

	inline void setActiveAnimation(unsigned int animType) { m_activeAnimation = animType; }
	inline unsigned int getActiveAnimation() const { return m_activeAnimation; }
	inline const SpriteAnimationComponent& getAnimations() const { return m_animations; }

private:
	Texture m_spriteSheet;
	SpriteAnimationComponent m_animations;
	unsigned int m_activeAnimation;
};