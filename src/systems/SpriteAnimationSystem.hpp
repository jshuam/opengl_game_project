#pragma once

#include "../interfaces/ISystem.hpp"

class SpriteAnimationSystem : public ISystem
{
public:
    virtual void update() const override;
};