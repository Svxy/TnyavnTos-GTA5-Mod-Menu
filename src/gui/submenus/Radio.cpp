#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Radio()
{
	GUI::Title("Radio");
	if (GUI::Option("Skip Track", "")) { AUDIO::SKIP_RADIO_FORWARD(); }
	GUI::Toggle("Freeze Station", Features::FreezeStationBool, "");
	GUI::Toggle("Mobile Radio", Features::MobileRadioBool, "");
}