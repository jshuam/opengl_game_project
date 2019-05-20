#pragma once
#include "System.hpp"

class PlayerMovement : public ISystem
{
public:
	virtual void update() const override;
};
