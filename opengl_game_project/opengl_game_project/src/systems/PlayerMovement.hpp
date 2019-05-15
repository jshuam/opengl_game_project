#pragma once
#include "System.hpp"

class PlayerMovement : public System
{
public:
	virtual void update() const override;
};
