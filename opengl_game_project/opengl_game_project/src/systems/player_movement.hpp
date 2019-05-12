#pragma once
#include "system.hpp"

class PlayerMovement : public System
{
public:
	virtual void update() const override;
};