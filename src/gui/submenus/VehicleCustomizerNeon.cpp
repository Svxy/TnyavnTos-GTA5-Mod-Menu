#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
int VehicleNeonLightRed, VehicleNeonLightGreen, VehicleNeonLightBlue;
void GUI::Submenus::VehicleCustomizerNeon()
{
	GUI::Title("Neon");
	if (GUI::Option("Enable Neons", "Enable Vehicle Neons"))
	{
		for (int i = 0; i <= 7; i++)
		{
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), i, true);
		}
	}
	if (GUI::Option("Disable Neons", "Disable Vehicle Neons"))
	{
		for (int i = 0; i <= 7; i++)
		{
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), i, false);
		}
	}
	GUI::Int("Neon Color: Red", VehicleNeonLightRed, 0, 255, 1, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Neon Color: Green", VehicleNeonLightGreen, 0, 255, 1, "", SELECTABLE_RETURN_VALUE_CHANGE);
	GUI::Int("Neon Color: Blue", VehicleNeonLightBlue, 0, 255, 1, "", SELECTABLE_RETURN_VALUE_CHANGE);
	if (GUI::Option("Set Neon Color", "Set Vehicle Neon Colors"))
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			::Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, VehicleNeonLightRed, VehicleNeonLightGreen, VehicleNeonLightBlue);
		}
		else
		{
			Game::notification::Minimap((char*)"~r~Player is not in a vehicle");
		}
	}
	GUI::Break("Neon Presets", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Red", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 0, 0);
	}
	if (GUI::Option("Green", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 255, 0);
	}
	if (GUI::Option("Blue", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 0, 255);
	}
	if (GUI::Option("Hot Pink", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 226, 35, 157);
	}
	if (GUI::Option("Yellow", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 244, 0);
	}
	if (GUI::Option("Orange", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 91, 0);
	}
	if (GUI::Option("Aqua", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 40, 255, 255);
	}
	if (GUI::Option("White", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 255, 255);
	}
	if (GUI::Option("Magenta", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 102, 0, 35);
	}
	if (GUI::Option("Purple", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 53, 0, 83);
	}
	if (GUI::Option("Dark Green", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 118, 0);
	}
	if (GUI::Option("Rose Red", ""))
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 161, 0, 0);
	}
}