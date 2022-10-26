#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerApartmentTeleport()
{
	GUI::Title("Teleport to Apartment");
	for (auto& i : GameArrays::TSEPropertyList)
	{
		if (GUI::Option(i.PropertyName, ""))
		{
			GameFunctions::TriggerScriptEvent(eScriptEventTypes::PROPERTY_TELEPORT, CheatFeatures::SelectedPlayer, i.Index);
		}
	}
}