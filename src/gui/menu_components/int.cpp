#include "../../cheat/fibermain.hpp"
#include "../../cheat/cheat.hpp"
#include "../../cheat/config.hpp"
#include "../../game/game.hpp"

using namespace Cheat;

bool GUI::Int(std::string option, int& _int, int min, int max, int step, std::string InformationText, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) && !config::Loaded) { config::LoadIntSelectableState(option, _int); }

	if (Option(option, InformationText, BitFlags))
	{
		std::string KeyboardString;
		if (Game::keyboard::get_input("Enter number", KeyboardString, min, max) != Game::keyboard::input_status::SUCCESS)
			return false;

		int KeyBoardInput = Cheat::helper::StringToInt(KeyboardString);
		if (KeyBoardInput >= min && KeyBoardInput <= max)
		{
			_int = KeyBoardInput;
		}
		return true;
	}

	std::string Text;
	if (_int > min)
	{
		Text.append("< ");
	}
	Text.append(std::to_string(_int));
	if (_int < max)
	{
		Text.append(" >");
	}

	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		if (_int < 100)
		{
			DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 36 / 100), GUI::guiY + GUI::optionCount * SelectableHeight - 0.174f }, { 0.32f, 0.32f }, false, true);
		}
		else if (_int < 999)
		{
			DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 33 / 100), GUI::guiY + GUI::optionCount * SelectableHeight - 0.174f }, { 0.32f, 0.32f }, false, true);
		}
		else
		{
			DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 29 / 100), GUI::guiY + GUI::optionCount * SelectableHeight - 0.174f }, { 0.32f, 0.32f }, false, true);
		}
	}
	else if ((GUI::optionCount > (GUI::currentOption - GUI::maxVisOptions)) && GUI::optionCount <= GUI::currentOption)
	{
		if (_int < 100)
		{
			DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 36 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.32f, 0.32f }, false, true);
		}
		else if (_int < 999)
		{
			DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 33 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.32f, 0.32f }, false, true);
		}
		else
		{
			DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 29 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.32f, 0.32f }, false, true);
		}
	}

	if (GUI::optionCount == GUI::currentOption)
	{
		if (GUI::gui_controls::LeftPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			if (_int < max)
			{
				if (step == 1) { _int++; }
				else { _int = _int + step; }
			}
			if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
		}
		if (GUI::gui_controls::RightPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			if (_int > min)
			{
				if (step == 1) { _int--; }
				else { _int = _int - step; }
			}
			if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
		}
		config::SaveSelectable(option, std::to_string(_int), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
	}
	return false;
}