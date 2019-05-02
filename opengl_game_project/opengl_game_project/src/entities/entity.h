#pragma once

#include "../components/component.h"
#include "../systems/system.h"

#include <memory>
#include <vector>

class Entity
{
public:
	Entity() = default;

	void update();

public:
	std::vector<std::shared_ptr<Component>> components;
	std::vector<std::shared_ptr<System>> systems;
};