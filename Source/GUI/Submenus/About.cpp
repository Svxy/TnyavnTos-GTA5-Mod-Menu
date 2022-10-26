#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::About()
{
	GUI::Title("About");
	GUI::Break("Author: TnyavnTo");
	if (GUI::Option("Support this project!", "Select to copy Bitcoin address to clipboard"))
	{
		CheatFunctions::CopyStringToClipboard("198P1gtpx4bao3nCXTZ1km3z7L6oRSoRjE");
		GameFunctions::SubtitleNotification("~g~Bitcoin address copied to clipboard.~n~Thank you for your support!");
	}
	if (GUI::Option("Unload Cheat", ""))
	{
		CheatFunctions::UnloadCheat();
	}
}