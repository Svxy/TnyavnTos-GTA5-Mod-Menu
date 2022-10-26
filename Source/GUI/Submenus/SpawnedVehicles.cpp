#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::SpawnedVehicles()
{
	GUI::Title("Previously Spawned");
	if (!GameArrays::SpawnedVehicles.empty())
	{
		for (::Vehicle i : GameArrays::SpawnedVehicles)
		{
			if (!ENTITY::DOES_ENTITY_EXIST(i)) { GameArrays::SpawnedVehicles.erase(std::remove(GameArrays::SpawnedVehicles.begin(), GameArrays::SpawnedVehicles.end(), i), GameArrays::SpawnedVehicles.end()); }
			GUI::Break(std::to_string(i), SELECTABLE_CENTER_TEXT);
			if (GUI::Option("Teleport To", ""))
			{
				GameFunctions::TeleportToCoords(GameFunctions::PlayerPedID, ENTITY::GET_ENTITY_COORDS(i, false), false, false);
			}
			if (GUI::Option("Teleport Into Vehicle", ""))
			{
				PED::SET_PED_INTO_VEHICLE(GameFunctions::PlayerPedID, i, -1);
			}
			if (GUI::Option("Repair & Clean Vehicle", ""))
			{
				GameFunctions::RepairAndCleanVehicle(i);
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
		GUI::Break("No Vehicles Were Spawned Yet");
	}
}