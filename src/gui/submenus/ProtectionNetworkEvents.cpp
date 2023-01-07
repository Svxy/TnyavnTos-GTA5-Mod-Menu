#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::ProtectionNetworkEvents()
{
	GUI::Title("Network Events Protection");
	GUI::Toggle("Vote Kick", Features::ProtectionVoteKickBool, "");
	GUI::Toggle("Freeze", Features::ProtectionFreezeBool, "");
	GUI::Toggle("Give/Remove Weapons", Features::ProtectionGiveRemoveWeaponsBool, "");
	GUI::Toggle("Alter Wanted Level", Features::ProtectionAlterWantedLevelBool, "");
	GUI::Toggle("World Events", Features::ProtectionWorldEventsBool, "Fire, explosions and more");
	GUI::Toggle("Vehicle", Features::ProtectionVehicleBool, "Control & Explosions");
}