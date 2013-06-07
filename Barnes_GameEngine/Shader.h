#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <gl/glew.h>

class Shader
{
public:
	Shader();
	Shader(const char*, GLenum);
	Shader(const Shader&);
	~Shader();
	GLuint object() const;
	Shader& operator =(const Shader& other);

private:
	void readFromFile(const char* filepath, std::string&);
	GLuint _object;
	unsigned* _refCount;

	void _retain();
	void _release();
};

#endif