#include <glm/glm.hpp>
#include <gl/glew.h>
#include <vector>
#include <iostream>

#include "Object.h"

using namespace std;

Object::Object(Program *shaders, std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs)
{
	Object::vertices = vertices;
	Object::normals = normals;
	Object::uvs = uvs;

	Object::shaders = shaders;

	drawType = GL_TRIANGLES;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &uvBuffer);
	glGenBuffers(1, &normalBuffer);
}

Object::Object(Program *shaders, const char* file_path)
{
	Object::shaders = shaders;

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;

	FILE *file = fopen(file_path, "r");
	if(file == NULL)
	{
		printf("Impossible to open the file!\n");
	}
	while(1)
	{
		char lineHeader[128];
		//read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if(res == EOF)
			break;

		if(strcmp(lineHeader, "v") == 0)
		{
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if(strcmp(lineHeader, "vt") == 0)
		{
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			uv.y = -uv.y;
			temp_uvs.push_back(uv);
		}
		else if(strcmp(lineHeader, "vn") == 0)
		{
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if(strcmp(lineHeader, "f") == 0)
		{
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", 
				&vertexIndex[0], &uvIndex[0], &normalIndex[0], 
				&vertexIndex[1], &uvIndex[1], &normalIndex[1], 
				&vertexIndex[2], &uvIndex[2], &normalIndex[2]
			);

			if(matches != 9)
			{
				printf("File can't be read by simple parser\n");
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices	 .push_back(uvIndex[0]);
			uvIndices	 .push_back(uvIndex[1]);
			uvIndices	 .push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}

	for(unsigned int i =0; i < vertexIndices.size(); i++)
	{
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];

		glm::vec3 vertex = temp_vertices[vertexIndex-1];
		glm::vec2 uv = temp_uvs[uvIndex-1];
		glm::vec3 normal = temp_normals[normalIndex-1];

		vertices.push_back(vertex);
		uvs.push_back(uv);
		normals.push_back(normal);
	}

	Object::shaders = shaders;

	drawType = GL_TRIANGLES;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &uvBuffer);
	glGenBuffers(1, &normalBuffer);
}

Object::~Object()
{
	//clean up
}

void Object::Load()
{
	//set important data
	glBindVertexArray(vao);
	
	//set vertices
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(shaders->attrib("vert"));
	glVertexAttribPointer(shaders->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

	//set UVs
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(shaders->attrib("uv"));
	glVertexAttribPointer(shaders->attrib("uv"), 2, GL_FLOAT, GL_TRUE, 0,NULL);

	//set Normals
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(shaders->attrib("norm"));
	glVertexAttribPointer(shaders->attrib("norm"),3, GL_FLOAT, GL_TRUE, 0, NULL);
	
	//unbind vertex array object
	glBindVertexArray(0);
}

void Object::Draw(glm::mat4 camera)
{
	shaders->Use();
	shaders->setUniform("model" , glm::mat4(1.0));
	//set texture here

	glBindVertexArray(vao);

	glDrawArrays(drawType, 0, vertices.size());

	glBindVertexArray(0);
	shaders->stopUsing();
}

std::vector<glm::vec3> Object::getVertices()
{
	return vertices;
}

std::vector<glm::vec3> Object::getNormals()
{
	return normals;
}

std::vector<glm::vec2> Object::getUVs()
{
	return uvs;
}

void Object::setVertices(std::vector<glm::vec3> vertices)
{
	Object::vertices = vertices;
}

void Object::setNormals(std::vector<glm::vec3> normals)
{
	Object::normals = normals;
}

void Object::setUVs(std::vector<glm::vec2> uvs)
{
	Object::uvs = uvs;
}