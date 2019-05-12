#pragma once

#include "../components/component.hpp"
#include "../gl/gl_drawable.hpp"
#include "../gl/drawables/vertex_array.hpp"

#include <memory>
#include <vector>

class Drawable : public Component<Drawable>
{
private:
	VertexArray vao;
	std::vector<std::unique_ptr<GLDrawable>> drawables;

public:
	Drawable( VertexArray&& vao );

	void add_drawable( std::unique_ptr<GLDrawable> drawable );
	std::vector<std::unique_ptr<GLDrawable>>& get_drawables();
};