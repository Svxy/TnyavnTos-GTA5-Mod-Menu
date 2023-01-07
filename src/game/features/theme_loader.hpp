#pragma once
#include <iostream>
#include <vector>

namespace Cheat
{
	namespace Features
	{
		class theme_loader
		{
		public:
			static void Create(std::string Name);
			static void Load(std::string Name, bool AtInit);
			static void Remove(std::string Name);
			static std::string Current;
			static std::vector <std::string> Array; // Only filled and updated when ThemeFiles submenu is open
		};
	}
}