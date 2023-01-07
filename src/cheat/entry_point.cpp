#include "entry_point.hpp"
#include "file_system.hpp"
#include "Logger.hpp"
#include "../hooking/hooking.hpp"
#include <MinHook.h>
#include <Windows.h>
#include <filesystem>

namespace Cheat
{
	HMODULE entry_point::module_handle	= NULL;
	DWORD WINAPI entry_point::init_thread(LPVOID lpParam)
	{
		// Some users are too enthusiastic and inject before the game had time to create it's window and initialize everything
		bool WindowWait = false;
		while (!FindWindowA("grcWindow", NULL))
		{
			WindowWait = true;
			Sleep(50);
		}	
		// Wait an additional 2.5 seconds once the game window has been created for good measure
		if (WindowWait)
			Sleep(2500);

		// Create directories
		if (!std::filesystem::exists(file_system::paths::DataDir))
			std::filesystem::create_directory(file_system::paths::DataDir);

		if (!std::filesystem::exists(file_system::paths::LogDir))
			std::filesystem::create_directory(file_system::paths::LogDir);

		if (!std::filesystem::exists(file_system::paths::ThemesDir))
			std::filesystem::create_directory(file_system::paths::ThemesDir);

		if (!std::filesystem::exists(file_system::paths::WardrobesDir))
			std::filesystem::create_directory(file_system::paths::WardrobesDir);

		// Data migration for existing config and data prior to v2.2.1.0
		std::string OldDataPath = file_system::get_path::module() + "\\gtav";
		if (std::filesystem::exists(OldDataPath))
		{
			// Move Logs directory
			std::string OldLogsDirectory = OldDataPath + "\\Logs";
			MoveFileExA(OldLogsDirectory.c_str(), file_system::paths::DataDir.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

			// Move Themes directory
			std::string OldThemesDirectory = OldDataPath + "\\Themes";
			MoveFileExA(OldThemesDirectory.c_str(), file_system::paths::DataDir.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

			// Move Config.ini
			std::string OldConfigPath = OldDataPath + "\\Config.ini";
			MoveFileExA(OldConfigPath.c_str(), file_system::paths::ConfigFile.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

			// Move HUDColors.ini
			std::string OldHUDColorsPath = OldDataPath + "\\HUDColors.ini";
			MoveFileExA(OldHUDColorsPath.c_str(), file_system::paths::HUDColorsFile.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

			// Delete old data folder
			std::filesystem::remove_all(OldDataPath);
		}

		// Data cleanup for Custom TP Location, version v2.2.2.0 and older
		std::string OldCustomTPLocationFile = file_system::paths::DataDir + "\\CustomTeleportLocations.json";
		if (std::filesystem::exists(OldCustomTPLocationFile))
			std::filesystem::remove(OldCustomTPLocationFile);

		// Initalize Logger
		Logger::Init();

		// Initialize MinHook
		if (MH_Initialize() != MH_OK)
		{
			Logger::LogMsg(LOGGER_FATAL_MSG, "Initialize MH failed"); 
			std::exit(EXIT_FAILURE);
		}
		Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Initialize MH -> success");

		// Initalize RAGE hooks
		GameHooking::Init();

		// Exit thread
		Logger::LogMsg(LOGGER_DBG_MSG, "init_thread - exit code 0");
		return EXIT_SUCCESS;
	}
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpvReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Cheat::entry_point::module_handle = hModule;
		DisableThreadLibraryCalls(Cheat::entry_point::module_handle);
		CreateThread(NULL, NULL, Cheat::entry_point::init_thread, Cheat::entry_point::module_handle, NULL, NULL);
		break;
	}
	return TRUE;
}