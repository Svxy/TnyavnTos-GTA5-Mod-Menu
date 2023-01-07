#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../cheat/file_system.hpp"

using namespace Cheat;
void GUI::Submenus::VehicleSpawnSettings()
{
	GUI::Title("Vehicle Spawn Settings");
	GUI::Toggle("Spawn Inside", Features::VehicleSpawnerSpawnInsideVehicle, "");
	GUI::Toggle("Spawn Invincible", Features::VehicleSpawnerSpawnWithGodmode, "");
	GUI::Toggle("Spawn Max Upgraded", Features::VehicleSpawnerSpawnMaxUpgraded, "");
	GUI::Toggle("Delete Current", Features::VehicleSpawnerDeleteOldVehicle, "");
	GUI::Toggle("Spawn Air Vehicles In The Air", Features::VehicleSpawnerSpawnAirVehicleAir, "");
	GUI::StringVector("License Plate Text", { "Default", "Empty", "Custom" }, Features::VehicleSpawnerLicensePlateVectorPosition, "");
	if (Features::VehicleSpawnerLicensePlateVectorPosition == 2)
	{
		if (GUI::Option("Current: ~c~" + Features::VehicleSpawnerCustomLicensePlateTextString, "Select to change"))
		{
			std::string Input;
			if (Game::keyboard::get_input("Enter Custom License Plate Text", Input, 1, 8) == Game::keyboard::input_status::SUCCESS)
			{
				Features::VehicleSpawnerCustomLicensePlateTextString = Input;
				file_system::ini_file::write(Features::VehicleSpawnerCustomLicensePlateTextString, file_system::paths::ConfigFile, "SETTINGS", "Vehicle Spawner Custom License Plate Text");
			}
		}
	}
}