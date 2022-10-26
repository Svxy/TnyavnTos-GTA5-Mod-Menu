#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int FakeWantedLevelInteger = 0;
void GUI::Submenus::Miscellaneous()
{
	GUI::Title("Miscellaneous");
	GUI::MenuOption("Report Statistics", Submenus::ReportStatistics);
	GUI::MenuOption("Disables", Submenus::Disables);
	GUI::MenuOption("In-game Television", Submenus::Television);
	GUI::MenuOption("Radio", Submenus::Radio);
	GUI::MenuOption("Extra-sensory Perception", Submenus::ESP);
	GUI::MenuOption("Head-up Display", Submenus::HUD);
	GUI::MenuOption("IPL Loader", Submenus::IPLLoader);
	if (GUI::Int("Fake Wanted Level", FakeWantedLevelInteger, 0, 6, 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE))
	{
		MISC::SET_FAKE_WANTED_LEVEL(FakeWantedLevelInteger);
	}
	GUI::Toggle("No-Clip", CheatFeatures::NoClipBool, "Use W and mouse to control");
	GUI::Toggle("Jump Around Mode", CheatFeatures::JumpAroundModeBool, "Nearby vehicles will 'jump around'");
	GUI::Toggle("Free Cam", CheatFeatures::FreeCamBool, "Use W and S to control. Shift to go faster", SELECTABLE_DISABLE_SAVE);
	GUI::Toggle("Show Joining Players Notification", CheatFeatures::ShowJoiningPlayersNotification, "");
	GUI::Toggle("Show FPS", CheatFeatures::ShowFPSBool, "");
	if (GUI::Option("Stop Spectating Player", ""))
	{
		CheatFeatures::SpectatePlayerBool = false;
	}
	if (GUI::Option("Drive To Waypoint", "A NPC drives you to the set waypoint"))
	{
		int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(SpriteWaypoint);
		if (UI::DOES_BLIP_EXIST(WaypointHandle))
		{
			std::string VehicleName = "MARSHALL";
			Vector3 WayPointVector = UI::GET_BLIP_COORDS(WaypointHandle);
			STREAMING::REQUEST_MODEL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(VehicleName)));
			while (!STREAMING::HAS_MODEL_LOADED(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(VehicleName)))) { GameHooking::PauseMainFiber(0); }
			Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(GameFunctions::PlayerPedID, 0.0, 5.0, 0);
			::Vehicle VehicleHandle = VEHICLE::CREATE_VEHICLE(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(VehicleName)), pos.x, pos.y, pos.z, ENTITY::GET_ENTITY_HEADING(GameFunctions::PlayerPedID), 1, 1, false);
			if (VehicleHandle != 0)
			{
				Ped Driver = PED::CREATE_RANDOM_PED_AS_DRIVER(VehicleHandle, false);
				PED::SET_PED_INTO_VEHICLE(Driver, VehicleHandle, -1);
				PED::SET_PED_INTO_VEHICLE(GameFunctions::PlayerPedID, VehicleHandle, 0);
				TASK::TASK_VEHICLE_DRIVE_TO_COORD(Driver, VehicleHandle, WayPointVector.x, WayPointVector.y, WayPointVector.z, 40, 1, ENTITY::GET_ENTITY_MODEL(VehicleHandle), 7, 6, -1);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "CRUSADER");
				GameFunctions::MinimapNotification("NPC Driver Spawned");
			}
		}
		else { GameFunctions::MinimapNotification("Please set a waypoint first to use this feature"); }
	}
	if (GUI::Option("Get Empty Session", "Get Empty (Public) Session")) { Sleep(10000); }
	if (GUI::Option("Exit to Single Player", "")) { if (NETWORK::NETWORK_IS_SESSION_STARTED()) { NETWORK::_SHUTDOWN_AND_LOAD_MOST_RECENT_SAVE(); } }
}