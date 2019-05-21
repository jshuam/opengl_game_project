#pragma once

#include "glm/ext/vector_float4.hpp"

#include <memory>
#include <unordered_map>

#include "../gl/drawables/VertexArray.hpp"
#include "BaseComponent.hpp"

class Drawable : public BaseComponent<Drawable>
{
public:
	Drawable(VertexArray vertexArray, glm::vec4 color = {1.0, 1.0, 1.0, 1.0});
	void addDrawable(GLDrawable::DrawableType type, std::unique_ptr<Drawable> drawable);

	inline glm::vec4& getColor() { return m_color; };
	inline const auto& getDrawables() { return m_drawables.begin(); };
	inline const auto& getDrawable(GLDrawable::DrawableType drawable) { return m_drawables.find(drawable); }

private:
	glm::vec4 m_color;
	std::unordered_map<GLDrawable::DrawableType, std::unique_ptr<GLDrawable>> m_drawables;
};
