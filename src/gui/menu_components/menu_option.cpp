#include "../../cheat/fibermain.hpp"

using namespace Cheat;

bool GUI::MenuOptionArrowAnimationState = false;
bool GUI::MenuOption(std::string option, void* NewSubmenu, int BitFlags)
{
	if (Option(option, "", BitFlags))
	{
		GUI::MoveMenu(NewSubmenu);
		return true;
	}

	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		DrawTextInGame(MenuOptionArrowAnimationState ? ">" : " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 43 / 100), GUI::guiY + (GUI::optionCount)*SelectableHeight - 0.174f }, { 0.35f, 0.35f }, false);
	}
	else if (GUI::optionCount > (GUI::currentOption - GUI::maxVisOptions) && GUI::optionCount <= GUI::currentOption)
	{
		DrawTextInGame(MenuOptionArrowAnimationState ? ">" : " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 43 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.35f, 0.35f }, false);
	}
	return false;
}