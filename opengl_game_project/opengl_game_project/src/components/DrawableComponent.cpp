#include "DrawableComponent.hpp"

DrawableComponent::DrawableComponent(VertexArray vertexArray, glm::vec4 color)
	:
	m_color(color)
{
	m_drawables.emplace(VERTEX_ARRAY, std::make_unique<VertexArray>(std::move(vertexArray)));
}

void DrawableComponent::addDrawable(unsigned int type, std::unique_ptr<GLDrawable> drawable)
{
	m_drawables.emplace(type, std::move(drawable));
}
