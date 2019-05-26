#pragma once

#define ANIM_MOVEMENT_FORWARD 0x01
#define ANIM_MOVEMENT_BACKWARD 0x02
#define ANIM_MOVEMENT_UP 0x03
#define ANIM_MOVEMENT_DOWN 0x04

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
	inline const auto& getAnimations(unsigned int animType) const { return m_animations.find(animType)->second; }

private:
	std::unordered_map<unsigned int, std::vector<glm::vec2>> m_animations;
	std::unordered_map<unsigned int, float> m_animationDelays;
	float m_passedTime;
};