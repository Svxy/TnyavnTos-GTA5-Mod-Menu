#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
int Stamina, Strength, LungCapacity, Driving, Flying, Shooting, Stealth;
const std::vector <std::string> SkillStats = { "STAM", "STRN", "LUNG", "DRIV", "FLY", "SHO", "STL" };
void GUI::Submenus::RecoveryStatistics()
{
	Stamina = Game::gtao::get_skill_stat(SkillStats[0]);
	Strength = Game::gtao::get_skill_stat(SkillStats[1]);
	LungCapacity = Game::gtao::get_skill_stat(SkillStats[2]);
	Driving = Game::gtao::get_skill_stat(SkillStats[3]);
	Flying = Game::gtao::get_skill_stat(SkillStats[4]);
	Shooting = Game::gtao::get_skill_stat(SkillStats[5]);
	Stealth = Game::gtao::get_skill_stat(SkillStats[6]);
	GUI::Title("Statistics");
	if (GUI::Option("Max All Skills", ""))
	{
		for (const auto& i : SkillStats)
		{
			Game::gtao::set_skill_stat(i, 100);
		}
		Game::notification::Minimap((char*)"Maxed out all skill stats for your current character");
	}
	if (GUI::Int("Stamina", Stamina, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		Game::gtao::set_skill_stat(SkillStats[0], Stamina);
	}
	if (GUI::Int("Strength", Strength, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		Game::gtao::set_skill_stat(SkillStats[1], Strength);
	}
	if (GUI::Int("Lung Capacity", LungCapacity, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		Game::gtao::set_skill_stat(SkillStats[2], LungCapacity);
	}
	if (GUI::Int("Driving", Driving, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		Game::gtao::set_skill_stat(SkillStats[3], Driving);
	}
	if (GUI::Int("Flying", Flying, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		Game::gtao::set_skill_stat(SkillStats[4], Flying);
	}
	if (GUI::Int("Shooting", Shooting, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		Game::gtao::set_skill_stat(SkillStats[5], Shooting);
	}
	if (GUI::Int("Stealth", Stealth, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		Game::gtao::set_skill_stat(SkillStats[6], Stealth);
	}
}