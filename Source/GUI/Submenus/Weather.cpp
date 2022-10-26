#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int CloudTypes;
const std::vector<std::string> CloudHats = { "Altostratus", "Cirrus", "Cirrocumulus", "Clear 01", "Cloudy 01", "Contrails", "Horizon", "horizonband1", 
										  "horizonband2", "horizonband3", "horsey", "Nimbus", "Puffs", "RAIN", "Snowy 01", "Stormy 01", "stratoscumulus", 
										  "Stripey", "shower", "Wispy" };
void GUI::Submenus::Weather()
{
	GUI::Title("Weather");
	if (GUI::StringVector("Clouds", { "Default/Reset", CloudHats[0], CloudHats[1], CloudHats[2], CloudHats[3], CloudHats[4],
											 CloudHats[5], CloudHats[6], CloudHats[7], CloudHats[8], CloudHats[9], CloudHats[10],
											 CloudHats[11], CloudHats[12], CloudHats[13], CloudHats[14], CloudHats[15], CloudHats[16],
											 CloudHats[17], CloudHats[18], CloudHats[19] }, CloudTypes, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		if (CloudTypes == 0)
		{
			MISC::UNLOAD_ALL_CLOUD_HATS();
		}
		else
		{
			MISC::LOAD_CLOUD_HAT(CheatFunctions::StringToChar(CloudHats[CloudTypes - 1]), 1.f);
		}
	}
	GUI::Break("Weather Types", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Reset", ""))
	{
		MISC::CLEAR_OVERRIDE_WEATHER();
	}
	for (int i = 0; i < GameArrays::WeatherTypes.size(); i++)
	{
		if (GUI::Option(GameArrays::WeatherTypes[i].SelectableName, ""))
		{
			MISC::SET_OVERRIDE_WEATHER(CheatFunctions::StringToChar(GameArrays::WeatherTypes[i].WeatherType));
		}
	}
}