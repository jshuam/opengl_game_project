#pragma once
#include "component.hpp"
#include "glm\ext\vector_float3.hpp"

class Transform : public Component<Transform>
{
private:
	glm::vec3 position;
	float scale;

public:
	Transform( glm::vec3 position = { 0, 0, 0 }, float scale = 1.0f );
	glm::vec3& get_position();
	float& get_scale();
};