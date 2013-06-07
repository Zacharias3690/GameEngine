#include <gl/glfw.h>

#include "System.h"

double System::currentTime = 0;
float System::lastTime = 0;
float System::deltaTime = 0;
float System::screenWidth = 1024;
float System::screenHeight = 768;

System::System()
{

}

void System::Update()
{
	currentTime = glfwGetTime();
	deltaTime = float(currentTime - lastTime);
	lastTime = currentTime;
}