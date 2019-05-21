#include "Drawable.hpp"

Drawable::Drawable(VertexArray vertexArray, glm::vec4 color)
	:
	m_color(color)
{
	m_drawables.emplace(GLDrawable::VertexArray, std::make_unique<VertexArray>(std::move(vertexArray)));
}

void Drawable::addDrawable(GLDrawable::DrawableType type, std::unique_ptr<Drawable> drawable)
{
	m_drawables.emplace(type, std::move(drawable));
}
