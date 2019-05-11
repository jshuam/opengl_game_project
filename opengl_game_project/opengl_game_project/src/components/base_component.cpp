#include "base_component.hpp"

unsigned int BaseComponent::base_component_id = 0;

unsigned int BaseComponent::create_component_id()
{
	return base_component_id++;
}
