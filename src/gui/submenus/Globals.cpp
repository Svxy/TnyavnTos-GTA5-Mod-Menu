#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../hooking/globalhandle.hpp"
#include "../../hooking/offsets.hpp"

using namespace Cheat;
int RequestServices;
void GUI::Submenus::Globals()
{
	GUI::Title("Globals");
	if (GUI::Option("Get BST", "Gives you Bull Shark Testosterone"))
	{
		globalHandle(GLOBAL_BULLSHARKTESTOSTERONE[0]).At(GLOBAL_BULLSHARKTESTOSTERONE[1]).As<bool>() = true;
	}
	GUI::Toggle("Off Radar", Features::OffRadarBool, "Enables Lester Off Radar Feature");
	GUI::Toggle("No Idle Kick", Features::NoIdleKickBool, "Does not work when out of game focus");
	GUI::Toggle("Cops Turn Blind Eye", Features::CopsTurnBlindEyeBool, "Enables Bribe Authorities");
	GUI::Toggle("No Orbital Cannon Cooldown", Features::OrbitalCannonCooldownBypassBool, "");
	if (GUI::StringVector("Request Service", { "RC Bandito ", "Mini Tank", "Taxi", "Airstrike", "Helicopter Pickup", "Backup Helicopter", "Ammo Crate",
													"Ballistic Armour" }, RequestServices, "", SELECTABLE_DISABLE_SAVE))
	{
		switch (RequestServices)
		{
		case 0:
			globalHandle(GLOBAL_REQUEST_RCBANDITO[0]).At(GLOBAL_REQUEST_RCBANDITO[1]).As<bool>() = true;
			break;
		case 1:
			globalHandle(GLOBAL_REQUEST_MINITANK[0]).At(GLOBAL_REQUEST_MINITANK[1]).As<bool>() = true;
			break;
		case 2:
			globalHandle(GLOBAL_REQUEST_TAXI[0]).At(GLOBAL_REQUEST_TAXI[1]).As<bool>() = true;
			break;
		case 3:
			globalHandle(GLOBAL_REQUEST_AIRSTRIKE[0]).At(GLOBAL_REQUEST_AIRSTRIKE[1]).As<bool>() = true;
			break;
		case 4:
			globalHandle(GLOBAL_REQUEST_HELIPICKUP[0]).At(GLOBAL_REQUEST_HELIPICKUP[1]).As<bool>() = true;
			break;
		case 5:
			globalHandle(GLOBAL_REQUEST_BACKUPHELI[0]).At(GLOBAL_REQUEST_BACKUPHELI[1]).As<bool>() = true;
			break;
		case 6:
			globalHandle(GLOBAL_REQUEST_AMMOCRATE[0]).At(GLOBAL_REQUEST_AMMOCRATE[1]).As<bool>() = true;
			break;
		case 7:
			globalHandle(GLOBAL_REQUEST_BALLISTICARMOUR[0]).At(GLOBAL_REQUEST_BALLISTICARMOUR[1]).As<bool>() = true;
			break;
		}
	}
}