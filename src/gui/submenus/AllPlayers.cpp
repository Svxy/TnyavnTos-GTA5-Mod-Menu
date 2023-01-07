#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::AllPlayers()
{
	GUI::Title("All Players");
	GUI::MenuOption("Exclusions", AllPlayersExclusions);
	GUI::Break("Friendly", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Give All Weapons", "Give all players all weapons"))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = PLAYER::PLAYER_ID() == i && Features::AllPlayersExclusionsSelf;
			bool ExcludeFriend = Game::gtao::is_friend(i) && Features::AllPlayersExclusionsFriends;
			bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && Features::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Game::notification::Subtitle((char*)"Giving all weapons to all players in session, one moment", 2000);
				Game::weapon::give_all(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
			}
		}
	}
	GUI::Break("Griefing", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Teleport to Eclipse Tower", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = PLAYER::PLAYER_ID() == i && Features::AllPlayersExclusionsSelf;
		bool ExcludeFriend = Game::gtao::is_friend(i) && Features::AllPlayersExclusionsFriends;
		bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && Features::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Game::gtao::tse::start_event(Game::gtao::tse::types::PROPERTY_TELEPORT, i, 1);
			}
		}
	}
	GUI::Toggle("Freeze", Features::FreezeAllPlayersBool, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Kick Out Of Vehicle", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = PLAYER::PLAYER_ID() == i && Features::AllPlayersExclusionsSelf;
		bool ExcludeFriend = Game::gtao::is_friend(i) && Features::AllPlayersExclusionsFriends;
		bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && Features::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Game::entity::request_network_control(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				TASK::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				TASK::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
			}
		}
	}
	if (GUI::Option("Airstrike", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = PLAYER::PLAYER_ID() == i && Features::AllPlayersExclusionsSelf;
		bool ExcludeFriend = Game::gtao::is_friend(i) && Features::AllPlayersExclusionsFriends;
		bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && Features::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);

				// VEHICLE_WEAPON_SPACE_ROCKET
				MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 35.f, Coords.x, Coords.y, Coords.z, 250, true, 0xF8A3939F, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), true, false, 500.f);
			}
		}
	}
	if (GUI::Option("Trap", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = PLAYER::PLAYER_ID() == i && Features::AllPlayersExclusionsSelf;
			bool ExcludeFriend = Game::gtao::is_friend(i) && Features::AllPlayersExclusionsFriends;
			bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && Features::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				// prop_gold_cont_01
				OBJECT::CREATE_OBJECT(0x392D62AA, remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
			}
		}
	}
	if (GUI::Option("Attach Beach Fire", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = PLAYER::PLAYER_ID() == i && Features::AllPlayersExclusionsSelf;
			bool ExcludeFriend = Game::gtao::is_friend(i) && Features::AllPlayersExclusionsFriends;
			bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && Features::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Game::entity::attach_to_entity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0xC079B265); // prop_beach_fire
			}
		}
	}
	GUI::Break("Miscellaneous", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Host Kick", "Kick all players from session"))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = PLAYER::PLAYER_ID() == i && Features::AllPlayersExclusionsSelf;
			bool ExcludeFriend = Game::gtao::is_friend(i) && Features::AllPlayersExclusionsFriends;
			bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && Features::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				NETWORK::NETWORK_SESSION_KICK_PLAYER(i);
			}
		}
	}
}