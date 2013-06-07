#ifndef OBJECT_H
#define OBJECT_H

#include "Program.h"

class Object
{
public:
	Object(Program*,std::vector<glm::vec3>,std::vector<glm::vec3>,std::vector<glm::vec2>);
	Object::Object(Program*, const char* file_path);
	~Object();
	void Draw(glm::mat4);
	void Load();
	std::vector<glm::vec3> getVertices();
	std::vector<glm::vec3> getNormals();
	std::vector<glm::vec2> getUVs();

	void setVertices(std::vector<glm::vec3>);
	void setNormals(std::vector<glm::vec3>);
	void setUVs(std::vector<glm::vec2>);

	Program* shaders;

	//Transform transform;
private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	GLuint vao;
	GLuint vertexBuffer;
	GLuint uvBuffer;
	GLuint normalBuffer;
	GLenum drawType;
	//texture
};

#endif