#include "../Header/Cheat Functions/FiberMain.h"
using namespace Cheat;

const float GUI::guiX_Default				= 0.15f;
const float GUI::guiY_Default				= 0.30f;
const float GUI::guiWidth_Default			= 0.25f;
const float GUI::SelectableInfoBoxX_Default	= 0.50f;
const float GUI::SelectableInfoBoxY_Default	= 0.040f;
float GUI::guiX					= 0.15f;
float GUI::guiY					= 0.30f;
float GUI::guiWidth				= 0.25f;
float GUI::SelectableInfoBoxX	= 0.50f;
float GUI::SelectableInfoBoxY	= 0.850f;
float GUI::SelectableHeight		= 0.040f;
bool GUI::ShowHeaderBackground	= true;
bool GUI::ShowHeaderTexture		= true;
bool GUI::DisableMenuGUIOpenCloseFade = false;
bool GUI::HideGUIElements		= false; // Prevents all GUI elements from being visible when True
bool GUI::MenuGUIHasBeenOpened = false; // True when the Menu GUI has been opened at least once
bool GUI::CurrentSelectableIsSavable = false;
bool GUI::RestorePreviousSubmenu = true;
std::string SelectableInformationText;
std::string GUI::CurrentTheme;
std::string GUI::CurrentSubmenu;
int GUI::maxVisOptions			= 11;
int GUI::currentOption			= 0;
int GUI::currentOptionVisible   = 0; // This has GUI::Break excluded
int GUI::previousOption			= 0;
int GUI::optionCount			= 0;
int GUI::optionCountVisible		= 0; // This has GUI::Break excluded
int GUI::TotalOptionsCount		= 0;
int GUI::menuLevel				= 0;
void* GUI::PreviousMenu			= nullptr;
void* GUI::currentMenu			= nullptr;
int GUI::PreviousMenuLevel		= 0;
int GUI::optionsArray			[1000];
void* GUI::menusArray			[1000];
std::vector <std::string> GUI::ThemeFilesVector;
                 
RGBA GUI::PrimaryColor					{ 0, 0, 255, 255 };
RGBAF GUI::TextColorAndFont				{ 255, 255, 255, 255, FontChaletLondon };
int GUI::SelectableTransparency			= 150;
int GUI::HeaderBackgroundTransparency	= 200;
int GUI::TitleAndEndTransparency		= 210;
int GUI::ToggleSelectableTransparency	= 255;
int GUI::HeaderTextureTransparency		= 255;
int GUI::EndSmallLogoTransparency		= 255;
int GUI::OnlinePlayerPictureTransparency = 255;

int GUI::MenuArrowAnimationDelay		= 1000;

std::string CursorBackCloseString;
void GUI::Title(std::string TitleName)
{
	if (ShowHeaderBackground) { DrawRectInGame({ PrimaryColor.r, PrimaryColor.g, PrimaryColor.b, HeaderBackgroundTransparency }, { guiX, GUI::guiY - SelectableHeight - 0.181f }, { guiWidth, SelectableHeight + 0.045f }); }
	if (ShowHeaderTexture) { DrawSpriteInGame("Textures", "HeaderDefaultTransparent", guiX, GUI::guiY - SelectableHeight - 0.181f, guiWidth, SelectableHeight + 0.045f, 0, 255, 255, 255, HeaderTextureTransparency); }
	DrawTextInGame(TitleName, TextColorAndFont, { GUI::guiX, GUI::guiY - 0.174f }, { 0.40f, 0.38f }, true, true);
	DrawRectInGame({ 0, 0, 0, TitleAndEndTransparency }, { guiX, GUI::guiY - 0.1585f }, { guiWidth, SelectableHeight });

	if (CheatFeatures::CursorNavigationState)
	{
		if (GUI::currentMenu == Submenus::Home) { CursorBackCloseString = "Close"; }
		else { CursorBackCloseString = "Back"; }
		DrawSpriteInGame("commonmenu", "arrowleft", GUI::guiX - (GUI::guiWidth * 48 / 100), GUI::guiY - 0.160f, 0.015f, 0.025f, 0, 255, 255, 255, 255);
		DrawTextInGame(CursorBackCloseString, TextColorAndFont, { GUI::guiX - (GUI::guiWidth * 45 / 100), GUI::guiY - 0.174f }, { 0.35f, 0.37f }, false, true);
	}

	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(false);
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);	

	CurrentSubmenu = TitleName;
}

