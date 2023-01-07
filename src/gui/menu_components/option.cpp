#include "../../cheat/fibermain.hpp"
#include "../../game/notification.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;

std::string SelectableInformationText;
bool GUI::Option(std::string option, std::string InformationText, int BitFlags)
{
	GUI::optionCount++;
	GUI::optionCountVisible++;
	bool OnCurrent = GUI::currentOption == GUI::optionCount ? true : false;
	Vector2 TextPosition, RectPosition;
	RGBA RectColor;

	if (BitFlags & SELECTABLE_DISABLED) { option.append(" (Disabled)"); }

	int TextXPosPercentage = !(BitFlags & SELECTABLE_PLAYER_LIST) ? 48 : 40;
	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		TextPosition = { GUI::guiX - (GUI::guiWidth * TextXPosPercentage / 100), GUI::guiY + (GUI::optionCount) * SelectableHeight - 0.174f };
		RectPosition = { GUI::guiX, GUI::guiY + (GUI::optionCount) * SelectableHeight - 0.1585f };
		OnCurrent ? RectColor = PrimaryColor : RectColor = { 0, 0, 0, SelectableTransparency };
		DrawTextInGame(option, TextColorAndFont, TextPosition, { 0.35f, 0.35f }, false);
		DrawRectInGame(RectColor, RectPosition, { GUI::guiWidth, SelectableHeight });
	}
	else if (GUI::optionCount > (GUI::currentOption - GUI::maxVisOptions) && GUI::optionCount <= GUI::currentOption)
	{
		TextPosition = { GUI::guiX - (GUI::guiWidth * TextXPosPercentage / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f };
		RectPosition = { GUI::guiX, GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.1585f };
		OnCurrent ? RectColor = PrimaryColor : RectColor = { 0, 0, 0, SelectableTransparency };
		DrawTextInGame(option, TextColorAndFont, TextPosition, { 0.35f, 0.35f }, false);
		DrawRectInGame(RectColor, RectPosition, { GUI::guiWidth, SelectableHeight });
	}
	if (OnCurrent)
	{
		// Selectable Information Box
		if (!Features::HideSelectableInformationBox && !(BitFlags & SELECTABLE_HIDE_INFO_BOX))
		{
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX, SelectableInfoBoxY + 0.042f }, { 0.25f, 0.004f });
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX, SelectableInfoBoxY - 0.042f }, { 0.25f, 0.004f });
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX - 0.126f, SelectableInfoBoxY }, { 0.002f, 0.088f });
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX + 0.126f, SelectableInfoBoxY }, { 0.002f, 0.088f });
			DrawRectInGame({ 0, 0, 0, 210 }, { SelectableInfoBoxX, SelectableInfoBoxY }, { 0.25f, 0.080f });
			DrawTextInGame(InformationText.empty() ? option : InformationText, TextColorAndFont, { SelectableInfoBoxX - 0.12f, SelectableInfoBoxY - 0.033f }, { 0.30f, 0.30f }, false);
			if (GUI::CurrentSelectableIsSavable) { DrawTextInGame("Save: " + gui_controls::VirtualKeyCodeToString(gui_controls::SaveSelectableKey), TextColorAndFont, { SelectableInfoBoxX + 0.07f, SelectableInfoBoxY - 0.033f }, { 0.30f, 0.30f }, false); }
		}

		GUI::currentOptionVisible = GUI::optionCount - (GUI::optionCount - GUI::optionCountVisible);
		GUI::CurrentSelectableIsSavable = false;
		GUI::previousOption = GUI::currentOption;
		SelectableInformationText = InformationText;

		if (gui_controls::SelectPressed || (gui_controls::cursor_at_pos(RectPosition, { GUI::guiWidth, SelectableHeight }) && gui_controls::cursor_nav_state && PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_CURSOR_ACCEPT)))
		{
			if (BitFlags & SELECTABLE_DISABLED)
			{
				Game::notification::MinimapAdvanced((char*)"This selectable is disabled", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"TnyavnTos GTA 5 Mod Menu", (char*)"", 0.5f, (char*)"");
				return false;
			}
			return true;
		}
	}
	return false;
}