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
	Mouse mouse( display );
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

	float positions[] =
	{
		0.0f, 0.0f,
		200.0f, 0.0f,
		200.0f, 200.0f,
		0.0f, 200.0f
	};

	float tex_coords[] =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	unsigned int indices[] = { 0, 1, 2, 2, 3, 0 };

	Vertex_Array vao;
	Index_Buffer ibo( indices, 6 );

	vao.add_buffer( { sizeof( float ) * 8, positions, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );
	vao.add_buffer( { sizeof( float ) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );

	Entity entity( vao, ibo );

	Program program;

	Shader vertex_shader( GL_VERTEX_SHADER, "res/shaders/vertex.glsl" );
	Shader fragment_shader( GL_FRAGMENT_SHADER, "res/shaders/fragment.glsl" );

	program.attach_shader( vertex_shader );
	program.attach_shader( fragment_shader );
	program.compile();

	program.bind();

	glm::mat4 proj = glm::ortho( 0.0f, (float) display.get_width(), 0.0f, (float) display.get_height() );

	Texture texture( "res/textures/logo.png" );

	program.set_uniform_1i( "u_tex", 1 );
	program.set_uniform_mat4f( "u_mvp", proj );

	Renderer renderer;

	Font font( "res/fonts/Roboto/Roboto-Regular.ttf", 48 );
	Text hello( "Hello World!", &font, { 0, 0 }, 1.0f, { 1.0f, 1.0f, 1.0f } );
	hello.set_position( { ( display.get_width() / 2 ) - ( hello.get_width() / 2 ), ( display.get_height() / 2 ) - ( hello.get_height() / 2 ) } );
	hello.set_color( { 1.0, 1.0, 1.0 } );

	float positions_2[] =
	{
		( display.get_width() / 2 ) - ( hello.get_width() / 2 ) - 15.0f, ( display.get_height() / 2 ) - ( hello.get_height() / 2 ) - 15.0f,
		( display.get_width() / 2 ) - ( hello.get_width() / 2 ) + hello.get_width() + 15.0f, ( display.get_height() / 2 ) - ( hello.get_height() / 2 ) - 15.0f,
		( display.get_width() / 2 ) - ( hello.get_width() / 2 ) + hello.get_width() + 15.0f, ( display.get_height() / 2 ) - ( hello.get_height() / 2 ) + hello.get_height() + 15.0f,
		( display.get_width() / 2 ) - ( hello.get_width() / 2 ) - 15.0f, ( display.get_height() / 2 ) - ( hello.get_height() / 2 ) + hello.get_height() + 15.0f
	};

	unsigned int indices_2[] = { 0, 1, 2, 2, 3, 0 };

	Vertex_Array vao_2;
	Index_Buffer ibo_2( indices_2, 6 );

	vao_2.add_buffer( { sizeof( float ) * 8, positions_2, 2, GL_FLOAT, GL_FALSE, GL_DYNAMIC_DRAW } );

	Entity entity_2( vao_2, ibo_2 );

	while( !display.should_close() )
	{
		display.clear();

		program.bind();

		if( mouse.cursor_within( hello.get_bounds() ) )
		{
			program.set_uniform_4f( "u_color", 1.0, 0.6, 0.6, 1.0 );
		}
		else
		{
			program.set_uniform_4f( "u_color", 1.0, 0.5, 0.5, 1.0 );
		}

		texture.bind( 1 );
		entity.bind();
		renderer.draw();
		entity_2.bind();
		renderer.draw();
		hello.render();

		display.update();
	}

	return 0;
}