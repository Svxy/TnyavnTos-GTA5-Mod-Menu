#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Aimbot()
{
	GUI::Title("Aimbot");
	GUI::Toggle("Triggerbot", CheatFeatures::TriggerBotBool, "");
	GUI::StringVector("Bone", { "Head", "Neck", "Right Hand", "Left Hand" }, CheatFeatures::AimbotBoneVectorPosition, "");
	GUI::Break("Target", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Shoot NPC's", CheatFeatures::TriggerBot_ShootNPCBool, "Triggerbot shoots at NPC's");
	GUI::Toggle("Shoot Players", CheatFeatures::TriggerBot_ShootPlayersBool, "Triggerbot shoots at players");
}