#pragma once

#include "../components/component.h"
#include "../systems/system.h"

#include <vector>

class Entity
{
public:
	Entity() = default;

	void update();
	void add_component( Component&& component );

private:
	std::vector<Component> components;
	std::vector<System> systems;
};