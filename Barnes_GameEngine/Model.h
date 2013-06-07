#include <assimp\scene.h>
#include <gl/glew.h>
#include <vector>
#include <assimp\scene.h>
#include "Program.h"
#include "Shader.h"
#include "Component.h"

struct Texture
{
	GLuint id;
	GLuint width;
	GLuint height;
	GLenum target;
};

struct Mesh
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	std::vector<GLuint> textures;

	GLuint vao;
	GLuint vertexBuffer;
	GLuint normalBuffer;
	GLuint uvBuffer;
	GLenum drawType;

	unsigned int matIndex;

	bool isLoaded;
	bool hasUvs;

	Mesh()
	{
		isLoaded = false;
		drawType = GL_TRIANGLES;
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vertexBuffer);
		glGenBuffers(1, &normalBuffer);
		glGenBuffers(1, &uvBuffer);
	}
};

class Model : Component
{
public:

	Model(std::string);
	~Model();

	void Load(Mesh);
	void Update();

	std::vector<Mesh> meshes;
	std::vector<GLuint> textures;
	GLuint defaultTex;

	Program* program;
private:
};