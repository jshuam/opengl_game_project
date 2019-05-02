#pragma once

#include "../components/component.h"
#include "../gl/gl_drawable.h"
#include "../gl/drawables/vertex_array.h"

#include <memory>
#include <vector>

class Drawable : public Component
{
private:
	VertexArray vao;

public:
	std::vector<std::shared_ptr<GLDrawable>> drawables;

public:
	Drawable( VertexArray&& vao );

	virtual void update() override;
};