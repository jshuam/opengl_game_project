#pragma once

#include <vector>

class Scene
{
public:
	virtual ~Scene() = default;
	virtual void render() = 0;
};