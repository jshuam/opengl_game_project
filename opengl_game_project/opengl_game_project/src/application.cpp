#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <iostream>
#include <fstream>

#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "program.h"
#include "shader.h"

static void APIENTRY glCheckErrors( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *user_param )
{
	const char* _source, *_type, *_severity;

	switch( source )
	{
		case GL_DEBUG_SOURCE_API:
			_source = "API";
			break;

		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
			_source = "WINDOW SYSTEM";
			break;

		case GL_DEBUG_SOURCE_SHADER_COMPILER:
			_source = "SHADER COMPILER";
			break;

		case GL_DEBUG_SOURCE_THIRD_PARTY:
			_source = "THIRD PARTY";
			break;

		case GL_DEBUG_SOURCE_APPLICATION:
			_source = "APPLICATION";
			break;

		case GL_DEBUG_SOURCE_OTHER:
			_source = "UNKNOWN";
			break;

		default:
			_source = "UNKNOWN";
			break;
	}

	switch( type )
	{
		case GL_DEBUG_TYPE_ERROR:
			_type = "ERROR";
			break;

		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
			_type = "DEPRECATED BEHAVIOR";
			break;

		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
			_type = "UDEFINED BEHAVIOR";
			break;

		case GL_DEBUG_TYPE_PORTABILITY:
			_type = "PORTABILITY";
			break;

		case GL_DEBUG_TYPE_PERFORMANCE:
			_type = "PERFORMANCE";
			break;

		case GL_DEBUG_TYPE_OTHER:
			_type = "OTHER";
			break;

		case GL_DEBUG_TYPE_MARKER:
			_type = "MARKER";
			break;

		default:
			_type = "UNKNOWN";
			break;
	}

	switch( severity )
	{
		case GL_DEBUG_SEVERITY_HIGH:
			_severity = "HIGH";
			break;

		case GL_DEBUG_SEVERITY_MEDIUM:
			_severity = "MEDIUM";
			break;

		case GL_DEBUG_SEVERITY_LOW:
			_severity = "LOW";
			break;

		case GL_DEBUG_SEVERITY_NOTIFICATION:
			_severity = "NOTIFICATION";
			break;

		default:
			_severity = "UNKNOWN";
			break;
	}

	/* If the severity is higher than notification, then print the message and break execution */
	if( severity > GL_DEBUG_SEVERITY_NOTIFICATION )
	{
		printf( "[ERROR %d] %s of %s severity, raised from %s: \n%s\n", id, _type, _severity, _source, message );
		__debugbreak();
	}
}

int main( void )
{
	GLFWwindow* window;

	/* Initialize the library */
	if( !glfwInit() )
		return -1;

	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 4 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow( 640, 480, "Hello World", NULL, NULL );
	if( !window )
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent( window );
	glfwSwapInterval( 1 );

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

	float positions[] =
	{
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f,
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	vertex_array va;
	vertex_buffer vb( positions, sizeof( float ) * 8 );
	vertex_buffer_layout vbl;
	vbl.push<float>( 2 );
	va.add_buffer( vb, vbl );

	index_buffer ib( indices, 6 );

	const std::string vertex_filename = "res/shaders/vertex.glsl";
	const std::string fragment_filename = "res/shaders/fragment.glsl";

	program program;
	shader vertex_shader( GL_VERTEX_SHADER, vertex_filename );
	shader fragment_shader( GL_FRAGMENT_SHADER, fragment_filename );
	
	program.attach_shader( vertex_shader );
	program.attach_shader( fragment_shader );
	program.compile();

	ib.unbind();
	vb.unbind();
	va.unbind();

	float r = 0.0f;
	float increment = 0.005f;

	renderer renderer;
	/* Loop until the user closes the window */
	while( !glfwWindowShouldClose( window ) )
	{
		/* Render here */
		renderer.clear();

		program.bind();
		program.set_uniform_4f( "u_color", r, 0.3, 0.8, 1.0 );

		va.bind();
		ib.bind();

		renderer.draw();

		if( r > 1.0f || r < 0.0f ) increment = -increment;
		r += increment;

		ib.unbind();
		va.unbind();
		program.unbind();

		/* Swap front and back buffers */
		glfwSwapBuffers( window );

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}