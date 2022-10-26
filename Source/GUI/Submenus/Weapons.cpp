#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Weapons()
{
	GUI::Title("Weapons");
	if (GUI::Option("Get All Weapons", ""))
	{
		GameFunctions::GiveAllWeaponsToPlayer(GameFunctions::PlayerPedID);
	}
	if (GUI::Option("Clear All Weapons", "Weapons are not permanently removed"))
	{
		if (CheatFeatures::AutoGiveAllWeaponsBool) { GameFunctions::MinimapNotification("Disable 'Auto Give All Weapons' to use this"); }
		else { WEAPON::REMOVE_ALL_PED_WEAPONS(GameFunctions::PlayerPedID, true); }
	}
	GUI::Break("Upgrades", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Max Upgrade All Weapons", "Max Upgrade All Weapons"))
	{
		GameFunctions::MaxUpgradeAllWeapons();
	}
	if (GUI::Option("Max Upgrade Current Weapon", ""))
	{
		Hash CurrentWeapon;
		WEAPON::GET_CURRENT_PED_WEAPON(GameFunctions::PlayerPedID, &CurrentWeapon, true);
		for (auto const& i : GameArrays::MaxUpgradeWeaponComponents)
		{
			if (i.WeaponHash == CurrentWeapon)
			{
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(GameFunctions::PlayerPedID, i.WeaponHash, MISC::GET_HASH_KEY(CheatFunctions::StringToChar(i.UpgradeHash)));
			}
		}
	}
	GUI::Break("Auto", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Auto Get All Weapons", CheatFeatures::AutoGiveAllWeaponsBool, "");
	GUI::Toggle("Auto Get All Weapon Upgrades", CheatFeatures::AutoGiveAllWeaponUpgradesBool, "");
	GUI::Break("Color", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Rainbow Gun", CheatFeatures::RainbowGunBool, "");
}