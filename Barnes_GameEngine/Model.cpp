#include <assimp\color4.h>
#include <assimp\postprocess.h>
#include <assimp\Importer.hpp>
#include <iostream>

#include "LoadTexture.h"
#include "Model.h"
#include "LoadMesh.h"

Model::Model(std::string file_location) : Component("Model")
{

	defaultTex = Load2DTexture("C:/Users/Zach/Desktop/texture_watchtower.png");

	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(file_location, aiProcessPreset_TargetRealtime_MaxQuality);
	if(scene == NULL)
	{
		std::cout << importer.GetErrorString() << std::endl;
		system("pause");
		exit(-1);
	}
	for(unsigned int i = 0; i < scene->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[i];
		meshes.push_back(Mesh());
		meshes[i].matIndex = mesh->mMaterialIndex;
		for(int j = 0; j < mesh->mNumFaces; j++)
		{
			aiFace face = scene->mMeshes[i]->mFaces[j];

			for(int k = 0; k < 3; k++)
			{
				if(mesh->HasTextureCoords(0))
				{
					aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[k]];
					meshes[i].uvs.push_back(glm::vec2(uv.x, uv.y));
					meshes[i].hasUvs = true;
				}
				else
				{
					meshes[i].hasUvs = false;
				}

				aiVector3D normal = mesh->mNormals[face.mIndices[k]];
				meshes[i].normals.push_back(glm::vec3(normal.x, normal.y, normal.z));

				aiVector3D vertices = mesh->mVertices[face.mIndices[k]];
				meshes[i].vertices.push_back(glm::vec3(vertices.x, vertices.y, vertices.z));
			}
		}
	}
	for(unsigned int i = 0; i < scene->mNumMaterials; i++)
	{
		aiMaterial* mat = scene->mMaterials[i];
		if(mat->GetTextureCount(aiTextureType_DIFFUSE) > 0)
		{
			aiString path;
			if(mat->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS)
			{
				std::string fullPath = "C:/Users/Zach/Desktop/";
				fullPath += path.data;
				std::cout << fullPath << std::endl;
				GLuint tex = Load2DTexture(fullPath);
				if(tex != 0)
					textures.push_back(tex);
			}
		}
	}

	importer.FreeScene();
	

	Shader vertShader = Shader("shader.vert", GL_VERTEX_SHADER);
	Shader fragShader = Shader("shader.frag", GL_FRAGMENT_SHADER);
	std::vector<Shader> shaders;
	shaders.push_back(vertShader);
	shaders.push_back(fragShader);
	program = new Program(shaders);
}

Model::~Model()
{
}

void Model::Update()
{
	program->Use();
	program->setUniform("model", glm::mat4(1.0f));
	program->setUniform("sampler", 0);
	for(size_t i = 0; i < meshes.size(); i++)
	{
		if(!meshes[i].isLoaded)
			Load(meshes[i]);
		glBindVertexArray(meshes[i].vao);

		unsigned int matIndex = meshes[i].matIndex;

		if(matIndex < textures.size() && textures[matIndex])
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, textures[0]);
		}
		else
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, defaultTex);
		}

		glDrawArrays(meshes[i].drawType, 0, meshes[i].vertices.size());
	}
	glBindVertexArray(0);
}

void Model::Load(Mesh mesh)
{
	//set important data
	glBindVertexArray(mesh.vao);
	
	//set vertices
	glBindBuffer(GL_ARRAY_BUFFER,mesh.vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(glm::vec3), &mesh.vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(program->attrib("vert"));
	glVertexAttribPointer(program->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

	//set UVs
	if(mesh.hasUvs)
	{
		glBindBuffer(GL_ARRAY_BUFFER, mesh.uvBuffer);
		glBufferData(GL_ARRAY_BUFFER, mesh.uvs.size() * sizeof(glm::vec2), &mesh.uvs[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(program->attrib("uv"));
		glVertexAttribPointer(program->attrib("uv"), 2, GL_FLOAT, GL_TRUE, 0,NULL);
	}
	//set Normals
	glBindBuffer(GL_ARRAY_BUFFER, mesh.normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.normals.size() * sizeof(glm::vec3), &mesh.normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(program->attrib("norm"));
	glVertexAttribPointer(program->attrib("norm"),3, GL_FLOAT, GL_TRUE, 0, NULL);
	
	//unbind vertex array object
	glBindVertexArray(0);

	mesh.isLoaded = true;
}