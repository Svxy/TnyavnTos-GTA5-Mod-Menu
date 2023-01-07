#include "theme_loader.hpp"
#include "../../cheat/file_system.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/features.hpp"
#include "../../game/game.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include <string>
#include <filesystem>

namespace Cheat
{
	namespace Features
	{
		std::vector <std::string> theme_loader::Array;
		std::string theme_loader::Current;
		void theme_loader::Create(std::string Name)
		{
			std::string TargetThemePath = file_system::paths::ThemesDir + "\\" + Name + ".ini";

			file_system::ini_file::write("2.3", TargetThemePath, "Theme", "theme_file_version");

			file_system::ini_file::write_bool(GUI::DisableMenuGUIOpenCloseFade, TargetThemePath, "Menu", "open/close_fade_disabled");
			file_system::ini_file::write(std::to_string(GUI::guiWidth), TargetThemePath, "Menu", "menu_gui_width");

			file_system::ini_file::write(std::to_string(GUI::guiX), TargetThemePath, "Positioning", "menu_gui_x");
			file_system::ini_file::write(std::to_string(GUI::guiY), TargetThemePath, "Positioning", "menu_gui_y");

			file_system::ini_file::write(std::to_string(GUI::SelectableInfoBoxX), TargetThemePath, "Positioning", "selectable_information_box_x");
			file_system::ini_file::write(std::to_string(GUI::SelectableInfoBoxY), TargetThemePath, "Positioning", "selectable_information_box_y");
			file_system::ini_file::write(std::to_string(GUI::SelectableHeight), TargetThemePath, "Positioning", "selectable_height");

			file_system::ini_file::write_bool(GUI::ShowHeaderTexture, TargetThemePath, "Header", "header_texture");
			file_system::ini_file::write_bool(GUI::ShowHeaderBackground, TargetThemePath, "Header", "header_background");

			file_system::ini_file::write_bool(Features::RGBDiscoBool, TargetThemePath, "Color", "rgb_disco");
			if (!Features::RGBDiscoBool)
			{
				file_system::ini_file::write(std::to_string(GUI::PrimaryColor.r), TargetThemePath, "Color", "primary_color_r");
				file_system::ini_file::write(std::to_string(GUI::PrimaryColor.g), TargetThemePath, "Color", "primary_color_g");
				file_system::ini_file::write(std::to_string(GUI::PrimaryColor.b), TargetThemePath, "Color", "primary_color_b");

				file_system::ini_file::write(std::to_string(GUI::TextColorAndFont.r), TargetThemePath, "Color", "text_color_r");
				file_system::ini_file::write(std::to_string(GUI::TextColorAndFont.g), TargetThemePath, "Color", "text_color_g");
				file_system::ini_file::write(std::to_string(GUI::TextColorAndFont.b), TargetThemePath, "Color", "text_color_b");
			}

			file_system::ini_file::write(std::to_string(GUI::TextColorAndFont.f), TargetThemePath, "Font", "text_font");

			Game::notification::Minimap((char*)"Theme Saved");
		}
		void theme_loader::Load(std::string Name, bool AtInit)
		{
			std::string TargetThemePath = file_system::paths::ThemesDir + "\\" + Name + ".ini";

			if (!std::filesystem::exists(TargetThemePath))
			{
				Game::notification::Minimap((char*)"Requested Theme does not exist. Auto load entry removed from config file.");
				file_system::ini_file::remove_key(file_system::paths::ConfigFile, "submenu_settings", "Active Theme");
				return;
			}

			theme_loader::Current = Name;
			try
			{
				GUI::DisableMenuGUIOpenCloseFade = helper::StringToBool(file_system::ini_file::get(TargetThemePath, "Menu", "open/close_fade_disabled"));
				GUI::guiWidth = std::stof(file_system::ini_file::get(TargetThemePath, "Menu", "menu_gui_width"));

				GUI::guiX = std::stof(file_system::ini_file::get(TargetThemePath, "Positioning", "menu_gui_x"));
				GUI::guiY = std::stof(file_system::ini_file::get(TargetThemePath, "Positioning", "menu_gui_y"));

				GUI::SelectableInfoBoxX = std::stof(file_system::ini_file::get(TargetThemePath, "Positioning", "selectable_information_box_x"));
				GUI::SelectableInfoBoxY = std::stof(file_system::ini_file::get(TargetThemePath, "Positioning", "selectable_information_box_y"));
				GUI::SelectableHeight = std::stof(file_system::ini_file::get(TargetThemePath, "Positioning", "selectable_height"));

				GUI::ShowHeaderTexture = helper::StringToBool(file_system::ini_file::get(TargetThemePath, "Header", "header_texture"));
				GUI::ShowHeaderBackground = helper::StringToBool(file_system::ini_file::get(TargetThemePath, "Header", "header_background"));

				Features::RGBDiscoBool = helper::StringToBool(file_system::ini_file::get(TargetThemePath, "Color", "rgb_disco"));

				if (!Features::RGBDiscoBool)
				{
					GUI::PrimaryColor.r = helper::StringToInt(file_system::ini_file::get(TargetThemePath, "Color", "primary_color_r"));
					GUI::PrimaryColor.g = helper::StringToInt(file_system::ini_file::get(TargetThemePath, "Color", "primary_color_g"));
					GUI::PrimaryColor.b = helper::StringToInt(file_system::ini_file::get(TargetThemePath, "Color", "primary_color_b"));

					GUI::TextColorAndFont.r = helper::StringToInt(file_system::ini_file::get(TargetThemePath, "Color", "text_color_r"));
					GUI::TextColorAndFont.g = helper::StringToInt(file_system::ini_file::get(TargetThemePath, "Color", "text_color_g"));
					GUI::TextColorAndFont.b = helper::StringToInt(file_system::ini_file::get(TargetThemePath, "Color", "text_color_b"));
				}

				GUI::TextColorAndFont.f = helper::StringToInt(file_system::ini_file::get(TargetThemePath, "Font", "text_font"));
			}
			catch (...) {}

			// Check Theme File Version
			if (file_system::ini_file::get(TargetThemePath, "Theme", "theme_file_version") != "2.3")
				Game::notification::Subtitle((char*)"The loaded Theme is outdated. Please resave it", 5000);

			// Save New Active Theme Name To Config File
			if (!AtInit)
			{
				file_system::ini_file::write(theme_loader::Current, file_system::paths::ConfigFile, "submenu_settings", "Active Theme");
				Game::notification::Minimap((char*)"Theme Loaded");
			}
		}
		void theme_loader::Remove(std::string Name)
		{
			remove(helper::StringToChar(file_system::paths::ThemesDir + "\\" + Name + ".ini"));
			file_system::ini_file::remove_key(file_system::paths::ConfigFile, "submenu_settings", "Active Theme");
			theme_loader::Current.clear();
			GUI::currentOption = 1;
			Game::notification::Minimap((char*)"Theme Removed");
		}
	}
}