#ifndef KEYTYPES_H
#define KEYTYPES_H

#include "Key.h"
#include <vector>

#define KEY_COUNT 54

namespace Barnes
{
	class KeyTypes
	{
	public:
		KeyTypes();
		~KeyTypes();

		void Update();
		void Init();
		Key FindKey(std::string key);

		static std::string ESC;
		static std::string BACKSPACE;
		static std::string SPACE;
		static std::string ENTER;
		static std::string LCTRL;
		static std::string RCTRL;
		static std::string LALT;
		static std::string RALT;
		static std::string LSHIFT;
		static std::string RSHIFT;
		static std::string TAB;
		static std::string UP;
		static std::string DOWN;
		static std::string LEFT;
		static std::string RIGHT;
		static std::string MOUSE1;
		static std::string MOUSE2;
		static std::string MOUSE3;
		static std::string MOUSE4;
		static std::string MOUSE5;

		static Key Keys[KEY_COUNT];
	};
}

#endif