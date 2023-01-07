#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Vehicle()
{
	GUI::Title("Vehicle");
	GUI::MenuOption("Los Santos Customs", Submenus::VehicleCustomizer);
	GUI::MenuOption("Weapons", Submenus::VehicleWeapons);
	if (GUI::Option("Delete Current", ""))
	{
		if (!Game::vehicle::delete_v(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())))
		{
			Game::notification::Minimap((char*)"~r~Player is not in a vehicle");
		}
	}
	if (GUI::Option("Flip Up", "Flip vehicle up")) { VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0.f); }
	if (GUI::Option("Set Max Speed", ""))
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			std::string MaxSpeedInput;
			if (Game::keyboard::get_input("Enter the desired max speed", MaxSpeedInput, 1, 3) == Game::keyboard::input_status::SUCCESS)
			{
				::Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				if (MISC::SHOULD_USE_METRIC_MEASUREMENTS())
				{
					ENTITY::SET_ENTITY_MAX_SPEED(VehicleHandle, Game::math::KMHToMS(Cheat::helper::StringToInt(MaxSpeedInput)));
					Game::notification::Minimap((char*)"Max Speed Set (KM/H)");
				}
				else
				{
					ENTITY::SET_ENTITY_MAX_SPEED(VehicleHandle, Game::math::MPHToMS(Cheat::helper::StringToInt(MaxSpeedInput)));
					Game::notification::Minimap((char*)"Max Speed Set (MP/H)");
				}
			}
			else
			{
				Game::notification::Minimap((char*)"Canceled setting Max Vehicle Speed");
			}		
		}
		else
		{
			Game::notification::Minimap((char*)"~r~Player is not in a vehicle");
		}
	}
	GUI::Toggle("Invincibility", Features::VehicleGodmodeBool, "Makes current vehicle invincible");
	GUI::Toggle("Invisibility", Features::VehicleInvisibleBool, "Makes current vehicle invisible");
	GUI::Toggle("Horn Boost", Features::VehicleHornBoostBool, "Press horn button to use");
	GUI::Toggle("Unlimited Rocket Boost", Features::UnlimitedRocketBoostBool, "");
	GUI::StringVector("Speedometer", { "Disabled", "On-Screen", "License Plate", "Both" }, Features::SpeedometerVectorPosition, "Set speedometer");
	GUI::Toggle("Rainbow Colors", Features::RainbowVehicleBool, "");
	GUI::Toggle("Drive On Water", Features::DriveOnWaterBool, "Drive your vehicle on water");
	GUI::Toggle("Super Brakes", Features::SuperBrakesBool, "");
}