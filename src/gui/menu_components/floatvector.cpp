#include "../../cheat/fibermain.hpp"
#include "../../cheat/config.hpp"

using namespace Cheat;

bool GUI::FloatVector(std::string option, std::vector<float> Vector, int& position, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) && !config::Loaded) { config::LoadIntSelectableState(option, position); }

	if (Option(option, "", BitFlags))
	{
		return true;
	}

	if (GUI::optionCount == GUI::currentOption)
	{
		config::SaveSelectable(option, std::to_string(position), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
		size_t max = static_cast<int>(Vector.size()) - 1;
		int min = 0;
		if (gui_controls::LeftPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			position >= 1 ? position-- : position = static_cast<int>(max);
			return true;
		}
		if (gui_controls::RightPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			position < max ? position++ : position = static_cast<int>(min);
			return true;
		}
	}

	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		DrawTextInGame(std::to_string(Vector[position]), TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 32 / 100), GUI::guiY + GUI::optionCount * SelectableHeight - 0.174f }, { 0.5f, 0.5f }, true, true);
	}
	else if (GUI::optionCount > GUI::currentOption - GUI::maxVisOptions && GUI::optionCount <= GUI::currentOption)
	{
		DrawTextInGame(std::to_string(Vector[position]), TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 32 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.5f, 0.5f }, true, true);
	}
	return false;
}