#include "Drawable.hpp"

Drawable::Drawable(VertexArray vertex_array)
{
	m_drawables.push_back(std::make_unique<VertexArray>(std::move(vertex_array)));
}
