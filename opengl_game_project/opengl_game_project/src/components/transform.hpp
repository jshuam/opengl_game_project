#pragma once

#include "glm/ext/vector_float3.hpp"

#include "BaseComponent.hpp"

class Transform : public BaseComponent<Transform>
{
public:
	Transform(glm::vec3 position = {0, 0, 0}, float scale = 1.0f);
	inline glm::vec3& getPosition() { return m_position; };
	inline float& getScale() { return m_scale; };

private:
	glm::vec3 m_position;
	float m_scale;
};
