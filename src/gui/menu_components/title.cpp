#include "../../cheat/fibermain.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;

std::string CursorBackCloseString;
void GUI::Title(std::string TitleName)
{
	if (ShowHeaderBackground) { DrawRectInGame({ PrimaryColor.r, PrimaryColor.g, PrimaryColor.b, HeaderBackgroundTransparency }, { guiX, GUI::guiY - SelectableHeight - 0.181f }, { guiWidth, SelectableHeight + 0.045f }); }
	if (ShowHeaderTexture) { DrawSpriteInGame("Textures", "HeaderDefaultTransparent", guiX, GUI::guiY - SelectableHeight - 0.181f, guiWidth, SelectableHeight + 0.045f, 0, 255, 255, 255, HeaderTextureTransparency); }
	DrawTextInGame(TitleName, TextColorAndFont, { GUI::guiX, GUI::guiY - 0.174f }, { 0.40f, 0.38f }, true, true);
	DrawRectInGame({ 0, 0, 0, TitleAndEndTransparency }, { guiX, GUI::guiY - 0.1585f }, { guiWidth, SelectableHeight });

	if (gui_controls::cursor_nav_state)
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