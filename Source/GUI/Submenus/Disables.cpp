#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Disables()
{
	GUI::Title("Disables");
	GUI::Toggle("Transaction Error Warnings", CheatFeatures::DisableTransactionErrorWarning, "");
	GUI::Toggle("Cutscenes", CheatFeatures::DisableCutscenes, "");
	GUI::Toggle("Mobile Phone", CheatFeatures::DisableMobilePhoneBool, "");
}