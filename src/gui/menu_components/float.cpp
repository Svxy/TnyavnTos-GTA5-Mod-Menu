#include "../../cheat/fibermain.hpp"
#include "../../cheat/config.hpp"

using namespace Cheat;

bool GUI::Float(std::string option, float& _float, float min, float max, float steps, std::string InformationText, std::streamsize FloatPrecision, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) && !config::Loaded) { config::LoadFloatSelectableState(option, _float); }

	if (Option(option, InformationText, BitFlags))
	{
		return true;
	}

	bool IgnoreMinMax = min == 0.0f && max == 0.0f;
	if (GUI::optionCount == GUI::currentOption)
	{
		config::SaveSelectable(option, std::to_string(_float), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
		if (gui_controls::LeftPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			if (_float < max || IgnoreMinMax)
			{
				_float += steps;
			}
			if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
		}
		if (gui_controls::RightPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			if (_float > min || IgnoreMinMax)
			{
				_float -= steps;
			}
			if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
		}
	}

	std::ostringstream DisplayFloat;
	DisplayFloat.precision(FloatPrecision);
	DisplayFloat << std::fixed << _float;
	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		DrawTextInGame("< " + DisplayFloat.str() + " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 38 / 100), GUI::guiY + GUI::optionCount * SelectableHeight - 0.172f }, { 0.32f, 0.32f }, true, true);
	}
	else if (GUI::optionCount > GUI::currentOption - GUI::maxVisOptions && GUI::optionCount <= GUI::currentOption)
	{
		DrawTextInGame("< " + DisplayFloat.str() + " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 38 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.172f }, { 0.32f, 0.32f }, true, true);
	}
	return false;
}