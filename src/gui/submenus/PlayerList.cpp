#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::PlayerList()
{
	GUI::Title("Players");
	PlayersSessionForLoop
	{
		if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
		{
			GUI::MenuOptionPlayerList(i) ? Features::SelectedPlayer = i : NULL;
			if (GUI::currentOption == GUI::optionCount) 
			{
				GUI::ShowPlayerInformationBox(i);
			}
		}
	}
}