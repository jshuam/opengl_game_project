#pragma once

#include "../components/component.h"
#include "../systems/system.h"

#include <vector>

class Entity
{
public:
	Entity() = default;

	void update();

private:
	std::vector<Component> components;
	std::vector<System> systems;
};