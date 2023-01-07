#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../cheat/file_system.hpp"
#include "../../game/features/theme_loader.hpp"
#include <filesystem>

using namespace Cheat;
void GUI::Submenus::ThemeFiles()
{
	GUI::Title("Available Themes");
	if (!Features::theme_loader::Array.empty())
	{
		for (auto const& i : Features::theme_loader::Array)
		{
			if (GUI::Option(i, ""))
			{
				if (std::filesystem::exists(file_system::paths::ThemesDir + "\\" + i + ".ini"))
				{
					Features::theme_loader::Load(helper::StringToChar(i), false);
				}
				else
				{
					Game::notification::Minimap((char*)"~r~Unable to locate theme file");
				}
			}
		}
	}
	else
	{
		GUI::Break("No themes have been saved");
	}
}