#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerTeleport()
{
	GUI::Title("Teleport");
	if (GUI::Option("Parachute To", ""))
	{
		int TimeoutTick = 0;
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 0, false, true);
		Vector3 TargetCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false);
		TargetCoords.z += 50.f;
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), TargetCoords, false, true);
		while (PED::GET_PED_PARACHUTE_STATE(PLAYER::PLAYER_PED_ID()) != 0)
		{
			TimeoutTick++;
			GameHooking::PauseMainFiber(0, false);
			if (TimeoutTick >= 500)
			{
				break;
			}
		}
		PED::FORCE_PED_TO_OPEN_PARACHUTE(PLAYER::PLAYER_PED_ID());
	}
	if (GUI::Option("Teleport To", ""))
	{
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false),
			false, false);
	}
	if (GUI::Option("Teleport Into Vehicle", "Teleport into Selected Player vehicle"))
	{
		::Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false);
		for (int i = -1; i < 16; i++) { if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i, false)) { PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, i); } }
	}
}