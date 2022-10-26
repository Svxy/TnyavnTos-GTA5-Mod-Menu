#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::SafehousesTeleportLocations()
{
	GUI::Title("Safehouses");
	GameFunctions::ShowTeleportLocationsMenu(GameArrays::TeleportLocationsSafehouses);
}