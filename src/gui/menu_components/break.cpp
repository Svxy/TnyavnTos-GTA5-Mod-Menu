#include "../../cheat/fibermain.hpp"

using namespace Cheat;

void GUI::Break(std::string option, int BitFlags)
{
	GUI::optionCount++;

	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		if (BitFlags & SELECTABLE_CENTER_TEXT)
		{
			DrawTextInGame("[ ~c~" + option + " ~s~]", { PrimaryColor.r, PrimaryColor.g, PrimaryColor.b, PrimaryColor.a, TextColorAndFont.f }, { GUI::guiX, GUI::guiY + (GUI::optionCount)*SelectableHeight - 0.174f }, { 0.35f, 0.35f }, true, true);
		}
		else
		{
			DrawTextInGame(option, TextColorAndFont, { GUI::guiX - (GUI::guiWidth * 48 / 100), GUI::guiY + (GUI::optionCount)*SelectableHeight - 0.174f }, { 0.35f, 0.35f }, false);
		}
		DrawRectInGame({ 0, 0, 0, SelectableTransparency }, { GUI::guiX, GUI::guiY + (GUI::optionCount)*SelectableHeight - 0.1585f }, { GUI::guiWidth, SelectableHeight });
	}
	else if (GUI::optionCount > (GUI::currentOption - GUI::maxVisOptions) && GUI::optionCount <= GUI::currentOption)
	{
		if (BitFlags & SELECTABLE_CENTER_TEXT)
		{
			DrawTextInGame("[ ~c~" + option + " ~s~]", { PrimaryColor.r, PrimaryColor.g, PrimaryColor.b, PrimaryColor.a, TextColorAndFont.f }, { GUI::guiX, GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.35f, 0.35f }, true, true);
		}
		else
		{
			DrawTextInGame(option, TextColorAndFont, { GUI::guiX - (GUI::guiWidth * 48 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.35f, 0.35f }, false);
		}
		DrawRectInGame({ 0, 0, 0, SelectableTransparency }, { GUI::guiX, GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.1585f }, { GUI::guiWidth, SelectableHeight });
	}

	if (GUI::optionCount == GUI::currentOption)
	{
		if (GUI::previousOption < GUI::currentOption && GUI::optionCount > 1)
		{
			GUI::currentOption++;
			if (GUI::TotalOptionsCount < GUI::currentOption)
			{
				GUI::currentOption = 1;
			}
		}
		else if (GUI::previousOption > GUI::currentOption && GUI::optionCount > 1)
		{
			GUI::currentOption--;
			if (GUI::TotalOptionsCount < 1)
			{
				GUI::currentOption = GUI::optionCount;
			}
		}
		else if (GUI::currentOption == 1 && GUI::TotalOptionsCount > 1)
		{
			GUI::currentOption++;
		}
	}
}