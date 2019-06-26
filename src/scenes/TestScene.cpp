#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <random>

#include "../components/DrawableComponent.hpp"
#include "../components/SpriteAnimationComponent.hpp"
#include "../components/SpriteComponent.hpp"
#include "../components/TextComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../core/BatchRenderer.hpp"
#include "../entities/EntityManager.hpp"
#include "../gl/drawables/IndexBuffer.hpp"
#include "../gl/drawables/Texture.hpp"
#include "../gl/drawables/VertexArray.hpp"
#include "../gl/objects/Program.hpp"
#include "../gl/objects/Shader.hpp"
#include "../systems/FontRenderer.hpp"
#include "../systems/PlayerMovement.hpp"
#include "../systems/SpriteAnimationSystem.hpp"
#include "../utility/Display.hpp"
#include "TestScene.hpp"

TestScene::TestScene()
{
    auto batchRenderer = std::make_unique<BatchRenderer>();
    auto playerMovement = std::make_unique<PlayerMovement>();
    auto spriteAnimationSystem = std::make_unique<SpriteAnimationSystem>();

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> color_dist(0, 1);

    std::uniform_int_distribution<int> w_dist(0, Display::getWidth());
    std::uniform_int_distribution<int> h_dist(0, Display::getHeight());

    std::vector<UUID> entities;

    Texture spriteSheet("../res/sprites/adventurer.png", 1);
    int numSpritesWidth = 7;
    int numSpritesHeight = 11;
    float spriteWidth = spriteSheet.getWidth() / numSpritesWidth;
    float spriteHeight = spriteSheet.getHeight() / numSpritesHeight;
    float glSpriteWidth = spriteWidth / spriteSheet.getWidth();
    float glSpriteHeight = spriteHeight / spriteSheet.getHeight();
    float positions[] = { 0.0f, 0.0f, spriteWidth, 0.0f, spriteWidth, spriteHeight, 0.0f, spriteHeight };
    unsigned int indices[] = { 0, 1, 2, 2, 3, 0 };
    for (unsigned int i = 0; i < 1; i++)
    {
        VertexArray vertexArray;
        vertexArray.addBuffer(VBO_POSITION, { sizeof(float) * 8, positions, 2, GL_FLOAT, GL_FALSE, GL_STATIC_DRAW });
        vertexArray.addBuffer(VBO_TEX_COORD, { sizeof(float) * 4 * 2, nullptr, 2, GL_FLOAT, GL_FALSE, GL_DYNAMIC_DRAW });

        auto entity(std::make_unique<Entity>());

        auto drawable(std::make_unique<DrawableComponent>(std::move(vertexArray), std::move(glm::vec4(color_dist(gen), color_dist(gen), color_dist(gen), color_dist(gen)))));
        drawable->addDrawable(INDEX_BUFFER, std::make_unique<IndexBuffer>(indices, 6));

        auto transform(std::make_unique<TransformComponent>(std::move(glm::vec3(0.0f, 0.0f, 0.0f)), std::move(glm::vec3(7.0f, 7.0f, 7.0f))));

        entity->addComponent<DrawableComponent>(std::move(drawable));
        entity->addComponent<TransformComponent>(std::move(transform));

        std::vector<glm::vec2> animsIdle = { { 0.0f, 10.0f }, { 1.0f, 10.0f }, { 2.0f, 10.0f }, { 3.0f, 10.0f } };
        std::vector<glm::vec2> animsMovement = { { 1.0f, 9.0f }, { 2.0f, 9.0f }, { 3.0f, 9.0f }, { 4.0f, 9.0f }, { 5.0f, 9.0f }, { 6.0f, 9.0f } };
        std::vector<glm::vec2> animsRoll = { { 5.0f, 8.0f }, { 6.0f, 8.0f }, { 0.0f, 7.0f } };

        std::unique_ptr<SpriteAnimationComponent> spriteAnimationComponent(std::make_unique<SpriteAnimationComponent>());
        spriteAnimationComponent->addAnimation(ANIM_MOVEMENT_IDLE, animsIdle, 0.2);
        spriteAnimationComponent->addAnimation(ANIM_MOVEMENT_HORIZONTAL, animsMovement, 0.1);
        spriteAnimationComponent->addAnimation(ANIM_MOVEMENT_ROLL, animsRoll, 0.1);
        std::unique_ptr<SpriteComponent> spriteComponent(std::make_unique<SpriteComponent>(std::move(spriteAnimationComponent), ANIM_MOVEMENT_IDLE, glSpriteWidth, glSpriteHeight));
        entity->addComponent<SpriteComponent>(std::move(spriteComponent));

        entities.push_back(entity->getEntityId());

        playerMovement->addEntity(entity->getEntityId());
        spriteAnimationSystem->addEntity(entity->getEntityId());

        EntityManager::createEntity(std::move(entity));
    }
    batchRenderer->addBatch(std::move(spriteSheet), std::move(entities));

    Shader vertexShader(GL_VERTEX_SHADER, "../res/shaders/vertex.glsl");
    Shader fragmentShader(GL_FRAGMENT_SHADER, "../res/shaders/fragment.glsl");

    auto program = std::make_unique<Program>();
    program->attachShader(vertexShader);
    program->attachShader(fragmentShader);
    program->compile();
    program->bind();
    program->setUniform1i("u_tex", 1);

    batchRenderer->addProgram(std::move(program));

    Shader fontVertexShader(GL_VERTEX_SHADER, "../res/shaders/font_vertex.glsl");
    Shader fontFragmentShader(GL_FRAGMENT_SHADER, "../res/shaders/font_fragment.glsl");

    auto fontProgram = std::make_unique<Program>();
    fontProgram->attachShader(vertexShader);
    fontProgram->attachShader(fragmentShader);
    fontProgram->compile();

    fontProgram->bind();
    fontProgram->setUniform1i("u_tex", 0);

    auto fontRenderer(std::make_unique<FontRenderer>());
    auto fontRoboto(std::make_unique<Font>("../res/fonts/Roboto-Thin.ttf", 48));

    fontRenderer->addProgram(std::move(fontProgram));

    VertexArray vertexArray;
    vertexArray.addBuffer(VBO_POSITION, { sizeof(float) * 6 * 4, nullptr, 4, GL_FLOAT, GL_FALSE, GL_DYNAMIC_DRAW });

    auto entity(std::make_unique<Entity>());
    auto drawable(std::make_unique<DrawableComponent>(std::move(vertexArray)));
    auto transform(std::make_unique<TransformComponent>(std::move(glm::vec3(0.0, 0.0, 0.0))));
    auto text(std::make_unique<TextComponent>("Hello World!", std::move(fontRoboto)));

    entity->addComponent<DrawableComponent>(std::move(drawable));
    entity->addComponent<TransformComponent>(std::move(transform));
    entity->addComponent<TextComponent>(std::move(text));

    fontRenderer->addEntity(entity->getEntityId());
    EntityManager::createEntity(std::move(entity));

    m_systems.push_back(std::move(spriteAnimationSystem));
    m_systems.push_back(std::move(playerMovement));
    m_systems.push_back(std::move(fontRenderer));

    m_renderers.push_back(std::move(batchRenderer));
}

void TestScene::process()
{
    for (auto& system : m_systems)
    {
        system->update();
    }

    for (auto& renderer : m_renderers)
    {
        renderer->render();
    }
}
