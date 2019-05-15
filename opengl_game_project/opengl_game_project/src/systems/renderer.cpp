#include "..\components\Drawable.hpp"
#include "..\components\Transform.hpp"
#include "..\Display.hpp"
#include "..\entities\EntityManager.hpp"

#include "glm\ext\matrix_clip_space.hpp"
#include "glm\gtx\Transform.hpp"

#include "Renderer.hpp"

void Renderer::update() const
{
	for(const auto& entity : m_entities)
	{
		auto& drawableComponent = EntityManager::getComponent<Drawable>(entity);
		auto& transformComponent = EntityManager::getComponent<Transform>(entity);

		for(auto& drawable : drawableComponent.getDrawables())
		{
			drawable->bind();
		}

		m_program->bind();

		glm::mat4 proj = glm::ortho(0.0f, (float) Display::getWidth(), 0.0f, (float) Display::getHeight());
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), transformComponent.getPosition());
		glm::mat4 mvp = proj * view * model;
		m_program->setUniformMat4f("u_mvp", mvp);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}

void Renderer::addProgram(std::unique_ptr<Program> program)
{
	this->m_program = std::move(program);
}
