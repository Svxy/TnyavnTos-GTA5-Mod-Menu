#pragma once
#include <ini.h>
#include "../../hooking/types.hpp"
#include "../../cheat/file_system.hpp"
#include <filesystem>

namespace Cheat
{
	namespace Features
	{
		class custom_tel_locations
		{
		public:
			static bool Add(std::string Name, Vector3 Coordinates);
			static bool Remove(std::string Name);
		};
	}
}