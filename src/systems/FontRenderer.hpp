#pragma once

#include "../interfaces/IRenderer.hpp"
#include "../interfaces/ISystem.hpp"

class FontRenderer : public IRenderer, public ISystem
{
public:
    FontRenderer();

    virtual void update() const override;
};
