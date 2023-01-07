#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
int EngineMultiplier, TorqueMultiplier;
void GUI::Submenus::VehicleMultipliers()
{
	GUI::Title("Multipliers");
	GUI::Int("Engine Multiplier", EngineMultiplier, 0, 1000, 1, "Set Engine Multiplier value", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Engine Torque Multiplier", TorqueMultiplier, 0, 1000, 1, "Set engine torque multiplier value", SELECTABLE_RETURN_VALUE_CHANGE);
	if (GUI::Option("Set", "Set Multiplier"))
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			::Vehicle CurrentVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::MODIFY_VEHICLE_TOP_SPEED(CurrentVehicle, EngineMultiplier);
			VEHICLE::SET_VEHICLE_CHEAT_POWER_INCREASE(CurrentVehicle, TorqueMultiplier);
		}
		else
		{
			Game::notification::Minimap((char*)"~r~Player is not in a vehicle");
		}
	}
}