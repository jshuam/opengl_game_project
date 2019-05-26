#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(Texture spriteSheet, SpriteAnimationComponent animations)
	:
	m_spriteSheet(std::move(spriteSheet)),
	m_animations(std::move(animations))
{}
