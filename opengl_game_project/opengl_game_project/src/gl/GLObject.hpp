#pragma once

#include <GL/glew.h>

class GLObject
{
public:
	virtual ~GLObject() = default;

	inline auto& const getGlObjectId() const { return m_glObjectId; }

protected:
	unsigned int m_glObjectId;
};
