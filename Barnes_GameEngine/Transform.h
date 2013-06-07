#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include "Component.h"

class Transform : public Component
{
public:

	Transform();
	Transform(glm::vec3);
	~Transform();

	void Update();
	void Start();

	glm::vec3 position;		//position in x,y,z format
	glm::vec3 rotation;		//rotate in x,y,z format
	glm::vec3 scale;		//scale in x,y,z format

	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 forward;
private:
};

#endif