#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int EngineMultiplier, TorqueMultiplier;
void GUI::Submenus::VehicleMultipliers()
{
	GUI::Title("Multipliers");
	GUI::Int("Engine Multiplier", EngineMultiplier, 0, 1000, 1, "Set Engine Multiplier value", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Engine Torque Multiplier", TorqueMultiplier, 0, 1000, 1, "Set engine torque multiplier value", SELECTABLE_RETURN_VALUE_CHANGE);
	if (GUI::Option("Set", "Set Multiplier"))
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, 0))
		{
			::Vehicle CurrentVehicle = PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID);
			VEHICLE::MODIFY_VEHICLE_TOP_SPEED(CurrentVehicle, EngineMultiplier);
			VEHICLE::SET_VEHICLE_CHEAT_POWER_INCREASE(CurrentVehicle, TorqueMultiplier);
		}
		else
		{
			GameFunctions::MinimapNotification("~r~Player is not in a vehicle");
		}
	}
}