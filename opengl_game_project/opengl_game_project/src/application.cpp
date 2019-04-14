#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <iostream>
#include <fstream>

#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"

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
		std::cin.get();
		exit( -1 );
	}
}

static std::string load_shader( const char* file_name )
{
	std::ifstream shader_file( file_name );

	if( !shader_file.good() )
	{
		std::cout << "[ERROR] Could not find shader: " << file_name << std::endl;
		std::cin.get();
		exit( -1 );
	}

	shader_file.seekg( 0, std::ios::end );
	size_t size = shader_file.tellg();
	std::string shader_src( size, ' ' );
	shader_file.seekg( 0 );
	shader_file.read( &shader_src[0], size );

	return shader_src;
}

static unsigned int compile_shader( unsigned int type, const std::string& source )
{
	unsigned int id = glCreateShader( type );
	const char* src = source.c_str();
	glShaderSource( id, 1, &src, nullptr );
	glCompileShader( id );

	int result;
	glGetShaderiv( id, GL_COMPILE_STATUS, &result );
	if( result == GL_FALSE )
	{
		int length;
		glGetShaderiv( id, GL_INFO_LOG_LENGTH, &length );
		char* message = new char[length];
		glGetShaderInfoLog( id, length, &length, message );
		const char* shader_type = type == GL_VERTEX_SHADER ? "vertex" : "fragment";
		std::cout << "[ERROR] Failed to compile " << shader_type << " shader:" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader( id );
		delete[] message;
		return 0;
	}

	return id;
}

static unsigned int create_program( const std::string& vertex_shader, const std::string& fragment_shader )
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compile_shader( GL_VERTEX_SHADER, vertex_shader );
	unsigned int fs = compile_shader( GL_FRAGMENT_SHADER, fragment_shader );

	glAttachShader( program, vs );
	glAttachShader( program, fs );
	glLinkProgram( program );
	glValidateProgram( program );

	/* Delete the shaders as they are now compiled into the program and are no longer needed */
	glDetachShader( program, vs );
	glDetachShader( program, fs );
	glDeleteShader( vs );
	glDeleteShader( fs );

	return program;
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

	std::string vertex_shader = load_shader( "res/shaders/vertex.glsl" );
	std::string fragment_shader = load_shader( "res/shaders/fragment.glsl" );

	unsigned int program = create_program( vertex_shader, fragment_shader );
	glUseProgram( program );

	int location = glGetUniformLocation( program, "u_color" );
	assert( location > -1 );
	glUniform4f( location, 0.2f, 0.3f, 0.8f, 1.0f );

	glUseProgram( 0 );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );

	float r = 0.0f;
	float increment = 0.005f;
	/* Loop until the user closes the window */
	while( !glfwWindowShouldClose( window ) )
	{
		/* Render here */
		glClear( GL_COLOR_BUFFER_BIT );

		glUseProgram( program );
		glUniform4f( location, r, 0.3f, 0.8f, 1.0f );

		va.bind();
		ib.bind();

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );

		if( r > 1.0f || r < 0.0f ) increment = -increment;
		r += increment;

		/* Swap front and back buffers */
		glfwSwapBuffers( window );

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram( program );

	glfwTerminate();
	return 0;
}