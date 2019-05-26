#pragma once

#include "../interfaces/ISystem.hpp"

class SpriteAnimationSystem : ISystem
{
public:
	virtual void update() const override;
};