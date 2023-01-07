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
void GUI::Submenus::SelectedPlayerApartmentTeleport()
{
	GUI::Title("Teleport to Apartment");
	for (auto& i : game_data::PropertyList)
	{
		if (GUI::Option(i.PropertyName, ""))
		{
			Game::gtao::tse::start_event(Game::gtao::tse::types::PROPERTY_TELEPORT, Features::SelectedPlayer, i.Index);
		}
	}
}