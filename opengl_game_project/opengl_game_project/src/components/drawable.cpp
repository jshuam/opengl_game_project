#include "Drawable.hpp"

Drawable::Drawable(VertexArray vertexArray)
{
	m_drawables.push_back(std::make_unique<VertexArray>(std::move(vertexArray)));
}
