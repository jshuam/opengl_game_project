#pragma once

#include "scene.h"
#include "../entities/entity.h"
#include "../gl/objects/program.h"

#include <memory>
#include <vector>

class TestScene : public Scene
{
private:
	std::vector<std::shared_ptr<Entity>> entities;
	Program program;

public:
	TestScene();
	~TestScene() = default;
	void render() const override;
};