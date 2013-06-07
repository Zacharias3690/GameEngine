#include "Shader.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cassert>
#include <iostream>

Shader::Shader()
{

}

Shader::Shader(const char* filepath, GLenum shaderType) :
	_object(0),
	_refCount(NULL)
{
	_object = glCreateShader(shaderType);

	std::string shaderCode;

	readFromFile(filepath, shaderCode);

	const char* code = shaderCode.c_str();

	glShaderSource(_object,1,(const GLchar**)&code, NULL);

	glCompileShader(_object);

	GLint status;
	glGetShaderiv(_object,GL_COMPILE_STATUS, &status);
	if(status == GL_FALSE)
	{
		std::string msg("Compile failed in shader:\n");
		
		GLint infoLogLength;
		glGetShaderiv(_object, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* strInfoLog = new char[infoLogLength+1];
		glGetShaderInfoLog(_object, infoLogLength, NULL, strInfoLog);
		msg += strInfoLog;
		delete[] strInfoLog;

		glDeleteShader(_object);
		_object = 0;
		throw std::runtime_error(msg);
	}
}

Shader::Shader(const Shader& other) :
	_object(other._object)

{
	_retain();
}

GLuint Shader::object() const
{
	return _object;
}

void Shader::readFromFile(const char* filepath, std::string &str)
{
	std::ifstream file;
	file.open(filepath, std::ios::in | std::ios::binary);
	if(!file.is_open())
	{
		throw std::runtime_error(std::string("Cannot open file at " ) + filepath);
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	str = buffer.str();
}

Shader::~Shader()
{

}

void Shader::_retain()
{

}

void Shader::_release()
{
	if(_object)
	{
		glDeleteShader(_object);

	}
}

Shader& Shader::operator = (const Shader& other)
{
	_release();
	_object = other._object;
	_retain();
	return *this;
}