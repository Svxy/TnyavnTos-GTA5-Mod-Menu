#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::SelectedPlayer()
{
	GUI::Title(PLAYER::GET_PLAYER_NAME(CheatFeatures::SelectedPlayer));
	GUI::Toggle("Spectate", CheatFeatures::SpectatePlayerBool, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Host Kick", "Kick Selected Player - Host only")) { NETWORK::NETWORK_SESSION_KICK_PLAYER(CheatFeatures::SelectedPlayer); }
	GUI::MenuOption("Teleport", Submenus::SelectedPlayerTeleport);
	GUI::MenuOption("Friendly", Submenus::SelectedPlayerFriendly);
	GUI::MenuOption("Griefing", Submenus::SelectedPlayerGriefing);
	if (GUI::Option("View Social Club Profile", "")) { int playerHandle; NETWORK::NETWORK_HANDLE_FROM_PLAYER(CheatFeatures::SelectedPlayer, &playerHandle, 13); NETWORK::NETWORK_SHOW_PROFILE_UI(&playerHandle); }
}