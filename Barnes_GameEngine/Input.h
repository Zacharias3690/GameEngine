#ifndef INPUT_H
#define INPUT_H

#define KEY_COUNT 56

struct Key
{
	Key(std::string name)
	{
		this->name = name;
		up = false;
		down = false;
		pressed = false;
		released = false;
	}
	std::string name;
	bool up;
	bool down;
	bool pressed;
	bool released;
};

class Input
{
public:
	//Functions
	Input();
	~Input();
	void Update();
	bool KeyDown(std::string key);		//true while key down
	bool KeyUp(std::string key);		//true while key up
	bool KeyPressed(std::string key);	//true on frame key is pressed
	bool KeyReleased(std::string key);	//true on frame key is pressed
	bool MouseButtonPressed(std::string key);
	bool MouseButtonReleased(std::string key);
	bool MouseButtonDown(std::string key);
	bool MouseButtonUp(std::string key);
	glm::vec2 GetMousePos();

	static void GLFWCALL key_callback(int key, int action);

	//variables
	static Key Keys[KEY_COUNT];
};

#endif