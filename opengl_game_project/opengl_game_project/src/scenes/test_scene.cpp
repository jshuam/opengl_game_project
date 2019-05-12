#include "test_scene.hpp"
#include "../gl/drawables/vertex_array.hpp"
#include "../gl/drawables/index_buffer.hpp"
#include "../gl/objects/program.hpp"
#include "../gl/objects/shader.hpp"
#include "../components/drawable.hpp"
#include "../entities/entity_manager.hpp"
#include "../display.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

TestScene::TestScene()
	:
	program(),
	renderer()
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

	auto entity = std::make_unique<Entity>();
	auto drawable = std::make_unique<Drawable>( std::move( vao ) );
	drawable->drawables.push_back( std::make_unique<IndexBuffer>( indices, 6 ) );
	entity->add_component<Drawable>( std::move( drawable ) );
	renderer.add_entity( entity->get_id() );
	EntityManager::create_entity( std::move( entity ) );
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
	renderer.update();
}
