#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::VehicleCustomizer()
{
	GUI::Title("Los Santos Customs");
	if (PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false))
	{
		if (GUI::Option("Repair & Clean", "Repair & Clean current vehicle"))
		{
			GameFunctions::RepairAndCleanVehicle(PED::GET_VEHICLE_PED_IS_USING(Cheat::GameFunctions::PlayerPedID));
		}
		if (GUI::Option("Max Upgrade", "Max Upgrade current vehicle"))
		{
			GameFunctions::MaxUpgradeVehicle(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID));
			GameFunctions::AdvancedMinimapNotification("Vehicle Max Upgraded", "Textures", "AdvancedNotificationImage", false, 4, "Los Santos Customs", "", 1.0, "");
		}
		if (GUI::Option("Max Downgrade", "Max downgrade current vehicle"))
		{
			GameFunctions::MaxDowngradeVehicle(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID));
			GameFunctions::AdvancedMinimapNotification("Vehicle Max Downgraded", "Textures", "AdvancedNotificationImage", false, 4, "Los Santos Customs", "", 1.0, "");
		}
		if (GUI::Option("Add Blip Registration", "Add Blip To Current Vehicle"))
		{
			GameFunctions::AddBlipToVehicle(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID));
		}
		if (GUI::Option("Change License Plate Text", "Input custom vehicle license plate text"))
		{
			const char* KeyboardInput;
			if (GameFunctions::DisplayKeyboardAndReturnInput(8, "Enter new license plate text", KeyboardInput))
			{
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID), KeyboardInput);
				GameFunctions::AdvancedMinimapNotification("License Plate Text Updated", "Textures", "AdvancedNotificationImage", false, 4, "Los Santos Customs", "", 1.0, "");
			}
		}
		GUI::MenuOption("Color", Submenus::VehicleCustomizerColor);
		GUI::MenuOption("Neon", Submenus::VehicleCustomizerNeon);
		GUI::MenuOption("Multipliers", Submenus::VehicleMultipliers);
		GUI::Break("Doors", SELECTABLE_CENTER_TEXT);
		if (GUI::StringVector("Open", { "Front Left", "Front Right", "Back Left", "Back Right", "Hood", "Trunk", "Back", "Back2" }, CheatFeatures::OpenVehicleDoorPosition, "Select to open door"))
		{
			VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID), CheatFeatures::PedMovementVectorPosition, false, false);
		}
		if (GUI::StringVector("Close", { "Front Left", "Front Right", "Back Left", "Back Right", "Hood", "Trunk", "Back", "Back2" }, CheatFeatures::CloseVehicleDoorPosition, "Select to close door"))
		{
			VEHICLE::SET_VEHICLE_DOOR_SHUT(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID), CheatFeatures::PedMovementVectorPosition, true);
		}
	}
	else
	{
		GUI::Break("Player is not in a vehicle");
	}
}