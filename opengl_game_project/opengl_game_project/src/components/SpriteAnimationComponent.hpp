#pragma once

#define ANIM_MOVEMENT_IDLE 0x01
#define ANIM_MOVEMENT_FORWARD 0x02
#define ANIM_MOVEMENT_BACKWARD 0x03
#define ANIM_MOVEMENT_UP 0x04
#define ANIM_MOVEMENT_DOWN 0x05

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
	const std::vector<glm::vec2>& getAnimations(unsigned int animType) const;

private:
	std::unordered_map<unsigned int, std::vector<glm::vec2>> m_animations;
	std::unordered_map<unsigned int, float> m_animationDelays;
	float m_passedTime;
};