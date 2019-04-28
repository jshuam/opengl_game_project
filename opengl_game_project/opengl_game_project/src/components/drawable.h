#pragma once

#include "../components/component.h"
#include "../index_buffer.h"
#include "../vertex_array.h"
#include "../vertex_buffer.h"

class Drawable : public Component
{
private:


public:
	void update() override;
};