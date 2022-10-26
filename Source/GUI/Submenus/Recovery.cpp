#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Recovery()
{
	GUI::Title("Recovery");
	GUI::MenuOption("Stats", Submenus::RecoveryStatistics);
	GUI::Break("Unlocks", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Unlock All", "Unlocks many unlockable GTA Online items"))
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_10")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_11")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_12")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_8")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_CLOTHES_GV_BS_9")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ADMIN_WEAPON_GV_BS_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AIR_LAUNCHES_OVER_40M")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_5STAR_WANTED_AVOIDANCE")), 50, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_ACTIVATE_2_PERSON_KEY")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_ALL_ROLES_HEIST")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_BUY_EVERY_GUN")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_CAR_BOMBS_ENEMY_KILLS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_CARS_EXPORTED")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_CONTROL_CROWDS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_DAILYOBJCOMPLETED")), 100, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_DAILYOBJMONTHBONUS")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_DAILYOBJWEEKBONUS")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_DO_HEIST_AS_MEMBER")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_DO_HEIST_AS_THE_LEADER")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_DRIVELESTERCAR5MINS")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_DROPOFF_CAP_PACKAGES")), 100, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FINISH_HEIST_NO_DAMAGE")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FINISH_HEIST_SETUP_JOB")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FINISH_HEISTS")), 50, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM25DIFFERENTDM")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM25DIFFERENTRACES")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM25DIFITEMSCLOTHES")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM6DARTCHKOUT")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_KILLSTREAK")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_STOLENKILL")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_TOTALKILLS")), 500, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_WINS")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GOLF_BIRDIES")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GOLF_HOLE_IN_1")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GOLF_WON")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GTA_RACES_WON")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_RACE_LAST_FIRST")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_RACES_FASTEST_LAP")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_CT_WON")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_GRAN_WON")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_RT_WON")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_TG_WON")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TDM_MVP")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TDM_WINS")), 50, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_5_SET_WINS")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_ACE")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_STASETWIN")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_WON")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMATTGANGHQ")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMBASEJMP")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMBBETWIN")), 50000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMCRATEDROPS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMDRIVEWITHOUTCRASH")), 30, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMFULLYMODDEDCAR")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMHORDWAVESSURVIVE")), 10, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILL3ANDWINGTARACE")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILLBOUNTY")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILLSTREAKSDM")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMMOSTKILLSGANGHIDE")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMMOSTKILLSSURVIVE")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMPICKUPDLCCRATE1ST")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMRACEWORLDRECHOLDER")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMRALLYWONDRIVE")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMRALLYWONNAV")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMREVENGEKILLSDM")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMSHOOTDOWNCOPHELI")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMTATTOOALLBODYPARTS")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINAIRRACE")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINALLRACEMODES")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINCUSTOMRACE")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINEVERYGAMEMODE")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINRACETOPOINTS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINSEARACE")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_HOLD_UP_SHOPS")), 20, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_KILL_CARRIER_CAPTURE")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_KILL_PSYCHOPATHS")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_KILL_TEAM_YOURSELF_LTS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_LAPDANCES")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_LESTERDELIVERVEHICLES")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_MENTALSTATE_TO_NORMAL")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_NIGHTVISION_KILLS")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_NO_HAIRCUTS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_ODISTRACTCOPSNOEATH")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_ONLY_PLAYER_ALIVE_LTS")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_PARACHUTE_JUMPS_20M")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_PARACHUTE_JUMPS_50M")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_PASSENGERTIME")), 4, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_PICKUP_CAP_PACKAGES")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_RACES_WON")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_SECURITY_CARS_ROBBED")), 25, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_SPLIT_HEIST_TAKE_EVENLY")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_STORE_20_CAR_IN_GARAGES")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_TAKEDOWNSMUGPLANE")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_TIME_IN_HELICOPTER")), 4, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_TRADE_IN_YOUR_PROPERTY")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_VEHICLES_JACKEDR")), 500, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_WIN_AT_DARTS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_WIN_CAPTURE_DONT_DYING")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_WIN_CAPTURES")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_WIN_GOLD_MEDAL_HEISTS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_WIN_LAST_TEAM_STANDINGS")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_BOTTLE_IN_POSSESSION")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CARS_EXPLODED")), 500, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_CARMOD_1_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_CARMOD_2_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_CARMOD_3_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_CARMOD_4_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_CARMOD_5_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_CARMOD_6_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_CARMOD_7_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_VEHICLE_1_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_VEHICLE_2_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_WEAP_ADDON_1_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_WEAP_ADDON_2_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_WEAP_ADDON_3_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_WEAP_ADDON_4_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_WEAP_ADDON_5_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_WEAP_UNLOCKED")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_WEAP_UNLOCKED2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_10_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_11_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_12_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_1_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_2_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_3_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_4_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_5_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_6_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_7_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_8_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_9_FM_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE10")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE11")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE12")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE8")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHASE9")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_WANTED_LEVEL_TIME5STAR")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_WEAP_FM_PURCHASE")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_WEAP_FM_PURCHASE2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_BERD")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_BERD_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_BERD_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_BERD_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_BERD_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_BERD_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_BERD_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_DECL")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_FEET_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_JBIB_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_LEGS_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_OUTFIT")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_10")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_8")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_PROPS_9")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL2_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_SPECIAL_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_TEETH")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_TEETH_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_TEETH_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_ACQUIRED_TORSO")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_BERD_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_DECL")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_FEET_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_HAIR_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_JBIB_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_LEGS_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_OUTFIT")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_10")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_8")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_PROPS_9")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL2_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_SPECIAL_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_TEETH")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_TEETH_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_TEETH_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLTHS_AVAILABLE_TORSO")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_0")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_10")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_11")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_12")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_13")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_14")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_15")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_16")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_17")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_18")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_19")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_20")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_21")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_22")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_23")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_24")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_25")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_26")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_27")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_28")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_29")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_30")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_31")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_32")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_33")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_34")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_35")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_36")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_37")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_38")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_39")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_40")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_8")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DLC_APPAREL_ACQUIRED_9")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_GRENADE_ENEMY_KILLS")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_KILLS_PLAYERS")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LONGEST_WHEELIE_DIST")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MOST_ARM_WRESTLING_WINS")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MOST_FLIPS_IN_ONE_JUMP")), 5, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MOST_SPINS_IN_ONE_JUMP")), 5, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_NUMBER_SLIPSTREAMS_IN_RACE")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_NUMBER_TURBO_STARTS_IN_RACE")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PASS_DB_PLAYER_KILLS")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PISTOL_ENEMY_KILLS")), 500, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PLAYER_HEADSHOTS")), 500, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_RACES_WON")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SAWNOFF_ENEMY_KILLS")), 500, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_DRIV")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_FLY")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_LUNG")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_MECH")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_SHO")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_STAM")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_STL")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_STRN")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_STKYBMB_ENEMY_KILLS")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_UNARMED_ENEMY_KILLS")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_USJS_COMPLETED")), 50, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_WEAP_FM_ADDON_PURCH")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_WEAP_FM_ADDON_PURCH2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_WEAP_FM_ADDON_PURCH3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_WEAP_FM_ADDON_PURCH4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_WEAP_FM_ADDON_PURCH5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CRDEADLINE")), 10, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_ABILITY_1_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_ABILITY_2_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_ABILITY_3_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_ABILITY_1_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_ABILITY_2_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_ABILITY_3_UNLCK")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BUY_COMPLETE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BUY_UNDERTAKEN")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_SELL_COMPLETE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_SELL_UNDERTAKEN")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_CONTRA_EARNINGS")), 20000000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_COMPLET")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_UNDERTA")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_COMPLET")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_UNDERTA")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_COMPLET1")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_UNDERTA1")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_COMPLET1")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_UNDERTA1")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_COMPLET2")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_UNDERTA2")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_COMPLET2")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_UNDERTA2")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_COMPLET3")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_UNDERTA3")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_COMPLET3")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_UNDERTA3")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_COMPLET4")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_UNDERTA4")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_COMPLET4")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_UNDERTA4")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_COMPLET5")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_BUY_UNDERTA5")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_COMPLET5")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BIKER_SELL_UNDERTA5")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BKR_SELL_EARNINGS0")), 20000000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BKR_SELL_EARNINGS1")), 20000000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BKR_SELL_EARNINGS2")), 20000000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BKR_SELL_EARNINGS3")), 20000000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BKR_SELL_EARNINGS4")), 20000000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LIFETIME_BKR_SELL_EARNINGS5")), 20000000, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_COMPLET_HEIST_MEM")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_FLEECA_FIN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_HST_ORDER")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_HST_SAME_TEAM")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_HST_ULT_CHAL")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_HUMANE_FIN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_PACIFIC_FIN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_PRISON_FIN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_SERIESA_FIN")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_HEIST_ACH_TRACKER")), -1, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_IAA")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_SUBMARINE")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_ALLINORDER")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_LOYALTY")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_CRIMMASMD")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_MISSILE")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_LOYALTY2")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_LOYALTY3")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_CRIMMASMD2")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_CRIMMASMD3")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_GANGOPS_SUPPORT")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_NO_BOUGHT_YUM_SNACKS")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_NO_BOUGHT_HEALTH_SNACKS")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_NO_BOUGHT_EPIC_SNACKS")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_NUMBER_OF_ORANGE_BOUGHT")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MP_CHAR_ARMOUR_1_COUNT")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MP_CHAR_ARMOUR_2_COUNT")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MP_CHAR_ARMOUR_3_COUNT")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MP_CHAR_ARMOUR_4_COUNT")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MP_CHAR_ARMOUR_5_COUNT")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_NUMBER_OF_BOURGE_BOUGHT")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_1_WHITE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_1_RED")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_1_BLUE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_2_WHITE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_2_RED")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_2_BLUE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_3_WHITE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_3_RED")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_3_BLUE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_4_WHITE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_4_RED")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FIREWORK_TYPE_4_BLUE")), 1000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_FM_CR_DM_MADE")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_FM_CR_PLAYED_BY_PEEP")), 100, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_FM_CR_RACES_MADE")), 25, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PHN")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH2")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH3")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH4")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH5")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_VEH_TX1")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH6")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH7")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH8")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_ACT_PH9")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SNIPERRFL_ENEMY_KILLS")), 500, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_HVYSNIPER_ENEMY_KILLS")), 500, true);



		GameFunctions::MinimapNotification("'Unlocked All' completed");
	}
	if (GUI::Option("Unlock Tattoo's", "Unlock most tattoo's"))
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_WINS")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TDM_MVP")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_TOTALKILLS")), 500, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMATTGANGHQ")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMBBETWIN")), 50000, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINEVERYGAMEMODE")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMRACEWORLDRECHOLDER")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMFULLYMODDEDCAR")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMMOSTKILLSSURVIVE")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILL3ANDWINGTARACE")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILLBOUNTY")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMREVENGEKILLSDM")), 50, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILLSTREAKSDM")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_HOLD_UP_SHOPS")), 20, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_LAPDANCES")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_SECURITY_CARS_ROBBED")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_RACES_WON")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_CAR_BOMBS_ENEMY_KILLS")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PLAYER_HEADSHOTS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_DB_PLAYER_KILLS")), 1000, 1);
	}
	if (GUI::Option("Unlock Heist Vehicles", "Unlock Heist Vehicles"))
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E2")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E3")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E4")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E5")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E6")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E7")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E8")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E9")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E10")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E11")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_FM_PURCHAS E12")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_1_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_2_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_3_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_4_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_5_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_6_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_7_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_8_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_9_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_10_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_11_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_KIT_12_FM_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_races_won")), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_number_turbo_starts_in_race")), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_usjs_found")), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_usjs_completed")), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_awd_fmwinairrace")), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_awd_fmwinsearace")), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_awd_fmrallywonnav")), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_awd_fmrallywondrive ")), 500, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_awd_fm_races_fastest_lap")), 500, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_0_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_1_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_2_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_3_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_4_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_5_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_6_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_char_fm_carmod_7_unlck")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_VEHICLE_1_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_VEHICLE_2_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_ABILITY_1_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_ABILITY_2_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_ABILITY_3_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_1_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_2_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_3_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_4_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_5_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_6_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_7_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_8_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_PACKAGE_9_COLLECT")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_HEALTH_1_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_FM_HEALTH_2_UNLCK")), -1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_HOLDUPS_BITSET")), -1, 0);
	}
	if (GUI::Option("Unlock Awards & Trophies", ""))
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PLAYER_HEADSHOTS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PISTOL_ENEMY_KILLS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SAWNOFF_ENEMY_KILLS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MICROSMG_ENEMY_KILLS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SNIPERRFL_ENEMY_KILLS")), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_UNARMED_ENEMY_KILLS")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_STKYBMB_ENEMY_KILLS")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_GRENADE_ENEMY_KILLS")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_RPG_ENEMY_KILLS")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CARS_EXPLODED")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_5STAR_WANTED_AVOIDANCE")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_CAR_BOMBS_ENEMY_KILLS")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_CARS_EXPORTED")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PASS_DB_PLAYER_KILLS")), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_WINS")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GOLF_WON")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GTA_RACES_WON")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_CT_WON")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_RT_WON")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_TG_WON")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TDM_WINS")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_WON")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MOST_SPINS_IN_ONE_JUMP")), 5, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_FM_CR_DM_MADE")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMHORDWAVESSURVIVE")), 10, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_HOLD_UP_SHOPS")), 20, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ASLTRIFLE_ENEMY_KILLS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MG_ENEMY_KILLS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_LAPDANCES")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MOST_ARM_WRESTLING_WINS")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_NO_HAIRCUTS")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_RACES_WON")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_SECURITY_CARS_ROBBED")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_VEHICLES_JACKEDR")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_MOST_FLIPS_IN_ONE_JUMP")), 5, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_WIN_AT_DARTS")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_PASSENGERTIME")), 4, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_TIME_IN_HELICOPTER")), 4, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_3KILLSAMEGUY")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_KILLSTREAK")), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_STOLENKILL")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_DM_TOTALKILLS")), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GOLF_BIRDIES")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_GOLF_HOLE_IN_1")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_RACE_LAST_FIRST")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_RACES_FASTEST_LAP")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_SHOOTRANG_GRAN_WON")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TDM_MVP")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_ACE")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_STASETWIN")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM6DARTCHKOUT")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMATTGANGHQ")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_PARACHUTE_JUMPS_20M")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_PARACHUTE_JUMPS_50M")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AIR_LAUNCHES_OVER_40M")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_BUY_EVERY_GUN")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINEVERYGAMEMODE")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMDRIVEWITHOUTCRASH")), 255, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMCRATEDROPS")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM25DIFFERENTDM")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM_TENNIS_5_SET_WINS")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_FM_CR_PLAYED_BY_PEEP")), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "MPPLY_AWD_FM_CR_RACES_MADE")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM25DIFFERENTRACES")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FM25DIFITEMSCLOTHES")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMFULLYMODDEDCAR")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILLBOUNTY")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_KILLS_PLAYERS")), 1000, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMPICKUPDLCCRATE1ST")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMSHOOTDOWNCOPHELI")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILL3ANDWINGTARACE")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMKILLSTREAKSDM")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMMOSTKILLSGANGHIDE")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMMOSTKILLSSURVIVE")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMRACEWORLDRECHOLDER")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMRALLYWONDRIVE")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMRALLYWONNAV")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMREVENGEKILLSDM")), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINAIRRACE")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINCUSTOMRACE")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINRACETOPOINTS")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMWINSEARACE")), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMBASEJMP")), 25, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "__AWD_FMWINALLRACEMODES")), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_AWD_FMTATTOOALLBODYPARTS")), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CHAR_WANTED_LEVEL_TIME5STAR")), 2147483647, 1);
		STATS::STAT_SET_FLOAT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LONGEST_WHEELIE_DIST")), 1000, 1);
		GameFunctions::MinimapNotification("GTA Online Awards & Trophies unlocked");
	}
	if (GUI::Option("Allow Character Gender Change", ""))
	{
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_ALLOW_GENDER_CHANGE")), true, true);
	}
	if (GUI::Option("Complete Flight School", ""))
	{
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_0")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_1")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_2")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_3")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_4")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_5")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_6")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_7")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_8")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_ASPASSEDLESSON_9")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_0")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_1")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_2")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_3")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_4")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_5")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_6")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_7")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_8")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PILOT_SCHOOL_MEDAL_9")), true, true);
	}
	if (GUI::Option("Unlock Increased Throwables Amount", "Also unlocks Shooting Range High Score"))
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_HIGHSCORE_1")), 690, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_HIGHSCORE_2")), 1860, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_HIGHSCORE_3")), 2690, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_HIGHSCORE_4")), 2660, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_HIGHSCORE_5")), 2650, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_HIGHSCORE_6")), 450, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_TARGETS_HIT")), 269, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_WEAPON_BIT_SET")), 0xFFFFFFFF, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_TIER_1_REWARD")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_INCREASE_THROW_CAP")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_SR_TIER_3_REWARD")), true, true);
	}
	if (GUI::Option("Skip Casino Mission and unlock Armored Paragon", ""))
	{
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_FLOW_CS_RSC_SEEN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_FLOW_CS_BWL_SEEN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_FLOW_CS_MTG_SEEN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_FLOW_CS_OIL_SEEN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_FLOW_CS_DEF_SEEN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_FLOW_CS_FIN_SEEN")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CAS_VEHICLE_REWARD")), false, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CASINOPSTAT_BOOL0")), true, true);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CASINOPSTAT_BOOL1")), true, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_FLOW_PROGRESS")), -1, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_VCM_STORY_PROGRESS")), -1, true);
	}
	if (GUI::Option("Unlock All Bunker Missions", ""))
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_LFETIME_BIKER_BUY_COMPLET5")), 14, true);
	}
	GUI::Break("Rank", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Set Rank", "Input a custom Rank"))
	{
		int Rank;
		if (GameFunctions::DisplayKeyboardAndReturnInputInteger(4, "Enter desired rank", Rank))
		{
			GameFunctions::SetRankRockstarGift(Rank);
		}
	}
	GUI::Break("Money", SELECTABLE_CENTER_TEXT);
	GUI::Break("Wallet balance: ~g~$~s~" + std::to_string(MONEY::NETWORK_GET_VC_WALLET_BALANCE(-1)));
	GUI::Break("Bank balance: ~g~$~s~" + std::to_string(MONEY::NETWORK_GET_VC_BANK_BALANCE()));
	GUI::Break("Miscellaneous", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Set Max Nightclub Popularity", "Set NightClub Popularity to 100%"))
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_CLUB_POPULARITY")), 9999, false);
		GameFunctions::MinimapNotification("Maxed out Nightclub Popularity");
	}
	if (GUI::Option("Redesign Character Prompt", ""))
	{
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_FM_CHANGECHAR_ASKED")), false, true);
		GameFunctions::MinimapNotification("Leave GTAO and rejoin to receive the notification");
	}
	if (GUI::Option("Clear Badsport", "Clears Badsport status"))
	{
		DWORD date[12];
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MPPLY_CHAR_IS_BADSPORT "), false, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), false, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), false, true);
		STATS::STAT_SET_DATE(MISC::GET_HASH_KEY("MPPLY_BECAME_BADSPORT_DT"), &date[0], 7, true);
		GameFunctions::MinimapNotification("Cleared Badsport Status");
	}
	if (GUI::Option("Clear Mental State", "Clear current mental state"))
	{
		STATS::STAT_SET_FLOAT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(GameFunctions::ReturnCurrentGTAOCharacter() + "_PLAYER_MENTAL_STATE")), 0.0f, true);
		GameFunctions::MinimapNotification("Mental State Reset");
	}

	GUI::Break("MONEY CHEAT", SELECTABLE_CENTER_TEXT);
	//void(MONEY::NETWORK_EARN_FROM_ROCKSTAR(500000));
	if (GUI::Option("Add money to ur balance", "Be Careful"))
	{
		MONEY::NETWORK_EARN_FROM_PICKUP(500000);
	}


	GUI::Break("ATM", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Move Wallet To Bank", ""))
	{
		const char* KeyboardInput;
		if (GameFunctions::DisplayKeyboardAndReturnInput(30, "Enter amount to move. Type \"all\" to move all money.", KeyboardInput))
		{
			int Amount = CheatFunctions::StringToInt(KeyboardInput);
			if (KeyboardInput == "all")
			{
				Amount = MONEY::NETWORK_GET_VC_WALLET_BALANCE(-1);
			}
			NETSHOPPING::_NET_GAMESERVER_TRANSFER_WALLET_TO_BANK(CheatFunctions::StringToInt(GameFunctions::ReturnCurrentGTAOCharacter(true)), Amount);
		}
	}
	if (GUI::Option("Move Bank To Wallet", ""))
	{
		const char* KeyboardInput;
		if (GameFunctions::DisplayKeyboardAndReturnInput(30, "Enter amount to move. Type \"all\" to move all money.", KeyboardInput))
		{
			int Amount = CheatFunctions::StringToInt(KeyboardInput);
			if (KeyboardInput == "all")
			{
				Amount = MONEY::NETWORK_GET_VC_BANK_BALANCE();
			}
			NETSHOPPING::_NET_GAMESERVER_TRANSFER_BANK_TO_WALLET(CheatFunctions::StringToInt(GameFunctions::ReturnCurrentGTAOCharacter(true)), Amount);
		}
	}
}