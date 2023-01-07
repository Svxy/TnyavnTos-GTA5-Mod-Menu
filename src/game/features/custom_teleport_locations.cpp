#include "custom_teleport_locations.hpp"

namespace Cheat
{
	namespace Features
	{
		bool custom_tel_locations::Add(std::string Name, Vector3 Coordinates)
		{
			// Create file
			if (!std::filesystem::exists(file_system::paths::CusTelLocFile))
			{
				file_system::write_file(file_system::paths::CusTelLocFile, "; TnyavnTos GTA 5 Mod Menu custom teleport locations - contents must always comply with INI file standards");
			}

			// Remove INI section if it already exists
			file_system::ini_file::remove_section(file_system::paths::CusTelLocFile, Name);

			// Create INI section with coordinate data
			file_system::ini_file::write(std::to_string(Coordinates.x), file_system::paths::CusTelLocFile, Name, "x");
			file_system::ini_file::write(std::to_string(Coordinates.y), file_system::paths::CusTelLocFile, Name, "y");
			file_system::ini_file::write(std::to_string(Coordinates.z), file_system::paths::CusTelLocFile, Name, "z");
			return true;
		}
		bool custom_tel_locations::Remove(std::string Name)
		{
			if (file_system::ini_file::remove_section(file_system::paths::CusTelLocFile, Name))
				return true;
			return false;
		}
	}
}
