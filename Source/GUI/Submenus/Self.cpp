#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
float SelfHealth = 200.f;
float SelfMaxHealth = 200.f;
int PlayerWantedLevelInteger = 0;
void GUI::Submenus::Self()
{
	GUI::Title("Self");
	GUI::MenuOption("Model", Submenus::SelfModel);
	GUI::MenuOption("Globals", Submenus::Globals);
	GUI::MenuOption("Animations", Submenus::Animations);
	GUI::MenuOption("Wardrobe", Submenus::Wardrobe);
	GUI::MenuOption("Vision", Submenus::Vision);
	GUI::Toggle("God mode", CheatFeatures::GodmodeBool, "Makes your character invincible");
	if (GUI::Float("Health", SelfHealth, 1.f, ENTITY::GET_ENTITY_MAX_HEALTH(GameFunctions::PlayerPedID), 10.f, "", 0, SELECTABLE_RETURN_VALUE_CHANGE))
	{
		ENTITY::SET_ENTITY_HEALTH(GameFunctions::PlayerPedID, SelfHealth, 0);
	}
	if (GUI::Float("Max Health", SelfMaxHealth, 25.f, 1000.f, 25.f, "", 0, SELECTABLE_RETURN_VALUE_CHANGE))
	{
		ENTITY::SET_ENTITY_MAX_HEALTH(GameFunctions::PlayerPedID, SelfMaxHealth);
	}
	GUI::Toggle("Invisible (local)", CheatFeatures::PlayerInvisibleLocalBool, "Makes your character invisible ~bold~locally~s~");
	GUI::Toggle("Invisible (others)", CheatFeatures::PlayerInvisibleNetworkBool, "Makes your character invisible ~bold~for other players~s~");
	if (GUI::Int("Opacity", CheatFeatures::PlayerOpacityInt, 50, 250, 50, "Changes local player opacity", SELECTABLE_RETURN_VALUE_CHANGE)) { ENTITY::SET_ENTITY_ALPHA(GameFunctions::PlayerPedID, (CheatFeatures::PlayerOpacityInt), false); }
	GUI::Toggle("No Ragdoll", CheatFeatures::NoRagdollAndSeatbeltBool, "Disables ragdoll on your character");
	GUI::Toggle("Super Jump", CheatFeatures::SuperJumpBool, "Makes your character jump higher");
	if (GUI::StringVector("Sprint Speed", { "Disabled", "Fast", "Super" }, CheatFeatures::FastSuperRunPosition, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		if (CheatFeatures::FastSuperRunPosition == 0)
		{
			PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(GameFunctions::PlayerID, 1.f);
		}
	}
	GUI::Toggle("Ignored By Everyone", CheatFeatures::PlayerIgnoredBool, "NPC's will (mostly) ignore you");
	GUI::Toggle("Never Wanted", CheatFeatures::NeverWantedBool, "Never get a wanted level");
	if (GUI::Int("Wanted Level", PlayerWantedLevelInteger, 0, 5, 1, "Set Wanted Level", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE)) { CheatFeatures::NeverWantedBool = false; PLAYER::SET_PLAYER_WANTED_LEVEL(GameFunctions::PlayerID, PlayerWantedLevelInteger, false); PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(GameFunctions::PlayerID, false); }
	GUI::Toggle("Explosive Melee", CheatFeatures::ExplosiveMeleeBool, "Objects you hit with melee explode");
	GUI::Toggle("Tiny Player", CheatFeatures::TinyPlayerBool, "Lowers your character's scaling");
	GUI::Toggle("Super Man", CheatFeatures::SuperManBool, "Fly around like a superman!");
	if (GUI::Option("Suicide", "Kill your character")) { PED::APPLY_DAMAGE_TO_PED(GameFunctions::PlayerPedID, 1000.f, false, false); }
	if (GUI::Option("Clean", "Remove any damage from player character")) { PED::CLEAR_PED_BLOOD_DAMAGE(GameFunctions::PlayerPedID); PED::RESET_PED_VISIBLE_DAMAGE(GameFunctions::PlayerPedID); GameFunctions::MinimapNotification("Player Cleaned"); }
}