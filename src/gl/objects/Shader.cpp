#include <fstream>
#include <iostream>

#include "Shader.hpp"

Shader::Shader(unsigned int type, const std::string& filename)
{
    const std::string& shaderSrc = loadSource(filename);
    m_glObjectId = compileSource(type, shaderSrc);
}

void Shader::attach(unsigned int program) const
{
    glAttachShader(program, m_glObjectId);
}

void Shader::detach(unsigned int program) const
{
    glDetachShader(program, m_glObjectId);
    glDeleteShader(m_glObjectId);
}

const std::string Shader::loadSource(const std::string& filename)
{
    std::ifstream shaderFile(filename.c_str());

    if (!shaderFile.good())
    {
        std::cout << "[ERROR] Could not find shader: " << filename << std::endl;
        std::cin.get();
        exit(-1);
    }

    shaderFile.seekg(0, std::ios::end);
    std::streamoff size = shaderFile.tellg();
    std::string shaderSrc((unsigned int)size, ' ');
    shaderFile.seekg(0);
    shaderFile.read(&shaderSrc[0], size);

    return shaderSrc;
}

unsigned int Shader::compileSource(unsigned int type, const std::string& shaderSrc)
{
    unsigned int glObjectId = glCreateShader(type);
    const char* src = shaderSrc.c_str();
    glShaderSource(glObjectId, 1, &src, nullptr);
    glCompileShader(glObjectId);

    int result;
    glGetShaderiv(glObjectId, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(glObjectId, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];
        glGetShaderInfoLog(glObjectId, length, &length, message);
        const char* shaderType = type == GL_VERTEX_SHADER ? "vertex" : "fragment";
        std::cout << "[ERROR] Failed to compile " << shaderType << " shader:" << std::endl;
        std::cout << message << std::endl;
        delete[] message;
        std::cin.get();
        exit(-1);
    }

    return glObjectId;
}
