#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int Stamina, Strength, LungCapacity, Driving, Flying, Shooting, Stealth;
const std::vector <std::string> SkillStats = { "STAM", "STRN", "LUNG", "DRIV", "FLY", "SHO", "STL" };
void GUI::Submenus::RecoveryStatistics()
{
	Stamina = GameFunctions::GetCharacterSkillStat(SkillStats[0]);
	Strength = GameFunctions::GetCharacterSkillStat(SkillStats[1]);
	LungCapacity = GameFunctions::GetCharacterSkillStat(SkillStats[2]);
	Driving = GameFunctions::GetCharacterSkillStat(SkillStats[3]);
	Flying = GameFunctions::GetCharacterSkillStat(SkillStats[4]);
	Shooting = GameFunctions::GetCharacterSkillStat(SkillStats[5]);
	Stealth = GameFunctions::GetCharacterSkillStat(SkillStats[6]);
	GUI::Title("Statistics");
	if (GUI::Option("Max All Skills", ""))
	{
		for (const auto& i : SkillStats)
		{
			GameFunctions::SetCharacterSkillStat(i, 100);
		}
		GameFunctions::MinimapNotification("Maxed out all skill stats for your current character");
	}
	if (GUI::Int("Stamina", Stamina, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		GameFunctions::SetCharacterSkillStat(SkillStats[0], Stamina);
	}
	if (GUI::Int("Strength", Strength, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		GameFunctions::SetCharacterSkillStat(SkillStats[1], Strength);
	}
	if (GUI::Int("Lung Capacity", LungCapacity, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		GameFunctions::SetCharacterSkillStat(SkillStats[2], LungCapacity);
	}
	if (GUI::Int("Driving", Driving, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		GameFunctions::SetCharacterSkillStat(SkillStats[3], Driving);
	}
	if (GUI::Int("Flying", Flying, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		GameFunctions::SetCharacterSkillStat(SkillStats[4], Flying);
	}
	if (GUI::Int("Shooting", Shooting, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		GameFunctions::SetCharacterSkillStat(SkillStats[5], Shooting);
	}
	if (GUI::Int("Stealth", Stealth, 0, 100, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		GameFunctions::SetCharacterSkillStat(SkillStats[6], Stealth);
	}
}