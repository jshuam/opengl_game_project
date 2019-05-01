#pragma once

#include <vector>

class Scene
{
protected:
	Scene() = default;

public:
	virtual ~Scene() = default;
	virtual void render() const;
};