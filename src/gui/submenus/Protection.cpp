#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
Cam antiCrashCam;
void GUI::Submenus::Protection()
{
	GUI::Title("Protection");
	if (GUI::Option("Toggle Anti-Crash Camera", "Changes camera position to prevent entity crash")) 
	{ 
		if (CAM::DOES_CAM_EXIST(antiCrashCam))
		{
			CAM::SET_CAM_ACTIVE(antiCrashCam, false);
			CAM::RENDER_SCRIPT_CAMS(false, true, 10, false, false, false);
			CAM::DESTROY_CAM(antiCrashCam, false);
			PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), true, 0);
		}
		else
		{
			antiCrashCam = CAM::CREATE_CAM_WITH_PARAMS("DEFAULT_SCRIPTED_CAMERA", 9999.f, 9999.f, 9999.f, 9999.f, 9999.f, 9999.f, 9999.f, true, 1);
			CAM::RENDER_SCRIPT_CAMS(true, true, 1, false, false, false);
			CAM::SET_CAM_ACTIVE(antiCrashCam, true);
			PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), false, 0);
		}
	}
	GUI::Break("Protection", SELECTABLE_CENTER_TEXT);
	GUI::MenuOption("Script Events", Submenus::ProtectionScriptEvents);
	GUI::MenuOption("Network Events", Submenus::ProtectionNetworkEvents);
}