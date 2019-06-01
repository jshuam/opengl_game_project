#pragma once

#include "../gl/drawables/texture.hpp"
#include "BaseComponent.hpp"
#include "SpriteAnimationComponent.hpp"

class SpriteComponent : public BaseComponent<SpriteComponent>
{
public:
	SpriteComponent(std::unique_ptr<SpriteAnimationComponent> animations, unsigned int activeAnim, float width, float height);

	inline void setActiveAnimation(unsigned int animType) { m_activeAnimation = animType; }
	inline const glm::vec2& getAnimation() const { return m_animations->getAnimation(m_activeAnimation); }
	inline const unsigned int getActiveAnimation() const { return m_activeAnimation; }
	inline float getWidth() const { return m_width; }
	inline float getHeight() const { return m_height; }

private:
	std::unique_ptr<SpriteAnimationComponent> m_animations;
	unsigned int m_activeAnimation;
	float m_width, m_height;
};