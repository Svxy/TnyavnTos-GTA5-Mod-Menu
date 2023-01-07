#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

struct SelectedPlayerAttachmentsStruct
{
	std::string ModelName;
	Hash ModelHash;
};

using namespace Cheat;
const std::vector<SelectedPlayerAttachmentsStruct> Models = {
	{ "Plate", 0xE2A6080F },			// p_oil_slick_01
	{ "EMP", 0x3794ACC9 },				// hei_prop_heist_emp
	{ "Beach Fire", 0xC079B265 },		// prop_beach_fire
	{ "Orange Ball", 0x08DA1C0E },		// prop_juicestand
	{ "Weed", 0x1AFA6A0A },				// prop_weed_01
	{ "Safe", 0x40F52369 },				// p_v_43_safe_s
	{ "UFO", 0xB467C540 },				// p_spinning_anus_s
	{ "Toilet", 0x6F9939C7 },			// prop_ld_toilet_01
	{ "Christmas Tree", 0x0E3BA450 },	// prop_xmas_tree_int
	{ "Windmill", 0x745F3383 },			// prop_windmill_01
	{ "Radar", 0x8973A868 }				// prop_air_bigradar
};
void GUI::Submenus::SelectedPlayerAttachments()
{
	GUI::Title("Attachments");
	for (auto& i : Models)
	{
		if (GUI::Option(i.ModelName, ""))
		{
			Game::entity::attach_to_entity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), i.ModelHash);
		}
	}
	GUI::Break("");
	if (GUI::Option("Detach All", ""))
	{
		for (auto& i : Models)
		{
			Game::entity::remove_attached_entity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), i.ModelHash);
		}
	}
}