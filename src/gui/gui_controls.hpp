#pragma once
#include <map>

namespace Cheat
{
	namespace GUI
	{
		class gui_controls
		{
		public:
			static void Loop();
			static bool KeyInputDisabled;
			static int KeyPressDelay;
			static int OpenMenuGUIKey;
			static int CursorNavigationKey;
			static int SaveSelectableKey;
			static std::string VirtualKeyCodeToString(unsigned char virtualKey);
			static bool IsKeyCurrentlyPressed(int vKey, bool RepeatInput = false);
			static const std::map<int, std::string> VirtualKeyToString;
			static bool AllowGameplayWithCursorNavigationActive;
			static bool DisableCursorNavigationWhenMenuGUIIsClosed;
			static Vector2 get_cursor_location();
			static int WaitForAndReturnPressedKey();
			static bool cursor_at_pos(Vector2 const& boxCentre, Vector2 const& boxSize);
			static bool cursor_nav_state;
			static bool toggle_cursor_nav_state();

			static bool SelectPressed;
			static bool LeftPressed;
			static bool RightPressed;
		private:
			static int KeyPressDelayPreviousTick;
		};
	}
}