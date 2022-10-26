#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Globals()
{
	GUI::Title("Globals");
	if (GUI::Option("Get BST", "Gives you Bull Shark Testosterone"))
	{ 
		globalHandle(GLOBAL_BULLSHARKTESTOSTERONE[0]).At(GLOBAL_BULLSHARKTESTOSTERONE[1]).As<bool>() = true; 
	}
	GUI::Toggle("Off Radar", CheatFeatures::OffRadarBool, "Enables Lester Off Radar Feature");
	GUI::Toggle("No Idle Kick", CheatFeatures::NoIdleKickBool, "Does not work when out of game focus");
	GUI::Toggle("Cops Turn Blind Eye", CheatFeatures::CopsTurnBlindEyeBool, "Enables Bribe Authorities");
	GUI::Toggle("No Orbital Cannon Cooldown", CheatFeatures::OrbitalCannonCooldownBypassBool, "");
	if (GUI::Option("Enter RC Bandito", ""))
	{
		globalHandle(GLOBAL_REQUEST_RCBANDITO[0]).At(GLOBAL_REQUEST_RCBANDITO[1]).As<bool>() = true;
	}
	if (GUI::Option("Enter Mini Tank", ""))
	{
		globalHandle(GLOBAL_REQUEST_MINITANK[0]).At(GLOBAL_REQUEST_MINITANK[1]).As<bool>() = true;
	}
	if (GUI::Option("Request Taxi", ""))
	{
		globalHandle(GLOBAL_REQUEST_TAXI[0]).At(GLOBAL_REQUEST_TAXI[1]).As<bool>() = true;
	}
	if (GUI::Option("Request Airstrike", ""))
	{
		globalHandle(GLOBAL_REQUEST_AIRSTRIKE[0]).At(GLOBAL_REQUEST_AIRSTRIKE[1]).As<bool>() = true;
	}
	if (GUI::Option("Request Helicopter Pickup", ""))
	{
		globalHandle(GLOBAL_REQUEST_HELIPICKUP[0]).At(GLOBAL_REQUEST_HELIPICKUP[1]).As<bool>() = true;
	}
	if (GUI::Option("Request Backup Helicopter", ""))
	{
		globalHandle(GLOBAL_REQUEST_BACKUPHELI[0]).At(GLOBAL_REQUEST_BACKUPHELI[1]).As<bool>() = true;
	}
	if (GUI::Option("Request Ammo Crate", ""))
	{
		globalHandle(GLOBAL_REQUEST_AMMOCRATE[0]).At(GLOBAL_REQUEST_AMMOCRATE[1]).As<bool>() = true;
	}
	if (GUI::Option("Request Ballistic Armour", ""))
	{
		globalHandle(GLOBAL_REQUEST_BALLISTICARMOUR[0]).At(GLOBAL_REQUEST_BALLISTICARMOUR[1]).As<bool>() = true;
	}
}