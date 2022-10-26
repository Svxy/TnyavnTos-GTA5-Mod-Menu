#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;

DWORD WINAPI InitializationThread(LPVOID lpParam)
{
	// Create directories
	std::string GtavDirectoryPath = CheatFunctions::GetWindowsUserDocumentsFolderPath() + (std::string)"\\GTAV Cheat";
	if (!std::filesystem::exists(GtavDirectoryPath)) { CheatFunctions::CreateNewDirectory(GtavDirectoryPath); }
	std::string LogsDirectoryPath = CheatFunctions::GetWindowsUserDocumentsFolderPath() + (std::string)"\\GTAV Cheat\\Logs";
	if (!std::filesystem::exists(LogsDirectoryPath)) { CheatFunctions::CreateNewDirectory(LogsDirectoryPath); }
	std::string ThemesDirectoryPath = Cheat::CheatFunctions::GetWindowsUserDocumentsFolderPath() + (std::string)"\\GTAV Cheat\\Themes";
	if (!std::filesystem::exists(ThemesDirectoryPath)) { CheatFunctions::CreateNewDirectory(ThemesDirectoryPath); }

	// Data migration for existing config and data prior to v2.2.1.0
	std::string OldDataPath = CheatFunctions::ReturnCheatModuleDirectoryPath() + "\\gtav";
	std::string NewDataPath = CheatFunctions::GetWindowsUserDocumentsFolderPath() + "\\GTAV Cheat";
	if (std::filesystem::exists(OldDataPath))
	{
		// Move Logs directory
		std::string OldLogsDirectory = OldDataPath + "\\Logs";
		MoveFileExA(OldLogsDirectory.c_str(), NewDataPath.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

		// Move Themes directory
		std::string OldThemesDirectory = OldDataPath + "\\Themes";
		MoveFileExA(OldThemesDirectory.c_str(), NewDataPath.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

		// Move Config.ini
		std::string OldConfigPath = OldDataPath + "\\Config.ini";
		MoveFileExA(OldConfigPath.c_str(), CheatFunctions::ReturnConfigFilePath().c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

		// Move CustomTeleportLocations.json
		std::string OldCustomTeleportLocationsPath = OldDataPath + "\\CustomTeleportLocations.json";
		MoveFileExA(OldCustomTeleportLocationsPath.c_str(), CheatFunctions::ReturnCustomTeleportLocationsFilePath().c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

		// Move HUDColors.ini
		std::string OldHUDColorsPath = OldDataPath + "\\HUDColors.ini";
		MoveFileExA(OldHUDColorsPath.c_str(), CheatFunctions::ReturnHUDColorsFilePath().c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH | MOVEFILE_COPY_ALLOWED);

		// Delete old data folder
		std::filesystem::remove_all(OldDataPath);
	}
	
	// Initalize Logger
	Logger::Init();

	// Initialize MinHook
	if (MH_Initialize() != MH_OK) { Logger::LogMsg(LOGGER_FATAL_MSG, "Initialize MinHook failed"); std::exit(EXIT_FAILURE); }
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG,"Initialized MH");

	// Initalize RAGE hooks
	GameHooking::Init();

	// Exit thread
	return EXIT_SUCCESS;
}

HMODULE Cheat::CheatModuleHandle;
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpvReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CheatModuleHandle = hModule;
		DisableThreadLibraryCalls(CheatModuleHandle);
		CreateThread(NULL, NULL, InitializationThread, CheatModuleHandle, NULL, NULL);
		break;
	}
	return TRUE;
}