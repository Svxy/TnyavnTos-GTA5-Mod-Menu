#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int VehicleCategory;
void GUI::Submenus::VehicleSpawn()
{
	GUI::Title("Vehicle Spawn");
	GUI::MenuOption("Settings", Submenus::VehicleSpawnSettings);
	GUI::MenuOption("Previously Spawned", SpawnedVehicles);
	if (GUI::Option("Custom Input", "Input custom vehicle model name"))
	{
		const char* KeyboardInput;
		if (GameFunctions::DisplayKeyboardAndReturnInput(30, "Enter Vehicle Model Name", KeyboardInput))
		{
			GameFunctions::SpawnVehicle(KeyboardInput);
		}
	}
	GUI::StringVector("Category", { "All", "Compacts", "Sedans", "SUVs", "Coupes", "Muscle", "Sports Classics", "Sports", 
					  "Super", "Motorcycles", "Off-road", "Industrial", "Utility", "Vans", "Cycles", "Boats", "Helicopters", 
					  "Planes", "Service", "Emergency", "Military", "Commercial", "Trains", "Open Wheel" }, VehicleCategory, "", SELECTABLE_DISABLE_SAVE);
	GUI::Break("List", SELECTABLE_CENTER_TEXT);
	for (auto const&VehicleHash : GameArrays::VehicleModels)
	{
		if (VehicleCategory == 0 || VEHICLE::GET_VEHICLE_CLASS_FROM_NAME(VehicleHash) == VehicleCategory - 1)
		{
			if (GUI::VehicleOption(VehicleHash))
			{
				GameFunctions::SpawnVehicle(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(VehicleHash));
			}
		}
	}
}