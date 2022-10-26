#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::RecoverySubmenuWarning()
{
	if (CheatFunctions::CheatInitEntirelyCompleted)
	{
		if (GameFunctions::ShowFullScreenMessage("Using features located within this submenu~n~could result in an account ban"))
		{
			GUI::CloseMenuGUI();
			GUI::MoveMenu(Home);
			GUI::MoveMenu(Recovery);
		}
		else
		{
			GUI::CloseMenuGUI();
			GUI::MoveMenu(Home);
		}
	}
}