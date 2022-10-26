#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::WeaponAmmo()
{
	GUI::Title("Ammo Modification");
	GUI::StringVector("Impact", { "Disabled", "Fire", "Airstrike", "Teleport To", "Explosion", "Show Bullet Coord" }, CheatFeatures::ImpactAmmoVectorPosition, "");
	GUI::StringVector("Custom", { "Disabled", "Valkyrie", "Rhino Tank", "RPG", "Firework" }, CheatFeatures::CustomAmmoVectorPosition, "");
	GUI::StringVector("Particle", { "Disabled", "Cartoon" }, CheatFeatures::ParticleAmmoVectorPosition, "");
	GUI::Break("Options", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Delete Gun", CheatFeatures::DeleteGunBool, "Use SNS Pistol with this option");
	GUI::Toggle("Nerf Bullets", CheatFeatures::NerfBulletsBool, "Significantly reduces bullet damage");
}