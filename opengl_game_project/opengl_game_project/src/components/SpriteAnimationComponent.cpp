#include "../utility/Display.hpp"
#include "SpriteAnimationComponent.hpp"
#include <xutility>

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

const glm::vec2& SpriteAnimationComponent::getAnimation(unsigned int animType)
{
	float animDelay = m_animationDelays.find(animType)->second;
	const auto& animations = m_animations.find(animType);

	if(animations == m_animations.end())
		std::out_of_range("Animation type could not be found");

	if(m_passedTime > animDelay)
	{
		m_passedTime = 0.0f;
		m_currentAnim++;
	}

	if(m_currentAnim >= animations->second.size())
		m_currentAnim = 0;

	m_passedTime += Display::getDeltaTime();

	return animations->second.at(m_currentAnim);
}
