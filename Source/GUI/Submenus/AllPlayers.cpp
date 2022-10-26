#include "../Header/Cheat Functions/FiberMain.h"

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
			bool ExcludeSelf = GameFunctions::PlayerID == i && CheatFeatures::AllPlayersExclusionsSelf;
			bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && CheatFeatures::AllPlayersExclusionsFriends;
			bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && CheatFeatures::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				GameFunctions::SubtitleNotification("Giving all weapons to all players in session, one moment", 2000);
				GameFunctions::GiveAllWeaponsToPlayer(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
			}
		}
	}
	GUI::Break("Griefing", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Teleport to Eclipse Tower", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = GameFunctions::PlayerID == i && CheatFeatures::AllPlayersExclusionsSelf;
			bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && CheatFeatures::AllPlayersExclusionsFriends;
			bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && CheatFeatures::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				GameFunctions::TriggerScriptEvent(eScriptEventTypes::PROPERTY_TELEPORT, i, 1);
			}
		}
	}
	GUI::Toggle("Freeze", CheatFeatures::FreezeAllPlayersBool, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Kick Out Of Vehicle", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = GameFunctions::PlayerID == i && CheatFeatures::AllPlayersExclusionsSelf;
			bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && CheatFeatures::AllPlayersExclusionsFriends;
			bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && CheatFeatures::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				GameFunctions::RequestNetworkControlOfEntity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				GameFunctions::StopAllPedAnimations(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				TASK::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				TASK::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
			}
		}
	}
	if (GUI::Option("Airstrike", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = GameFunctions::PlayerID == i && CheatFeatures::AllPlayersExclusionsSelf;
			bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && CheatFeatures::AllPlayersExclusionsFriends;
			bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && CheatFeatures::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 35.f, Coords.x, Coords.y, Coords.z, 250, true, MISC::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), true, false, 500.f);
			}
		}
	}
	if (GUI::Option("Trap", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = GameFunctions::PlayerID == i && CheatFeatures::AllPlayersExclusionsSelf;
			bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && CheatFeatures::AllPlayersExclusionsFriends;
			bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && CheatFeatures::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
			}
		}
	}
	if (GUI::Option("Attach Beach Fire", ""))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = GameFunctions::PlayerID == i && CheatFeatures::AllPlayersExclusionsSelf;
			bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && CheatFeatures::AllPlayersExclusionsFriends;
			bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && CheatFeatures::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				GameFunctions::AttachObjectToPed(i, "prop_beach_fire");
			}
		}
	}
	GUI::Break("Miscellaneous", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Host Kick", "Kick all players from session"))
	{
		PlayersSessionForLoop
		{
			bool ExcludeSelf = GameFunctions::PlayerID == i && CheatFeatures::AllPlayersExclusionsSelf;
			bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && CheatFeatures::AllPlayersExclusionsFriends;
			bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && CheatFeatures::AllPlayersExclusionsHost;

			if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				NETWORK::NETWORK_SESSION_KICK_PLAYER(i);
			}
		}
	}
}