#pragma once

#include "glm/ext/vector_float4.hpp"

#include <memory>
#include <vector>

#include "../gl/drawables/VertexArray.hpp"
#include "BaseComponent.hpp"

class Drawable : public BaseComponent<Drawable>
{
public:
	Drawable(VertexArray vertexArray, glm::vec4 color = {1.0, 1.0, 1.0, 1.0});
	inline glm::vec4& getColor() { return m_color; };
	inline std::vector<std::unique_ptr<GLDrawable>>& getDrawables() { return m_drawables; };

private:
	glm::vec4 m_color;
	std::vector<std::unique_ptr<GLDrawable>> m_drawables;
};
