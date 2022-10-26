#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::ProtectionNetworkEvents()
{
	GUI::Title("Network Events Protection");
	GUI::Toggle("Vote Kick", CheatFeatures::ProtectionVoteKickBool, "");
	GUI::Toggle("Freeze", CheatFeatures::ProtectionFreezeBool, "");
	GUI::Toggle("Give/Remove Weapons", CheatFeatures::ProtectionGiveRemoveWeaponsBool, "");
	GUI::Toggle("Alter Wanted Level", CheatFeatures::ProtectionAlterWantedLevelBool, "");
	GUI::Toggle("World Events", CheatFeatures::ProtectionWorldEventsBool, "Fire, explosions and more");
	GUI::Toggle("Vehicle", CheatFeatures::ProtectionVehicleBool, "Control & Explosions");
}