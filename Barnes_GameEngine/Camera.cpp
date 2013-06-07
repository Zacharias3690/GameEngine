#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"

Camera::Camera()
{
	fieldOfView = 45.0f;
	transform.position = glm::vec3(0,0,100);
	transform.rotation = glm::vec3(3.14f,0.0f,0.0f);

	transform = Transform();
}

Camera::Camera(glm::mat4 view, glm::mat4 projection)
{
	viewMatrix = view;
	projectionMatrix = projection;
	fieldOfView = 45.0f;
	transform.position = glm::vec3(0,0,100);
	transform.rotation = glm::vec3(3.14f,0.0f,0.0f);

	transform = Transform();
}

Camera::~Camera()
{

}

glm::mat4 Camera::getProjection()
{
	return projectionMatrix;
}

glm::mat4 Camera::getView()
{
	return viewMatrix;
}

void Camera::setProjection(glm::mat4 projection)
{
	projectionMatrix = projection;
}

void Camera::setView(glm::mat4 view)
{
	viewMatrix = view;
}

void Camera::update()
{
	transform.forward = glm::vec3(cos(transform.rotation.y) * sin (transform.rotation.x),
								   sin(transform.rotation.y),
								   cos(transform.rotation.y) * cos(transform.rotation.x)
								 );

	transform.right = glm::vec3(sin(transform.rotation.x - 3.14f/2.0f),
								0,
								cos(transform.rotation.x - 3.14f/2.0f));

	transform.up = glm::cross(transform.right,transform.forward);

	projectionMatrix = glm::perspective(fieldOfView, 4.0f / 3.0f, 0.1f, 100.0f);
	viewMatrix = glm::lookAt(transform.position,transform.position + transform.forward, transform.up);
}