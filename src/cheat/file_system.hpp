#pragma once
#include <iostream>

namespace Cheat
{
	namespace file_system
	{
		extern bool write_file(std::string FilePath, std::string data);
		struct paths
		{
			static const std::string UserprofileDir;		// Default: <SystemDriveLetter>:\Users\<username>
			static const std::string UserDocumentsDir;		// Default: <SystemDriveLetter>:\Users\<username>\Documents
			static const std::string DataDir;				// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat
			static const std::string LogDir;				// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat\Logs
			static const std::string ThemesDir;				// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat\Themes
			static const std::string WardrobesDir;			// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat\Wardrobes
			static const std::string ConfigFile;			// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat\Config.ini
			static const std::string CusTelLocFile;			// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat\CustomTeleportLocations.ini
			static const std::string HUDColorsFile;			// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat\HUDColors.ini
			static const std::string TextureFile;			// Default: <SystemDriveLetter>:\Users\<username>\Documents\GTAV Cheat\Textures.ytd
		};
		class get_path
		{
		public:
			static std::string module();
		};
		class ini_file
		{
		public:
			static bool write(std::string data, std::string FilePath, std::string Section, std::string Key);
			static bool write_bool(bool State, std::string FilePath, std::string Section, std::string Key);
			static bool remove_key(std::string FilePath, std::string Section, std::string Key);
			static bool remove_section(std::string FilePath, std::string Section);
			static std::string get(std::string FilePath, std::string Section, std::string Key);
		};
	}
}