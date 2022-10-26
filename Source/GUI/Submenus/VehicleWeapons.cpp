#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::VehicleWeapons()
{
	GUI::Title("Vehicle Weapons");
	GUI::Toggle("Toggle", CheatFeatures::VehicleWeaponsBool, "Press horn button to use");
	GUI::Toggle("Show Lines", CheatFeatures::VehicleWeapons_DrawLaser, "Show lines in front of vehicle");
	if (CheatFeatures::VehicleWeapons_TankRounds)
	{
		GUI::Break("Current: ~c~Tank Rounds");
	}
	if (CheatFeatures::VehicleWeapons_VehicleRockets)
	{
		GUI::Break("Current: ~c~Vehicle Rockets");
	}
	if (CheatFeatures::VehicleWeapons_Fireworks)
	{
		GUI::Break("Current: ~c~Fireworks");
	}
	if (GUI::Option("Tank Rounds", ""))
	{
		CheatFeatures::VehicleWeapons_TankRounds = true;
		CheatFeatures::VehicleWeapons_Fireworks = false;
		CheatFeatures::VehicleWeapons_VehicleRockets = false;
	}
	if (GUI::Option("Vehicle Rockets", ""))
	{
		CheatFeatures::VehicleWeapons_VehicleRockets = true;
		CheatFeatures::VehicleWeapons_Fireworks = false;
		CheatFeatures::VehicleWeapons_TankRounds = false;
	}
	if (GUI::Option("Fireworks", ""))
	{
		CheatFeatures::VehicleWeapons_Fireworks = true;
		CheatFeatures::VehicleWeapons_TankRounds = false;
		CheatFeatures::VehicleWeapons_VehicleRockets = false;
	}
}