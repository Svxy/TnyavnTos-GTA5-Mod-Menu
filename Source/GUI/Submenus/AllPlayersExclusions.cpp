#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::AllPlayersExclusions()
{
	GUI::Title("Exclusions");
	GUI::Toggle("Exclude Self", CheatFeatures::AllPlayersExclusionsSelf, "");
	GUI::Toggle("Exclude Friends", CheatFeatures::AllPlayersExclusionsFriends, "");
	GUI::Toggle("Exclude Host", CheatFeatures::AllPlayersExclusionsHost, "");
}