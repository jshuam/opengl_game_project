#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cassert>
#include <iostream>
#include <fstream>

#include "Display.h"
#include "Mouse.h"
#include "Renderer.h"
#include "Font.h"
#include "Text.h"
#include "Vertex_Array.h"
#include "Vertex_Buffer.h"
#include "Index_Buffer.h"
#include "Entity.h"
#include "Program.h"
#include "Shader.h"
#include "Texture.h"
#include "Utils.h"

int main( void )
{
	Display display;
	Mouse Mouse( display );
	GLenum err = glewInit();
	if( GLEW_OK != err )
	{
		fprintf( stderr, "Error: %s\n", glewGetErrorString( err ) );
		std::cin.get();
	}

	/* Setup callback functions */
	#if DEBUG
	if( glDebugMessageCallback != NULL )
	{
		glEnable( GL_DEBUG_OUTPUT );
		glDebugMessageCallback( glCheckErrors, nullptr );
	}
	#endif

	Renderer Renderer;
	Font font( "res/fonts/Roboto/Roboto-Regular.ttf", 48 );
	Text hello( "Hello World!", { 0.0f, 0.0f }, 1.0f, { 1.0f, 1.0f, 1.0f }, &font );

	while( !display.should_close() )
	{
		display.clear();

		hello.render();

		display.update();
	}

	return 0;
}