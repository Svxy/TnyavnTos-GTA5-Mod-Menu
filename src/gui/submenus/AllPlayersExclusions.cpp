#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::AllPlayersExclusions()
{
	GUI::Title("Exclusions");
	GUI::Toggle("Exclude Self", Features::AllPlayersExclusionsSelf, "");
	GUI::Toggle("Exclude Friends", Features::AllPlayersExclusionsFriends, "");
	GUI::Toggle("Exclude Host", Features::AllPlayersExclusionsHost, "");
}