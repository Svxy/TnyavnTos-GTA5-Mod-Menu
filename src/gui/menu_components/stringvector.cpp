#include "../../cheat/fibermain.hpp"
#include "../../cheat/config.hpp"

using namespace Cheat;

bool GUI::StringVector(std::string option, std::vector<std::string> Vector, int& position, std::string InformationText, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) && !config::Loaded) { config::LoadIntSelectableState(option, position); }

	if (Option(option, InformationText, BitFlags))
	{
		return true;
	}

	if (GUI::optionCount == GUI::currentOption)
	{
		config::SaveSelectable(option, std::to_string(position), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
		if (gui_controls::LeftPressed)
		{
			if (position < Vector.size() - 1)
			{
				position++;
				if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
			}
		}
		if (gui_controls::RightPressed)
		{
			if (position > 0)
			{
				position--;
				if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
			}
		}
	}

	std::string Text;
	if (position > 0)
	{
		Text.append("< ");
	}
	Text.append(Vector[position]);
	std::stringstream Total;
	Total << " [" << position + 1 << "/" << Vector.size() << "]";
	Text.append(Total.str());

	if (position < Vector.size() - 1)
	{
		Text.append(" >");
	}

	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 36 / 100), GUI::guiY + GUI::optionCount * SelectableHeight - 0.174f }, { 0.35f, 0.35f }, true, true);
	}
	else if (GUI::optionCount > GUI::currentOption - GUI::maxVisOptions && GUI::optionCount <= GUI::currentOption)
	{
		DrawTextInGame(Text, TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 36 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.35f, 0.35f }, true, true);
	}
	return false;
}