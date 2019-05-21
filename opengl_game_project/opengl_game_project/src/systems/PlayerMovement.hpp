#pragma once

#include "../interfaces/ISystem.hpp"

class PlayerMovement : public ISystem
{
public:
	virtual void update() const override;
};
