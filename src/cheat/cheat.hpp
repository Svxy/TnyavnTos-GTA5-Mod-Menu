#pragma once
#include <iostream>

namespace Cheat
{
	class core
	{
	public:
		static bool init_complete;
		static bool c_running;
	};
	class helper
	{
	public:
		static std::string ReturnDateTimeFormatAsString(const char* DateTimeFormat);
		static int StringToInt(std::string String);
		static bool StringToBool(std::string String);
		static char* StringToChar(std::string String);
		static void remove_chars(std::string& String, const char* CharactersToRemove);
	};
}