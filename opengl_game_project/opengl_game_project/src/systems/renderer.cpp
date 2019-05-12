#include "renderer.hpp"
#include "..\components\Drawable.hpp"
#include "..\entities\entity_manager.hpp"
#include "..\entities\entity_manager.hpp"
#include "glm\ext\matrix_clip_space.hpp"
#include "..\display.hpp"
#include "glm\gtx\Transform.hpp"
#include "..\components\Transform.hpp"

void Renderer::update() const
{
	for( const auto& entity : entities )
	{
		auto& drawable_component = EntityManager::get_component<Drawable>( entity );
		auto& transform_component = EntityManager::get_component<Transform>( entity );

		for( auto& drawable : drawable_component.get_drawables() )
		{
			drawable->bind();
		}

		program->bind();

		glm::mat4 proj = glm::ortho( 0.0f, (float) Display::get_width(), 0.0f, (float) Display::get_height() );
		glm::mat4 view = glm::translate( glm::mat4( 1.0f ), glm::vec3( 0, 0, 0 ) );
		glm::mat4 model = glm::translate( glm::mat4( 1.0f ), transform_component.get_position() );
		glm::mat4 mvp = proj * view * model;
		program->set_uniform_mat4f( "u_mvp", mvp );

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
	}
}

void Renderer::add_program( std::unique_ptr<Program> program )
{
	this->program = std::move( program );
}
