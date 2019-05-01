#include "drawable.h"

Drawable::Drawable( VertexArray&& vao )
	:
	vao( std::move( vao ) )
{}

void Drawable::update()
{}

void Drawable::add_drawable( GLDrawable&& drawable )
{
	drawables.emplace_back( std::move( drawable ) );
}
