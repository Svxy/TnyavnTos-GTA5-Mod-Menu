#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Settings()
{
	GUI::Title("Settings");
	GUI::MenuOption("Theme", Submenus::Theme);
	GUI::MenuOption("Hide Elements", Submenus::HideElements);
	GUI::Int("Max Visible Menu Options", GUI::maxVisOptions, 5, 16, 1, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Toggle("Restore To Previous Submenu", GUI::RestorePreviousSubmenu, "When opening restores previous submenu");
	GUI::Break("Keys", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Menu GUI: ~c~" + CheatFunctions::VirtualKeyCodeToString(Controls::OpenMenuGUIKey), "Select to change"))
	{
		int PressedKey = CheatFunctions::WaitForAndReturnPressedKey();
		if (PressedKey != 0)
		{
			Controls::OpenMenuGUIKey = PressedKey;
			CheatFunctions::IniFileWriteString(std::to_string(PressedKey), CheatFunctions::ReturnConfigFilePath(), "submenu_settings", "Menu GUI Key");
			GameFunctions::MinimapNotification("Menu GUI key has been set");
		}
	}
	if (GUI::Option("Cursor Navigation: ~c~" + CheatFunctions::VirtualKeyCodeToString(Controls::CursorNavigationKey), "Select to change"))
	{
		int PressedKey = CheatFunctions::WaitForAndReturnPressedKey();
		if (PressedKey != 0)
		{
			Controls::CursorNavigationKey = PressedKey;
			CheatFunctions::IniFileWriteString(std::to_string(PressedKey), CheatFunctions::ReturnConfigFilePath(), "submenu_settings", "Cursor Navigation Key");
			GameFunctions::MinimapNotification("Cursor Navigation key has been set");
		}
	}
	if (GUI::Option("Save Selectable: ~c~" + CheatFunctions::VirtualKeyCodeToString(Controls::SaveSelectableKey), "Select to change"))
	{
		int PressedKey = CheatFunctions::WaitForAndReturnPressedKey();
		if (PressedKey != 0)
		{
			Controls::SaveSelectableKey = PressedKey;
			CheatFunctions::IniFileWriteString(std::to_string(PressedKey), CheatFunctions::ReturnConfigFilePath(), "submenu_settings", "Save Selectable Key");
			GameFunctions::MinimapNotification("Cursor Navigation key has been set");
		}
	}
	GUI::Int("Key Press Delay", Controls::KeyPressDelay, 1, 250, 5, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Menu Arrow Animation Delay", GUI::MenuArrowAnimationDelay, 250, 2500, 25, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Toggle("Gameplay While Cursor Is Active", Controls::AllowGameplayWithCursorNavigationActive, "");
	GUI::Toggle("Disable Cursor When Menu Gets Closed", Controls::DisableCursorNavigationWhenMenuGUIIsClosed, "");
	GUI::Toggle("Do not overwrite \"Textures.ytd\" at init", CheatFeatures::NoTextureFileOverwrite, "Prevents the texture file from being ovewritten so you can use your own instead");
	GUI::MenuOption("About", Submenus::About);
}