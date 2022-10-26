#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Theme()
{
	GUI::Title("Theme");
	GUI::MenuOption("Saved Themes", Submenus::ThemeFiles);
	if (!GUI::CurrentTheme.empty())
	{
		GUI::Break("Loaded Theme: ~c~" + GUI::CurrentTheme);
		if (GUI::Option("Save To Current Theme", ""))
		{
			GUI::SaveTheme(GUI::CurrentTheme);
		}
		if (GUI::Option("Delete Theme", "Delete loaded theme"))
		{
			GUI::DeleteLoadedTheme();
		}
	}
	else
	{
		GUI::Break("Loaded Theme: ~c~None");
	}
	if (GUI::Option("Save To New", ""))
	{
		const char* NewThemeFileName;
		if (GameFunctions::DisplayKeyboardAndReturnInput(20, "Enter Theme Name", NewThemeFileName))
		{
			GUI::SaveTheme(NewThemeFileName);
		}
	}
	GUI::Break("Header", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Texture", GUI::ShowHeaderTexture, "", SELECTABLE_DISABLE_SAVE);
	GUI::Toggle("Background", GUI::ShowHeaderBackground, "", SELECTABLE_DISABLE_SAVE);
	GUI::Break("Color", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("RGB Disco", CheatFeatures::RGBDiscoBool, "It's party time!", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Primary", "Save is disabled while RGB Disco is enabled", CheatFeatures::RGBDiscoBool ? SELECTABLE_DISABLED : SELECTABLE_DUMMY))
	{
		int Red, Green, Blue;
		bool Canceled = false;
		if (GameFunctions::DisplayKeyboardAndReturnInputInteger(3, "Enter R-color", Red))
		{
			GUI::PrimaryColor.r = Red;
		}
		else { Canceled = true; }
		if (GameFunctions::DisplayKeyboardAndReturnInputInteger(3, "Enter G-color", Green) && !Canceled)
		{
			GUI::PrimaryColor.g = Green;
		}
		else { Canceled = true; }
		if (GameFunctions::DisplayKeyboardAndReturnInputInteger(3, "Enter B-color", Blue) && !Canceled)
		{
			GUI::PrimaryColor.b = Blue;
		}
		else { Canceled = true; }
		if (!Canceled)
		{
			GameFunctions::MinimapNotification("Updated Primary Color");
		}
		else
		{
			GameFunctions::MinimapNotification("Canceled Updating Primary Color");
		}
	}
	if (GUI::Option("Text", "Save is disabled while RGB Disco is enabled", CheatFeatures::RGBDiscoBool ? SELECTABLE_DISABLED : SELECTABLE_DUMMY))
	{
		int Red, Green, Blue;
		bool Canceled = false;
		if (GameFunctions::DisplayKeyboardAndReturnInputInteger(3, "Enter R-color", Red))
		{
			GUI::TextColorAndFont.r = Red;
		}
		else { Canceled = true; }
		if (GameFunctions::DisplayKeyboardAndReturnInputInteger(3, "Enter G-color", Green) && !Canceled)
		{
			GUI::TextColorAndFont.g = Green;
		}
		else { Canceled = true; }
		if (GameFunctions::DisplayKeyboardAndReturnInputInteger(3, "Enter B-color", Blue) && !Canceled)
		{
			GUI::TextColorAndFont.b = Blue;
		}
		else { Canceled = true; }
		if (!Canceled)
		{
			GameFunctions::MinimapNotification("Updated Text Color");
		}
		else
		{
			GameFunctions::MinimapNotification("Canceled Updating Text Color");
		}
	}
	GUI::Break("Font", SELECTABLE_CENTER_TEXT);
	if (GUI::StringVector("Type", { "Chalet London", "House Script", "Monospace", "Wing Dings", "Chalet Comprime Cologne", "Pricedown" }, CheatFeatures::FontTypeVectorPosition, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		if (CheatFeatures::FontTypeVectorPosition == 0)
		{
			GUI::TextColorAndFont.f = FontChaletLondon;
		}
		else if (CheatFeatures::FontTypeVectorPosition == 1)
		{
			GUI::TextColorAndFont.f = FontHouseScript;
		}
		else if (CheatFeatures::FontTypeVectorPosition == 2)
		{
			GUI::TextColorAndFont.f = FontMonospace;
		}
		else if (CheatFeatures::FontTypeVectorPosition == 3)
		{
			GUI::TextColorAndFont.f = FontWingDings;
		}
		else if (CheatFeatures::FontTypeVectorPosition == 4)
		{
			GUI::TextColorAndFont.f = FontChaletComprimeCologne;
		}
		else if (CheatFeatures::FontTypeVectorPosition == 5)
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