#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::World()
{
	GUI::Title("World");
	GUI::MenuOption("Time", Submenus::Time);
	GUI::MenuOption("Weather", Submenus::Weather);
	GUI::MenuOption("Nearby Vehicles", Submenus::NearbyVehicles);
	GUI::MenuOption("Nearby Peds", Submenus::NearbyPeds);
	GUI::Toggle("Snow", CheatFeatures::WorldSnowLocalBool, "GTA Online Only");
	GUI::Toggle("No Gravity", CheatFeatures::NoGravityBool, "Disable gravity in the world");
	GUI::Toggle("Blackout", CheatFeatures::WorldBlackoutBool, "Disable All Map Lights");
	if (GUI::Option("Clear Area", "Clear area of vehicles, objects etc"))
	{
		Vector3 MyPos = ENTITY::GET_ENTITY_COORDS(GameFunctions::PlayerPedID, false);
		MISC::CLEAR_AREA(MyPos.x, MyPos.y, MyPos.z, 250, true, false, false, false);
		MISC::CLEAR_AREA_OF_COPS(MyPos.x, MyPos.y, MyPos.z, 250, 0);
		MISC::CLEAR_AREA_OF_OBJECTS(MyPos.x, MyPos.y, MyPos.z, 250, 0);
		MISC::CLEAR_AREA_OF_VEHICLES(MyPos.x, MyPos.y, MyPos.z, 250, false, false, false, false, false, false, 0);
		MISC::CLEAR_AREA_OF_PEDS(MyPos.x, MyPos.y, MyPos.z, 250, 0);
		MISC::CLEAR_AREA_OF_PROJECTILES(MyPos.x, MyPos.y, MyPos.z, 250, false);

		// Seperate Remove Nearby Vehicles: for spawned vehicles
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		::Vehicle* vehs = new ::Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(GameFunctions::PlayerPedID, vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, false))
			{
				GameFunctions::RequestNetworkControlOfEntity(vehs[OffsetID]);
				ENTITY::DELETE_ENTITY(&vehs[OffsetID]);
			}
		}
		delete[] vehs;
		GameFunctions::MinimapNotification(CheatFunctions::StringToChar("Area Cleared"));
	}
}