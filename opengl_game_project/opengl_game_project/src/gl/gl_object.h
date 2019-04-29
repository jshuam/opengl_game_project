#pragma once

#include <GL/glew.h>

class GLObject
{
protected:
	unsigned int gl_id;

public:
	virtual ~GLObject() = default;

	inline auto& const get_gl_id() const { return gl_id; }
};