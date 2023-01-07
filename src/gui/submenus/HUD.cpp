#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../cheat/file_system.hpp"
#include "../../game/data/game_data.hpp"
#include <ini.h>

using namespace Cheat;
int HUDColorRed, HUDColorGreen, HUDColorBlue;
int HUDColorAlpha = 255;
int SelectedComponent, ResetColorStringVector;
void GUI::Submenus::HUD()
{
	GUI::Title("Head-up Display");
	GUI::Toggle("Disable HUD", Features::DisableHUDBool, "Disables all HUD elements");
	GUI::Toggle("Hide Minimap", Features::HideMinimapBool, "");
	GUI::Break("Color", SELECTABLE_CENTER_TEXT);
	GUI::StringVector("Component", game_data::HUDColors, SelectedComponent, "", SELECTABLE_DISABLE_SAVE);
	GUI::Int("Red", HUDColorRed, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Green", HUDColorGreen, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Blue", HUDColorBlue, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Alpha", HUDColorAlpha, 0, 255, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE);
	if (GUI::Option("Set", ""))
	{
		UI::REPLACE_HUD_COLOUR_WITH_RGBA(SelectedComponent, HUDColorRed, HUDColorGreen, HUDColorBlue, HUDColorAlpha);

		// Write to ini file
		file_system::ini_file::write(std::to_string(HUDColorRed), file_system::paths::HUDColorsFile, game_data::HUDColors[SelectedComponent], "r");
		file_system::ini_file::write(std::to_string(HUDColorGreen), file_system::paths::HUDColorsFile, game_data::HUDColors[SelectedComponent], "g");
		file_system::ini_file::write(std::to_string(HUDColorBlue), file_system::paths::HUDColorsFile, game_data::HUDColors[SelectedComponent], "b");
		file_system::ini_file::write(std::to_string(HUDColorAlpha), file_system::paths::HUDColorsFile, game_data::HUDColors[SelectedComponent], "a");
	}
	if (GUI::StringVector("Reset Color", { "Selected", "All" }, ResetColorStringVector, "", SELECTABLE_DISABLE_SAVE))
	{
		// Set color(s) back to its/their default(s)
		int index = 0;
		for (auto const& data : game_data::DefaultHUDColors)
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
			for (auto const& HUDColorComponentName : game_data::HUDColors)
			{
				if (index == SelectedComponent)
				{
					mINI::INIFile File(file_system::paths::HUDColorsFile);
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
			remove(file_system::paths::HUDColorsFile.c_str());
		}
	}
}