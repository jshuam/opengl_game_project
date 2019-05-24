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
	void addDrawable(unsigned int type, std::unique_ptr<GLDrawable> drawable);

	inline const glm::vec4& getColor() const { return m_color; };
	inline const auto& getDrawables() const { return m_drawables; };
	inline const auto& getDrawable(unsigned int drawable) const { return *m_drawables.find(drawable)->second; }

private:
	glm::vec4 m_color;
	std::unordered_map<unsigned int, std::unique_ptr<GLDrawable>> m_drawables;
};
