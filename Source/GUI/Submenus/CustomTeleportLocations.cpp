#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int CustomLocationsAmount;
void GUI::Submenus::CustomTeleportLocations()
{
	GUI::Title("Custom Locations");
	if (std::filesystem::exists(CheatFunctions::ReturnCustomTeleportLocationsFilePath()))
	{
		Json::Value JsonData;
		try 
		{
			if (CheatFunctions::GetJsonFromFile(CheatFunctions::ReturnCustomTeleportLocationsFilePath(), JsonData))
			{
				for (auto it = JsonData.begin(); it != JsonData.end(); ++it)
				{
					CustomLocationsAmount++;
					Vector3 Target;
					Target.x = JsonData[it.key().asString()]["X"].asFloat();
					Target.y = JsonData[it.key().asString()]["Y"].asFloat();
					Target.z = JsonData[it.key().asString()]["Z"].asFloat();
					GUI::Break(it.key().asString(), SELECTABLE_CENTER_TEXT);
					if (GUI::Option("Teleport To", ""))
					{
						GameFunctions::TeleportToCoords(GameFunctions::PlayerPedID, Target, false, false);
					}
					if (GUI::Option("Copy Coordinates To Clipboard", ""))
					{
						CheatFunctions::CopyStringToClipboard("X: " + std::to_string(Target.x) + " Y: " + std::to_string(Target.y) + " Z: " + std::to_string(Target.z));
						GameFunctions::MinimapNotification("Custom Location coordinates copied to clipboard");
					}
					if (GUI::Option("Delete", ""))
					{
						CheatFunctions::DeleteCustomTeleportLocation(it.key().asString());
					}
				}
			}
		}
		catch (...){};
	}
	if (CustomLocationsAmount == 0)
	{
		GUI::Break("No custom locations have been saved");
	}
	CustomLocationsAmount = 0;
}