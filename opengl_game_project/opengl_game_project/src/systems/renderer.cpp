#include "renderer.h"

Renderer::Renderer( std::shared_ptr<Drawable> drawable )
	:
	drawable( drawable )
{}

void Renderer::update()
{
	drawable->update();
	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
}
