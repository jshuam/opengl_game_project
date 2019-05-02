#include "drawable.h"

Drawable::Drawable( VertexArray&& vao )
	:
	vao( std::move( vao ) )
{}

void Drawable::update()
{
	for( auto& drawable : drawables )
	{
		drawable->bind();
	}
}
