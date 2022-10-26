#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int HUDColorRed, HUDColorGreen, HUDColorBlue;
int HUDColorAlpha = 255;
int SelectedComponent, ResetColorStringVector;
void GUI::Submenus::HUD()
{
	GUI::Title("Head-up Display");
	GUI::Toggle("Disable HUD", CheatFeatures::DisableHUDBool, "Disables all HUD elements");
	GUI::Toggle("Hide Minimap", CheatFeatures::HideMinimapBool, "");
	GUI::Break("Color", SELECTABLE_CENTER_TEXT);
	GUI::StringVector("Component", GameArrays::HUDColors, SelectedComponent, "", SELECTABLE_DISABLE_SAVE);
	GUI::Int("Red", HUDColorRed, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Green", HUDColorGreen, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Blue", HUDColorBlue, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Alpha", HUDColorAlpha, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	if (GUI::Option("Set", ""))
	{
		UI::REPLACE_HUD_COLOUR_WITH_RGBA(SelectedComponent, HUDColorRed, HUDColorGreen, HUDColorBlue, HUDColorAlpha);

		// Write to ini file
		CheatFunctions::IniFileWriteString(std::to_string(HUDColorRed), CheatFunctions::ReturnHUDColorsFilePath(), GameArrays::HUDColors[SelectedComponent], "r");
		CheatFunctions::IniFileWriteString(std::to_string(HUDColorGreen), CheatFunctions::ReturnHUDColorsFilePath(), GameArrays::HUDColors[SelectedComponent], "g");
		CheatFunctions::IniFileWriteString(std::to_string(HUDColorBlue), CheatFunctions::ReturnHUDColorsFilePath(), GameArrays::HUDColors[SelectedComponent], "b");
		CheatFunctions::IniFileWriteString(std::to_string(HUDColorAlpha), CheatFunctions::ReturnHUDColorsFilePath(), GameArrays::HUDColors[SelectedComponent], "a");
	}
	if (GUI::StringVector("Reset Color", { "Selected", "All" }, ResetColorStringVector, "", SELECTABLE_DISABLE_SAVE))
	{
		// Set color(s) back to its/their default(s)
		int index = 0;
		for (auto const& data : GameArrays::DefaultHUDColors)
		{
			if (ResetColorStringVector == 0 && index == SelectedComponent || ResetColorStringVector == 1)
			{
				UI::REPLACE_HUD_COLOUR_WITH_RGBA(index, data.R, data.G, data.B, data.A);
			}			
			index++;
		}

		// Remove data from the HUDColors.ini file
		if (ResetColorStringVector == 0)
		{
			int index = 0;
			for (auto const& HUDColorComponentName : GameArrays::HUDColors)
			{
				if (index == SelectedComponent)
				{
					mINI::INIFile File(CheatFunctions::ReturnHUDColorsFilePath());
					mINI::INIStructure IniStruct;
					File.read(IniStruct);
					IniStruct.remove(HUDColorComponentName);
					File.write(IniStruct);
				}
				index++;
			}
		}
		else
		{
			// No need to remove specific ini sections, just delete the whole file
			remove(CheatFunctions::ReturnHUDColorsFilePath().c_str());
		}
	}
}