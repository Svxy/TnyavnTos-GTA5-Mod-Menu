#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/features/custom_teleport_locations.hpp"
#include "../../hooking/globalhandle.hpp"
#include "../../hooking/offsets.hpp"

using namespace Cheat;
float TeleportFoward = 1.f;
void GUI::Submenus::Teleport()
{
	GUI::Title("Teleport");
	if (GUI::Option("Teleport To Waypoint", "")) 
	{ 
		if (!Game::teleport::to_blip(SpriteWaypoint))
			Game::notification::Minimap((char*)"~r~No Waypoint has been set");
	}
	GUI::Toggle("Auto Teleport To Waypoint", Features::AutoTeleportToWaypointBool, "");
	if (GUI::Option("Teleport into Personal Vehicle", "")) 
	{
		globalHandle(GLOBAL_TP_INTO_PERSONAL_VEHICLE[0]).At(GLOBAL_TP_INTO_PERSONAL_VEHICLE[1]).As<bool>() = true;
	}
	if (GUI::Option("Teleport To Objective", "")) { Game::teleport::to_objective(); }
	if (GUI::Option("Teleport to Custom Coordinate", ""))
	{
		Vector3 TargetCoordinates;
		try
		{
			std::string X, Y, Z;
			if (Game::keyboard::get_input("Enter X-axis coordinate", X, 1, 25) == Game::keyboard::input_status::SUCCESS)
			{ 
				if (Game::keyboard::get_input("Enter Y-axis coordinate", Y, 1, 25) == Game::keyboard::input_status::SUCCESS)
				{
					if (Game::keyboard::get_input("Enter Z-axis coordinate", Z, 1, 25) == Game::keyboard::input_status::SUCCESS)
					{ 
						TargetCoordinates.x = std::stof(X);
						TargetCoordinates.y = std::stof(Y);
						TargetCoordinates.y = std::stof(Z);
						Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), TargetCoordinates, false, false);
					}
				}
			}
		}
		catch (...)
		{
			Game::notification::Minimap((char*)"~r~Invalid float coordinate format inputted");
		}
	}
	if (GUI::Option("Teleport Into Last Used Vehicle", ""))
	{
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VEHICLE::GET_LAST_DRIVEN_VEHICLE(), -1);
	}
	if (GUI::Float("Teleport Forward", TeleportFoward, 1, 10, 1, "", 0))
	{
		Entity Target;
		Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0f, TeleportFoward, 0.0f);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
			Target = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		else
			Target = PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Target, Coords.x, Coords.y, Coords.z, false, false, true);
	}
	GUI::Break("Custom Locations", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Save Current Location", ""))
	{
		std::string NewThemeFileName;
		if (Game::keyboard::get_input("Enter Custom Teleport Location Name", NewThemeFileName, 1, 25) == Game::keyboard::input_status::SUCCESS)
		{
			if (Features::custom_tel_locations::Add(NewThemeFileName, ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false)))
				Game::notification::Minimap((char*)"Custom Location Saved");
		}
	}
	GUI::MenuOption("View Locations", Submenus::CustomTeleportLocations);
	GUI::Break("Presets", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Teleport Transition", Features::TeleportTransition, "");
	if (GUI::Option("Teleport to Cayo Perico Island", ""))
	{
		Game::gtao::tse::start_event(Game::gtao::tse::types::CAYO_PERICO_TELEPORT, PLAYER::PLAYER_ID());
	}
	GUI::MenuOption("Landmarks", Submenus::LandmarkTeleportLocations);
	GUI::MenuOption("IPL's", Submenus::IPLTeleports);
	GUI::MenuOption("Safehouses", Submenus::SafehousesTeleportLocations);
	GUI::MenuOption("Underwater", Submenus::UnderwaterTeleportLocations);
	GUI::MenuOption("High Altitude", Submenus::HighAltitudeTeleportLocations);
}