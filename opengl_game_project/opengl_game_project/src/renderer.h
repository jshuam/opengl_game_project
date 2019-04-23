#pragma once

#include <GL/glew.h>

#include "Entity.h"

class Renderer
{
public:
	Renderer();

	void draw( const Entity& entity ) const;
};