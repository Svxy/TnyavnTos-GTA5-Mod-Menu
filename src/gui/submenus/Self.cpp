#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
float SelfHealth = 200.f;
float SelfMaxHealth = 200.f;
int PlayerWantedLevelInteger = 0;
void GUI::Submenus::Self()
{
	GUI::Title("Self");
	GUI::MenuOption("Model", Submenus::SelfModel);
	GUI::MenuOption("Wardrobe", Submenus::Wardrobe);
	GUI::MenuOption("Globals", Submenus::Globals);
	GUI::MenuOption("Animations", Submenus::Animations);
	GUI::MenuOption("Vision", Submenus::Vision);
	GUI::Toggle("God mode", Features::GodmodeBool, "Makes your character invincible");
	if (GUI::Float("Health", SelfHealth, 1.f, ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), 10.f, "", 0, SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE))
	{
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), SelfHealth, 0);
	}
	if (GUI::Float("Max Health", SelfMaxHealth, 25.f, 1000.f, 25.f, "", 0, SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE))
	{
		ENTITY::SET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID(), SelfMaxHealth);
	}
	GUI::Toggle("Invisible (local)", Features::PlayerInvisibleLocalBool, "Makes your character invisible ~bold~locally");
	GUI::Toggle("Invisible (others)", Features::PlayerInvisibleNetworkBool, "Makes your character invisible ~bold~for other players");
	if (GUI::Int("Opacity", Features::PlayerOpacityInt, 50, 250, 50, "Changes local player opacity", SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE)) { ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), (Features::PlayerOpacityInt), false); }
	GUI::Toggle("No Ragdoll", Features::NoRagdollAndSeatbeltBool, "Disables ragdoll on your character");
	GUI::Toggle("Super Jump", Features::SuperJumpBool, "Makes your character jump higher");
	if (GUI::StringVector("Sprint Speed", { "Disabled", "Fast", "Super" }, Features::FastSuperRunPosition, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		if (Features::FastSuperRunPosition == 0)
		{
			PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.f);
		}
	}
	GUI::Toggle("Never Wanted", Features::NeverWantedBool, "Never get a wanted level");
	if (GUI::Int("Wanted Level", PlayerWantedLevelInteger, 0, 5, 1, "Set Wanted Level", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE)) { Features::NeverWantedBool = false; PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), PlayerWantedLevelInteger, false); PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), false); }
	GUI::Toggle("Explosive Melee", Features::ExplosiveMeleeBool, "Objects you hit with melee explode");
	GUI::Toggle("Tiny Player", Features::TinyPlayerBool, "Lowers your character's scaling");
	GUI::Toggle("Super Man", Features::SuperManBool, "Fly around like a superman!");
	if (GUI::Option("Suicide", "Kill your character")) { PED::APPLY_DAMAGE_TO_PED(PLAYER::PLAYER_PED_ID(), 1000.f, false, false); }
	if (GUI::Option("Clean", "Remove any damage from player character")) { PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID()); PED::RESET_PED_VISIBLE_DAMAGE(PLAYER::PLAYER_PED_ID()); Game::notification::Minimap((char*)"Player Cleaned"); }
}