#pragma once

#include <memory>
#include <vector>

#include "../systems/System.hpp"
#include "Scene.hpp"

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene() = default;
	void render() override;

private:
	std::vector<std::unique_ptr<System>> m_systems;
};