bool GUI::Option(std::string option, std::string InformationText, int BitFlags)
{
	GUI::optionCount++;
	GUI::optionCountVisible++;
	bool OnCurrent = GUI::currentOption == GUI::optionCount ? true : false;
	VECTOR2 TextPosition, RectPosition;
	RGBA RectColor;

	if(BitFlags & SELECTABLE_DISABLED) { option.append(" (Disabled)"); }
	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		TextPosition = { GUI::guiX - (GUI::guiWidth * 48 / 100), GUI::guiY + (GUI::optionCount) * SelectableHeight - 0.174f};
		RectPosition = { GUI::guiX, GUI::guiY + (GUI::optionCount) * SelectableHeight - 0.1585f };
		OnCurrent ? RectColor = PrimaryColor : RectColor = { 0, 0, 0, SelectableTransparency };
		DrawTextInGame(option, TextColorAndFont, TextPosition, { 0.35f, 0.35f }, false);
		DrawRectInGame(RectColor, RectPosition, { GUI::guiWidth, SelectableHeight });
	}
	else if (GUI::optionCount > (GUI::currentOption - GUI::maxVisOptions) && GUI::optionCount <= GUI::currentOption)
	{
		TextPosition = { GUI::guiX - (GUI::guiWidth * 48 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f };
		RectPosition = { GUI::guiX, GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.1585f };
		OnCurrent ? RectColor = PrimaryColor : RectColor = { 0, 0, 0, SelectableTransparency };
		DrawTextInGame(option, TextColorAndFont, TextPosition, { 0.35f, 0.35f }, false);
		DrawRectInGame(RectColor, RectPosition, { GUI::guiWidth, SelectableHeight });
	}
	if (OnCurrent)
	{
		// Selectable Information Box
		if (!CheatFeatures::HideSelectableInformationBox && !(BitFlags & SELECTABLE_HIDE_INFO_BOX))
		{
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX, SelectableInfoBoxY + 0.042f }, { 0.25f, 0.004f });
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX, SelectableInfoBoxY - 0.042f }, { 0.25f, 0.004f });
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX - 0.126f, SelectableInfoBoxY }, { 0.002f, 0.088f });
			DrawRectInGame({ GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 210 }, { SelectableInfoBoxX + 0.126f, SelectableInfoBoxY }, { 0.002f, 0.088f });
			DrawRectInGame({ 0, 0, 0, 210 }, { SelectableInfoBoxX, SelectableInfoBoxY }, { 0.25f, 0.080f });
			DrawTextInGame(SelectableInformationText != "" ? CheatFunctions::TextWrap(SelectableInformationText, 30) : option, TextColorAndFont, { SelectableInfoBoxX - 0.12f, SelectableInfoBoxY - 0.033f }, { 0.30f, 0.30f }, false);
			if (GUI::CurrentSelectableIsSavable) { DrawTextInGame("Save: " + CheatFunctions::VirtualKeyCodeToString(Controls::SaveSelectableKey), TextColorAndFont, { SelectableInfoBoxX + 0.07f, SelectableInfoBoxY - 0.033f }, { 0.30f, 0.30f }, false); }
		}
		
		GUI::currentOptionVisible = GUI::optionCount - (GUI::optionCount - GUI::optionCountVisible);
		GUI::CurrentSelectableIsSavable = false;
		GUI::previousOption = GUI::currentOption;
		SelectableInformationText = InformationText;

		if (Controls::SelectPressed || (GameFunctions::IsCursorAtXYPosition(RectPosition, { GUI::guiWidth, SelectableHeight }) && CheatFeatures::CursorNavigationState && PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_CURSOR_ACCEPT)))
		{
			if (BitFlags & SELECTABLE_DISABLED)
			{
				GameFunctions::AdvancedMinimapNotification("This selectable is disabled", "Textures", "AdvancedNotificationImage", false, 4, "TnyavnTo's GTAV Cheat", "", 0.5f, "");
				return false;
			}
			return true;
		}
	}
	return false;
}

bool GUI::VehicleOption(DWORD VehicleHash)
{
	if (STREAMING::IS_MODEL_A_VEHICLE(VehicleHash))
	{
		std::string ModelName = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(VehicleHash);
		std::string OptionText = UI::_GET_LABEL_TEXT(ModelName.c_str());
		if (Option(OptionText == "NULL" ? ModelName : OptionText, "Model Name: " + ModelName))
		{
			return true;
		}
		if (GUI::currentOption == GUI::optionCount && !CheatFeatures::HideVehiclePreview)
		{
			std::string VehiclePreviewDictName, VehiclePreviewName;
			std::transform(ModelName.begin(), ModelName.end(), ModelName.begin(), tolower);
			VehiclePreviewDictName = "Textures";
			VehiclePreviewName = "NoVehiclePreviewAvailable";

			for (auto& Vector : GameArrays::VehicleModelPictures)
			{
				if (Vector.PreviewName == ModelName)
				{
					VehiclePreviewDictName = Vector.DictName;
					VehiclePreviewName = Vector.PreviewName;
				}
			}

			float x = guiX < 0.75f ? guiX + (GUI::guiWidth / 2) + 0.080f : guiX - (GUI::guiWidth / 2) - 0.080f;
			DrawSpriteInGame(VehiclePreviewDictName, VehiclePreviewName, x, guiY - 0.098f, 0.16f, 0.16f, 0.f, 255, 255, 255, 255);
		}
	}
	return false;
}

bool GUI::Break(std::string option, int BitFlags)
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
		DrawRectInGame({ 0, 0, 0, SelectableTransparency }, { GUI::guiX, GUI::guiY + (GUI::optionCount) * SelectableHeight - 0.1585f }, { GUI::guiWidth, SelectableHeight });
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
		DrawRectInGame({ 0, 0, 0, SelectableTransparency }, { GUI::guiX, GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions))*SelectableHeight - 0.1585f }, { GUI::guiWidth, SelectableHeight });
	}

	if (GUI::optionCount == GUI::currentOption)
	{
		GUI::CurrentSelectableIsSavable = false;
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
	return false;
}

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
		DrawTextInGame(MenuOptionArrowAnimationState ? ">" : " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 43 / 100), GUI::guiY + (GUI::optionCount) * SelectableHeight - 0.174f}, {0.35f, 0.35f}, false);
	}
	else if (GUI::optionCount > (GUI::currentOption - GUI::maxVisOptions) && GUI::optionCount <= GUI::currentOption)
	{
		DrawTextInGame(MenuOptionArrowAnimationState ? ">" : " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 43 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.174f }, { 0.35f, 0.35f }, false);
	}
	return false;
}

