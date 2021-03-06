#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtx/transform.hpp"

#include "../components/DrawableComponent.hpp"
#include "../components/TextComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../entities/EntityManager.hpp"
#include "../utility/Display.hpp"
#include "../utility/Font.hpp"
#include "FontRenderer.hpp"

FontRenderer::FontRenderer()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void FontRenderer::update() const
{
    m_program->bind();

    glm::mat4 proj = glm::ortho(0.0f, (float)Display::getWidth(), 0.0f, (float)Display::getHeight());
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    for (const auto& entity : m_entities)
    {
        auto& drawableComponent = EntityManager::getComponent<DrawableComponent>(entity);
        auto& textComponent = EntityManager::getComponent<TextComponent>(entity);
        auto& transformComponent = EntityManager::getComponent<TransformComponent>(entity);

        for (auto& drawable : drawableComponent.getDrawables())
        {
            drawable.second->bind();
        }

        glm::mat4 model = glm::translate(glm::mat4(1.0f), transformComponent.getPosition());
        glm::mat4 mvp = proj * view * model;
        m_program->setUniformMat4f("u_mvp", mvp);
        m_program->setUniformVec4f("u_color", drawableComponent.getColor());
        glActiveTexture(GL_TEXTURE0);

        glm::vec3 position = transformComponent.getPosition();
        glm::vec3& scale = transformComponent.getScale();
        for (const char* i = textComponent.getText(); *i != '\0'; i++)
        {
            auto& c = Font::getCharacter(*i);

            float x_pos = position.x * scale.x;
            float y_pos = position.y - (c.m_size.y - c.m_bearing.y) * scale.y;

            float width = c.m_size.x * scale.x;
            float height = c.m_size.y * scale.y;

            float vertices[6][4] = {
                { x_pos, y_pos + height, 0.0f, 0.0f },
                { x_pos, y_pos, 0.0f, 1.0f },
                { x_pos + width, y_pos, 1.0f, 1.0f },
                { x_pos, y_pos + height, 0.0f, 0.0f },
                { x_pos + width, y_pos, 1.0f, 1.0f },
                { x_pos + width, y_pos + height, 1.0f, 0.0f }
            };

            glBindTexture(GL_TEXTURE_2D, c.m_texture);

            auto& vertexArray = static_cast<const VertexArray&>(drawableComponent.getDrawable(VERTEX_ARRAY));
            auto& vertexBuffer = vertexArray.getBuffer(VBO_POSITION);
            vertexBuffer.modifyBuffer(sizeof(float) * 6 * 4, vertices);

            glDrawArrays(GL_TRIANGLES, 0, 6);

            position.x += (c.m_advance >> 6) * scale.x;
        }
    }
}
