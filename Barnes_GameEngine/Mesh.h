#ifndef MESH_H
#define MESH_H

#include "Component.h"
#include "Material.h"
#include "Program.h"
#include "Shader.h"
#include <vector>
#include <glm/glm.hpp>
#include <assimp\mesh.h>
#include <assimp\vector3.h>

class Mesh : public Component
{
public:
	Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs);
	Mesh(aiMesh*);
	~Mesh();
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	bool hasVertices;
	bool hasNormals;
	bool hasUvs;

	Material* material;

private:

	void Load();
	void Update();

	GLenum drawType;
	GLuint vao;
	GLuint vertexBuffer;
	GLuint uvBuffer;
	GLuint normalBuffer;

	bool loaded;
};

#endif