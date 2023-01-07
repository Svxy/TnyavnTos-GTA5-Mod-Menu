#include "cheat.hpp"
#include <Windows.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>

namespace Cheat
{
	bool core::init_complete = false;
	bool core::c_running = true;

	// See https://en.cppreference.com/w/cpp/io/manip/put_time
	std::string helper::ReturnDateTimeFormatAsString(const char* DateTimeFormat)
	{
		struct tm NewTimeHandle;
		time_t CurrentTimeHandle = time(0);
		localtime_s(&NewTimeHandle, &CurrentTimeHandle);
		std::ostringstream TimeDateString;
		TimeDateString << std::put_time(&NewTimeHandle, DateTimeFormat);
		return TimeDateString.str();
	}
	char* helper::StringToChar(std::string String)
	{
		return _strdup(String.c_str());
	}
	bool helper::StringToBool(std::string String)
	{
		std::transform(String.begin(), String.end(), String.begin(), std::tolower);
		
		if (String == "true" || String == "1")
			return true;
		else
			return false;
	}
	void helper::remove_chars(std::string& String, const char* CharactersToRemove)
	{
		for (unsigned int i = 0; i < strlen(CharactersToRemove); ++i)
			String.erase(remove(String.begin(), String.end(), CharactersToRemove[i]), String.end());
	}
	int helper::StringToInt(std::string String)
	{
		try
		{
			return std::stoi(String);
		}
		catch (...)
		{
			return NULL;
		}
	}
}