#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../cheat/file_system.hpp"

using namespace Cheat;
void GUI::Submenus::Settings()
{
	GUI::Title("Settings");
	GUI::MenuOption("Theme", Submenus::Theme);
	GUI::MenuOption("Hide Elements", Submenus::HideElements);
	GUI::Int("Max Visible Menu Selectables", GUI::maxVisOptions, 5, 16, 1, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Toggle("Restore To Previous Submenu", GUI::RestorePreviousSubmenu, "When opening restores to previous submenu");
	GUI::Break("Keys", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Menu GUI: ~c~" + gui_controls::VirtualKeyCodeToString(gui_controls::OpenMenuGUIKey), "Select to change"))
	{
		int PressedKey = gui_controls::WaitForAndReturnPressedKey();
		if (PressedKey != 0)
		{
			gui_controls::OpenMenuGUIKey = PressedKey;
			file_system::ini_file::write(std::to_string(PressedKey), file_system::paths::ConfigFile, "submenu_settings", "Menu GUI Key");
			Game::notification::Minimap((char*)"Menu GUI key has been set");
		}
	}
	if (GUI::Option("Cursor Navigation: ~c~" + gui_controls::VirtualKeyCodeToString(gui_controls::CursorNavigationKey), "Select to change"))
	{
		int PressedKey = gui_controls::WaitForAndReturnPressedKey();
		if (PressedKey != 0)
		{
			gui_controls::CursorNavigationKey = PressedKey;
			file_system::ini_file::write(std::to_string(PressedKey), file_system::paths::ConfigFile, "submenu_settings", "Cursor Navigation Key");
			Game::notification::Minimap((char*)"Cursor Navigation key has been set");
		}
	}
	if (GUI::Option("Save Selectable: ~c~" + gui_controls::VirtualKeyCodeToString(gui_controls::SaveSelectableKey), "Select to change"))
	{
		int PressedKey = gui_controls::WaitForAndReturnPressedKey();
		if (PressedKey != 0)
		{
			gui_controls::SaveSelectableKey = PressedKey;
			file_system::ini_file::write(std::to_string(PressedKey), file_system::paths::ConfigFile, "submenu_settings", "Save Selectable Key");
			Game::notification::Minimap((char*)"Cursor Navigation key has been set");
		}
	}
	GUI::Int("Key Press Delay", gui_controls::KeyPressDelay, 1, 250, 5, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Menu Arrow Animation Delay", GUI::MenuArrowAnimationDelay, 250, 2500, 25, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Toggle("Gameplay While Cursor Is Active", gui_controls::AllowGameplayWithCursorNavigationActive, "");
	GUI::Toggle("Safe Mode", Features::SafeMode, "This must be disabled to use potentially detected features");
	GUI::Toggle("Disable Cursor When Menu Gets Closed", gui_controls::DisableCursorNavigationWhenMenuGUIIsClosed, "");
	GUI::Toggle("Do not overwrite \"Textures.ytd\" at init", Features::NoTextureFileOverwrite, "Prevents the texture file from being ovewritten so you can use your own instead");
	GUI::MenuOption("About", Submenus::About);
}