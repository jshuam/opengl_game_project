#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(std::unique_ptr<SpriteAnimationComponent> animations, unsigned int activeAnim, float width, float height)
	:
	m_animations(std::move(animations)),
	m_activeAnimation(activeAnim),
	m_width(width),
	m_height(height)
{}
