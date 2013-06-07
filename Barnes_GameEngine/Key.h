#ifndef KEY_H
#define KEY_H

namespace Barnes
{
	class Key
	{
	public:
		Key(std::string);
		~Key();

		void Update();
		void Press();
		void Release();
		bool IsPressed();
		bool IsReleased();
		bool IsDown();
		bool IsUp();

		//variables
		std::string name;

	private:
		bool pressed;
		bool released;
		bool down;
		bool up;
	};
}

#endif