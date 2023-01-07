#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/data/game_data.hpp"
#include <algorithm>

using namespace Cheat;
std::string ChangeModelPedSearchTerm;
void GUI::Submenus::SelfModel()
{
	GUI::Title("Model");
	if (GUI::Option("Custom Input", "Input custom Ped model"))
	{
		std::string KeyboardInput;
		if (Game::keyboard::get_input("Enter custom ped model name", KeyboardInput, 5, 30) == Game::keyboard::input_status::SUCCESS)
		{
			DWORD model = MISC::GET_HASH_KEY(KeyboardInput.c_str());
			if (!STREAMING::IS_MODEL_IN_CDIMAGE(model))
			{
				Game::notification::Minimap((char*)"~r~That is not a valid ped model");
			}
			else
			{
				Game::ped::change_player_model(model);
			}
		}	
	}
	GUI::Break("Ped List", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Search", "Enter keywords to filter ped list"))
	{
		std::string KeyboardInput;
		if (Game::keyboard::get_input( "Enter search term", KeyboardInput, 1, 30) == Game::keyboard::input_status::SUCCESS)
		{
			ChangeModelPedSearchTerm = KeyboardInput;
			std::transform(ChangeModelPedSearchTerm.begin(), ChangeModelPedSearchTerm.end(), ChangeModelPedSearchTerm.begin(), tolower);
		}
	}
	if (!ChangeModelPedSearchTerm.empty())
	{
		if (GUI::Option("Clear Search Results", ""))
		{
			ChangeModelPedSearchTerm.clear();
		}
		GUI::Break("Search Results", SELECTABLE_CENTER_TEXT);
	}
	for (auto const& i : game_data::PedModels)
	{
		std::string i_lowercase = i;
		std::transform(i_lowercase.begin(), i_lowercase.end(), i_lowercase.begin(), tolower);
		if (ChangeModelPedSearchTerm.empty() || i_lowercase.find(ChangeModelPedSearchTerm) != std::string::npos)
		{
			if (GUI::Option(i, ""))
			{
				Game::ped::change_player_model(MISC::GET_HASH_KEY(helper::StringToChar(i)));
			}
		}
	}
}