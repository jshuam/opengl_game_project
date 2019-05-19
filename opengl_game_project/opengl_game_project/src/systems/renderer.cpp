#include "glm\ext\matrix_clip_space.hpp"
#include "glm\gtx\Transform.hpp"

#include "..\components\Drawable.hpp"
#include "..\components\Transform.hpp"
#include "..\entities\EntityManager.hpp"
#include "..\gl\drawables\texture.hpp"
#include "..\utility\Display.hpp"
#include "Renderer.hpp"

void Renderer::update() const
{
	m_program->bind();

	Texture texture("res/textures/logo.png");
	texture.bind();

	m_program->setUniform1i("u_tex", 0);

	glm::mat4 proj = glm::ortho(0.0f, (float) Display::getWidth(), 0.0f, (float) Display::getHeight());
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	for(const auto& entity : m_entities)
	{
		auto& drawableComponent = EntityManager::getComponent<Drawable>(entity);
		auto& transformComponent = EntityManager::getComponent<Transform>(entity);

		for(auto& drawable : drawableComponent.getDrawables())
		{
			drawable->bind();
		}
		glm::mat4 model = glm::translate(glm::mat4(1.0f), transformComponent.getPosition());
		glm::mat4 mvp = proj * view * model;
		m_program->setUniformMat4f("u_mvp", mvp);
		m_program->setUniformVec4f("u_color", drawableComponent.getColor());

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}

void Renderer::addProgram(std::unique_ptr<Program> program)
{
	this->m_program = std::move(program);
}
