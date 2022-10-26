#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::HighAltitudeTeleportLocations()
{
	GUI::Title("High Altitude");
	GameFunctions::ShowTeleportLocationsMenu(GameArrays::TeleportLocationsHighAltitude);
}