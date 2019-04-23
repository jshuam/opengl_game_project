#pragma once

#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene() = default;
	void render() const override;
};