#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerTeleport()
{
	GUI::Title("Teleport");
	if (GUI::Option("Parachute To", ""))
	{
		int TimeoutTick = 0;
		WEAPON::GIVE_WEAPON_TO_PED(GameFunctions::PlayerPedID, 0xFBAB5776, 0, false, true);
		Vector3 TargetCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false);
		TargetCoords.z += 50.f;
		GameFunctions::TeleportToCoords(GameFunctions::PlayerPedID, TargetCoords, false, true);
		while (PED::GET_PED_PARACHUTE_STATE(GameFunctions::PlayerPedID) != 0)
		{
			TimeoutTick++;
			GameHooking::PauseMainFiber(0, false);
			if (TimeoutTick >= 500)
			{
				break;
			}
		}
		PED::FORCE_PED_TO_OPEN_PARACHUTE(GameFunctions::PlayerPedID);
	}
	if (GUI::Option("Teleport To", ""))
	{
		GameFunctions::TeleportToCoords(GameFunctions::PlayerPedID, ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false),
			false, false);
	}
	if (GUI::Option("Teleport Into Vehicle", "Teleport into Selected Player vehicle"))
	{
		::Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false);
		for (int i = -1; i < 16; i++) { if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i, false)) { PED::SET_PED_INTO_VEHICLE(GameFunctions::PlayerPedID, veh, i); } }
	}
}