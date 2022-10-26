#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerGriefing()
{
	GUI::Title("Griefing");
	GUI::MenuOption("Script Events", Submenus::SelectedPlayerRemote);
	GUI::MenuOption("Attachments", Submenus::SelectedPlayerAttachments);
	GUI::Toggle("Explode", CheatFeatures::ExplodeLoopSelectedPlayerBool, "", SELECTABLE_DISABLE_SAVE);
	GUI::Toggle("Freeze", CheatFeatures::FreezeSelectedPlayerBool, "", SELECTABLE_DISABLE_SAVE);
	GUI::Toggle("Shake Camera", CheatFeatures::ShakeCamSelectedPlayerBool, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Set Off Vehicle Alarm", ""))
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer);
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, false))
		{
			GameFunctions::SetOffAlarmPlayerVehicle(Handle);
		}
		else
		{
			GameFunctions::MinimapNotification("~r~Player is not in a vehicle");
		}
	}
	if (GUI::Option("Burst Vehicle Tires", ""))
	{
		Ped PlayerPedHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer);
		if (PED::IS_PED_IN_ANY_VEHICLE(PlayerPedHandle, false))
		{
			::Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_USING(PlayerPedHandle);
			GameFunctions::RequestNetworkControlOfEntity(VehicleHandle);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehicleHandle, true);
			static int tireID = 0;
			for (tireID = 0; tireID < 8; tireID++)
			{
				VEHICLE::SET_VEHICLE_TYRE_BURST(VehicleHandle, tireID, true, 1000.f);
			}
		}
	}
	if (GUI::Option("Airstrike", ""))
	{
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false);
		MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 35.f, Coords.x, Coords.y, Coords.z, 250, true, MISC::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), true, false, 500.f);
	}
	if (GUI::Option("Attach To", ""))
	{
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer) != GameFunctions::PlayerPedID)
		{
			ENTITY::ATTACH_ENTITY_TO_ENTITY(GameFunctions::PlayerPedID, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
		}
	}
	if (GUI::Option("Detach From", ""))
	{
		ENTITY::DETACH_ENTITY(GameFunctions::PlayerPedID, true, true);
	}
	if (GUI::Option("Slingshot Vehicle", ""))
	{
		Ped PedHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer);
		if (PED::IS_PED_IN_ANY_VEHICLE(PedHandle, false))
		{
			::Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, false);
			GameFunctions::RequestNetworkControlOfEntity(VehicleHandle);
			ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
		}
		else
		{
			GameFunctions::MinimapNotification("~r~Player is not in a vehicle");
		}
	}
	if (GUI::Option("Ram With Vehicle", ""))
	{
		Hash model = MISC::GET_HASH_KEY("trophytruck2");
		if (STREAMING::IS_MODEL_VALID(model))
		{
			for (int i = 0; i < 3; i++)
			{
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) { GameHooking::PauseMainFiber(0, false); }
				Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false);
				float forward = 10.f;
				float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer));
				float xVector = forward * sin(GameFunctions::DegreesToRadians(heading)) * -1.f;
				float yVector = forward * cos(GameFunctions::DegreesToRadians(heading));
				::Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x - xVector, ourCoords.y - yVector, ourCoords.z, heading, true, true, false);
				GameFunctions::RequestNetworkControlOfEntity(veh);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 250);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}
		}
	}
	if (GUI::Option("Cage Trap", ""))
	{
		Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false);
		Object obj = OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
	}
	if (GUI::Option("Clone Ped", ""))
	{
		GameFunctions::ClonePed(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer));
	}
	if (GUI::Option("Kick out of vehicle", ""))
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer);
		GameFunctions::RequestNetworkControlOfEntity(playerPed);
		GameFunctions::StopAllPedAnimations(playerPed);
	}
	if (GUI::Option("Blame Kill Everyone", ""))
	{
		PlayersSessionForLoop
		{
			if (GameFunctions::PlayerID != i && CheatFeatures::SelectedPlayer != i)
			{
				FIRE::ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false), 
					29, 1000.f, true, false, 0.f);
			}
		}
	}
	if (GUI::Option("Spawn Enemy", ""))
	{
		int eclone[1000];
		int egcount = 1;
		Ped SelectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer);
		Hash railgun = MISC::GET_HASH_KEY("WEAPON_RAILGUN");
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(SelectedPlayer, false);
		Hash pedm = MISC::GET_HASH_KEY("u_m_m_jesus_01");
		STREAMING::REQUEST_MODEL(pedm);
		while (!STREAMING::HAS_MODEL_LOADED(pedm)) { GameHooking::PauseMainFiber(0); }
		eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
		PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
		WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
		PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
		TASK::TASK_COMBAT_PED(eclone[egcount], SelectedPlayer, 1, 1);
		PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
		PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
		egcount++;
	}
}