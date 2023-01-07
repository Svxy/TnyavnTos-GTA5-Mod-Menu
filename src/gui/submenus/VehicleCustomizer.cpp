#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::VehicleCustomizer()
{
	GUI::Title("Los Santos Customs");
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		if (GUI::Option("Repair", ""))
		{
			Game::vehicle::repair(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));
		}
		if (GUI::Option("Clean", ""))
		{
			Game::vehicle::clean(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));
		}
		if (GUI::Option("Max Upgrade", "Max Upgrade current vehicle"))
		{
			Game::vehicle::up_downgrade(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true, true);		
		}
		if (GUI::Option("Max Downgrade", "Max downgrade current vehicle"))
		{
			Game::vehicle::up_downgrade(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false, true);
		}
		if (GUI::Option("Change License Plate Text", "Input custom vehicle license plate text"))
		{
			std::string KeyboardInput;
			if (Game::keyboard::get_input("Enter new license plate text", KeyboardInput, 1, 8) == Game::keyboard::input_status::SUCCESS)
			{
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), KeyboardInput.c_str());
				Game::notification::MinimapAdvanced((char*)"License Plate Text Updated", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Los Santos Customs", (char*)"", 1.0, (char*)"");
			}
		}
		GUI::MenuOption("Color", Submenus::VehicleCustomizerColor);
		GUI::MenuOption("Neon", Submenus::VehicleCustomizerNeon);
		GUI::MenuOption("Multipliers", Submenus::VehicleMultipliers);
		GUI::Break("Doors", SELECTABLE_CENTER_TEXT);
		if (GUI::StringVector("Open", { "Front Left", "Front Right", "Back Left", "Back Right", "Hood", "Trunk", "Back", "Back2" }, Features::OpenVehicleDoorPosition, "Select to open door"))
		{
			VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Features::PedMovementVectorPosition, false, false);
		}
		if (GUI::StringVector("Close", { "Front Left", "Front Right", "Back Left", "Back Right", "Hood", "Trunk", "Back", "Back2" }, Features::CloseVehicleDoorPosition, "Select to close door"))
		{
			VEHICLE::SET_VEHICLE_DOOR_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Features::PedMovementVectorPosition, true);
		}
	}
	else
	{
		GUI::Break("Player is not in a vehicle");
	}
}