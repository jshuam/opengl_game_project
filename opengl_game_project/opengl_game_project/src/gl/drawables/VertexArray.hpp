#pragma once

#include <unordered_map>

#include "../GLDrawable.hpp"
#include "VertexBuffer.hpp"

class VertexArray : public GLDrawable
{
public:
	VertexArray();

	void addBuffer(unsigned int type, VertexBuffer vertexBuffer);

	virtual void bind() const override;
	virtual void unbind() const override;

	inline const auto& getBuffer(unsigned int type) const { return m_buffers.find(type)->second; }

private:
	std::unordered_map<unsigned int, VertexBuffer> m_buffers;
};
