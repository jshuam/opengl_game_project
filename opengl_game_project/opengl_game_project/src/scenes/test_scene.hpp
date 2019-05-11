#pragma once

#include "scene.hpp"
#include "../gl/objects/program.hpp"
#include "../systems/renderer.hpp"

#include <memory>
#include <vector>

class TestScene : public Scene
{
private:
	Program program;
	Renderer renderer;

public:
	TestScene();
	~TestScene() = default;
	void render() const override;
};