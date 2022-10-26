#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::UnderwaterTeleportLocations()
{
	GUI::Title("Underwater");
	GameFunctions::ShowTeleportLocationsMenu(GameArrays::TeleportLocationsUnderwater);
}