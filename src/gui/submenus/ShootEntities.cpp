#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::ShootEntities()
{
	GUI::Title("Shoot Entities");
	GUI::Toggle("Toggle", Features::ShootEntitiesBool, "");
	GUI::Break("Current: ~t~" + Features::ShootEntitiesCurrent, false);
	if (GUI::Option("Custom Entity", ""))
	{
		std::string Input;
		if (Game::keyboard::get_input("Custom Entity Model Name", Input, 5, 25) == Game::keyboard::input_status::SUCCESS)
		{
			if (STREAMING::IS_MODEL_VALID(MISC::GET_HASH_KEY(Input.c_str())))
				Features::ShootEntitiesCurrent = Input;
			else
				Game::notification::Minimap((char*)"~r~That is not a valid entity name");
		}
	}
}