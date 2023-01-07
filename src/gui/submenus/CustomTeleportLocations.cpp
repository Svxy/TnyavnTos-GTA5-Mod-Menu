#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../cheat/file_system.hpp"
#include "../../game/features/custom_teleport_locations.hpp"

using namespace Cheat;
mINI::INIFile File(file_system::paths::CusTelLocFile);
mINI::INIStructure StructData;
void GUI::Submenus::CustomTeleportLocations()
{
	GUI::Title("Custom Teleport Locations");
	File.read(StructData);
	if (std::filesystem::exists(file_system::paths::CusTelLocFile) && StructData.size() > 0)
	{
		for (auto const& it : StructData)
		{
			Vector3 Coordinates;
			try
			{
				Coordinates.x = std::stof(it.second.get("x"));
				Coordinates.y = std::stof(it.second.get("y"));
				Coordinates.z = std::stof(it.second.get("z"));
			}
			catch (...) {}

			GUI::Break(it.first, SELECTABLE_CENTER_TEXT);
			if (GUI::Option("Teleport To", ""))
			{
				Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coordinates, false, false);
			}
			if (GUI::Option("Remove", ""))
			{
				Features::custom_tel_locations::Remove(it.first);
			}
		}
	}
	else
	{
		GUI::Break("No custom locations have been saved");
	}
}