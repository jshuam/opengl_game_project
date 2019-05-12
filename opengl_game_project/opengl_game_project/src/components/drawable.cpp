#include "drawable.hpp"

Drawable::Drawable( VertexArray vao )
{
	drawables.push_back( std::make_unique<VertexArray>( std::move( vao ) ) );
}

std::vector<std::unique_ptr<GLDrawable>>& Drawable::get_drawables()
{
	return drawables;
}
