#pragma once

#include <GL/glew.h>

class renderer
{
public:
	renderer();

	void clear() const;
	void draw() const;
};