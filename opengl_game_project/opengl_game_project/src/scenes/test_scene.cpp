#include "test_scene.h"
#include "../display.h"
#include "../gl/drawables/vertex_array.h"
#include "../gl/drawables/index_buffer.h"
#include "../gl/drawables/texture.h"
#include "../gl/objects/program.h"
#include "../gl/objects/shader.h"
#include "../components/drawable.h"
#include "../systems/renderer.h"

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

	vao.add_buffer( { sizeof( float ) * 8, positions, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );
	vao.add_buffer( { sizeof( float ) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );

	Entity entity;
	auto drawable = std::make_shared<Drawable>( std::move( vao ) );
	drawable->drawables.push_back( std::make_shared<IndexBuffer>( indices, 6 ) );
	entity.components.push_back( drawable );
	entity.systems.push_back( std::make_shared<Renderer>( drawable ) );
	entities.push_back( std::make_shared<Entity>( entity ) );

	/*Texture texture( "res/textures/logo.png" );

	entities.emplace_back( vao, ibo, texture );*/

	Shader vertex_shader( GL_VERTEX_SHADER, "res/shaders/vertex.glsl" );
	Shader fragment_shader( GL_FRAGMENT_SHADER, "res/shaders/fragment.glsl" );

	program.attach_shader( vertex_shader );
	program.attach_shader( fragment_shader );
	program.compile();

	program.bind();

	glm::mat4 proj = glm::ortho( 0.0f, (float) Display::get_width(), 0.0f, (float) Display::get_height() );

	program.set_uniform_1i( "u_tex", 0 );
	program.set_uniform_4f( "u_color", 1.0, 0.75, 0.5, 1.0 );
	program.set_uniform_mat4f( "u_mvp", proj );

}

void TestScene::render() const
{
	program.bind();
	for( auto& entity : entities )
	{
		entity->update();
	}
}
