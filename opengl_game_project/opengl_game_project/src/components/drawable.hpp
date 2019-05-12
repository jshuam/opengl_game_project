#pragma once

#include "../components/component.hpp"
#include "../gl/gl_drawable.hpp"
#include "../gl/drawables/vertex_array.hpp"

#include <memory>
#include <vector>

class Drawable : public Component<Drawable>
{
public:
	std::vector<std::unique_ptr<GLDrawable>> drawables;

public:
	Drawable( VertexArray vao );
	std::vector<std::unique_ptr<GLDrawable>>& get_drawables();
};