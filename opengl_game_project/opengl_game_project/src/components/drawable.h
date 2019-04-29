#pragma once

#include "../components/component.h"
#include "../gl/gl_drawable.h"
#include "../gl/drawables/vertex_array.h"

#include <vector>

class Drawable : public Component
{
private:
	VertexArray vao;
	std::vector<GLDrawable> drawables;

public:
	void update() override;
};