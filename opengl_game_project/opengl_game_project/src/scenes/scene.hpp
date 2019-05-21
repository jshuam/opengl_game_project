#pragma once

#include <vector>
#include "../interfaces/IRenderer.hpp"
#include "../interfaces/ISystem.hpp"

class Scene
{
public:
	virtual ~Scene() = default;
	virtual void render() = 0;

protected:
	std::vector<std::unique_ptr<ISystem>> m_systems;
	std::vector<std::unique_ptr<IRenderer>> m_renderers;
};
