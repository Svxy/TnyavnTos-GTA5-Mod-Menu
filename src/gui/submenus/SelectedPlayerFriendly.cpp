#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerFriendly()
{
	GUI::Title("Friendly");
	if (GUI::Option("Give All Weapons", "")) { Game::weapon::give_all(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer)); }
	if (GUI::Option("Copy Outfit", "")) 
	{
		if (Features::SelectedPlayer != PLAYER::PLAYER_ID())
		{
			Ped SelectedPlayerPedHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer);
			for (int i = 0; i < 12; i++)
			{
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), i, PED::GET_PED_DRAWABLE_VARIATION(SelectedPlayerPedHandle, i), PED::GET_PED_TEXTURE_VARIATION(SelectedPlayerPedHandle, i), PED::GET_PED_PALETTE_VARIATION(SelectedPlayerPedHandle, i));
			}
		}
	}
	if (GUI::Option("Set Waypoint", "Sets waypoint to Selected player location"))
	{
		Vector3 TargetCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false);
		UI::SET_NEW_WAYPOINT(TargetCoords.x, TargetCoords.y);
	}
	if (GUI::Option("Spawn Bodyguard", ""))
	{
		int clone[1000];
		int gcount = 1;
		Ped SelectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer);
		if (!ENTITY::DOES_ENTITY_EXIST(SelectedPlayer)) return;
		Hash railgun = MISC::GET_HASH_KEY("WEAPON_RAILGUN");
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(SelectedPlayer, false);
		Hash pedm = MISC::GET_HASH_KEY("u_m_m_jesus_01");
		STREAMING::REQUEST_MODEL(pedm);
		while (!STREAMING::HAS_MODEL_LOADED(pedm)) { GameHooking::PauseMainFiber(0); }
		int my_group = PLAYER::GET_PLAYER_GROUP(SelectedPlayer);
		clone[gcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
		PED::SET_PED_AS_GROUP_LEADER(SelectedPlayer, my_group);
		PED::SET_PED_AS_GROUP_MEMBER(clone[gcount], my_group);
		PED::SET_PED_NEVER_LEAVES_GROUP(clone[gcount], my_group);
		ENTITY::SET_ENTITY_INVINCIBLE(clone[gcount], false);
		PED::SET_PED_COMBAT_ABILITY(clone[gcount], 100);
		WEAPON::GIVE_WEAPON_TO_PED(clone[gcount], railgun, railgun, 9999, 9999);
		PED::SET_PED_CAN_SWITCH_WEAPON(clone[gcount], true);
		PED::SET_GROUP_FORMATION(my_group, 3);
		PED::SET_PED_MAX_HEALTH(clone[gcount], 5000);
		gcount++;
	}
}