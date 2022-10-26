#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::VehicleSpawnSettings()
{
	GUI::Title("Vehicle Spawn Settings");
	GUI::Toggle("Spawn Inside", CheatFeatures::VehicleSpawnerSpawnInsideVehicle, "");
	GUI::Toggle("Spawn Invincible", CheatFeatures::VehicleSpawnerSpawnWithGodmode, "");
	GUI::Toggle("Spawn Max Upgraded", CheatFeatures::VehicleSpawnerSpawnMaxUpgraded, "");
	GUI::Toggle("Delete Current", CheatFeatures::VehicleSpawnerDeleteOldVehicle, "");
	GUI::Toggle("Spawn With Blip", CheatFeatures::VehicleSpawnerSpawnWithBlip, "");
	GUI::Toggle("Spawn Air Vehicles In The Air", CheatFeatures::VehicleSpawnerSpawnAirVehicleAir, "");
	GUI::StringVector("License Plate Text", { "Default", "Empty", "Custom" }, CheatFeatures::VehicleSpawnerLicensePlateVectorPosition, "");
	if (CheatFeatures::VehicleSpawnerLicensePlateVectorPosition == 2)
	{
		if (GUI::Option("Current: ~c~" + CheatFeatures::VehicleSpawnerCustomLicensePlateTextString, "Select to change"))
		{
			const char* Input;
			if (GameFunctions::DisplayKeyboardAndReturnInput(8, "Enter Custom License Plate Text", Input))
			{
				if (strlen(Input) < 1)
				{ 
					GameFunctions::MinimapNotification("~r~Text must be at least one character long");
				}
				else
				{
					CheatFeatures::VehicleSpawnerCustomLicensePlateTextString = Input;
					CheatFunctions::IniFileWriteString(CheatFeatures::VehicleSpawnerCustomLicensePlateTextString, CheatFunctions::ReturnConfigFilePath(), "SETTINGS", "Vehicle Spawner Custom License Plate Text");
				}			
			}
		}
	}
}