#include <gl/glfw.h>
#include <glm/glm.hpp>
#include <ctype.h>
#include <string>
#include <sstream>
#include <boost\algorithm\string.hpp>
#include "KeyTypes.h"

using namespace Barnes;

std::string KeyTypes:: ESC = "ESC";
std::string KeyTypes:: BACKSPACE = "BACKSPACE";
std::string KeyTypes:: SPACE = "SPACE";
std::string KeyTypes:: ENTER = "ENTER";
std::string KeyTypes:: LCTRL = "LCTRL";
std::string KeyTypes:: RCTRL = "RCTRL";
std::string KeyTypes:: LALT = "LALT";
std::string KeyTypes:: RALT = "RALT";
std::string KeyTypes:: LSHIFT = "LSHIFT";
std::string KeyTypes:: RSHIFT = "RSHIFT";
std::string KeyTypes:: TAB = "TAB";
std::string KeyTypes:: UP = "UP";
std::string KeyTypes:: DOWN = "DOWN";
std::string KeyTypes:: LEFT = "LEFT";
std::string KeyTypes:: RIGHT = "RIGHT";
std::string KeyTypes:: MOUSE1 = "MOUSE1";
std::string KeyTypes:: MOUSE2 = "MOUSE2";
std::string KeyTypes:: MOUSE3 = "MOUSE3";
std::string KeyTypes:: MOUSE4 = "MOUSE4";
std::string KeyTypes:: MOUSE5 = "MOUSE5";

Key KeyTypes::Keys[KEY_COUNT] = {  
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
Key("RIGHT"),Key("LEFT"),
Key("DOWN"),Key("UP")
};
/*
void GLFWCALL Key_Callback(int key, int action)
{
	char c = key;
	std::stringstream ss;
	std::string key_string;
	ss << c;
	ss >> key_string;

	if(action == GLFW_PRESS)
	{
		for(size_t i = 0; i < KEY_COUNT; i++)
		{
			if(Keys[i].name.compare(key_string))
			{
				Keys[i].Press();
				return;
			}
			
			switch(key)
			{
			case GLFW_KEY_BACKSPACE: kt.FindKey("ESC").Press(); break;
			case GLFW_KEY_SPACE: kt.FindKey("SPACE").Press(); break;
			case GLFW_KEY_ENTER: kt.FindKey("ENTER").Press(); break;
			case GLFW_KEY_LCTRL: kt.FindKey("LCTRL").Press(); break;
			case GLFW_KEY_RCTRL: kt.FindKey("RCTRL").Press(); break;
			case GLFW_KEY_LALT: kt.FindKey("LALT").Press(); break;
			case GLFW_KEY_RALT: kt.FindKey("RALT").Press(); break;
			case GLFW_KEY_LSHIFT: kt.FindKey("LSHIFT").Press(); break;
			case GLFW_KEY_RSHIFT: kt.FindKey("RSHIFT").Press(); break;
			case GLFW_KEY_TAB: kt.FindKey("TAB").Press(); break;
			case GLFW_KEY_UP: kt.FindKey("UP").Press(); break;
			case GLFW_KEY_DOWN: kt.FindKey("DOWN").Press(); break;
			case GLFW_KEY_LEFT: kt.FindKey("LEFT").Press(); break;
			case GLFW_KEY_RIGHT: kt.FindKey("RIGHT").Press(); break;
			case GLFW_MOUSE_BUTTON_1: kt.FindKey("MOUSE1").Press(); break;
			case GLFW_MOUSE_BUTTON_2: kt.FindKey("MOUSE2").Press(); break;
			case GLFW_MOUSE_BUTTON_3: kt.FindKey("MOUSE3").Press(); break;
			case GLFW_MOUSE_BUTTON_4: kt.FindKey("MOUSE4").Press(); break;
			case GLFW_MOUSE_BUTTON_5: kt.FindKey("MOUSE5").Press(); break;
			}
		}
	}
	if(action == GLFW_RELEASE)
	{
		for(size_t i = 0; i < KEY_COUNT; i++)
		{
			if(kt.Keys[i].name.compare(key_string) == 0)
			{
				kt.Keys[i].Release();
				return;
			}
		
			switch(key)
			{
			case GLFW_KEY_BACKSPACE: kt.FindKey("ESC").Release(); break;
			case GLFW_KEY_SPACE: kt.FindKey("SPACE").Release(); break;
			case GLFW_KEY_ENTER: kt.FindKey("ENTER").Release(); break;
			case GLFW_KEY_LCTRL: kt.FindKey("LCTRL").Release(); break;
			case GLFW_KEY_RCTRL: kt.FindKey("RCTRL").Release(); break;
			case GLFW_KEY_LALT: kt.FindKey("LALT").Release(); break;
			case GLFW_KEY_RALT: kt.FindKey("RALT").Release(); break;
			case GLFW_KEY_LSHIFT: kt.FindKey("LSHIFT").Release(); break;
			case GLFW_KEY_RSHIFT: kt.FindKey("RSHIFT").Release(); break;
			case GLFW_KEY_TAB: kt.FindKey("TAB").Release(); break;
			case GLFW_KEY_UP: kt.FindKey("UP").Release(); break;
			case GLFW_KEY_DOWN: kt.FindKey("DOWN").Release(); break;
			case GLFW_KEY_LEFT: kt.FindKey("LEFT").Release(); break;
			case GLFW_KEY_RIGHT: kt.FindKey("RIGHT").Release(); break;
			case GLFW_MOUSE_BUTTON_1: kt.FindKey("MOUSE1").Release(); break;
			case GLFW_MOUSE_BUTTON_2: kt.FindKey("MOUSE2").Release(); break;
			case GLFW_MOUSE_BUTTON_3: kt.FindKey("MOUSE3").Release(); break;
			case GLFW_MOUSE_BUTTON_4: kt.FindKey("MOUSE4").Release(); break;
			case GLFW_MOUSE_BUTTON_5: kt.FindKey("MOUSE5").Release(); break;
			}
		}
	}
}
*/
void KeyTypes::Init()
{
	glfwSetKeyCallback(Key_Callback);
}

KeyTypes::KeyTypes()
{

}

Key KeyTypes::FindKey(std::string name)
{

	boost::to_upper(name);

	for(size_t i = 0; i < KEY_COUNT; i++)
	{
		if(Keys[i].name.compare(name) == 0)
		{
			return Keys[i];
		}
	}
	return NULL;
}

KeyTypes::~KeyTypes()
{
}

void KeyTypes::Update()
{
	for(size_t i = 0; i < KEY_COUNT; i++)
	{
		Keys[i].Update();
	}
}