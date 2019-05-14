#include <cassert>
#include <iostream>

#include "Program.hpp"

Program::Program()
{
	m_glObjectId = glCreateProgram();
}

Program::~Program()
{
	glDeleteProgram(m_glObjectId);
}

void Program::bind() const
{
	glUseProgram(m_glObjectId);
}

void Program::unbind() const
{
	glUseProgram(0);
}

void Program::attachShader(Shader shader)
{
	shader.attach(m_glObjectId);
	m_shaders.push_back(shader);
}

void Program::compile() const
{
	glLinkProgram(m_glObjectId);
	checkCompileStatus(GL_LINK_STATUS);

	glValidateProgram(m_glObjectId);
	checkCompileStatus(GL_VALIDATE_STATUS);

	/* Detaches and deletes the shaders as they are no longer needed due to being compiled into the program */
	for(const auto& shader : m_shaders)
	{
		shader.detach(m_glObjectId);
	}
}

void Program::setUniform1i(const std::string& name, int v0)
{
	glUniform1i(getUniformLocation(name), v0);
}

void Program::setUniform3f(const std::string& name, float v0, float v1, float v2)
{
	glUniform3f(getUniformLocation(name), v0, v1, v2);
}

void Program::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

void Program::setUniformMat4f(const std::string& name, glm::mat4& matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

void Program::checkCompileStatus(unsigned int param) const
{
	int status;
	glGetProgramiv(m_glObjectId, param, &status);
	if(status == GL_FALSE)
	{
		int length;
		glGetProgramiv(m_glObjectId, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetProgramInfoLog(m_glObjectId, length, &length, message);
		std::cout << "[ERROR] Program compilation failed:" << std::endl;
		std::cout << message << std::endl;
		std::cin.get();
		exit(-1);
	}
}

int Program::getUniformLocation(const std::string& name)
{
	if(m_uniformLocCache.find(name) != m_uniformLocCache.end()) return m_uniformLocCache[name];

	int loc = glGetUniformLocation(m_glObjectId, name.c_str());
	if(loc < 0) std::cout << "[WARNING] Uniform not in use" << std::endl;
	m_uniformLocCache[name] = loc;
	return loc;
}
