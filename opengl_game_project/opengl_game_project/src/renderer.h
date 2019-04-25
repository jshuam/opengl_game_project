#pragma once

#include <GL/glew.h>

class Renderer
{
public:
	Renderer();

	void draw( unsigned int vertex_count ) const;
};