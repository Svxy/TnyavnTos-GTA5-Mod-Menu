#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Protection()
{
	GUI::Title("Protection");
	if (GUI::Option("Toggle Anti-Crash Camera", "Changes camera position to prevent entity crash")) { GameFunctions::EnableDisableAntiCrashCamera(); }
	GUI::Break("Protection", SELECTABLE_CENTER_TEXT);
	GUI::MenuOption("Script Events", Submenus::ProtectionScriptEvents);
	GUI::MenuOption("Network Events", Submenus::ProtectionNetworkEvents);
}