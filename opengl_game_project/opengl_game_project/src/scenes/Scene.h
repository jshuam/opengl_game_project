#pragma once

#include "../program.h"

#include <vector>

class Scene
{
protected:

protected:
	Scene() = default;

public:
	virtual ~Scene() = default;
	virtual void render() const;
};