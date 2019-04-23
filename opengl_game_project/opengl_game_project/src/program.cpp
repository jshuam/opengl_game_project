#include "Program.h"
#include "Renderer.h"

#include <cassert>
#include <iostream>

Program::Program()
{
	renderer_id = glCreateProgram();
}

Program::~Program()
{
	glDeleteProgram( renderer_id );
}

void Program::bind() const
{
	glUseProgram( renderer_id );
}

void Program::unbind() const
{
	glUseProgram( 0 );
}

void Program::add_entity( Entity entity )
{
	entities.emplace_back( entity );
}

void Program::attach_shader( Shader shader )
{
	shader.attach( renderer_id );
	shaders.push_back( shader );
}

void Program::compile() const
{
	glLinkProgram( renderer_id );
	check_compile_status( GL_LINK_STATUS );

	glValidateProgram( renderer_id );
	check_compile_status( GL_VALIDATE_STATUS );

	/* Detaches and deletes the shaders as they are no longer needed due to being compiled into the program */
	for( const auto& shader : shaders )
	{
		shader.detach( renderer_id );
	}
}

void Program::set_uniform_1i( const std::string& name, int v0 )
{
	glUniform1i( get_uniform_location( name ), v0 );
}

void Program::set_uniform_3f( const std::string& name, float v0, float v1, float v2 )
{
	glUniform3f( get_uniform_location( name ), v0, v1, v2 );
}

void Program::set_uniform_4f( const std::string& name, float v0, float v1, float v2, float v3 )
{
	glUniform4f( get_uniform_location( name ), v0, v1, v2, v3 );
}

void Program::set_uniform_mat4f( const std::string& name, glm::mat4& matrix )
{
	glUniformMatrix4fv( get_uniform_location( name ), 1, GL_FALSE, &matrix[0][0] );
}

void Program::check_compile_status( unsigned int param ) const
{
	int status;
	glGetProgramiv( renderer_id, param, &status );
	if( status == GL_FALSE )
	{
		int length;
		glGetProgramiv( renderer_id, GL_INFO_LOG_LENGTH, &length );
		char* message = new char[length];
		glGetProgramInfoLog( renderer_id, length, &length, message );
		std::cout << "[ERROR] Program compilation failed:" << std::endl;
		std::cout << message << std::endl;
		std::cin.get();
		exit( -1 );
	}
}

int Program::get_uniform_location( const std::string& name )
{
	if( uniform_loc_cache.find( name ) != uniform_loc_cache.end() ) return uniform_loc_cache[name];

	int loc = glGetUniformLocation( renderer_id, name.c_str() );
	if( loc < 0 ) std::cout << "[WARNING] Uniform not in use" << std::endl;
	uniform_loc_cache[name] = loc;
	return loc;
}
