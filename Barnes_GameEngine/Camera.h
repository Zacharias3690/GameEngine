#ifndef CAMERA_H
#define CAMERA_H

#include "Transform.h"

class Camera
{
public:
	Camera(glm::mat4,glm::mat4);
	Camera();
	~Camera();
	glm::mat4 getView();
	glm::mat4 getProjection();
		
	void setView(glm::mat4);
	void setProjection(glm::mat4);
	void update();

	Transform transform;
	float fieldOfView;
private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

};

#endif