#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
int intexploits, intoffensive, REPORTSTRENGTH, OFFENSIVETAGPLATE, OFFENSIVEUGC,
EXPLOITS, GRIEFING, COMMENDSTRENGTH, FRIENDLY, HELPFUL, VCANNOYINGME, VCHATE,
BADCREWNAME, BADCREWMOTTO, BADCREWSTATUS, BADCREWEMBLEM, ISPUNISHED;
void GUI::Submenus::ReportStatistics()
{
	GUI::Title("Report Statistics");
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), &REPORTSTRENGTH, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &intexploits, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), &intoffensive, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), &OFFENSIVETAGPLATE, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), &OFFENSIVEUGC, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_EXPLOITS"), &EXPLOITS, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), &GRIEFING, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), &COMMENDSTRENGTH, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), &FRIENDLY, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), &HELPFUL, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), &VCANNOYINGME, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_VC_HATE"), &VCHATE, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_BAD_CREW_NAME"), &BADCREWNAME, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_BAD_CREW_MOTTO"), &BADCREWMOTTO, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_BAD_CREW_STATUS"), &BADCREWSTATUS, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_BAD_CREW_EMBLEM"), &BADCREWEMBLEM, -1);
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_ISPUNISHED"), &ISPUNISHED, -1);
	GUI::Option("Report Strength: " + std::to_string(REPORTSTRENGTH), "");
	GUI::Option("Game Exploits: " + std::to_string(intexploits), "");
	GUI::Option("Offensive Language: " + std::to_string(intoffensive), "");
	GUI::Option("Offensive Tagplate: " + std::to_string(OFFENSIVETAGPLATE), "");
	GUI::Option("Offensive UGC: " + std::to_string(OFFENSIVEUGC), "");
	GUI::Option("Exploits: " + std::to_string(EXPLOITS), "");
	GUI::Option("Griefing: " + std::to_string(GRIEFING), "");
	GUI::Option("Friendly: " + std::to_string(FRIENDLY), "");
	GUI::Option("Helpful: " + std::to_string(HELPFUL), "");
	GUI::Option("VC Annoying Me: " + std::to_string(VCANNOYINGME), "");
	GUI::Option("Vchate: " + std::to_string(VCHATE), "");
	GUI::Option("Bad Crew Name: " + std::to_string(BADCREWNAME), "");
	GUI::Option("Bad Crew Motto: " + std::to_string(BADCREWMOTTO), "");
	GUI::Option("Bad Crew Status: " + std::to_string(BADCREWSTATUS), "");
	GUI::Option("Bad Crew Emblem: " + std::to_string(BADCREWEMBLEM), "");
	GUI::Option("Is Punished: " + std::to_string(ISPUNISHED), "");
}