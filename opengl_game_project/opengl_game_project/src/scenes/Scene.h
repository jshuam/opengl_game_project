#pragma once

#include "../Program.h"
#include "../Renderer.h"

#include <vector>

class Scene
{
private:
	Renderer renderer;

protected:
	std::vector<Program> programs;

protected:
	Scene() = default;

public:
	virtual ~Scene() = default;
	virtual void render() const = 0;
};