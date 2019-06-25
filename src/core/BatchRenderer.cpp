#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtx/transform.hpp>

#include "../components/DrawableComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../entities/EntityManager.hpp"
#include "../gl/drawables/IndexBuffer.hpp"
#include "../gl/drawables/Texture.hpp"
#include "../utility/Display.hpp"
#include "BatchRenderer.hpp"

void BatchRenderer::render()
{
    m_program->bind();

    glm::mat4 proj = glm::ortho(0.0f, (float)Display::getWidth(), 0.0f, (float)Display::getHeight());
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    passedTime += Display::getDeltaTime();

    for (const auto& batch : m_batches)
    {
        batch.first.bind();

        for (const uuid_t& entity : batch.second)
        {
            auto& drawableComponent = EntityManager::getComponent<DrawableComponent>(entity);
            auto& transformComponent = EntityManager::getComponent<TransformComponent>(entity);

            for (auto& drawable : drawableComponent.getDrawables())
            {
                drawable.second->bind();
            }

            glm::mat4 model = glm::translate(glm::mat4(1.0f), transformComponent.getPosition());
            glm::vec3& scale = transformComponent.getScale();
            model = glm::scale(model, scale);
            glm::mat4 mvp = proj * view * model;
            m_program->setUniformMat4f("u_mvp", mvp);

            auto& indexBuffer = static_cast<const IndexBuffer&>(drawableComponent.getDrawable(INDEX_BUFFER));

            glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr);
        }
    }
}

void BatchRenderer::addBatch(Texture batchKey, std::vector<uuid_t> batch)
{
    m_batches.emplace(std::move(batchKey), std::move(batch));
}
