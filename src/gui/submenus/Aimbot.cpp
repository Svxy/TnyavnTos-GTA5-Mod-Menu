#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Aimbot()
{
	GUI::Title("Aimbot");
	GUI::Toggle("Triggerbot", Features::TriggerBotBool, "");
	GUI::StringVector("Bone", { "Head", "Neck", "Right Hand", "Left Hand" }, Features::AimbotBoneVectorPosition, "");
	GUI::Break("Target", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Shoot NPC's", Features::TriggerBot_ShootNPCBool, "Triggerbot shoots at NPC's");
	GUI::Toggle("Shoot Players", Features::TriggerBot_ShootPlayersBool, "Triggerbot shoots at players");
}