#include "../../cheat/fibermain.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;

std::string Game::InGameHelpTextMessage;
GetLabelText GameHooking::GetLabelTextOriginal = nullptr;
const char* GetLabelTextHooked(void* this_, const char* label)
{
	// Some standard loading related GXT strings - TODO
	if (std::strcmp(label, "HUD_MPREENTER") == 0) { return "Joining a New GTA Online Session with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "HUD_JOINING") == 0) { return "Loading GTA Online with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "HUD_QUITTING") == 0) { return "Leaving GTA Online with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "PM_QUIT_MP") == 0) { return "Leave GTA Online with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "PM_ENTER_MP") == 0) { return "Join GTA Online with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "PM_EXIT_GAME") == 0) { return "Exit Game with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "PM_GO") == 0) { return "Go Online with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "PM_FRIEND_FM") == 0) { return "Join Friend with TnyavnTos GTA 5 Mod Menu"; }
	if (std::strcmp(label, "PM_FIND_SESS") == 0) { return "Find New Session with TnyavnTos GTA 5 Mod Menu"; }
	
	// Modify FMMC_KEY_TIP8 string for DISPLAY_ONSCREEN_KEYBOARD title text
	if (!Game::keyboard::keyboard_title.empty())
		if (label == "FMMC_KEY_TIP8")
			return helper::StringToChar(Game::keyboard::keyboard_title);

	// Modify LETTERS_HELP2 string for DISPLAY_HELP_TEXT_THIS_FRAME text
	if (!Game::InGameHelpTextMessage.empty())
		if (label == "LETTERS_HELP2")
			return helper::StringToChar(Game::InGameHelpTextMessage);

	return GameHooking::GetLabelTextOriginal(this_, label);
}