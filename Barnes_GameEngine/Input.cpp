#include <gl/glfw.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <boost\algorithm\string.hpp>

#include "Input.h"

using namespace std;

Key Input::Keys[KEY_COUNT] = { 
		Key("A"),Key("B"),Key("C"),
		Key("D"),Key("E"),Key("F"),
		Key("G"),Key("H"),Key("I"),
		Key("J"),Key("K"),Key("L"),
		Key("M"),Key("N"),Key("O"),
		Key("P"),Key("Q"),Key("R"),
		Key("S"),Key("T"),Key("U"),
		Key("V"),Key("W"),Key("X"),
		Key("Y"),Key("Z"),Key("0"),
		Key("1"),Key("2"),Key("3"),
		Key("4"),Key("5"),Key("6"),
		Key("7"),Key("8"),Key("9"),
		Key("LCTRL"),Key("RCTRL"),
		Key("LALT"),Key("RALT"),
		Key("TAB"),Key("ENTER"),
		Key("SPACE"),Key("BACKSPACE"),
		Key("ESC"),
		Key("MOUSE1"),Key("MOUSE2"),Key("MOUSE3"),
		Key("MOUSE4"),Key("MOUSE5"),
		Key("UP"),Key("DOWN"),
		Key("RIGHT"),Key("RIGHT"),
		Key("LSHIFT"), Key("RSHIFT")
		};

Input::Input()
{
	glfwSetKeyCallback(key_callback);

}

Input::~Input()
{
	
}

void Input::Update()
{
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].pressed)
			Keys[i].pressed = false;
		if(Keys[i].released)
			Keys[i].released = false;
	}
}

bool Input::KeyDown(std::string keyName)
{
	boost::to_upper(keyName);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(keyName) == 0)
		{
			return Keys[i].down;
		}
	}
	return false;
}

bool Input::KeyUp(std::string keyName)
{
	boost::to_upper(keyName);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(keyName) == 0)
		{
			return Keys[i].up;
		}
	}
	return false;
}

bool Input::KeyPressed(std::string keyName)
{
	boost::to_upper(keyName);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(keyName) == 0)
		{
			return Keys[i].pressed;
		}
	}
	return false;
}

bool Input::KeyReleased(std::string keyName)
{
	boost::to_upper(keyName);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(keyName) == 0)
		{
			return Keys[i].released;
		}
	}
	return false;
}

bool Input::MouseButtonDown(std::string button)
{
	boost::to_upper(button);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(button) == 0)
		{
			return Keys[i].down;
		}
	}
	return false;
}

bool Input::MouseButtonUp(std::string button)
{
	boost::to_upper(button);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(button) == 0)
		{
			return Keys[i].up;
		}
	}
	return false;
}

bool Input::MouseButtonPressed(std::string button)
{
	boost::to_upper(button);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(button) == 0)
		{
			return Keys[i].pressed;
		}
	}
	return false;
}

bool Input::MouseButtonReleased(std::string button)
{
	boost::to_upper(button);
	for(int i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(button) == 0)
		{
			return Keys[i].released;
		}
	}
	return false;
}

glm::vec2 Input::GetMousePos()
{
	int x,y;
	glfwGetMousePos(&x, &y);
	return glm::vec2(x,y);
}

