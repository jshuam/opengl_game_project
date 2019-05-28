#include "SpriteAnimationComponent.hpp"

void SpriteAnimationComponent::addAnimation(unsigned int animType, std::vector<glm::vec2> animations, float animDelay)
{
	const auto& animation = m_animations.find(animType);

	if(animation != m_animations.end())
	{
		throw std::logic_error("Attempting to override existing animation set");
	}
	else
	{
		m_animations.emplace(animType, std::move(animations));
		m_animationDelays.emplace(animType, animDelay);
	}
}

const std::vector<glm::vec2>& SpriteAnimationComponent::getAnimations(unsigned int animType) const
{
	return m_animations.find(animType)->second;
}
