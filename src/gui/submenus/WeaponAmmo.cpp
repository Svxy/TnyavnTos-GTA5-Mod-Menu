#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::WeaponAmmo()
{
	GUI::Title("Ammo Modification");
	GUI::StringVector("Impact", { "Disabled", "Fire", "Airstrike", "Teleport To", "Explosion", "Show Bullet Coord" }, Features::ImpactAmmoVectorPosition, "");
	GUI::StringVector("Custom", { "Disabled", "Valkyrie", "Rhino Tank", "RPG", "Firework" }, Features::CustomAmmoVectorPosition, "");
	GUI::StringVector("Particle", { "Disabled", "Cartoon" }, Features::ParticleAmmoVectorPosition, "");
	GUI::Break("Options", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Delete Gun", Features::DeleteGunBool, "Use SNS Pistol with this option");
	GUI::Toggle("Nerf Bullets", Features::NerfBulletsBool, "Significantly reduces bullet damage");
}