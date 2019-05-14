#pragma once

#include "../GLDrawable.hpp"
#include "VertexBuffer.hpp"

#include <vector>

class VertexArray : public GLDrawable
{
public:
	VertexArray();

	void addBuffer(VertexBuffer vertexBuffer);

	virtual void bind() const override;
	virtual void unbind() const override;

	inline const auto& get_vertex_buffers() { return vbos; }

private:
	std::vector<VertexBuffer> vbos;
};

