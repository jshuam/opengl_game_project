#pragma once

#include <vector>

#include "../GLDrawable.hpp"
#include "VertexBuffer.hpp"

class VertexArray : public GLDrawable
{
public:
	VertexArray();

	void addBuffer(VertexBuffer vertexBuffer);

	virtual void bind() const override;
	virtual void unbind() const override;

	inline const auto& getVertexBuffers() { return vbos; }

private:
	std::vector<VertexBuffer> vbos;
};
