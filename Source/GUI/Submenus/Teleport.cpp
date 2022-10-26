#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
float TeleportFoward = 1.f;
void GUI::Submenus::Teleport()
{
	GUI::Title("Teleport");
	if (GUI::Option("Teleport To Waypoint", "")) { GameFunctions::TeleportToBlipCoord(SpriteWaypoint); }
	GUI::Toggle("Auto Teleport To Waypoint", CheatFeatures::AutoTeleportToWaypointBool, "");
	if (GUI::Option("Teleport into Personal Vehicle", "")) 
	{ 
		globalHandle(GLOBAL_TP_INTO_PERSONAL_VEHICLE[0]).At(GLOBAL_TP_INTO_PERSONAL_VEHICLE[1]).As<bool>() = true;
	}
	if (GUI::Option("Teleport To Objective", "")) { GameFunctions::TeleportToObjective(); }
	if (GUI::Option("Teleport to Custom Coordinate", ""))
	{
		Vector3 TargetCoordinates;
		try
		{
			const char* X; const char* Y; const char* Z;
			if (GameFunctions::DisplayKeyboardAndReturnInput(25, "Enter X-axis coordinate", X))
			{ 
				if (GameFunctions::DisplayKeyboardAndReturnInput(25, "Enter Y-axis coordinate", Y))
				{
					if (GameFunctions::DisplayKeyboardAndReturnInput(25, "Enter Z-axis coordinate", Z))
					{ 
						TargetCoordinates.x = std::stof(X);
						TargetCoordinates.y = std::stof(Y);
						TargetCoordinates.y = std::stof(Z);
						GameFunctions::TeleportToCoords(GameFunctions::PlayerPedID, TargetCoordinates, false, false);
					}
				}
			}
		}
		catch (...)
		{
			GameFunctions::MinimapNotification("~r~Invalid float coordinate format inputted");
		}
	}
	if (GUI::Option("Teleport Into Last Used Vehicle", ""))
	{
		PED::SET_PED_INTO_VEHICLE(GameFunctions::PlayerPedID, VEHICLE::GET_LAST_DRIVEN_VEHICLE(), -1);
	}
	if (GUI::Float("Teleport Forward", TeleportFoward, 1, 10, 1, "", 0))
	{
		Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(GameFunctions::PlayerPedID, 0.0f, TeleportFoward, 0.0f);
		if (PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false)) { GameFunctions::PlayerPedID = PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, false); }
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(GameFunctions::PlayerPedID, Coords.x, Coords.y, Coords.z, false, false, true);
	}
	GUI::Break("Custom Locations", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Save Current Location", ""))
	{
		const char* NewThemeFileName;
		if (GameFunctions::DisplayKeyboardAndReturnInput(20, "Enter Custom Teleport Location Name", NewThemeFileName))
		{
			CheatFunctions::AddCustomTeleportLocation(NewThemeFileName);
			GameFunctions::MinimapNotification("Custom Location Saved");
		}
	}
	GUI::MenuOption("View Locations", Submenus::CustomTeleportLocations);
	GUI::Break("Presets", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Teleport Transition", CheatFeatures::TeleportTransition, "");
	if (GUI::Option("Teleport to Cayo Perico Island", ""))
	{
		GameFunctions::TriggerScriptEvent(eScriptEventTypes::CAYO_PERICO_TELEPORT, GameFunctions::PlayerID);
	}
	GUI::MenuOption("Landmarks", Submenus::LandmarkTeleportLocations);
	GUI::MenuOption("IPL's", Submenus::IPLTeleports);
	GUI::MenuOption("Safehouses", Submenus::SafehousesTeleportLocations);
	GUI::MenuOption("Underwater", Submenus::UnderwaterTeleportLocations);
	GUI::MenuOption("High Altitude", Submenus::HighAltitudeTeleportLocations);
}