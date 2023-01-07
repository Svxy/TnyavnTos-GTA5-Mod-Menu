#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::SelectedPlayer()
{
	GUI::Title(PLAYER::GET_PLAYER_NAME(Features::SelectedPlayer));
	GUI::Toggle("Spectate", Features::SpectatePlayerBool, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Option("Host Kick", "Kick Selected Player - Host only")) { NETWORK::NETWORK_SESSION_KICK_PLAYER(Features::SelectedPlayer); }
	GUI::MenuOption("Teleport", Submenus::SelectedPlayerTeleport);
	GUI::MenuOption("Friendly", Submenus::SelectedPlayerFriendly);
	GUI::MenuOption("Griefing", Submenus::SelectedPlayerGriefing);
	if (GUI::Option("View Social Club Profile", "")) { int playerHandle; NETWORK::NETWORK_HANDLE_FROM_PLAYER(Features::SelectedPlayer, &playerHandle, 13); NETWORK::NETWORK_SHOW_PROFILE_UI(&playerHandle); }
}