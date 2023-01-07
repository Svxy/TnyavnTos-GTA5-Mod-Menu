#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/game.hpp"

using namespace Cheat;
void GUI::Submenus::SpawnedVehicles()
{
	GUI::Title("Previously Spawned");
	if (!Game::vehicle::previously_spawned.empty())
	{
		for (::Vehicle i : Game::vehicle::previously_spawned)
		{
			if (!ENTITY::DOES_ENTITY_EXIST(i)) 
				Game::vehicle::previously_spawned.erase(std::remove(Game::vehicle::previously_spawned.begin(), Game::vehicle::previously_spawned.end(), i), Game::vehicle::previously_spawned.end()); 
			
			GUI::Break(std::to_string(i), SELECTABLE_CENTER_TEXT);
			if (GUI::Option("Teleport To", ""))
			{
				Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_COORDS(i, false), false, false);
			}
			if (GUI::Option("Teleport Into Vehicle", ""))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), i, -1);
			}
			if (GUI::Option("Repair", ""))
			{
				Game::vehicle::repair(i);
			}
			if (GUI::Option("Clean", ""))
			{
				Game::vehicle::clean(i);
			}
			if (GUI::Option("Delete", ""))
			{
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(i, true, true);
				VEHICLE::DELETE_VEHICLE(&i);
			}
		}
	}
	else
	{
		GUI::Break("No vehicles have been spawned");
	}
}