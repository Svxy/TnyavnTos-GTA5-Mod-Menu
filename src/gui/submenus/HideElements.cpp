#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::HideElements()
{
	GUI::Title("Hide Elements");
	GUI::Toggle("Selectable Information Box", Cheat::Features::HideSelectableInformationBox, "");
	GUI::Toggle("Player Information Box", Features::HidePlayerInformationBox, "");
	GUI::Toggle("Vehicle Preview", Features::HideVehiclePreview, "");
	GUI::Toggle("Own/local IP Address", Features::HideOwnIPAddress, "");
}