#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::ThemeFiles()
{
	GUI::Title("Saved Themes");
	if (!GUI::ThemeFilesVector.empty())
	{
		for (auto const& i : GUI::ThemeFilesVector)
		{
			if (GUI::Option(i, ""))
			{
				if (std::filesystem::exists(CheatFunctions::ReturnThemeFilePath(i)))
				{
					GUI::LoadTheme(CheatFunctions::StringToChar(i), false);
				}
				else
				{
					GameFunctions::MinimapNotification("~r~Unable to locate theme file");
				}
			}
		}
	}
	else
	{
		GUI::Break("No Theme Files Saved Yet");
	}
}