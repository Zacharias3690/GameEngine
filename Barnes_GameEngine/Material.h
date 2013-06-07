#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>

#include "Shader.h"
#include "Component.h"
#include <assimp\material.h>

class Material : public Component
{
public:
	Material();
	Material(Shader vertShader, Shader fragShader);
	Material(aiMaterial* material);
	~Material();

	void Update();
	void SetTexture(GLuint texture);
	void SetShaders(Shader, Shader);

	Program* shaders;

	bool reload;
private:
};

#endif