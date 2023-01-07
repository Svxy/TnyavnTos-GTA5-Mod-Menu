#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::VehicleWeapons()
{
	GUI::Title("Vehicle Weapons");
	GUI::Toggle("Toggle", Features::VehicleWeaponsBool, "Press horn button to use");
	GUI::Toggle("Show Lines", Features::VehicleWeapons_DrawLaser, "Show lines in front of vehicle");
	if (Features::VehicleWeapons_TankRounds)
	{
		GUI::Break("Current: ~c~Tank Rounds");
	}
	if (Features::VehicleWeapons_VehicleRockets)
	{
		GUI::Break("Current: ~c~Vehicle Rockets");
	}
	if (Features::VehicleWeapons_Fireworks)
	{
		GUI::Break("Current: ~c~Fireworks");
	}
	if (GUI::Option("Tank Rounds", ""))
	{
		Features::VehicleWeapons_TankRounds = true;
		Features::VehicleWeapons_Fireworks = false;
		Features::VehicleWeapons_VehicleRockets = false;
	}
	if (GUI::Option("Vehicle Rockets", ""))
	{
		Features::VehicleWeapons_VehicleRockets = true;
		Features::VehicleWeapons_Fireworks = false;
		Features::VehicleWeapons_TankRounds = false;
	}
	if (GUI::Option("Fireworks", ""))
	{
		Features::VehicleWeapons_Fireworks = true;
		Features::VehicleWeapons_TankRounds = false;
		Features::VehicleWeapons_VehicleRockets = false;
	}
}