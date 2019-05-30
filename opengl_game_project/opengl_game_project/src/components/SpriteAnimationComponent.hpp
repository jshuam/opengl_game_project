#pragma once

#define ANIM_MOVEMENT_IDLE 0x01
#define ANIM_MOVEMENT_HORIZONTAL 0x02
#define ANIM_MOVEMENT_VERTICAL 0x03
#define ANIM_MOVEMENT_ROLL 0x04

#include "glm/ext/vector_float2.hpp"

#include <unordered_map>
#include <vector>

#include "BaseComponent.hpp"

class SpriteAnimationComponent : BaseComponent<SpriteAnimationComponent>
{
public:
	SpriteAnimationComponent() = default;

	void addAnimation(unsigned int animType, std::vector<glm::vec2> animations, float animDelay);
	inline float& getPassedTime() { return m_passedTime; }
	const glm::vec2& getAnimations(unsigned int animType);

private:
	std::unordered_map<unsigned int, std::vector<glm::vec2>> m_animations;
	std::unordered_map<unsigned int, float> m_animationDelays;
	float m_passedTime = 0.0f;
	int m_currentAnim = 0;
};