bool GUI::MenuOptionPlayerList(Player Player)
{
	std::string PlayerName = PLAYER::GET_PLAYER_NAME(Player);
	bool IsLocalPlayer = GameFunctions::PlayerID == Player;
	std::string PlayerNameString = IsLocalPlayer ? "~g~YOU~s~ (" + PlayerName + ")" : PlayerName;
	const char* CurrentOnlinePlayerPictureName = "AdvancedNotificationImage";
	if (!IsLocalPlayer)
	{
		CurrentOnlinePlayerPictureName = GameFunctions::ReturnOnlinePlayerPictureString(Player);
	}

	if (Option("      " + PlayerNameString, "", SELECTABLE_HIDE_INFO_BOX))
	{
		GUI::MoveMenu(Submenus::SelectedPlayer);
		return true;
	}

	VECTOR2 Position;
	if (GUI::currentOption <= GUI::maxVisOptions && GUI::optionCount <= GUI::maxVisOptions)
	{
		Position = { GUI::guiX - (GUI::guiWidth * 45 / 100), GUI::guiY + (GUI::optionCount * SelectableHeight - 0.158f) };
	}
	else if (GUI::optionCount > GUI::currentOption - GUI::maxVisOptions && GUI::optionCount <= GUI::currentOption)
	{
		Position = { GUI::guiX - (GUI::guiWidth * 45 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.158f };
	}
	DrawSpriteInGame(IsLocalPlayer ? "Textures" : CurrentOnlinePlayerPictureName, CurrentOnlinePlayerPictureName, Position.x, Position.y, 0.02f, 0.03f, 0.f, 255, 255, 255, OnlinePlayerPictureTransparency);
	return false;
}

bool GUI::Toggle(std::string option, bool & TargetBool, std::string InformationText, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED)) { CheatFunctions::LoadConfigOption(option, TargetBool); }

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
		CheatFunctions::SaveSelectable(option, TargetBool ? "true" : "false", !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
	}
	return false;
}

bool GUI::Int(std::string option, int & _int, int min, int max, int step, std::string InformationText, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED)) { CheatFunctions::LoadConfigOption(option, _int); }

	if (Option(option, InformationText, BitFlags))
	{
		int KeyBoardInput;
		if (!GameFunctions::DisplayKeyboardAndReturnInputInteger(CheatFunctions::ReturnNumberOfDigitsInValue(max), "Enter number", KeyBoardInput))
		{
			return false;
		}
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
		if (Controls::LeftPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			if (_int < max)
			{
				if (step == 1) { _int++; }
				else { _int = _int + step; }
			}
			if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
		}
		if (Controls::RightPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			if (_int > min)
			{
				if (step == 1) { _int--; }
				else { _int = _int - step; }
			}
			if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
		}

		CheatFunctions::SaveSelectable(option, std::to_string(_int), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
	}
	return false;
}

bool GUI::Float(std::string option, float& _float, float min, float max, float steps, std::string InformationText, std::streamsize FloatPrecision, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED)) { CheatFunctions::LoadConfigOption(option, _float); }

	if (Option(option, InformationText, BitFlags))
	{
		return true;
	}

	bool IgnoreMinMax = min == 0.0f && max == 0.0f;
	if (GUI::optionCount == GUI::currentOption)
	{	
		CheatFunctions::SaveSelectable(option, std::to_string(_float), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
		if (Controls::LeftPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			if (_float < max || IgnoreMinMax)
			{
				_float += steps;
			}
			if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true;  }
		}
		if (Controls::RightPressed && !(BitFlags & SELECTABLE_DISABLED))
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
		DrawTextInGame("< " + DisplayFloat.str() + " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 38 / 100), GUI::guiY + GUI::optionCount * SelectableHeight - 0.172f}, {0.32f, 0.32f}, true, true);
	}
	else if (GUI::optionCount > GUI::currentOption - GUI::maxVisOptions && GUI::optionCount <= GUI::currentOption)
	{
		DrawTextInGame("< " + DisplayFloat.str() + " >", TextColorAndFont, { GUI::guiX + (GUI::guiWidth * 38 / 100), GUI::guiY + (GUI::optionCount - (GUI::currentOption - GUI::maxVisOptions)) * SelectableHeight - 0.172f }, { 0.32f, 0.32f }, true, true);
	}
	return false;
}

