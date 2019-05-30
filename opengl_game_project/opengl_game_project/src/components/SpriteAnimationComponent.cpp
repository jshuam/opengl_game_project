#include "../utility/Display.hpp"
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

const glm::vec2& SpriteAnimationComponent::getAnimations(unsigned int animType)
{
	float animDelay = m_animationDelays.find(animType)->second;
	if(m_passedTime > animDelay)
	{
		m_passedTime = 0.0f;
		m_currentAnim++;
	}
	m_passedTime += Display::getDeltaTime();

	const auto& animations = m_animations.find(animType)->second;

	try
	{
		const glm::vec2& animation = animations.at(m_currentAnim);
		return animation;
	}
	catch (std::out_of_range exception)
	{
		m_currentAnim = 0;
		const glm::vec2& animation = animations.at(m_currentAnim);
		return animation;
	}
}
