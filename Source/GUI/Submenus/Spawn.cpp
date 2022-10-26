#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Spawn()
{
	GUI::Title("Spawn");
	GUI::MenuOption("Ped", Submenus::PedSpawn);
	GUI::MenuOption("Vehicle", Submenus::VehicleSpawn);
	//GUI::MenuOption("Object", ObjectSpawnMenu); TODO
}