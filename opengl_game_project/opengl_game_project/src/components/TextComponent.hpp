#pragma once

#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/ext/vector_float4.hpp"

#include "../utility/Font.hpp"
#include "BaseComponent.hpp"

class Text : public BaseComponent<Text>
{
public:
	Text() = default;
	Text(const char* text, std::unique_ptr<Font> font);

	inline const char* getText() const { return &m_text[0]; }

private:
	const char* m_text;
	std::unique_ptr<Font> m_font;
};
