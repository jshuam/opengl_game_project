#include "transform.hpp"

Transform::Transform( glm::vec3 position, float scale )
	:
	position( position ),
	scale( scale )
{}

glm::vec3& Transform::get_position()
{
	return position;
}

float& Transform::get_scale()
{
	return scale;
}
