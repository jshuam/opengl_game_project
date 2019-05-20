#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include <random>

#include "TestScene.hpp"
#include "../components/Drawable.hpp"
#include "../components/Text.hpp"
#include "../components/Transform.hpp"
#include "../entities/EntityManager.hpp"
#include "../gl/drawables/VertexArray.hpp"
#include "../gl/drawables/IndexBuffer.hpp"
#include "../gl/drawables/Texture.hpp"
#include "../gl/objects/Program.hpp"
#include "../gl/objects/Shader.hpp"
#include "../systems/FontRenderer.hpp"
#include "../systems/Renderer.hpp"
#include "../systems/PlayerMovement.hpp"
#include "../utility/Display.hpp"

TestScene::TestScene()
{

	float positions[] =
	{
		0.0f, 0.0f,
		30.0f, 0.0f,
		30.0f, 30.0f,
		0.0f, 30.0f
	};

	float tex_coords[] =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	unsigned int indices[] = {0, 1, 2, 2, 3, 0};
	auto renderer = std::make_unique<Renderer>();
	auto playerMovement = std::make_unique<PlayerMovement>();

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> color_dist(0, 1);

	std::uniform_int_distribution<int> w_dist(0, Display::getWidth());
	std::uniform_int_distribution<int> h_dist(0, Display::getHeight());

	for(unsigned int i = 0; i < 100; i++)
	{
		VertexArray vertexArray;
		vertexArray.addBuffer({sizeof(float) * 8, positions, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW});
		vertexArray.addBuffer({sizeof(float) * 8, tex_coords, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW});

		auto entity(std::make_unique<Entity>());

		auto drawable(std::make_unique<Drawable>(std::move(vertexArray), std::move(glm::vec4(color_dist(gen), color_dist(gen), color_dist(gen), color_dist(gen)))));
		drawable->getDrawables().push_back(std::make_unique<IndexBuffer>(indices, 6));
		drawable->getDrawables().push_back(std::make_unique<Texture>("res/textures/logo.png", 1));

		auto transform(std::make_unique<Transform>(std::move(glm::vec3(w_dist(gen), h_dist(gen), 0.0))));

		entity->addComponent<Drawable>(std::move(drawable));
		entity->addComponent<Transform>(std::move(transform));

		renderer->addEntity(entity->getEntityId());

		EntityManager::createEntity(std::move(entity));
	}

	Shader vertexShader(GL_VERTEX_SHADER, "res/shaders/vertex.glsl");
	Shader fragmentShader(GL_FRAGMENT_SHADER, "res/shaders/fragment.glsl");

	auto program = std::make_unique<Program>();
	program->attachShader(vertexShader);
	program->attachShader(fragmentShader);
	program->compile();
	program->bind();
	program->setUniform1i("u_tex", 1);

	renderer->addProgram(std::move(program));

	Shader fontVertexShader(GL_VERTEX_SHADER, "res/shaders/font_vertex.glsl");
	Shader fontFragmentShader(GL_FRAGMENT_SHADER, "res/shaders/font_fragment.glsl");

	auto fontProgram = std::make_unique<Program>();
	fontProgram->attachShader(vertexShader);
	fontProgram->attachShader(fragmentShader);
	fontProgram->compile();

	fontProgram->bind();
	fontProgram->setUniform1i("u_tex", 0);

	auto fontRenderer(std::make_unique<FontRenderer>());
	auto fontRoboto(std::make_unique<Font>("res/fonts/Roboto-Thin.ttf", 48));

	fontRenderer->addProgram(std::move(fontProgram));

	VertexArray vertexArray;
	vertexArray.addBuffer({sizeof(float) * 6 * 4, nullptr, 4, GL_FLOAT, GL_FALSE, GL_DYNAMIC_DRAW});

	auto entity(std::make_unique<Entity>());
	auto drawable(std::make_unique<Drawable>(std::move(vertexArray)));
	auto transform(std::make_unique<Transform>(std::move(glm::vec3(0.0, 0.0, 0.0))));
	auto text(std::make_unique<Text>("Hello World!", std::move(fontRoboto)));

	entity->addComponent<Drawable>(std::move(drawable));
	entity->addComponent<Transform>(std::move(transform));
	entity->addComponent<Text>(std::move(text));

	fontRenderer->addEntity(entity->getEntityId());
	playerMovement->addEntity(entity->getEntityId());
	EntityManager::createEntity(std::move(entity));

	m_systems.push_back(std::move(playerMovement));
	m_systems.push_back(std::move(fontRenderer));
	m_systems.push_back(std::move(renderer));
}

void TestScene::render()
{
	for(auto& system : m_systems)
	{
		system->update();
	}
}
