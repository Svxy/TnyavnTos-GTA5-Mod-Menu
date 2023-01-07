#include "../cheat/fibermain.hpp"
#include "../game/notification.hpp"
#include "../gui/gui_controls.hpp"
#include "../hooking/natives.hpp"
 
namespace Cheat
{
	namespace GUI
	{
		bool gui_controls::AllowGameplayWithCursorNavigationActive		= false;
		bool gui_controls::DisableCursorNavigationWhenMenuGUIIsClosed	= false;
		int gui_controls::KeyPressDelayPreviousTick = GetTickCount64();
		bool gui_controls::KeyInputDisabled		= false;
		bool gui_controls::SelectPressed		= false;
		bool gui_controls::LeftPressed			= false;
		bool gui_controls::RightPressed			= false;
		int gui_controls::KeyPressDelay			=	150;
		int gui_controls::OpenMenuGUIKey		= VK_F4;
		int gui_controls::CursorNavigationKey	= VK_F5;
		int gui_controls::SaveSelectableKey		= VK_F12;
		void gui_controls::Loop()
		{
			if (!KeyInputDisabled)
			{
				SelectPressed = false;
				LeftPressed = false;
				RightPressed = false;

				if (GetTickCount64() - KeyPressDelayPreviousTick > KeyPressDelay)
				{
					// Enable/Disable Cursor Control
					if (IsKeyCurrentlyPressed(CursorNavigationKey))
					{
						gui_controls::toggle_cursor_nav_state();
						KeyPressDelayPreviousTick = GetTickCount64();
					}

					// Menu GUI
					if (IsKeyCurrentlyPressed(OpenMenuGUIKey))
					{
						GUI::MenuGUIHasBeenOpened = true;
						if (GUI::menuLevel == 0)
						{
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"YES", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
							if (GUI::PreviousMenu != nullptr && GUI::RestorePreviousSubmenu)
							{
								GUI::MoveMenu(GUI::PreviousMenu);
								GUI::menuLevel = GUI::PreviousMenuLevel;
								GUI::currentOption = GUI::previousOption;
							}
							else
							{
								GUI::MoveMenu(GUI::Submenus::Home);
							}
							if (!GUI::DisableMenuGUIOpenCloseFade)
							{
								MenuGUIFade(true);
							}
						}
						else
						{
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"NO", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
							if (!GUI::DisableMenuGUIOpenCloseFade)
							{
								MenuGUIFade(false);
							}
							else
							{
								GUI::CloseMenuGUI();
							}
						}
						KeyPressDelayPreviousTick = GetTickCount64();
					}
					else if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_CANCEL))
					{
						if (GUI::menuLevel > 0)
						{
							GUI::BackMenu();
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
						}
						KeyPressDelayPreviousTick = GetTickCount64();
					}
					else if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_UP))
					{
						GUI::currentOption > 1 ? GUI::currentOption-- : GUI::currentOption = GUI::optionCount;
						if (GUI::menuLevel > 0)
						{
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
						}
						KeyPressDelayPreviousTick = GetTickCount64();
					}
					else if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_DOWN))
					{
						GUI::currentOption < GUI::optionCount ? GUI::currentOption++ : GUI::currentOption = 1;
						if (GUI::menuLevel > 0)
						{
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
						}
						KeyPressDelayPreviousTick = GetTickCount64();
					}
					else if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_RIGHT))
					{
						LeftPressed = true;
						if (GUI::menuLevel > 0)
						{
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
						}
						KeyPressDelayPreviousTick = GetTickCount64();
					}
					else if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_LEFT))
					{
						RightPressed = true;
						if (GUI::menuLevel > 0)
						{
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
						}
						KeyPressDelayPreviousTick = GetTickCount64();
					}
					else if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_ACCEPT))
					{
						SelectPressed = true;
						if (GUI::menuLevel > 0)
						{
							AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"SELECT", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
						}
						KeyPressDelayPreviousTick = GetTickCount64();
					}
				}
				GUI::optionCount = 0;
				GUI::optionCountVisible = 0;
			}

			// Cursor Navigation Handler
			if (gui_controls::cursor_nav_state)
			{
				// Handle menu GUI navigation - only when the menu is actually open/visible
				UI::_SET_MOUSE_CURSOR_ACTIVE_THIS_FRAME();
				UI::_SET_MOUSE_CURSOR_SPRITE(CursorType::Normal);

				if (GUI::menuLevel > 0)
				{
					if (gui_controls::cursor_at_pos({ GUI::guiX, GUI::guiY - GUI::SelectableHeight - 0.181f }, { GUI::guiWidth, GUI::SelectableHeight + 0.045f }))
					{
						UI::_SET_MOUSE_CURSOR_SPRITE(CursorType::PreGrab);
						if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_ACCEPT))
						{
							GUI::guiX = gui_controls::get_cursor_location().x;
							GUI::guiY = gui_controls::get_cursor_location().y + 0.20f;
						}
					}
					if (gui_controls::cursor_at_pos({ GUI::SelectableInfoBoxX, GUI::SelectableInfoBoxY }, { 0.25f, 0.080f }))
					{
						UI::_SET_MOUSE_CURSOR_SPRITE(CursorType::PreGrab);
						if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_ACCEPT))
						{
							GUI::SelectableInfoBoxX = gui_controls::get_cursor_location().x;
							GUI::SelectableInfoBoxY = gui_controls::get_cursor_location().y;
						}
					}
					// Menu GUI Close/Back Button
					if (gui_controls::cursor_at_pos({ GUI::guiX - 0.100f, GUI::guiY - 0.156f }, { 0.060f, 0.025f }))
					{
						UI::_SET_MOUSE_CURSOR_SPRITE(CursorType::PreGrab);
						if (PAD::IS_DISABLED_CONTROL_JUST_RELEASED(0, INPUT_CURSOR_ACCEPT))
						{
							GUI::BackMenu();
						}
					}
					// Scroll Up
					if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_SCROLL_UP))
					{
						if (GUI::currentOption > 1)
						{
							GUI::currentOption -= 1;
						}
						else
						{
							GUI::currentOption = GUI::TotalOptionsCount;
						}
						AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
					}
					// Scroll Down
					if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_SCROLL_DOWN))
					{
						if (GUI::TotalOptionsCount > GUI::currentOption)
						{
							GUI::currentOption += 1;
						}
						else
						{
							GUI::currentOption = 1;
						}
						AUDIO::PLAY_SOUND_FRONTEND(-1, (char*)"NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
					}
				}
			}
		}
		bool gui_controls::IsKeyCurrentlyPressed(int vKey, bool RepeatInput)
		{
			if (GUI::IsGameWindowFocussed() && !KeyInputDisabled)
			{
				if (RepeatInput)
				{
					if (GetAsyncKeyState(vKey) & 0x8000)
						return true;
				}
				else
				{
					if (GetAsyncKeyState(vKey) & 0x01)
						return true;
				}
			}
			return false;
		}
		std::string gui_controls::VirtualKeyCodeToString(unsigned char virtualKey)
		{
			for (auto& pl : GUI::gui_controls::VirtualKeyToString)
			{
				if (pl.first == virtualKey)
				{
					return pl.second;
				}
			}
			return std::to_string(virtualKey);
		}
		const std::map<int, std::string> gui_controls::VirtualKeyToString
		{
			{ VK_LBUTTON, "Left mouse button" },
			{ VK_RBUTTON, "Right mouse button"},
			{ VK_CANCEL, "Control-break"},
			{ VK_MBUTTON, "Middle mouse button" },
			{ VK_BACK, "Backspace" },
			{ VK_TAB, "Tab" },
			{ VK_CLEAR, "Clear" },
			{ VK_RETURN, "Enter" },
			{ VK_SHIFT, "Shift (L/R)" },
			{ VK_CONTROL, "Control (L/R)" },
			{ VK_MENU, "Alt" },
			{ VK_PAUSE, "Pause" },
			{ VK_CAPITAL, "Caps Lock" },
			{ VK_ESCAPE, "Escape" },
			{ VK_SPACE, "Spacebar" },
			{ VK_PRIOR, "Page Up" },
			{ VK_NEXT, "Page Down" },
			{ VK_END, "End" },
			{ VK_HOME, "Home" },
			{ VK_LEFT, "Left Arrow" },
			{ VK_UP, "Up Arrow" },
			{ VK_RIGHT, "Right Arrow" },
			{ VK_DOWN, "Down Arroow" },
			{ VK_SELECT, "Select" },
			{ VK_PRINT, "Print" },
			{ VK_EXECUTE, "Execute" },
			{ VK_SNAPSHOT, "Print Screen" },
			{ VK_INSERT, "Insert" },
			{ VK_DELETE, "Delete" },
			{ VK_HELP, "Help" },
			{ 48, "0" },
			{ 49, "1" },
			{ 50, "2" },
			{ 51, "3" },
			{ 52, "4" },
			{ 53, "5" },
			{ 54, "6" },
			{ 55, "7" },
			{ 56, "8" },
			{ 57, "9" },
			{ 65, "A" },
			{ 66, "B" },
			{ 67, "C" },
			{ 68, "D" },
			{ 69, "E" },
			{ 70, "F" },
			{ 71, "G" },
			{ 72, "H" },
			{ 73, "I" },
			{ 74, "J" },
			{ 75, "K" },
			{ 76, "L" },
			{ 77, "M" },
			{ 78, "N" },
			{ 79, "O" },
			{ 80, "P" },
			{ 81, "Q" },
			{ 82, "R" },
			{ 83, "S" },
			{ 84, "T" },
			{ 85, "U" },
			{ 86, "V" },
			{ 87, "W" },
			{ 88, "X" },
			{ 89, "Y" },
			{ 90, "Z" },
			{ VK_LWIN, "Left Windows Key" },
			{ VK_RWIN, "Right Windows Key" },
			{ VK_SLEEP, "Sleep" },
			{ VK_NUMPAD0, "Numpad 0" },
			{ VK_NUMPAD1, "Numpad 1" },
			{ VK_NUMPAD2, "Numpad 2" },
			{ VK_NUMPAD3, "Numpad 3" },
			{ VK_NUMPAD4, "Numpad 4" },
			{ VK_NUMPAD5, "Numpad 5" },
			{ VK_NUMPAD6, "Numpad 6" },
			{ VK_NUMPAD7, "Numpad 7" },
			{ VK_NUMPAD8, "Numpad 8" },
			{ VK_NUMPAD9, "Numpad 9" },
			{ VK_MULTIPLY, "Numpad *" },
			{ VK_ADD, "Add" },
			{ VK_SEPARATOR, "Seperator" },
			{ VK_SUBTRACT, "Substract" },
			{ VK_DECIMAL, "Decimal" },
			{ VK_DIVIDE, "Divide" },
			{ VK_F1, "F1" },
			{ VK_F2, "F2" },
			{ VK_F3, "F3" },
			{ VK_F4, "F4" },
			{ VK_F5, "F5" },
			{ VK_F6, "F6" },
			{ VK_F7, "F7" },
			{ VK_F8, "F8" },
			{ VK_F9, "F9" },
			{ VK_F10, "F10" },
			{ VK_F11, "F11" },
			{ VK_F12, "F12" },
			{ VK_NUMLOCK, "Num Lock" },
			{ VK_SCROLL, "Scroll Lock" },
			{ VK_LSHIFT, "Left Shift" },
			{ VK_RSHIFT, "Right Shift" },
			{ VK_LCONTROL, "Left Control" },
			{ VK_RCONTROL, "Right Control" }
		};
		int gui_controls::WaitForAndReturnPressedKey()
		{
			while (true)
			{
				GUI::DrawTextInGame("Press any key, press Backspace to cancel", { 255, 255, 255, 255 }, { 0.525f, 0.400f }, { 0.900f, 0.900f }, true);
				for (int i = 1; i < 256; i++)
				{
					if (GUI::gui_controls::IsKeyCurrentlyPressed(i, true) && i != VK_RETURN && i != VK_NUMPAD5 && i != VK_ESCAPE)
					{
						if (i == VK_BACK)
						{
							Game::notification::Minimap((char*)"Canceled Key Selection");
							return 0;
						}
						return i;
					}
				}
				SwitchToFiber(GameHooking::fiber_main);
			}
		}
		Vector2 gui_controls::get_cursor_location()
		{
			return { PAD::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_X), PAD::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_Y) };
		}
		// https://github.com/MAFINS/MenyooSP/blob/v1.3.0/Solution/source/Menu/Menu.cpp
		bool gui_controls::cursor_at_pos(Vector2 const& boxCentre, Vector2 const& boxSize)
		{
			return (get_cursor_location().x >= boxCentre.x - boxSize.x / 2 && get_cursor_location().x <= boxCentre.x + boxSize.x / 2)
				&& (get_cursor_location().y > boxCentre.y - boxSize.y / 2 && get_cursor_location().y < boxCentre.y + boxSize.y / 2);
		}
		bool gui_controls::cursor_nav_state = false;
		bool gui_controls::toggle_cursor_nav_state()
		{
			if (cursor_nav_state)
			{
				cursor_nav_state = false;
				if (!GUI::gui_controls::AllowGameplayWithCursorNavigationActive)
					PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), true, 0);
			}
			else
			{
				cursor_nav_state = true;
				if (!GUI::gui_controls::AllowGameplayWithCursorNavigationActive)
					PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), false, 0);
			}
		}
	}
}