#include "shader.h"
#include "renderer.h"

#include <iostream>
#include <fstream>

Shader::Shader( unsigned int type, const std::string& filename )
{
	const std::string& shader_src = load_source( filename );
	renderer_id = compile_source( type, shader_src );
}

void Shader::attach( unsigned int program ) const
{
	glAttachShader( program, renderer_id );
}

void Shader::detach( unsigned int program ) const
{
	glDetachShader( program, renderer_id );
	glDeleteShader( renderer_id );
}

const std::string Shader::load_source( const std::string& filename )
{
	std::ifstream shader_file( filename.c_str() );

	if( !shader_file.good() )
	{
		std::cout << "[ERROR] Could not find shader: " << filename << std::endl;
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

unsigned int Shader::compile_source( unsigned int type, const std::string& shader_src )
{
	unsigned int id = glCreateShader( type );
	const char* src = shader_src.c_str();
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
		delete[] message;
		std::cin.get();
		exit( -1 );
	}

	return id;
}