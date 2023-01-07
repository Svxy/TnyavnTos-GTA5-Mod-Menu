#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Weapons()
{
	GUI::Title("Weapons");
	if (GUI::Option("Get All Weapons", ""))
	{
		Game::weapon::give_all(PLAYER::PLAYER_PED_ID());
	}
	if (GUI::Option("Clear All Weapons", "Weapons are not permanently removed"))
	{
		if (Features::AutoGiveAllWeaponsBool) { Game::notification::Minimap((char*)"Disable 'Auto Give All Weapons' to use this"); }
		else { WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::PLAYER_PED_ID(), true); }
	}
	GUI::Break("Upgrades", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Max Upgrade All Weapons", "Max Upgrade All Weapons"))
	{
		Game::weapon::max_upgrade_all(PLAYER::PLAYER_PED_ID());
	}
	if (GUI::Option("Max Upgrade Current Weapon", ""))
	{
		Hash CurrentWeapon;
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &CurrentWeapon, true);
		for (auto const& i : game_data::MaxUpgradeWeaponComponents)
		{
			if (i.WeaponHash == CurrentWeapon)
			{
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), i.WeaponHash, MISC::GET_HASH_KEY(helper::StringToChar(i.UpgradeHash)));
			}
		}
	}
	GUI::Break("Auto", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Auto Get All Weapons", Features::AutoGiveAllWeaponsBool, "");
	GUI::Toggle("Auto Get All Weapon Upgrades", Features::AutoGiveAllWeaponUpgradesBool, "");
	GUI::Break("Color", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Rainbow Gun", Features::RainbowGunBool, "");
}