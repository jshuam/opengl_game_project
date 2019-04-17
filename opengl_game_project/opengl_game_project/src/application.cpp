#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cassert>
#include <iostream>
#include <fstream>

#include "display.h"
#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "program.h"
#include "shader.h"
#include "texture.h"
#include "utils.h"

int main( void )
{
	display display;
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
		/* Position  Texture */
		250.0f,  250.0f, 0.0f, 0.0f,
		350.0f,  250.0f, 1.0f, 0.0f,
		350.0f,  350.0f, 1.0f, 1.0f,
		250.0f,  350.0f, 0.0f, 1.0f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	vertex_array va;
	vertex_buffer vb( positions, sizeof( float ) * 16 );
	vertex_buffer_layout vbl;
	vbl.push<float>( 2 );
	vbl.push<float>( 2 );
	va.add_buffer( vb, vbl );

	index_buffer ib( indices, 6 );

	glm::mat4 proj = glm::ortho( 0.0f, static_cast<float>( display.get_width() ), 0.0f, static_cast<float>( display.get_height() ), -1.0f, 1.0f );

	const std::string vertex_filename = "res/shaders/vertex.glsl";
	const std::string fragment_filename = "res/shaders/fragment.glsl";
	const std::string texture_filepath = "res/textures/logo.png";

	program program;
	shader vertex_shader( GL_VERTEX_SHADER, vertex_filename );
	shader fragment_shader( GL_FRAGMENT_SHADER, fragment_filename );

	program.attach_shader( vertex_shader );
	program.attach_shader( fragment_shader );
	program.compile();

	texture texture( texture_filepath );
	program.bind();
	texture.bind();

	program.set_uniform_1i( "u_texture", 0 );
	program.set_uniform_mat4f( "u_mvp", proj );

	program.unbind();
	ib.unbind();
	vb.unbind();
	va.unbind();

	float r = 0.0f;
	float increment = 0.005f;

	renderer renderer;
	display.set_renderer( &renderer );

	/* Loop until the user closes the window */
	while( !display.should_close() )
	{
		/* Render here */
		renderer.clear();

		program.bind();

		va.bind();
		ib.bind();

		renderer.draw();

		if( r > 1.0f || r < 0.0f ) increment = -increment;
		r += increment;

		ib.unbind();
		va.unbind();
		program.unbind();

		display.update();
	}

	return 0;
}