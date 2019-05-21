#pragma once

#include "GLObject.hpp"

class GLDrawable : public GLObject
{
public:
	virtual ~GLDrawable() = default;

	virtual void bind() const = 0;
	virtual void unbind() const = 0;

public:
	enum DrawableType
	{
		VertexArray,
		VertexBuffer,
		IndexBuffer
	};
};
