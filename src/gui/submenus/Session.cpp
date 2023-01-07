#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Session()
{
	GUI::Title("Session");
	GUI::MenuOption("Players", Submenus::PlayerList);
	GUI::MenuOption("All Players", Submenus::AllPlayers);
	GUI::MenuOption("Session Starter", Submenus::SessionStarter);
}