#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::WeaponVisuals()
{
	GUI::Title("Visuals");
	GUI::Toggle("Weapon Invisibility", Features::WeaponInvisibilityBool, "");
	GUI::Toggle("Crosshair", Features::CrossHairBool, "");
	GUI::Toggle("Crosshair -> ADS only", Features::CrossHairADSOnlyBool, "");
	GUI::Toggle("Entity Information Gun", Features::EntityInformationGunBool, "Shows info about aimed entity");
}