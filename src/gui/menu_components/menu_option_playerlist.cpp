#include "../../cheat/fibermain.hpp"
#include "../../hooking/globalhandle.hpp"
#include "../../hooking/offsets.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;

bool GUI::MenuOptionPlayerList(Player Player)
{
	bool IsLocalPlayer = PLAYER::PLAYER_ID() == Player;
	std::string PlayerName = PLAYER::GET_PLAYER_NAME(Player);
	PlayerName = PLAYER::PLAYER_ID() == Player ? "~g~YOU~w~ (" + PlayerName + ")" : PlayerName;

	// Append player tags
	if (Game::gtao::is_freemode_script_host(Player)) { PlayerName.append(" ~o~[HOST]"); }
	if (Game::gtao::is_friend(Player)) { PlayerName.append(" ~b~[FRIEND]"); }
	if (Game::entity::is_in_interior(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Player))) { PlayerName.append(" ~p~[INTERIOR]"); }

	// Get player picture texture string
	std::string CurrentOnlinePlayerPictureName = "CHAR_DEFAULT";
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int Index = GLOBAL_PLAYER_PICTURE_INDEX + 2;
		for (int x = 0; x <= 150; x += 5)
		{
			int playerId = globalHandle(Index).At(x).As<int>();
			if (playerId == Player)
			{
				int PedHeadshotHandle = globalHandle(Index).At(x).At(1).As<int>();
				if (PED::IS_PEDHEADSHOT_VALID(PedHeadshotHandle))
				{
					CurrentOnlinePlayerPictureName = PED::GET_PEDHEADSHOT_TXD_STRING(PedHeadshotHandle);
				}
			}
			if (playerId == -1)
			{
				break;
			}
		}
	}
	
	// Draw selectable
	if (Option(PlayerName, "", SELECTABLE_HIDE_INFO_BOX | SELECTABLE_PLAYER_LIST))
	{
		GUI::MoveMenu(Submenus::SelectedPlayer);
		return true;
	}

	// Determine player picture position
	Vector2 Position;
	bool Set = false;
	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		Position = { GUI::guiX - (GUI::guiWidth * 45 / 100), GUI::guiY + (GUI::optionCount * SelectableHeight - 0.158f) };
		Set = true;
	}
	else if (GUI::optionCount > GUI::currentOption - GUI::maxVisOptions && GUI::optionCount <= GUI::currentOption)
	{
		Position = { GUI::guiX - (GUI::guiWidth * 45 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.158f };
		Set = true;
	}

	// Only draw if a valid position has been determined
	if (Set)
		DrawSpriteInGame(IsLocalPlayer ? "Textures" : CurrentOnlinePlayerPictureName, IsLocalPlayer ? "AdvancedNotificationImage" : CurrentOnlinePlayerPictureName, Position.x, Position.y, 0.023f, 0.035f, 0.f, 255, 255, 255, OnlinePlayerPictureTransparency);
	
	return false;
}