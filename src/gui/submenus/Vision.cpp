#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Vision()
{
	GUI::Title("Vision");
	if (GUI::Option("Reset", ""))
	{
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
	}
	GUI::Break("Visions", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Timecycle", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("CAMERA_secuirity_FUZZ");
	}
	if (GUI::Option("Stoned", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("stoned");
	}
	if (GUI::Option("Orange", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("REDMIST");
	}
	if (GUI::Option("Cocaine", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_flying_base");
	}
	if (GUI::Option("Huffin Gas", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("DRUG_gas_huffin");
	}
	if (GUI::Option("Wobbly", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_wobbly");
	}
	if (GUI::Option("Drunk", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Drunk");
	}
	if (GUI::Option("Heaven", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Bloom");
	}
	if (GUI::Option("3D", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("PlayerSwitchPulse");
	}
	if (GUI::Option("Killstreak", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("MP_Killstreak");
	}
	if (GUI::Option("Hallucinations", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("player_transition");
	}
	if (GUI::Option("Low Quality", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("cinema_001");
	}
	if (GUI::Option("Blurry", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("CHOP");
	}
	if (GUI::Option("\"Fucked Up\" Screen", ""))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("BarryFadeOut");
	}
}