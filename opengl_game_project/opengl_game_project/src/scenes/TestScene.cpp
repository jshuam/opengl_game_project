#include "TestScene.h"
#include "../Display.h"
#include "../VertexArray.h"
#include "../IndexBuffer.h"
#include "../Program.h"
#include "../Shader.h"
#include "../Texture.h"
#include "../Font.h"
#include "../Text.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

TestScene::TestScene()
{

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

	VertexArray vao;
	IndexBuffer ibo( indices, 6 );

	vao.add_buffer( { sizeof( float ) * 8, positions, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );
	vao.add_buffer( { sizeof( float ) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );

	entities.push_back( { vao, ibo } );

	Shader vertex_shader( GL_VERTEX_SHADER, "res/shaders/vertex.glsl" );
	Shader fragment_shader( GL_FRAGMENT_SHADER, "res/shaders/fragment.glsl" );

	program_1.attach_shader( vertex_shader );
	program_1.attach_shader( fragment_shader );
	program_1.compile();

	program_1.bind();

	glm::mat4 proj = glm::ortho( 0.0f, (float) Display::get_width(), 0.0f, (float) Display::get_height() );

	Texture texture( "res/textures/logo.png" );

	program_1.set_uniform_1i( "u_tex", 1 );
	program_1.set_uniform_mat4f( "u_mvp", proj );

	Font font( "res/fonts/Roboto/Roboto-Regular.ttf", 48 );
	Text hello( "Hello World!", &font, { 0, 0 }, 1.0f, { 1.0f, 1.0f, 1.0f } );
	hello.set_position( { ( Display::get_width() / 2 ) - ( hello.get_width() / 2 ), ( Display::get_height() / 2 ) - ( hello.get_height() / 2 ) } );
	hello.set_color( { 1.0, 1.0, 1.0 } );

	float positions_2[] =
	{
		( Display::get_width() / 2 ) - ( hello.get_width() / 2 ) - 15.0f, ( Display::get_height() / 2 ) - ( hello.get_height() / 2 ) - 15.0f,
		( Display::get_width() / 2 ) - ( hello.get_width() / 2 ) + hello.get_width() + 15.0f, ( Display::get_height() / 2 ) - ( hello.get_height() / 2 ) - 15.0f,
		( Display::get_width() / 2 ) - ( hello.get_width() / 2 ) + hello.get_width() + 15.0f, ( Display::get_height() / 2 ) - ( hello.get_height() / 2 ) + hello.get_height() + 15.0f,
		( Display::get_width() / 2 ) - ( hello.get_width() / 2 ) - 15.0f, ( Display::get_height() / 2 ) - ( hello.get_height() / 2 ) + hello.get_height() + 15.0f
	};

	unsigned int indices_2[] = { 0, 1, 2, 2, 3, 0 };

	VertexArray vao_2;
	IndexBuffer ibo_2( indices_2, 6 );

	vao_2.add_buffer( { sizeof( float ) * 8, positions_2, 2, GL_FLOAT, GL_FALSE, GL_DYNAMIC_DRAW } );
	
	entities.push_back( { vao_2, ibo_2 } );
}

void TestScene::render() const
{
	program_1.bind();
	for( auto& entity : entities )
	{
		entity.bind();
		renderer.draw( entity );
	}
}
