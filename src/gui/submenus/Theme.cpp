#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/features/theme_loader.hpp"

using namespace Cheat;
void GUI::Submenus::Theme()
{
	GUI::Title("Theme");
	GUI::MenuOption("Saved", Submenus::ThemeFiles);
	if (!Features::theme_loader::Current.empty())
	{
		GUI::Break("Current: ~c~" + Features::theme_loader::Current);
		if (GUI::Option("Save To Current", ""))
		{
			Features::theme_loader::Create(Features::theme_loader::Current);
		}
		if (GUI::Option("Delete", "Delete loaded theme"))
		{
			Features::theme_loader::Remove(Features::theme_loader::Current);
		}
	}
	else
	{
		GUI::Break("Current: ~c~None");
	}
	if (GUI::Option("Create New", ""))
	{
		std::string NewThemeFileName;
		if (Game::keyboard::get_input("Enter theme name", NewThemeFileName, 1, 20) == Game::keyboard::input_status::SUCCESS)
		{
			Features::theme_loader::Create(NewThemeFileName);
		}
	}
	GUI::Break("Header", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Texture", GUI::ShowHeaderTexture, "", SELECTABLE_DISABLE_SAVE);
	GUI::Toggle("Background", GUI::ShowHeaderBackground, "", SELECTABLE_DISABLE_SAVE);
	GUI::Break("Color", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("RGB Disco", Features::RGBDiscoBool, "It's party time!", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Primary", "Save is disabled while RGB Disco is enabled", Features::RGBDiscoBool ? SELECTABLE_DISABLED : SELECTABLE_DUMMY))
	{
		std::string Red, Green, Blue;
		bool Canceled = false;
		if (Game::keyboard::get_input("Enter R-color", Red, 1, 3) == Game::keyboard::input_status::SUCCESS)
			GUI::PrimaryColor.r = Cheat::helper::StringToInt(Red);
		else
			Canceled = true;

		if (Game::keyboard::get_input("Enter G-color", Green, 1, 3) == Game::keyboard::input_status::SUCCESS)
			GUI::PrimaryColor.g = Cheat::helper::StringToInt(Green);
		else
			Canceled = true;

		if (Game::keyboard::get_input("Enter B-color", Blue, 1, 3) == Game::keyboard::input_status::SUCCESS)
			GUI::PrimaryColor.b = Cheat::helper::StringToInt(Blue);
		else
			Canceled = true;

		if (!Canceled)
			Game::notification::Minimap((char*)"Updated Primary Color");
		else
			Game::notification::Minimap((char*)"Canceled Updating Primary Color");
	}
	if (GUI::Option("Text", "Save is disabled while RGB Disco is enabled", Features::RGBDiscoBool ? SELECTABLE_DISABLED : SELECTABLE_DUMMY))
	{
		std::string Red, Green, Blue;
		bool Canceled = false;
		if (Game::keyboard::get_input("Enter R-color", Red, 1, 3) == Game::keyboard::input_status::SUCCESS)
			GUI::TextColorAndFont.r = Cheat::helper::StringToInt(Red);
		else
			Canceled = true;

		if (Game::keyboard::get_input("Enter G-color", Green, 1, 3) == Game::keyboard::input_status::SUCCESS)
			GUI::TextColorAndFont.g = Cheat::helper::StringToInt(Green);
		else
			Canceled = true;

		if (Game::keyboard::get_input("Enter B-color", Blue, 1, 3) == Game::keyboard::input_status::SUCCESS)
			GUI::TextColorAndFont.b = Cheat::helper::StringToInt(Blue);
		else
			Canceled = true;

		if (!Canceled)
			Game::notification::Minimap((char*)"Updated Text Color");
		else
			Game::notification::Minimap((char*)"Canceled Updating Text Color");
	}
	GUI::Break("Font", SELECTABLE_CENTER_TEXT);
	if (GUI::StringVector("Type", { "Chalet London", "House Script", "Monospace", "Wing Dings", "Chalet Comprime Cologne", "Pricedown" }, Features::FontTypeVectorPosition, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		if (Features::FontTypeVectorPosition == 0)
		{
			GUI::TextColorAndFont.f = FontChaletLondon;
		}
		else if (Features::FontTypeVectorPosition == 1)
		{
			GUI::TextColorAndFont.f = FontHouseScript;
		}
		else if (Features::FontTypeVectorPosition == 2)
		{
			GUI::TextColorAndFont.f = FontMonospace;
		}
		else if (Features::FontTypeVectorPosition == 3)
		{
			GUI::TextColorAndFont.f = FontWingDings;
		}
		else if (Features::FontTypeVectorPosition == 4)
		{
			GUI::TextColorAndFont.f = FontChaletComprimeCologne;
		}
		else if (Features::FontTypeVectorPosition == 5)
		{
			GUI::TextColorAndFont.f = FontPricedown;
		}
	}
	GUI::Break("Menu", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Disable Open/Close Fade", GUI::DisableMenuGUIOpenCloseFade, "", SELECTABLE_DISABLE_SAVE);
	GUI::Float("X-Axis", GUI::guiX, 0.0f, 0.0f, 0.01f, "", 3, SELECTABLE_DISABLE_SAVE);
	GUI::Float("Y-Axis", GUI::guiY, 0.0f, 0.0f, 0.01f, "", 3, SELECTABLE_DISABLE_SAVE);
	GUI::Float("Width", GUI::guiWidth, 0.20f, 0.30f, 0.01f, "");
	GUI::Float("Selectable Height", GUI::SelectableHeight, 0.035f, 0.045f, 0.001f, "This also slightly stretches the header element as a result of the rescale");
	if (GUI::Option("Reset Position & Width", ""))
	{
		GUI::guiX = GUI::guiX_Default;
		GUI::guiY = GUI::guiY_Default;
		GUI::guiWidth = GUI::guiWidth_Default;
	}
	GUI::Break("Selectable Information Box", SELECTABLE_CENTER_TEXT);
	GUI::Float("X-Axis", GUI::SelectableInfoBoxX, 0.0f, 0.0f, 0.01f, "", 3, SELECTABLE_DISABLE_SAVE);
	GUI::Float("Y-Axis", GUI::SelectableInfoBoxY, 0.0f, 0.0f, 0.01f, "", 3, SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Reset Position", ""))
	{
		GUI::SelectableInfoBoxX = GUI::SelectableInfoBoxX_Default;
		GUI::SelectableInfoBoxY = GUI::SelectableInfoBoxY_Default;
	}
}