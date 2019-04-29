#include "drawable.h"

void Drawable::update()
{
	vao.bind();

	for( auto& drawable : drawables )
	{
		drawable.bind();
	}
}
