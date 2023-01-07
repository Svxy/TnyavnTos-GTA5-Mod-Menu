#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/notification.hpp"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerGriefing()
{
	GUI::Title("Griefing");
	GUI::MenuOption("Script Events", Submenus::SelectedPlayerRemote);
	GUI::MenuOption("Attachments", Submenus::SelectedPlayerAttachments);
	GUI::Toggle("Explode", Features::ExplodeLoopSelectedPlayerBool, "", SELECTABLE_DISABLE_SAVE);
	GUI::Toggle("Freeze", Features::FreezeSelectedPlayerBool, "", SELECTABLE_DISABLE_SAVE);
	GUI::Toggle("Shake Camera", Features::ShakeCamSelectedPlayerBool, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Set Off Vehicle Alarm", ""))
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false))
		{
			::Vehicle selectedVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer));
			Game::entity::request_network_control(selectedVehicle);
			VEHICLE::SET_VEHICLE_ALARM(selectedVehicle, true);
			VEHICLE::START_VEHICLE_ALARM(selectedVehicle);
		}
	}
	if (GUI::Option("Burst Vehicle Tires", ""))
	{
		Ped PlayerPedHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer);
		if (PED::IS_PED_IN_ANY_VEHICLE(PlayerPedHandle, false))
		{
			::Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_USING(PlayerPedHandle);
			Game::entity::request_network_control(VehicleHandle);
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
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false);
		MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 35.f, Coords.x, Coords.y, Coords.z, 250, true, MISC::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), true, false, 500.f);
	}
	if (GUI::Option("Attach To", ""))
	{
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer) != PLAYER::PLAYER_PED_ID())
		{
			ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
		}
	}
	if (GUI::Option("Detach From", ""))
	{
		ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
	}
	if (GUI::Option("Slingshot Vehicle", ""))
	{
		Ped PedHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer);
		if (PED::IS_PED_IN_ANY_VEHICLE(PedHandle, false))
		{
			::Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, false);
			Game::entity::request_network_control(VehicleHandle);
			ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
		}
		else
		{
			Game::notification::Minimap((char*)"~r~Player is not in a vehicle");
		}
	}
	if (GUI::Option("Trap", ""))
	{
		Vector3 Target = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false);
		
		STREAMING::REQUEST_MODEL(0x392D62AA);
		while (!STREAMING::HAS_MODEL_LOADED(0x392D62AA))
			GameHooking::PauseMainFiber(0);
		
		if (OBJECT::CREATE_OBJECT(0x392D62AA, Target.x, Target.y, Target.z - 1.f, true, false, false))
			Game::notification::Minimap((char*)"Trapped!");

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x392D62AA);
	}
	if (GUI::Option("Clone", ""))
	{
		Ped Target = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer);
		Ped Clone = PED::CLONE_PED(Target, ENTITY::GET_ENTITY_HEADING(Target), true, true);
		if (Clone)
		{
			PED::SET_PED_FLEE_ATTRIBUTES(Clone, 0, true);
			PED::SET_PED_AS_ENEMY(Clone, true);
			ENTITY::SET_ENTITY_INVINCIBLE(Clone, false);
		}
	}
	if (GUI::Option("Kick out of vehicle", ""))
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer);
		Game::entity::request_network_control(playerPed);
		TASK::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
	}
	if (GUI::Option("Spawn Enemy", ""))
	{
		int eclone[1000];
		int egcount = 1;
		Ped SelectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer);
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
		PED::SET_PED_ALERTNESS(eclone[egcount], 3);
		PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
		egcount++;
	}
}