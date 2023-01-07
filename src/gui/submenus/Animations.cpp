#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/data/game_data.hpp"

using namespace Cheat;
void GUI::Submenus::Animations()
{
	GUI::Title("Animations");
	GUI::Toggle("Controllable", Features::ControllableAnimations, "You can move and shoot while an animation is playing");
	if (GUI::Option("Stop Animation", "")) { TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID()); }
	if (GUI::StringVector("Animations", game_data::AnimationsDisplayNames, Features::AnimationsVectorPosition, "Select to play animation", SELECTABLE_DISABLE_SAVE))
	{
		int IndexCount = 0;
		for (auto const& i : game_data::Animations)
		{
			if (IndexCount == Features::AnimationsVectorPosition)
			{
				Game::ped::play_animation(PLAYER::PLAYER_PED_ID(), helper::StringToChar(i.AnimationDictionary), helper::StringToChar(i.AnimationName), Features::ControllableAnimations);
			}
			IndexCount++;
		}
	}
	if (GUI::StringVector("Scenarios", game_data::Scenarios, Features::ScenariosVectorPosition, "Select to play scenario. 'Controllable' toggle not applicable.", SELECTABLE_DISABLE_SAVE))
	{
		int IndexCount = 0;
		for (auto const& i : game_data::Scenarios)
		{
			if (IndexCount == Features::ScenariosVectorPosition)
			{
				TASK::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), helper::StringToChar(i), 0, true);
			}
			IndexCount++;
		}
	}
}