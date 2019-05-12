#pragma once

#include <memory>
#include <vector>

#include "../gl/drawables/vertex_array.hpp"
#include "BaseComponent.hpp"

class Drawable : public BaseComponent<Drawable>
{
public:
	Drawable(VertexArray vertexArray);
	inline std::vector<std::unique_ptr<GLDrawable>>& getDrawables() { return m_drawables; };

private:
	std::vector<std::unique_ptr<GLDrawable>> m_drawables;
};