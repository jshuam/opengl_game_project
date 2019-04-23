#pragma once

#include "Scene.h"
#include "../Entity.h"
#include "../Text.h"
#include "../Program.h"

#include <vector>

class TestScene : public Scene
{
private:
	std::vector<Entity> entities;
	Program program_1;

public:
	TestScene();
	~TestScene() = default;
	void render() const override;
};