void Input::key_callback(int key, int action)
{
	char c = key;
	std::stringstream ss;
	std::string key_string;
	ss << c;
	ss >> key_string;
	
	if(action == GLFW_PRESS)
	{
		for(int i = 0; i < KEY_COUNT; i++)
		{
			if(Keys[i].name.c_str()[0] == key)
			{
				Keys[i].pressed = true;
				Keys[i].released = false;
				Keys[i].down = true;
				Keys[i].up = false;
				return;
			}
			
			switch(key)
			{
			case GLFW_KEY_BACKSPACE: 
				Keys[43].pressed = true;
				Keys[43].released = false;
				Keys[43].down = true;
				Keys[43].up = false;
				break;
			case GLFW_KEY_SPACE:
				Keys[42].pressed = true;
				Keys[42].released = false;
				Keys[42].down = true;
				Keys[42].up = false;
				break;
			case GLFW_KEY_ENTER: 
				Keys[41].pressed = true;
				Keys[41].released = false;
				Keys[41].down = true;
				Keys[41].up = false;
				break;
			case GLFW_KEY_LCTRL: 
				Keys[36].pressed = true;
				Keys[36].released = false;
				Keys[36].down = true;
				Keys[36].up = false;
				break;
			case GLFW_KEY_RCTRL:
				Keys[37].pressed = true;
				Keys[37].released = false;
				Keys[37].down = true;
				Keys[37].up = false;
				break;
			case GLFW_KEY_LALT: 
				Keys[38].pressed = true;
				Keys[38].released = false;
				Keys[38].down = true;
				Keys[38].up = false;
				break;
			case GLFW_KEY_RALT: 
				Keys[39].pressed = true;
				Keys[39].released = false;
				Keys[39].down = true;
				Keys[39].up = false;
				break;
			case GLFW_KEY_LSHIFT: 
				Keys[54].pressed = true;
				Keys[54].released = false;
				Keys[54].down = true;
				Keys[54].up = false;
				break;
			case GLFW_KEY_RSHIFT: 
				Keys[55].pressed = true;
				Keys[55].released = false;
				Keys[55].down = true;
				Keys[55].up = false;
				break;
			case GLFW_KEY_TAB:
				Keys[40].pressed = true;
				Keys[30].released = false;
				Keys[40].down = true;
				Keys[40].up = false;
				break;
			case GLFW_KEY_UP: 
				Keys[50].pressed = true;
				Keys[50].released = false;
				Keys[50].down = true;
				Keys[50].up = false;
				break;
			case GLFW_KEY_DOWN: 
				Keys[51].pressed = true;
				Keys[51].released = false;
				Keys[51].down = true;
				Keys[51].up = false;
				break;
			case GLFW_KEY_LEFT: 
				Keys[52].pressed = true;
				Keys[52].released = false;
				Keys[52].down = true;
				Keys[52].up = false;
				break;
			case GLFW_KEY_RIGHT: 
				Keys[53].pressed = true;
				Keys[53].released = false;
				Keys[53].down = true;
				Keys[53].up = false;
				break;
			case GLFW_KEY_ESC:
				Keys[44].pressed = true;
				Keys[44].released = false;
				Keys[44].down = true;
				Keys[44].up = false;
				break;
			case GLFW_MOUSE_BUTTON_1: 
				Keys[45].pressed = true;
				Keys[45].released = false;
				Keys[45].down = true;
				Keys[45].up = false;
				break;
			case GLFW_MOUSE_BUTTON_2: 
				Keys[46].pressed = true;
				Keys[46].released = false;
				Keys[46].down = true;
				Keys[46].up = false;
				break;
			case GLFW_MOUSE_BUTTON_3: 
				Keys[47].pressed = true;
				Keys[47].released = false;
				Keys[47].down = true;
				Keys[47].up = false;
				break;
			case GLFW_MOUSE_BUTTON_4: 
				Keys[48].pressed = true;
				Keys[48].released = false;
				Keys[48].down = true;
				Keys[48].up = false;
				break;
			case GLFW_MOUSE_BUTTON_5: 
				Keys[49].pressed = true;
				Keys[49].released = false;
				Keys[49].down = true;
				Keys[49].up = false;
				break;
			}
		}
	}
	if(action == GLFW_RELEASE)
	{
		for(int i = 0; i < KEY_COUNT; i++)
		{
			if(Keys[i].name.c_str()[0] == key)
			{
				Keys[i].pressed = false;
				Keys[i].released = true;
				Keys[i].down = false;
				Keys[i].up = true;
				return;
			}
			
			switch(key)
			{
			case GLFW_KEY_BACKSPACE: 
				Keys[43].pressed = false;
				Keys[43].released = true;
				Keys[43].down = false;
				Keys[43].up = true;
				break;
			case GLFW_KEY_SPACE:
				Keys[42].pressed = false;
				Keys[42].released = true;
				Keys[42].down = false;
				Keys[42].up = true;
				break;
			case GLFW_KEY_ENTER: 
				Keys[41].pressed = false;
				Keys[41].released = true;
				Keys[41].down = false;
				Keys[41].up = true;
				break;
			case GLFW_KEY_LCTRL: 
				Keys[36].pressed = false;
				Keys[36].released = true;
				Keys[36].down = false;
				Keys[36].up = true;
				break;
			case GLFW_KEY_RCTRL:
				Keys[37].pressed = false;
				Keys[37].released = true;
				Keys[37].down = false;
				Keys[37].up = true;
				break;
			case GLFW_KEY_LALT: 
				Keys[38].pressed = false;
				Keys[38].released = true;
				Keys[38].down = false;
				Keys[38].up = true;
				break;
			case GLFW_KEY_RALT: 
				Keys[39].pressed = false;
				Keys[39].released = true;
				Keys[39].down = false;
				Keys[39].up = true;
				break;
			case GLFW_KEY_LSHIFT: 
				Keys[54].pressed = false;
				Keys[54].released = true;
				Keys[54].down = false;
				Keys[54].up = true;
				break;
			case GLFW_KEY_RSHIFT: 
				Keys[55].pressed = false;
				Keys[55].released = true;
				Keys[55].down = false;
				Keys[55].up = true;
				break;
			case GLFW_KEY_TAB:
				Keys[40].pressed = false;
				Keys[30].released = true;
				Keys[40].down = false;
				Keys[40].up = true;
				break;
			case GLFW_KEY_UP: 
				Keys[50].pressed = false;
				Keys[50].released = true;
				Keys[50].down = false;
				Keys[50].up = true;
				break;
			case GLFW_KEY_DOWN: 
				Keys[51].pressed = false;
				Keys[51].released = true;
				Keys[51].down = false;
				Keys[51].up = true;
				break;
			case GLFW_KEY_LEFT: 
				Keys[52].pressed = false;
				Keys[52].released = true;
				Keys[52].down = false;
				Keys[52].up = true;
				break;
			case GLFW_KEY_RIGHT: 
				Keys[53].pressed = false;
				Keys[53].released = true;
				Keys[53].down = false;
				Keys[53].up = true;
				break;
			case GLFW_KEY_ESC:
				Keys[44].pressed = false;
				Keys[44].released = true;
				Keys[44].down = false;
				Keys[44].up = true;
				break;
			case GLFW_MOUSE_BUTTON_1: 
				Keys[45].pressed = false;
				Keys[45].released = true;
				Keys[45].down = false;
				Keys[45].up = true;
				break;
			case GLFW_MOUSE_BUTTON_2: 
				Keys[46].pressed = false;
				Keys[46].released = true;
				Keys[46].down = false;
				Keys[46].up = true;
				break;
			case GLFW_MOUSE_BUTTON_3: 
				Keys[47].pressed = false;
				Keys[47].released = true;
				Keys[47].down = false;
				Keys[47].up = true;
				break;
			case GLFW_MOUSE_BUTTON_4: 
				Keys[48].pressed = false;
				Keys[48].released = true;
				Keys[48].down = false;
				Keys[48].up = true;
				break;
			case GLFW_MOUSE_BUTTON_5: 
				Keys[49].pressed = false;
				Keys[49].released = true;
				Keys[49].down = false;
				Keys[49].up = true;
				break;
			}
		}
	}
}



