
#include "Transform.h"

Transform::Transform() : Component("Transform")
{
	position = glm::vec3(0,0,0);
	rotation = glm::vec3(0,0,0);
	scale = glm::vec3(0,0,0);
}

Transform::Transform(glm::vec3 position) : Component("Transform")
{
	this->position = position;
	rotation = glm::vec3(0,0,0);
	scale = glm::vec3(0,0,0);
}

Transform::~Transform()
{

}

void Transform::Start()
{

}

void Transform::Update()
{

}
