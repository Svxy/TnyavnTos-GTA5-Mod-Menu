#include "config.hpp"
#include "logger.hpp"
#include "file_system.hpp"
#include <filesystem>
#include "../game/features.hpp"
#include "cheat.hpp"
#include "../gui/GUI.hpp"
#include "../gui/gui_controls.hpp"
#include "../game/features/theme_loader.hpp"
#include "../gui/submenus/submenus.hpp"
#include "../game/game.hpp"
#include "../game/notification.hpp"

namespace Cheat
{
	bool config::Loaded = false;
	std::vector <std::string> config::LoadedSelectables;
	void config::Load()
	{
		Logger::LogMsg(LoggerMsgTypes::LOGGER_INFO_MSG, "Loading Configuration");

		// Create file
		if (!std::filesystem::exists(file_system::paths::ConfigFile))
			file_system::write_file(file_system::paths::ConfigFile, "; TnyavnTos GTA 5 Mod Menu configuration - contents must always comply with INI file standards");

		// Load hotkeys
		std::string MenuGUIKey = file_system::ini_file::get(file_system::paths::ConfigFile, "submenu_settings", "Menu GUI Key");
		if (!MenuGUIKey.empty())
			GUI::gui_controls::OpenMenuGUIKey = helper::StringToInt(MenuGUIKey);

		std::string CursorNavigationKeyString = file_system::ini_file::get(file_system::paths::ConfigFile, "submenu_settings", "Cursor Navigation Key");
		if (!CursorNavigationKeyString.empty())
			GUI::gui_controls::CursorNavigationKey = helper::StringToInt(CursorNavigationKeyString);

		std::string SaveSelectableKey = file_system::ini_file::get(file_system::paths::ConfigFile, "submenu_settings", "Save Selectable Key");
		if (!SaveSelectableKey.empty())
			GUI::gui_controls::SaveSelectableKey = helper::StringToInt(SaveSelectableKey);

		// Load Active Theme
		std::string ActiveThemeSetting = file_system::ini_file::get(file_system::paths::ConfigFile, "submenu_settings", "Active Theme");
		if (!ActiveThemeSetting.empty())
			Features::theme_loader::Load(ActiveThemeSetting, true);

		// Load Vehicle Spawner Custom License Plate Text
		std::string VehicleSpawnerCustomLicensePlateText = file_system::ini_file::get(file_system::paths::ConfigFile, "submenu_vehicle spawn settings", "Custom License Plate Text");
		if (!VehicleSpawnerCustomLicensePlateText.empty())
			Features::VehicleSpawnerCustomLicensePlateTextString = VehicleSpawnerCustomLicensePlateText;

		// Do not overwrite "Textures.ytd" at init feature - setting must be loaded immediately (not async)
		Features::NoTextureFileOverwrite = helper::StringToBool(file_system::ini_file::get(file_system::paths::ConfigFile, "submenu_settings", "do not overwrite \"textures.ytd\" at init"));

		std::thread LdConfigThrd([]()
		{
			using namespace Cheat;
			using namespace GUI;
			gui_controls::KeyInputDisabled = true;
			HideGUIElements = true;
			for (int FuncPointerIndex = 0; FuncPointerIndex < Submenus::NumberOfSubmenus; ++FuncPointerIndex)
			{
				MoveMenu((*Submenus::FunctionPointers[FuncPointerIndex]));
				std::this_thread::sleep_for(std::chrono::milliseconds(150));
			}
			CloseMenuGUI();
			PreviousMenu = nullptr;
			gui_controls::KeyInputDisabled = false;
			HideGUIElements = false;
			LoadedSelectables.clear();
			Loaded = true;
		});
		LdConfigThrd.detach();
	}
	bool config::SelectableLoaded(std::string Selectable)
	{
		for (auto const& l : LoadedSelectables)
			if (l == GUI::CurrentSubmenu + Selectable)
				return true;
		return false;
	}
	void config::LoadBoolSelectables(std::string Selectable, bool& ReturnedBool)
	{
		if (!config::SelectableLoaded(Selectable))
		{
			std::string ConfigFileValue = GetSelectableDataFromConfig(Selectable);
			if (!ConfigFileValue.empty())
			{
				ReturnedBool = helper::StringToBool(ConfigFileValue);
				SelectableLoadNotify(Selectable);
				config::LoadedSelectables.push_back(GUI::CurrentSubmenu + Selectable);
			}
		}
	}
	void config::LoadIntSelectableState(std::string Selectable, int& ReturnedInt)
	{
		if (!config::SelectableLoaded(Selectable))
		{
			std::string ConfigFileValue = GetSelectableDataFromConfig(Selectable);
			if (!ConfigFileValue.empty())
			{
				ReturnedInt = helper::StringToInt(ConfigFileValue);
				SelectableLoadNotify(Selectable);
				config::LoadedSelectables.push_back(GUI::CurrentSubmenu + Selectable);
			}
		}
	}
	void config::LoadFloatSelectableState(std::string Selectable, float& ReturnedFloat)
	{
		if (!config::SelectableLoaded(Selectable))
		{
			std::string ConfigFileValue = GetSelectableDataFromConfig(Selectable);
			if (!ConfigFileValue.empty())
			{
				ReturnedFloat = std::stof(ConfigFileValue);
				SelectableLoadNotify(Selectable);
				config::LoadedSelectables.push_back(GUI::CurrentSubmenu + Selectable);
			}
		}
	}
	std::string config::GetSelectableDataFromConfig(std::string Selectable)
	{
		return file_system::ini_file::get(file_system::paths::ConfigFile, "submenu_" + GUI::CurrentSubmenu, Selectable);
	}
	void config::SelectableLoadNotify(std::string Selectable)
	{
		Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "[CFG] Loaded selectable \"%s\" (submenu \"%s\")", Selectable.c_str(), GUI::CurrentSubmenu.c_str());
	}
	void config::SaveSelectable(std::string Selectable, std::string OptionValue, bool IsSavable)
	{
		GUI::CurrentSelectableIsSavable = IsSavable;
		if (GUI::gui_controls::IsKeyCurrentlyPressed(GUI::gui_controls::SaveSelectableKey))
		{
			if (IsSavable)
			{
				file_system::ini_file::write(OptionValue, file_system::paths::ConfigFile, "submenu_" + GUI::CurrentSubmenu, Selectable);
				std::string LogMessage = "Selectable " + Selectable + " saved";
				Game::notification::MinimapAdvanced(helper::StringToChar(LogMessage), (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Config", (char*)"", 0.5f, (char*)"");
				Logger::LogMsg(LOGGER_DBG_MSG, "[CFG] '%s' (%s submenu) selectable state saved", Selectable.c_str(), GUI::CurrentSubmenu.c_str());
			}
		}
	}
}