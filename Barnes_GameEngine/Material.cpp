#include "LoadTexture.h"
#include "Material.h"

Material::Material() : Component("Material")
{
	Shader vertShader = Shader("shader.vert", GL_VERTEX_SHADER);
	Shader fragShader = Shader("shader.frag", GL_FRAGMENT_SHADER);

	std::vector<Shader> temp;
	temp.push_back(vertShader);
	temp.push_back(fragShader);
	shaders = new Program(temp);
	reload = false;
}

Material::Material(Shader vertShader, Shader fragShader) : Component("Material")
{
	std::vector<Shader> temp;
	temp.push_back(vertShader);
	temp.push_back(fragShader);
	shaders = new Program(temp);
	reload = false;
}

Material::Material(aiMaterial* material) : Component("Material")
{

	Shader vertShader = Shader("shader.vert", GL_VERTEX_SHADER);
	Shader fragShader = Shader("shader.frag", GL_FRAGMENT_SHADER);

	std::vector<Shader> temp;
	temp.push_back(vertShader);
	temp.push_back(fragShader);
	shaders = new Program(temp);
	reload = false;
}

Material::~Material()
{
}

void Material::Update()
{

}

void Material::SetShaders(Shader vertShader, Shader fragShader)
{
	delete shaders;
	std::vector<Shader> temp;
	temp.push_back(vertShader);
	temp.push_back(fragShader);
	shaders = new Program(temp);
	reload = true;
}
