#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "display.h"
#include "mouse.h"
#include "scenes/test_scene.h"
#include "scenes/scene_manager.h"
#include "utils.h"

int main( void )
{
	Display display;
	Mouse mouse( display );
	GLenum err = glewInit();
	if( GLEW_OK != err )
	{
		fprintf( stderr, "Error: %s\n", glewGetErrorString( err ) );
		std::cin.get();
	}

	/* Setup callback functions */
	#if DEBUG
	if( glDebugMessageCallback != NULL )
	{
		glEnable( GL_DEBUG_OUTPUT );
		glDebugMessageCallback( glCheckErrors, nullptr );
	}
	#endif

	TestScene test_scene;

	SceneManager::add_scene( &test_scene );
	SceneManager::set_active_scene( 0 );

	while( !display.should_close() )
	{
		display.clear();

		SceneManager::render_scene();

		display.update();
	}

	return 0;
}