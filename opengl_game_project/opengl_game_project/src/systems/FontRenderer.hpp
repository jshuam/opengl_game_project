#pragma once

#include "Renderer.hpp"

class FontRenderer : public Renderer
{
public:
	FontRenderer();

	virtual void update() const override;
};
