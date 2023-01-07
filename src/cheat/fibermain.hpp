#pragma once

#pragma warning(disable : 4244)			//			'argument' : conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable : 26812)		//			The enum type type-name is unscoped. Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning(disable : 4091)	

#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <functional>
#include <filesystem>
#include <array>
#include <mutex>
#include <map>

// Project Header Files
#include "../gui/GUI.hpp"
#include "../gui/gui_controls.hpp"
#include "../gui/submenus/submenus.hpp"
#include "../game/features.hpp"
#include "../game/game.hpp"

namespace Cheat
{
	class fibermain
	{
	public:
		static void func_(LPVOID lpParameter);
	};
}