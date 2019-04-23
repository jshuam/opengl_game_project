#pragma once

#include "../Program.h"
#include "../Renderer.h"

#include <vector>

class Scene
{
protected:
	Renderer renderer;

protected:
	Scene() = default;

public:
	virtual ~Scene() = default;
	virtual void render() const;
};