#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Spawn()
{
	GUI::Title("Spawn");
	GUI::MenuOption("Ped", Submenus::PedSpawn);
	GUI::MenuOption("Vehicle", Submenus::VehicleSpawn);
	//GUI::MenuOption("Object", ObjectSpawnMenu); TODO
}