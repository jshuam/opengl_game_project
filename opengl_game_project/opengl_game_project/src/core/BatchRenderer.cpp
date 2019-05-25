#include "glm\ext\matrix_clip_space.hpp"
#include "glm\gtx\transform.hpp"

#include "..\components\DrawableComponent.hpp"
#include "..\components\TransformComponent.hpp"
#include "..\entities\EntityManager.hpp"
#include "..\gl\drawables\IndexBuffer.hpp"
#include "..\gl\drawables\Texture.hpp"
#include "..\utility\Display.hpp"
#include "BatchRenderer.hpp"

void BatchRenderer::render()
{
	m_program->bind();

	glm::mat4 proj = glm::ortho(0.0f, (float) Display::getWidth(), 0.0f, (float) Display::getHeight());
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	passedTime += Display::getDeltaTime();

	for(const auto& batch : m_batches)
	{
		batch.first.bind();

		for(const auto& entity : batch.second)
		{
			auto& drawableComponent = EntityManager::getComponent<Drawable>(entity);
			auto& transformComponent = EntityManager::getComponent<Transform>(entity);

			for(auto& drawable : drawableComponent.getDrawables())
			{
				drawable.second->bind();
			}

			glm::mat4 model = glm::translate(glm::mat4(1.0f), transformComponent.getPosition());
			float scale = transformComponent.getScale();
			model = glm::scale(model, glm::vec3(scale, scale, scale));
			glm::mat4 mvp = proj * view * model;
			m_program->setUniformMat4f("u_mvp", mvp);

			auto& indexBuffer = static_cast<const IndexBuffer&>(drawableComponent.getDrawable(INDEX_BUFFER));

			float spriteWidth = 1.0f / 13.0f;
			float spriteHeight = 1.0f;

			if(passedTime > 0.1)
			{
				passedTime = 0;
				index++;
				if(index > 12) index = 0;
				float tex_coords[4][2] =
				{
					{(spriteWidths[index] - 1.0f) * spriteWidth, 0.0f * spriteHeight},
					{spriteWidths[index] * spriteWidth, 0.0f * spriteHeight},
					{spriteWidths[index] * spriteWidth, 1.0f * spriteHeight},
					{(spriteWidths[index] - 1.0f) * spriteWidth, 1.0f * spriteHeight}
				};

				auto& vertexArray = static_cast<const VertexArray&>(drawableComponent.getDrawable(VERTEX_ARRAY));
				auto& vertexBuffer = vertexArray.getBuffer(VBO_TEX_COORD);
				vertexBuffer.modifyBuffer(sizeof(float) * 4 * 2, tex_coords);
			}

			glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr);
		}
	}
}

void BatchRenderer::addBatch(Texture batchKey, std::vector<GUID> batch)
{
	m_batches.emplace(std::move(batchKey), std::move(batch));
}
