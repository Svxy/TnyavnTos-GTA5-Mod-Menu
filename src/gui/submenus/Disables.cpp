#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Disables()
{
	GUI::Title("Disables");
	GUI::Toggle("Transaction Error Warnings", Features::DisableTransactionErrorWarning, "");
	GUI::Toggle("Cutscenes", Features::DisableCutscenes, "");
	GUI::Toggle("Mobile Phone", Features::DisableMobilePhoneBool, "");
}