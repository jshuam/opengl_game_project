#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtx/transform.hpp"

#include "../components/Drawable.hpp"
#include "../components/Text.hpp"
#include "../components/Transform.hpp"
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

	glm::mat4 proj = glm::ortho(0.0f, (float) Display::getWidth(), 0.0f, (float) Display::getHeight());
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	for(const auto& entity : m_entities)
	{
		auto& drawableComponent = EntityManager::getComponent<Drawable>(entity);
		auto& textComponent = EntityManager::getComponent<Text>(entity);
		auto& transformComponent = EntityManager::getComponent<Transform>(entity);

		for(auto& drawable : drawableComponent.getDrawables())
		{
			drawable->bind();
		}

		glm::mat4 model = glm::translate(glm::mat4(1.0f), transformComponent.getPosition());
		glm::mat4 mvp = proj * view * model;
		m_program->setUniformMat4f("u_mvp", mvp);
		m_program->setUniformVec4f("u_color", drawableComponent.getColor());
		glActiveTexture(GL_TEXTURE0);

		glm::vec3 position = transformComponent.getPosition();
		float scale = transformComponent.getScale();
		for(const char* i = textComponent.getText(); *i != '\0'; i++)
		{
			auto& c = Font::getCharacter(*i);

			float x_pos = position.x * scale;
			float y_pos = position.y - (c.m_size.y - c.m_bearing.y) * scale;

			float width = c.m_size.x * scale;
			float height = c.m_size.y * scale;

			float vertices[6][4] =
			{
				{ x_pos, y_pos + height, 0.0f, 0.0f },
				{ x_pos, y_pos, 0.0f, 1.0f },
				{ x_pos + width, y_pos, 1.0f, 1.0f },
				{ x_pos, y_pos + height, 0.0f, 0.0f },
				{ x_pos + width, y_pos, 1.0f, 1.0f },
				{ x_pos + width, y_pos + height, 1.0f, 0.0f }
			};

			glBindTexture(GL_TEXTURE_2D, c.m_texture);

			auto& vertexArray = static_cast<VertexArray&>(*drawableComponent.getDrawables()[0]);
			auto& vertexBuffer = vertexArray.getVertexBuffers()[0];
			vertexBuffer.modifyBuffer(sizeof(float) * 6 * 4, vertices);

			glDrawArrays(GL_TRIANGLES, 0, 6);

			position.x += (c.m_advance >> 6) * scale;
		}
	}
}
