#include "drawable.hpp"

Drawable::Drawable( VertexArray&& vao )
	:
	vao( std::move( vao ) )
{}

void Drawable::add_drawable( std::unique_ptr<GLDrawable> drawable )
{
	drawables.push_back( std::move( drawable ) );
}

std::vector<std::unique_ptr<GLDrawable>>& Drawable::get_drawables()
{
	return drawables;
}
