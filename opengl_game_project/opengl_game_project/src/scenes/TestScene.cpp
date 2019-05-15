#include "TestScene.hpp"
#include "../gl/drawables/VertexArray.hpp"
#include "../gl/drawables/IndexBuffer.hpp"
#include "../gl/objects/Program.hpp"
#include "../gl/objects/Shader.hpp"
#include "../components/Drawable.hpp"
#include "../components/Transform.hpp"
#include "../entities/EntityManager.hpp"
#include "../Display.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

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

	unsigned int indices[] = {0, 1, 2, 2, 3, 0};

	VertexArray vao;
	VertexArray vao_2;

	vao.addBuffer({sizeof(float) * 8, positions, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW});
	vao.addBuffer({sizeof(float) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW});

	vao_2.addBuffer({sizeof(float) * 8, positions_2, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW});
	vao_2.addBuffer({sizeof(float) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW});

	auto entity = std::make_unique<Entity>();
	auto entity_2 = std::make_unique<Entity>();
	auto drawable = std::make_unique<Drawable>(std::move(vao));
	auto drawable_2 = std::make_unique<Drawable>(std::move(vao_2));
	auto transform = std::make_unique<Transform>();
	auto transform_2 = std::make_unique<Transform>();
	drawable->getDrawables().push_back(std::make_unique<IndexBuffer>(indices, 6));
	drawable_2->getDrawables().push_back(std::make_unique<IndexBuffer>(indices, 6));
	entity->addComponent<Drawable>(std::move(drawable));
	entity->addComponent<Transform>(std::move(transform));
	entity_2->addComponent<Drawable>(std::move(drawable_2));
	entity_2->addComponent<Transform>(std::move(transform_2));
	auto renderer = std::make_unique<Renderer>();
	auto player_movement = std::make_unique<PlayerMovement>();
	renderer->addEntity(entity->getEntityId());
	renderer->addEntity(entity_2->getEntityId());
	player_movement->addEntity(entity->getEntityId());
	player_movement->addEntity(entity_2->getEntityId());
	EntityManager::createEntity(std::move(entity));
	EntityManager::createEntity(std::move(entity_2));
	/*Texture texture( "res/textures/logo.png" );

	entities.emplace_back( vao, ibo, texture );*/

	Shader vertex_shader(GL_VERTEX_SHADER, "res/shaders/vertex.glsl");
	Shader fragment_shader(GL_FRAGMENT_SHADER, "res/shaders/fragment.glsl");

	auto program = std::make_unique<Program>();
	program->attachShader(vertex_shader);
	program->attachShader(fragment_shader);
	program->compile();

	program->bind();

	program->setUniform1i("u_tex", 0);
	program->setUniform4f("u_color", 1.0, 0.75, 0.5, 1.0);
	renderer->addProgram(std::move(program));

	m_systems.push_back(std::move(player_movement));
	m_systems.push_back(std::move(renderer));
}

void TestScene::render()
{
	for(auto& system : m_systems)
	{
		system->update();
	}
}
