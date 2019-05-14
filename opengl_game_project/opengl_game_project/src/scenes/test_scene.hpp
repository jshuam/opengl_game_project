#pragma once

#include "scene.hpp"
#include "../gl/objects/Program.hpp"
#include "../systems/renderer.hpp"

#include <memory>
#include <vector>
#include "../systems/player_movement.hpp"
#include "../systems/system.hpp"

class TestScene : public Scene
{
private:
	std::vector<std::unique_ptr<System>> systems;

public:
	TestScene();
	~TestScene() = default;
	void render() override;
};