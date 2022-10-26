#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Vehicle()
{
	GUI::Title("Vehicle");
	GUI::MenuOption("Los Santos Customs", Submenus::VehicleCustomizer);
	GUI::MenuOption("Weapons", Submenus::VehicleWeapons);
	if (GUI::Option("Delete Current", ""))
	{
		if (!GameFunctions::DeleteVehicle(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID)))
		{
			GameFunctions::MinimapNotification("~r~Player is not in a vehicle");
		}
	}
	if (GUI::Option("Flip Up", "Flip vehicle up")) { VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, false), 0.f); }
	if (GUI::Option("Set Max Speed", ""))
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false))
		{
			int MaxSpeedInput;
			if (GameFunctions::DisplayKeyboardAndReturnInputInteger(3, "Enter the desired max speed", MaxSpeedInput))
			{
				::Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID);
				if (MISC::SHOULD_USE_METRIC_MEASUREMENTS())
				{
					ENTITY::SET_ENTITY_MAX_SPEED(VehicleHandle, GameFunctions::KMHToMS(MaxSpeedInput));
					GameFunctions::MinimapNotification("Max Speed Set (KM/H)");
				}
				else
				{
					ENTITY::SET_ENTITY_MAX_SPEED(VehicleHandle, GameFunctions::MPHToMS(MaxSpeedInput));
					GameFunctions::MinimapNotification("Max Speed Set (MP/H)");
				}
			}
			else
			{
				GameFunctions::MinimapNotification("Canceled setting Max Vehicle Speed");
			}		
		}
		else
		{
			GameFunctions::MinimapNotification("~r~Player is not in a vehicle");
		}
	}
	GUI::Toggle("Invincibility", CheatFeatures::VehicleGodmodeBool, "Makes current vehicle invincible");
	GUI::Toggle("Invisibility", CheatFeatures::VehicleInvisibleBool, "Makes current vehicle invisible");
	GUI::Toggle("Horn Boost", CheatFeatures::VehicleHornBoostBool, "Press horn button to use");
	GUI::Toggle("Unlimited Rocket Boost", CheatFeatures::UnlimitedRocketBoostBool, "");
	GUI::StringVector("Speedometer", { "Disabled", "On-Screen", "License Plate", "Both" }, CheatFeatures::SpeedometerVectorPosition, "Set speedometer");
	GUI::Toggle("Rainbow Colors", CheatFeatures::RainbowVehicleBool, "");
	GUI::Toggle("Drive On Water", CheatFeatures::DriveOnWaterBool, "Drive your vehicle on water");
	GUI::Toggle("Super Brakes", CheatFeatures::SuperBrakesBool, "");
}