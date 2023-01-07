#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Home()
{
	GUI::Title("Home");
	GUI::MenuOption("Self", Submenus::Self);
	GUI::MenuOption("Weapon", Submenus::Weapon);
	GUI::MenuOption("Vehicle", Submenus::Vehicle);
	GUI::MenuOption("Spawn", Submenus::Spawn);
	GUI::MenuOption("Teleport", Submenus::Teleport);
	GUI::MenuOption("World", Submenus::World);
	GUI::MenuOption("Session", Submenus::Session);
	GUI::MenuOption("Protection", Submenus::Protection);
	GUI::MenuOption("Recovery", Submenus::Recovery, Features::SafeMode ? SELECTABLE_DISABLED : SELECTABLE_DUMMY);
	GUI::MenuOption("Miscellaneous", Submenus::Miscellaneous);
	GUI::MenuOption("Settings", Submenus::Settings);
}