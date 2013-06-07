#include <vector>
#include <string>
#include <iostream>
#include "Key.h"

using namespace Barnes;

Key::Key(std::string name)
{
	this->name = name;
	up = false;
	down = false;
	released = false;
	pressed = false;
}

Key::~Key()
{

}

void Key::Press()
{
	std::cout << "Pressed" << std::endl;
	up = false;
	released = false;
	pressed = true;
	down = true;
}

void Key::Release()
{
	pressed = false;
	down = false;
	up = true;
	released = true;
}

bool Key::IsPressed()
{
	return pressed;
}

bool Key::IsReleased()
{
	return released;
}

bool Key::IsUp()
{
	return up;
}

bool Key::IsDown()
{
	return down;
}

void Key::Update()
{
	if(pressed)
		pressed = false;
	if(released)
		released = false;
}