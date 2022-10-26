#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::Animations()
{
	GUI::Title("Animations");
	GUI::Toggle("Controllable", CheatFeatures::ControllableAnimations, "You can move and shoot while an animation is playing");
	if (GUI::Option("Stop Animation", "")) { GameFunctions::StopAllPedAnimations(GameFunctions::PlayerPedID); }
	if (GUI::StringVector("Animations", GameArrays::AnimationsDisplayNames, CheatFeatures::AnimationsVectorPosition, "Select to play animation", SELECTABLE_DISABLE_SAVE))
	{
		int IndexCount = 0;
		for (auto const& i : GameArrays::Animations)
		{
			if (IndexCount == CheatFeatures::AnimationsVectorPosition)
			{
				GameFunctions::PlayPedAnimation(GameFunctions::PlayerPedID, CheatFunctions::StringToChar(i.AnimationDictionary), CheatFunctions::StringToChar(i.AnimationName), CheatFeatures::ControllableAnimations);
			}
			IndexCount++;
		}
	}
	if (GUI::StringVector("Scenarios", GameArrays::Scenarios, CheatFeatures::ScenariosVectorPosition, "Select to play scenario. 'Controllable' toggle not applicable.", SELECTABLE_DISABLE_SAVE))
	{
		int IndexCount = 0;
		for (auto const& i : GameArrays::Scenarios)
		{
			if (IndexCount == CheatFeatures::ScenariosVectorPosition)
			{
				TASK::TASK_START_SCENARIO_IN_PLACE(GameFunctions::PlayerPedID, CheatFunctions::StringToChar(i), 0, true);
			}
			IndexCount++;
		}
	}
}