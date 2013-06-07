#include <stdio.h>
#include <stdlib.h>
#include <gl/glew.h>
#include <gl/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <vector>

#include "Shader.h"
#include "Program.h"
#include "Input.h"
#include "Camera.h"
#include "System.h"
#include "Model.h"

#include "LoadMesh.h"
#include "LoadTexture.h"


using namespace std;

/* 
	A thank you to Tom Dalling for his openGL series that I'm building
	off of. You can find his source code at https://github.com/tomdalling/opengl-series
*/


//global
Input* input = NULL;
Program* program = NULL;
Camera* camera = NULL;
System* sys = NULL;
GLuint VBO = 0;
GLuint VAO = 0;
std::vector<Model> models;
bool flag = true;

static void Render()
{
	
}

static void Update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float speed = 20.0f;
	float mouseSpeed = 0.05f;
	sys->Update();
	input->Update();
	
	if(input->KeyDown("W"))
	{
		camera->transform.position += camera->transform.forward * System::deltaTime * speed;
	}
	
	if(input->KeyDown("a"))
	{
		camera->transform.position -= camera->transform.right * System::deltaTime * speed;
	}
	if(input->KeyDown("s"))
	{
		camera->transform.position -= camera->transform.forward * System::deltaTime * speed;
	}
	if(input->KeyDown("d"))
	{
		camera->transform.position += camera->transform.right * System::deltaTime * speed;
	}
	

	glm::vec2 mousePos = input->GetMousePos();
	glfwSetMousePos(System::screenWidth/2, System::screenHeight/2);
	camera->transform.rotation.x += mouseSpeed * System::deltaTime * float(System::screenWidth/2 - (int)mousePos.x);
	camera->transform.rotation.y += mouseSpeed * System::deltaTime * float(System::screenHeight/2 - (int)mousePos.y);
	
	camera->update();
	program = models[0].program;
	program->Use();
	program->setUniform("view",camera->getView());
	program->setUniform("projection", camera->getProjection());
	models[0].Update();
	program->stopUsing();

	glfwSwapBuffers();
	
}

void AppMain()
{
	if(!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return;
	}

	//initalize openGL 3.3 window with 4x anti-aliasing
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);	//4x anti-aliasing
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);	//major version 3.x
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);	//minor version x.3
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//no old OpenGL

	//Open window and create context
	if(!glfwOpenWindow(System::screenWidth, System::screenHeight, 0,0,0,0, 32, 0, GLFW_WINDOW))
	{
		fprintf(stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		return;
	}

	//Initialize GLEW
	glewExperimental = true;	//necessary in core profile
	if(glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return;
	}

	glfwSetWindowTitle("Barnes");		//Window name
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	std::vector<glm::vec3> vert;
	vert.push_back(glm::vec3(-1.0f, -1.0f, 0.0f));
	vert.push_back(glm::vec3(1.0f, -1.0f, 0.0f));
	vert.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	std::vector<glm::vec2> uv;
	uv.push_back(glm::vec2(1.0,1.0));
	std::vector<glm::vec3> norm;
	norm.push_back(glm::vec3(1.0,1.0,1.0));

	camera = new Camera();
	camera->transform.position = glm::vec3(0,0,5);

	input = new Input();
	sys = new System();

	models.push_back(Model("C:/Users/Zach/Desktop/Kitchen/kitchen.3ds"));

	glClearColor(0.0f,0.2f,0.0f,1.0f);

	glfwSetMousePos(System::screenWidth/2, System::screenHeight/2);

	glfwEnable(GLFW_STICKY_KEYS);
	do
	{
		Update();
		Render();
	}
	while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));
}

int main()
{
	try
	{
		AppMain();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		system("pause");
		return -1;
	}

	return 0;
}