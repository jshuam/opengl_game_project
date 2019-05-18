#include "Drawable.hpp"

Drawable::Drawable(VertexArray vertexArray, glm::vec4 color)
	:
	m_color(color)
{
	m_drawables.push_back(std::make_unique<VertexArray>(std::move(vertexArray)));
}
