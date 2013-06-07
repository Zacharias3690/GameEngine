#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/vector3.h>
#include <string>
#include <gl/glew.h>
#include <vector>
#include <iostream>
#include "Mesh.h"
#include "LoadMesh.h"

const aiScene* LoadModel(std::string file_location)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(file_location, aiProcessPreset_TargetRealtime_MaxQuality | aiProcess_Triangulate);

	if(scene)
		return scene;
	else
		return 0;
}