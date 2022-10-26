#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Weapon()
{
	GUI::Title("Weapon");
	GUI::MenuOption("Weapons", Submenus::Weapons);
	GUI::MenuOption("Visuals", Submenus::WeaponVisuals);
	GUI::MenuOption("Ammo Modification", Submenus::WeaponAmmo);
	GUI::MenuOption("Shoot Entities", Submenus::ShootEntities);
	GUI::MenuOption("Aimbot", Submenus::Aimbot);
	GUI::Break("General", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("No Reload", CheatFeatures::NoWeaponReloadBool, "Disables the reload animation of all weapons");
	GUI::Toggle("Infinite Ammo", CheatFeatures::InfiniteAmmoBool, "Never run out of ammo again");
	GUI::Toggle("Rapid Fire", CheatFeatures::WeaponRapidFireBool, "Shoot very fast");
	GUI::Toggle("One Shot One Kill", CheatFeatures::OneHitKillBool, "");
	GUI::Break("Entity Control", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Gravity Gun", CheatFeatures::GravityGunBool, "");
	GUI::Float("Entity Distance", CheatFeatures::GravityGunEntityDistance, 5.f, 25.f, 1.f, "Changing distance is also possible with the scroll wheel", 0);
}