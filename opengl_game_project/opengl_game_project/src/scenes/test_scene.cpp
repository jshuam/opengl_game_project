#include "test_scene.hpp"
#include "../gl/drawables/vertex_array.hpp"
#include "../gl/drawables/index_buffer.hpp"
#include "../gl/objects/program.hpp"
#include "../gl/objects/shader.hpp"
#include "../components/Drawable.hpp"
#include "../entities/entity_manager.hpp"
#include "../display.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "../components/Transform.hpp"

TestScene::TestScene()
{

	float positions[] =
	{
		0.0f, 0.0f,
		200.0f, 0.0f,
		200.0f, 200.0f,
		0.0f, 200.0f
	};

	float positions_2[] =
	{
		300.0f, 300.0f,
		200.0f, 300.0f,
		200.0f, 200.0f,
		300.0f, 200.0f
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
	VertexArray vao_2;

	vao.add_buffer( { sizeof( float ) * 8, positions, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );
	vao.add_buffer( { sizeof( float ) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );

	vao_2.add_buffer( { sizeof( float ) * 8, positions_2, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );
	vao_2.add_buffer( { sizeof( float ) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW } );

	auto entity = std::make_unique<Entity>();
	auto entity_2 = std::make_unique<Entity>();
	auto drawable = std::make_unique<Drawable>( std::move( vao ) );
	auto drawable_2 = std::make_unique<Drawable>( std::move( vao_2 ) );
	auto transform = std::make_unique<Transform>();
	auto transform_2 = std::make_unique<Transform>();
	drawable->drawables.push_back( std::make_unique<IndexBuffer>( indices, 6 ) );
	drawable_2->drawables.push_back( std::make_unique<IndexBuffer>( indices, 6 ) );
	entity->add_component<Drawable>( std::move( drawable ) );
	entity->add_component<Transform>( std::move( transform ) );
	entity_2->add_component<Drawable>( std::move( drawable_2 ) );
	entity_2->add_component<Transform>( std::move( transform_2 ) );
	auto renderer = std::make_unique<Renderer>();
	auto player_movement = std::make_unique<PlayerMovement>();
	renderer->add_entity( entity->get_id() );
	renderer->add_entity( entity_2->get_id() );
	player_movement->add_entity( entity->get_id() );
	player_movement->add_entity( entity_2->get_id() );
	EntityManager::create_entity( std::move( entity ) );
	EntityManager::create_entity( std::move( entity_2 ) );
	/*Texture texture( "res/textures/logo.png" );

	entities.emplace_back( vao, ibo, texture );*/

	Shader vertex_shader( GL_VERTEX_SHADER, "res/shaders/vertex.glsl" );
	Shader fragment_shader( GL_FRAGMENT_SHADER, "res/shaders/fragment.glsl" );

	auto program = std::make_unique<Program>();
	program->attach_shader( vertex_shader );
	program->attach_shader( fragment_shader );
	program->compile();

	program->bind();

	program->set_uniform_1i( "u_tex", 0 );
	program->set_uniform_4f( "u_color", 1.0, 0.75, 0.5, 1.0 );
	renderer->add_program( std::move( program ) );

	systems.push_back( std::move( player_movement ) );
	systems.push_back( std::move( renderer ) );
}

void TestScene::render()
{
	for( auto& system : systems )
	{
		system->update();
	}
}
