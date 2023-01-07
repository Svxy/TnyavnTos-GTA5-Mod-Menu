#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/data/game_data.hpp"

using namespace Cheat;
int VehicleCategory;
void GUI::Submenus::VehicleSpawn()
{
	GUI::Title("Vehicle Spawn");
	GUI::MenuOption("Settings", Submenus::VehicleSpawnSettings);
	GUI::MenuOption("Previously Spawned", SpawnedVehicles);
	if (GUI::Option("Custom Input", "Input custom vehicle model name"))
	{
		std::string KeyboardInput;
		if (Game::keyboard::get_input("Enter Vehicle Model Name", KeyboardInput, 1, 30) == Game::keyboard::input_status::SUCCESS)
		{
			Game::vehicle::spawn(MISC::GET_HASH_KEY(KeyboardInput.c_str()));
		}
	}
	GUI::StringVector("Category", { "All", "Compacts", "Sedans", "SUVs", "Coupes", "Muscle", "Sports Classics", "Sports", 
					  "Super", "Motorcycles", "Off-road", "Industrial", "Utility", "Vans", "Cycles", "Boats", "Helicopters", 
					  "Planes", "Service", "Emergency", "Military", "Commercial", "Trains", "Open Wheel" }, VehicleCategory, "", SELECTABLE_DISABLE_SAVE);
	GUI::Break("List", SELECTABLE_CENTER_TEXT);
	for (auto const&VehicleHash : game_data::VehicleModels)
	{
		if (VehicleCategory == 0 || VEHICLE::GET_VEHICLE_CLASS_FROM_NAME(VehicleHash) == VehicleCategory - 1)
		{
			if (GUI::VehicleOption(VehicleHash))
			{
				Game::vehicle::spawn(VehicleHash);
			}
		}
	}
}