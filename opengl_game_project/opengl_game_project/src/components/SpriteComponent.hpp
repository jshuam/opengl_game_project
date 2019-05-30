#pragma once

#include "../gl/drawables/texture.hpp"
#include "BaseComponent.hpp"
#include "SpriteAnimationComponent.hpp"

class SpriteComponent : public BaseComponent<SpriteComponent>
{
public:
	SpriteComponent(Texture spriteSheet, std::unique_ptr<SpriteAnimationComponent> animations, unsigned int activeAnim);

	inline void setActiveAnimation(unsigned int animType) { m_activeAnimation = animType; }
	inline const glm::vec2& getAnimations() const { return m_animations->getAnimations(m_activeAnimation); }
	inline const unsigned int getActiveAnimation() const { return m_activeAnimation; }

private:
	Texture m_spriteSheet;
	std::unique_ptr<SpriteAnimationComponent> m_animations;
	unsigned int m_activeAnimation;
};