bool GUI::IntVector(std::string option, std::vector<int> Vector, int& position, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED)) { CheatFunctions::LoadConfigOption(option, position); }

	if (Option(option, "", BitFlags))
	{
		return true;
	}

	if (GUI::optionCount == GUI::currentOption) 
	{
		int max = static_cast<int>(Vector.size()) - 1;
		int min = 0;
		if (Controls::LeftPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			position >= 1 ? position-- : position = max;
			return true;
		}
		if (Controls::RightPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			position < max ? position++ : position = min;
			return true;
		}
		CheatFunctions::SaveSelectable(option, std::to_string(position), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
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

bool GUI::FloatVector(std::string option, std::vector<float> Vector, int& position, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED)) { CheatFunctions::LoadConfigOption(option, position); }

	if (Option(option, "", BitFlags))
	{
		return true;
	}

	if (GUI::optionCount == GUI::currentOption) 
	{
		CheatFunctions::SaveSelectable(option, std::to_string(position), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
		size_t max = static_cast<int>(Vector.size()) - 1;
		int min = 0;
		if (Controls::LeftPressed && !(BitFlags & SELECTABLE_DISABLED))
		{
			position >= 1 ? position-- : position = static_cast<int>(max);
			return true;
		}
		if (Controls::RightPressed && !(BitFlags & SELECTABLE_DISABLED))
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

bool GUI::StringVector(std::string option, std::vector<std::string> Vector, int& position, std::string InformationText, int BitFlags)
{
	if (!(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED)) { CheatFunctions::LoadConfigOption(option, position); }

	if (Option(option, InformationText, BitFlags))
	{
		return true;
	}

	if (GUI::optionCount == GUI::currentOption)
	{
		CheatFunctions::SaveSelectable(option, std::to_string(position), !(BitFlags & SELECTABLE_DISABLE_SAVE) && !(BitFlags & SELECTABLE_DISABLED) ? true : false);
		if (Controls::LeftPressed)
		{
			if (position < Vector.size() - 1)
			{
				position++;
				if (BitFlags & SELECTABLE_RETURN_VALUE_CHANGE) { return true; }
			}
		}
		if (Controls::RightPressed)
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

void GUI::MenuGUIBottom()
{
	if (GUI::menuLevel > 0)
	{
		GUI::TotalOptionsCount = GUI::optionCount;
		float OptionCountPositionX = GUI::guiX - (GUI::guiWidth * 43 / 100);
		float BuildNumberPositionX = GUI::guiX + (GUI::guiWidth * 42 / 100);
		float OptionCountAndBuildNumberY, RectY, LogoSmall;
		if (GUI::optionCount >= GUI::maxVisOptions)
		{
			OptionCountAndBuildNumberY = GUI::guiY + ((GUI::maxVisOptions + 1) * SelectableHeight - 0.172f);
			RectY = GUI::guiY + ((GUI::maxVisOptions + 1) * SelectableHeight - 0.1585f);
			LogoSmall = GUI::guiY + ((GUI::maxVisOptions + 1) * SelectableHeight - 0.159f);
		}
		else if (GUI::optionCount > 0)
		{
			OptionCountAndBuildNumberY = GUI::guiY + (GUI::optionCount + 1) * SelectableHeight - 0.172f;
			RectY = GUI::guiY + (GUI::optionCount + 1) * SelectableHeight - 0.1585f;
			LogoSmall = GUI::guiY + ((GUI::optionCount + 1) * SelectableHeight - 0.159f);
		}

		if (GUI::currentOptionVisible != 0 && GUI::optionCountVisible != 0)
		{
			DrawTextInGame(std::to_string(GUI::currentOptionVisible) + "/" + std::to_string(GUI::optionCountVisible), TextColorAndFont, { OptionCountPositionX, OptionCountAndBuildNumberY }, { 0.30f, 0.30f }, true);
		}
		DrawTextInGame(CHEAT_BUILD_NUMBER, TextColorAndFont, { BuildNumberPositionX, OptionCountAndBuildNumberY }, { 0.30f, 0.30f }, true);
		DrawRectInGame({ 0, 0, 0, TitleAndEndTransparency }, { GUI::guiX, RectY }, { GUI::guiWidth, SelectableHeight });
		DrawSpriteInGame("Textures", "LogoSmall", GUI::guiX, LogoSmall, 0.030f, 0.045f, 0, GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, EndSmallLogoTransparency);
	}
}

void GUI::MoveMenu(void* Submenu)
{
	GUI::menusArray[GUI::menuLevel] = GUI::currentMenu;
	GUI::optionsArray[GUI::menuLevel] = GUI::currentOption;
	GUI::menuLevel++;
	GUI::currentMenu = Submenu;
	GUI::currentOption = 1;
}

void GUI::CloseMenuGUI()
{
	GUI::PreviousMenu = GUI::currentMenu;
	GUI::PreviousMenuLevel = GUI::menuLevel;
	GUI::previousOption = GUI::currentOption;
	GUI::menuLevel = 0;
	GUI::currentMenu = GUI::menusArray[GUI::menuLevel];
	GUI::currentOption = GUI::optionsArray[GUI::menuLevel];
	if (Controls::DisableCursorNavigationWhenMenuGUIIsClosed)
	{
		if (CheatFeatures::CursorNavigationState)
		{
			GameFunctions::EnableDisableCursorNavigation();
		}
	}
}

void GUI::BackMenu()
{
	if (GUI::currentMenu == GUI::Submenus::Home)
	{
		CloseMenuGUI();
	}
	else
	{
		GUI::PreviousMenu = GUI::currentMenu;
		GUI::PreviousMenuLevel = GUI::menuLevel;
		GUI::previousOption = GUI::currentOption;
		GUI::menuLevel--;
		GUI::currentMenu = GUI::menusArray[GUI::menuLevel];
		GUI::currentOption = GUI::optionsArray[GUI::menuLevel];
	}
}

void GUI::AddPlayerInfoBoxTextEntry(std::string text, int Row1, int Row2, int Row3, int Row4)
{
	if (GUI::guiX < 0.55f)
	{
		if (Row1 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.010f, GUI::guiY + (Row1 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row2 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.105f, GUI::guiY + (Row2 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row3 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.195f, GUI::guiY + (Row3 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row4 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.265f, GUI::guiY + (Row4 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
	}
	else
	{
		if (Row1 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.325f, GUI::guiY + (Row1 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row2 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.255f, GUI::guiY + (Row2 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row3 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.175f, GUI::guiY + (Row3 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row4 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.070f, GUI::guiY + (Row4 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
	}
}

void GUI::LoadTheme(std::string ThemeFileName, bool StartUp)
{
	if (!std::filesystem::exists(CheatFunctions::ReturnThemeFilePath(ThemeFileName)))
	{ 
		GameFunctions::MinimapNotification("Requested Theme does not exist. Auto load entry removed from config file."); 
		CheatFunctions::IniFileRemoveKey(CheatFunctions::ReturnConfigFilePath(), "submenu_settings", "Active Theme");
		return;
	}

	GUI::CurrentTheme = ThemeFileName;
	try
	{
		DisableMenuGUIOpenCloseFade = CheatFunctions::StringToBool(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Menu", "open/close_fade_disabled"));
		GUI::guiWidth = std::stof(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Menu", "menu_gui_width"));

		GUI::guiX = std::stof(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "menu_gui_x"));
		GUI::guiY = std::stof(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "menu_gui_y"));

		GUI::SelectableInfoBoxX = std::stof(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "selectable_information_box_x"));
		GUI::SelectableInfoBoxY = std::stof(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "selectable_information_box_y"));
		GUI::SelectableHeight = std::stof(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "selectable_height"));

		GUI::ShowHeaderTexture = CheatFunctions::StringToBool(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Header", "header_texture"));
		GUI::ShowHeaderBackground = CheatFunctions::StringToBool(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Header", "header_background"));
	
		CheatFeatures::RGBDiscoBool = CheatFunctions::StringToBool(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "rgb_disco"));

		if (!CheatFeatures::RGBDiscoBool)
		{
			GUI::PrimaryColor.r = CheatFunctions::StringToInt(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "primary_color_r"));
			GUI::PrimaryColor.g = CheatFunctions::StringToInt(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "primary_color_g"));
			GUI::PrimaryColor.b = CheatFunctions::StringToInt(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "primary_color_b"));

			GUI::TextColorAndFont.r = CheatFunctions::StringToInt(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "text_color_r"));
			GUI::TextColorAndFont.g = CheatFunctions::StringToInt(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "text_color_g"));
			GUI::TextColorAndFont.b = CheatFunctions::StringToInt(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "text_color_b"));
		}

		GUI::TextColorAndFont.f = CheatFunctions::StringToInt(CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Font", "text_font"));
	}
	catch (...) {}

	// Check Theme File Version
	if (CheatFunctions::IniFileReturnKeyValueAsString(CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Theme", "theme_file_version") != "2.3")
	{
		GameFunctions::SubtitleNotification("The loaded Theme is outdated. Please resave it", 5000);
	}

	// Save New Active Theme Name To Config File
	if (!StartUp) 
	{
		CheatFunctions::IniFileWriteString(GUI::CurrentTheme, CheatFunctions::ReturnConfigFilePath(), "submenu_settings", "Active Theme");
		GameFunctions::MinimapNotification("Theme Loaded"); 
	}
}

void GUI::DeleteLoadedTheme()
{
	remove(CheatFunctions::StringToChar(CheatFunctions::ReturnThemeFilePath(CurrentTheme)));
	CheatFunctions::IniFileRemoveKey(CheatFunctions::ReturnConfigFilePath(), "submenu_settings", "Active Theme");
	GUI::CurrentTheme.clear();
	GUI::currentOption = 1;
	GameFunctions::MinimapNotification("Theme Removed");
}

void GUI::SaveTheme(std::string ThemeFileName)
{
	CheatFunctions::IniFileWriteString("2.3", CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Theme", "theme_file_version");

	CheatFunctions::WriteBoolToIni(DisableMenuGUIOpenCloseFade, CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Menu", "open/close_fade_disabled");
	CheatFunctions::IniFileWriteString(std::to_string(GUI::guiWidth), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Menu", "menu_gui_width");

	CheatFunctions::IniFileWriteString(std::to_string(GUI::guiX), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "menu_gui_x");
	CheatFunctions::IniFileWriteString(std::to_string(GUI::guiY), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "menu_gui_y");

	CheatFunctions::IniFileWriteString(std::to_string(GUI::SelectableInfoBoxX), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "selectable_information_box_x");
	CheatFunctions::IniFileWriteString(std::to_string(GUI::SelectableInfoBoxY), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "selectable_information_box_y");
	CheatFunctions::IniFileWriteString(std::to_string(GUI::SelectableHeight), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Positioning", "selectable_height");

	CheatFunctions::WriteBoolToIni(GUI::ShowHeaderTexture, CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Header", "header_texture");
	CheatFunctions::WriteBoolToIni(GUI::ShowHeaderBackground, CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Header", "header_background");

	CheatFunctions::WriteBoolToIni(CheatFeatures::RGBDiscoBool, CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "rgb_disco");
	if (!CheatFeatures::RGBDiscoBool)
	{
		CheatFunctions::IniFileWriteString(std::to_string(GUI::PrimaryColor.r), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "primary_color_r");
		CheatFunctions::IniFileWriteString(std::to_string(GUI::PrimaryColor.g), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "primary_color_g");
		CheatFunctions::IniFileWriteString(std::to_string(GUI::PrimaryColor.b), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "primary_color_b");

		CheatFunctions::IniFileWriteString(std::to_string(GUI::TextColorAndFont.r), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "text_color_r");
		CheatFunctions::IniFileWriteString(std::to_string(GUI::TextColorAndFont.g), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "text_color_g");
		CheatFunctions::IniFileWriteString(std::to_string(GUI::TextColorAndFont.b), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Color", "text_color_b");
	}

	CheatFunctions::IniFileWriteString(std::to_string(GUI::TextColorAndFont.f), CheatFunctions::ReturnThemeFilePath(ThemeFileName), "Font", "text_font");

	GameFunctions::MinimapNotification("Theme Saved");
}

void GUI::LoadTextureFile()
{
	Logger::LogMsg(LoggerMsgTypes::LOGGER_INFO_MSG, "Loading Texture File");
	if (!CheatFeatures::NoTextureFileOverwrite)
	{
		remove(CheatFunctions::StringToChar(CheatFunctions::ReturnTextureFilePath()));

		// Find and load the resource
		HRSRC hResource = FindResourceA(CheatModuleHandle, MAKEINTRESOURCEA(140), "CHEAT_DATA");
		if (!hResource) { goto Error; }
		HGLOBAL hFileResource = LoadResource(CheatModuleHandle, hResource);
		if (!hFileResource) { goto Error; }

		// Open and map this to a disk file
		LPVOID lpFile = LockResource(hFileResource);
		DWORD dwSize = SizeofResource(CheatModuleHandle, hResource);

		// Open the file and filemap
		HANDLE hFile = CreateFileA(CheatFunctions::StringToChar(CheatFunctions::ReturnTextureFilePath()), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		HANDLE hFileMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, dwSize, NULL);
		if (!hFileMap) { goto Error; }

		LPVOID lpAddress = MapViewOfFile(hFileMap, FILE_MAP_WRITE, 0, 0, 0);
		if (!lpAddress) { goto Error; }

		// Write the file
		CopyMemory(lpAddress, lpFile, dwSize);

		// Un-map the file and close the handles
		UnmapViewOfFile(lpAddress);
		CloseHandle(hFileMap);
		CloseHandle(hFile);
	}

	int textureID;
	if (std::filesystem::exists(CheatFunctions::ReturnTextureFilePath()))
	{
		GameHooking::texture_file_register(&textureID, CheatFunctions::StringToChar(CheatFunctions::ReturnTextureFilePath()), true, "Textures.ytd", false);
		return;
	}
	else
	{
		goto Error;
	}

	//Error
Error:
	GameFunctions::MinimapNotification("~r~Failed to load Texture file");
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Failed to load Texture file; missing");
}

void GUI::DrawTextInGame(std::string text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool Outline)
{
	if (!GUI::HideGUIElements)
	{
		UI::SET_TEXT_CENTRE(center);
		UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
		UI::SET_TEXT_FONT(rgbaf.f);
		if (Outline) { UI::SET_TEXT_OUTLINE(); }
		UI::SET_TEXT_SCALE(size.w, size.h);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(CheatFunctions::StringToChar(text));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y, 0);
	}
}

void GUI::DrawSpriteInGame(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GUI::HideGUIElements)
	{
		if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture.c_str()))
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture.c_str(), false);
		}
		else
		{
			GRAPHICS::DRAW_SPRITE(Streamedtexture.c_str(), textureName.c_str(), x, y, width, height, rotation, r, g, b, a, false, 0);
		}
	}
}

void GUI::DrawRectInGame(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	if (!GUI::HideGUIElements)
	{
		GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a, false);
	}
}

void Cheat::GUI::ShowPlayerInformationBox(Player PlayerID)
{
	if (!Cheat::CheatFeatures::HidePlayerInformationBox)
	{
		//Definitions
		Ped SelectedPlayerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PlayerID);
		GameFunctions::RequestNetworkControlOfEntity(SelectedPlayerPed);

		//Draw Title and Background
		if (Cheat::GUI::guiX < 0.54f)
		{
			GUI::DrawRectInGame(GUI::PrimaryColor, { guiX + (GUI::guiWidth / 2) + 0.166f, GUI::guiY + 0.014f }, { 0.32f, 0.31f }); //Main Background Rect
			GUI::DrawTextInGame("Player Information", { GUI::TextColorAndFont }, { guiX + (GUI::guiWidth / 2) + 0.155f, GUI::guiY - 0.170f }, { 0.50f, 0.37f }, true);
			GUI::DrawRectInGame({ 0, 0, 0, 210 }, { guiX + (GUI::guiWidth / 2) + 0.166f, GUI::guiY - 0.156f }, { 0.32f, 0.030f });
		}
		else
		{
			GUI::DrawRectInGame(GUI::PrimaryColor, { guiX - (GUI::guiWidth / 2) - 0.166f, GUI::guiY + 0.014f }, { 0.32f, 0.31f }); //Main Background Rect
			GUI::DrawTextInGame("Player Information", { GUI::TextColorAndFont }, { guiX - (GUI::guiWidth / 2) - 0.155f, GUI::guiY - 0.170f }, { 0.50f, 0.37f }, true);
			GUI::DrawRectInGame({ 0, 0, 0, 210 }, { guiX - (GUI::guiWidth / 2) - 0.166f,GUI::guiY - 0.156f }, { 0.32f, 0.030f });
		}

		//Text Entry's
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Name", 1);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(PLAYER::GET_PLAYER_NAME(PlayerID), NULL, 1);

		Cheat::GUI::AddPlayerInfoBoxTextEntry("Rank", 2);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Money", 3);
		if (NETWORK::NETWORK_IS_SESSION_STARTED())
		{
			std::ostringstream PlayerRank;
			PlayerRank << globalHandle(1590908 + 1).At(PlayerID, 874).At(205).At(5).As<int>();
			Cheat::GUI::AddPlayerInfoBoxTextEntry(PlayerRank.str(), NULL, 2);

			std::ostringstream PlayerMoney;
			PlayerMoney << "$" << globalHandle(1590908).At(PlayerID, 874).At(205).At(56).As<__int64>();
			Cheat::GUI::AddPlayerInfoBoxTextEntry(PlayerMoney.str(), NULL, 3);
		}
		else
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("N/A", NULL, 2);
			Cheat::GUI::AddPlayerInfoBoxTextEntry("N/A", NULL, 3);
		}

		//Health
		std::ostringstream Health;
		float health = ENTITY::GET_ENTITY_HEALTH(SelectedPlayerPed);
		float HealthValue = health * 100 / ENTITY::GET_ENTITY_MAX_HEALTH(SelectedPlayerPed);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Health", 4);
		if (HealthValue == 100)
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("Full", NULL, 4);
		}
		else
		{
			Health << HealthValue << "%";
			Cheat::GUI::AddPlayerInfoBoxTextEntry(Health.str(), NULL, 4);
		}

		//Armor
		std::ostringstream Armor;
		int ArmorValue = PED::GET_PED_ARMOUR(SelectedPlayerPed) * 100 / PLAYER::GET_PLAYER_MAX_ARMOUR(PlayerID);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Armor", 5);
		if (ArmorValue == 99 || ArmorValue == 100)
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("Full", NULL, 5);
		}
		else
		{
			Armor << ArmorValue;
			Cheat::GUI::AddPlayerInfoBoxTextEntry(Armor.str(), NULL, 5);
		}

		//Status
		std::ostringstream Status;
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Status", 6);
		if (TASK::IS_PED_STILL(SelectedPlayerPed)) { Status << "Player is still"; }
		else if (TASK::IS_PED_WALKING(SelectedPlayerPed)) { Status << "Player is walking"; }
		else if (TASK::IS_PED_RUNNING(SelectedPlayerPed)) { Status << "Player is running"; }
		else if (TASK::IS_PED_SPRINTING(SelectedPlayerPed)) { Status << "Player is sprinting"; }
		else if (PED::IS_PED_CLIMBING(SelectedPlayerPed)) { Status << "Player is climbing"; }
		else if (PED::IS_PED_DIVING(SelectedPlayerPed)) { Status << "Player is diving"; }
		else if (PED::IS_PED_FALLING(SelectedPlayerPed)) { Status << "Player is falling"; }
		else if (PED::IS_PED_DEAD_OR_DYING(SelectedPlayerPed, true)) { Status << "Player is dead"; }
		else { Status << "~c~Unknown"; }
		Cheat::GUI::AddPlayerInfoBoxTextEntry(Status.str(), NULL, 6);


		//Vehicle
		bool InAnyVehicle = PED::IS_PED_IN_ANY_VEHICLE(SelectedPlayerPed, 0);
		std::ostringstream Vehicle;
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Vehicle", 7);
		if (InAnyVehicle)
		{
			Vehicle << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(SelectedPlayerPed, 0))));
		}
		else
		{
			Vehicle << "~c~Not in a vehicle";
		}
		Cheat::GUI::AddPlayerInfoBoxTextEntry(Vehicle.str(), NULL, 7);


		//Speed
		std::ostringstream Speed;
		if (InAnyVehicle)
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("Vehicle Speed", 8);
			float VehicleSpeed = round(ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(SelectedPlayerPed, false)) * 100) / 100;
			if (MISC::SHOULD_USE_METRIC_MEASUREMENTS())
			{
				Speed << GameFunctions::MSToKMH(VehicleSpeed) << " KM/H";
			}
			else
			{
				Speed << GameFunctions::MSToMPH(VehicleSpeed) << " MP/H";
			}
			Cheat::GUI::AddPlayerInfoBoxTextEntry(Speed.str(), NULL, 8);
		}
		else
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("Movement Speed", 8);
			Speed << round(ENTITY::GET_ENTITY_SPEED(SelectedPlayerPed) * 100) / 100 << " M/S";
			Cheat::GUI::AddPlayerInfoBoxTextEntry(Speed.str(), NULL, 8);
		}


		//Wanted Level
		std::ostringstream WantedLevel;
		int PlayerWantedLevel = PLAYER::GET_PLAYER_WANTED_LEVEL(PlayerID);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Wanted Level", 9);
		WantedLevel << PlayerWantedLevel << "/5";
		Cheat::GUI::AddPlayerInfoBoxTextEntry(WantedLevel.str(), NULL, 9);


		Hash WeaponHash;
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Weapon", 10);
		std::string WeaponName;
		if (WEAPON::GET_CURRENT_PED_WEAPON(SelectedPlayerPed, &WeaponHash, true))
		{
			for (auto const& i : GameArrays::WeaponsHashList)
			{
				if (WeaponHash == i.WeaponHash)
				{
					WeaponName = i.WeaponName;
				}
			}

		}
		else
		{
			WeaponName = "Unarmed";
		}
		Cheat::GUI::AddPlayerInfoBoxTextEntry(WeaponName, NULL, 10);


		//Coords
		Vector3 SelectedPlayerPedCoords = ENTITY::GET_ENTITY_COORDS(SelectedPlayerPed, false);
		std::ostringstream CoordX;
		std::ostringstream CoordY;
		std::ostringstream CoordZ;

		CoordX << SelectedPlayerPedCoords.x;
		CoordY << SelectedPlayerPedCoords.y;
		CoordZ << SelectedPlayerPedCoords.z;

		Cheat::GUI::AddPlayerInfoBoxTextEntry("X", 11);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Y", 12);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Z", 13);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(CoordX.str(), NULL, 11);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(CoordY.str(), NULL, 12);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(CoordZ.str(), NULL, 13);


		std::ostringstream Zone;
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Zone", 14);
		Zone << UI::_GET_LABEL_TEXT(ZONE::GET_NAME_OF_ZONE(SelectedPlayerPedCoords.x, SelectedPlayerPedCoords.y, SelectedPlayerPedCoords.z));
		Cheat::GUI::AddPlayerInfoBoxTextEntry(Zone.str(), NULL, 14);


		Hash streetName, crossingRoad;
		PATHFIND::GET_STREET_NAME_AT_COORD(SelectedPlayerPedCoords.x, SelectedPlayerPedCoords.y, SelectedPlayerPedCoords.z, &streetName, &crossingRoad);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Street", 15);
		std::ostringstream Street;
		Street << UI::GET_STREET_NAME_FROM_HASH_KEY(streetName);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(Street.str(), NULL, 15);

		float distance = GameFunctions::Get3DDistance(SelectedPlayerPedCoords, ENTITY::GET_ENTITY_COORDS(Cheat::GameFunctions::PlayerPedID, false));
		std::ostringstream Distance;

		if (PlayerID != GameFunctions::PlayerID)
		{
			if (distance > 1000)
			{
				distance = round((distance / 1000) * 100) / 100;
				Distance << distance << " KM";
			}
			else
			{
				distance = round(distance * 1000) / 100;
				Distance << distance << " M";
			}
		}
		else
		{
			Distance << "N/A";
		}
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Distance", NULL, NULL, 1);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(Distance.str(), NULL, NULL, NULL, 1);


		//Modded Model
		Hash SelectedPlayerPedModel = ENTITY::GET_ENTITY_MODEL(SelectedPlayerPed);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Modded Model", NULL, NULL, 2);
		if (NETWORK::NETWORK_IS_SESSION_STARTED() && SelectedPlayerPedModel != MISC::GET_HASH_KEY("mp_m_freemode_01") && SelectedPlayerPedModel != MISC::GET_HASH_KEY("mp_f_freemode_01"))
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("Yes", NULL, NULL, NULL, 2);
		}
		else
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("No", NULL, NULL, NULL, 2);
		}

		//Is in interior
		Cheat::GUI::AddPlayerInfoBoxTextEntry("In Interior", NULL, NULL, 3);
		if (Cheat::GameFunctions::IsEntityInInterior(SelectedPlayerPed))
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("Yes", NULL, NULL, NULL, 3);
		}
		else
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("No", NULL, NULL, NULL, 3);
		}

		//Cutscene
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Cutscene", NULL, NULL, 4);
		if (NETWORK::IS_PLAYER_IN_CUTSCENE(PlayerID))
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("Yes", NULL, NULL, NULL, 4);
		}
		else
		{
			Cheat::GUI::AddPlayerInfoBoxTextEntry("No", NULL, NULL, NULL, 4);
		}

		//Rockstar ID
		Cheat::GUI::AddPlayerInfoBoxTextEntry("Rockstar ID", NULL, NULL, 5);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(std::to_string(Cheat::GameFunctions::ReturnPlayerRockstarID(PlayerID)), NULL, NULL, NULL, 5);

		//IP Address
		std::string PlayerIPString = Cheat::GameFunctions::ReturnPlayerIPAddressAsString(PlayerID);
		Cheat::GUI::AddPlayerInfoBoxTextEntry("IP Address", NULL, NULL, 6);
		Cheat::GUI::AddPlayerInfoBoxTextEntry(PlayerIPString, NULL, NULL, NULL, 6);
	}
}