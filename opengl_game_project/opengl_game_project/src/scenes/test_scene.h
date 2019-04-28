#pragma once

#include "scene.h"
#include "../entities/entity.h"
#include "../text.h"
#include "../program.h"

#include <vector>

class TestScene : public Scene
{
private:
	std::vector<entity> entities;
	Program program_1;

public:
	TestScene();
	~TestScene() = default;
	void render() const override;
};