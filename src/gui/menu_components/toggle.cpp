#include "../../cheat/fibermain.hpp"
#include "../../cheat/config.hpp"

using namespace Cheat;

bool GUI::Toggle(std::string option, bool& TargetBool, std::string InformationText, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) && !config::Loaded) { config::LoadBoolSelectables(option, TargetBool); }

	if (Option(option, InformationText, BitFlags))
	{
		TargetBool ^= 1;
		return true;
	}

	std::string ToggleString;
	TargetBool ? ToggleString = "ToggleOn" : ToggleString = "ToggleOff";

	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		DrawSpriteInGame("Textures", ToggleString, GUI::guiX + (GUI::guiWidth * 43 / 100), GUI::guiY + (GUI::optionCount * SelectableHeight - 0.159f), 0.025f, 0.025f, 0, 255, 255, 255, ToggleSelectableTransparency);
	}
	else if ((GUI::optionCount > (GUI::currentOption - GUI::maxVisOptions)) && GUI::optionCount <= GUI::currentOption)
	{
		DrawSpriteInGame("Textures", ToggleString, GUI::guiX + (GUI::guiWidth * 43 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.159f, 0.025f, 0.025f, 0, 255, 255, 255, ToggleSelectableTransparency);
	}

	if (GUI::optionCount == GUI::currentOption)
	{
		config::SaveSelectable(option, TargetBool ? "true" : "false", !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
	}
	return false;
}
