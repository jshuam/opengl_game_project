#pragma once

#include "../interfaces/IRenderer.hpp"
#include "../interfaces/ISystem.hpp"
#include <vector>

class Scene
{
public:
    virtual ~Scene() = default;
    virtual void process() = 0;

protected:
    std::vector<std::unique_ptr<ISystem>> m_systems;
    std::vector<std::unique_ptr<IRenderer>> m_renderers;
};
