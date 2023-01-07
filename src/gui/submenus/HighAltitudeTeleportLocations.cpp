#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/data/game_data.hpp"

using namespace Cheat;
void GUI::Submenus::HighAltitudeTeleportLocations()
{
	GUI::Title("High Altitude");
	Game::ShowTeleportLocationsMenu(game_data::TeleportLocationsHighAltitude);
}