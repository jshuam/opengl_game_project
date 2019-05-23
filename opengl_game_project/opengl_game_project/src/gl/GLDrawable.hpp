#pragma once

#include "GLObject.hpp"

#define VERTEX_ARRAY	0x01
#define INDEX_BUFFER	0x02
#define VBO_POSITION	0x03
#define VBO_TEX_COORD	0x04
#define VBO_NORMAL		0x05

class GLDrawable : public GLObject
{
public:
	virtual ~GLDrawable() = default;

	virtual void bind() const = 0;
	virtual void unbind() const = 0;
};
