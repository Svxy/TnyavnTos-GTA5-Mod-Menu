#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerRemote()
{
	GUI::Title("Script Events");
	if (GUI::Option("Kick To Single Player", ""))
	{
		Game::gtao::tse::start_event(Game::gtao::tse::types::KICK_TO_SINGLE_PLAYER, Features::SelectedPlayer);
	}
	if (GUI::Option("Force Into Mission", ""))
	{
		Game::gtao::tse::start_event(Game::gtao::tse::types::FORCE_INTO_MISSION, Features::SelectedPlayer);
	}
	GUI::Break("Teleport", SELECTABLE_CENTER_TEXT);
	GUI::MenuOption("Apartment", SelectedPlayerApartmentTeleport);
	if (GUI::Option("Cayo Perico Island", ""))
	{
		Game::gtao::tse::start_event(Game::gtao::tse::types::CAYO_PERICO_TELEPORT, Features::SelectedPlayer);
	}
}