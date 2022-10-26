#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::SelectedPlayerAttachments()
{
	GUI::Title("Attachments");
	if (GUI::Option("Plate", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "p_oil_slick_01"); }
	if (GUI::Option("EMP", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "hei_prop_heist_emp"); }
	if (GUI::Option("Beach Fire", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "prop_beach_fire"); }
	if (GUI::Option("Orange Ball", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "prop_juicestand"); }
	if (GUI::Option("Weed", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "prop_weed_01"); }
	if (GUI::Option("Safe", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "p_v_43_safe_s"); }
	if (GUI::Option("UFO", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "p_spinning_anus_s"); }
	if (GUI::Option("Toilet", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "prop_ld_toilet_01"); }
	if (GUI::Option("Christmas Tree", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "prop_xmas_tree_int"); }
	if (GUI::Option("Windmill", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "prop_windmill_01"); }
	if (GUI::Option("Radar", "")) { GameFunctions::AttachObjectToPed(CheatFeatures::SelectedPlayer, "prop_air_bigradar"); }
	if (GUI::Option("Remove All Objects", "Only removes above attached objects"))
	{
		const std::vector<std::string> ObjectsToRemoveArray = {
			"p_oil_slick_01",  "hei_prop_heist_emp", "prop_beach_fire",  "prop_juicestand",
			"prop_weed_01",  "p_v_43_safe_s",  "p_spinning_anus_s",  "prop_ld_toilet_01",
			"prop_xmas_tree_int",  "prop_windmill_01",  "prop_air_bigradar"
		};
		for (auto const& i : ObjectsToRemoveArray)
		{
			GameFunctions::RemoveObjectFromPed(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), CheatFunctions::StringToChar(i));
		}
		GameFunctions::MinimapNotification("Object(s) Removed");
	}
}