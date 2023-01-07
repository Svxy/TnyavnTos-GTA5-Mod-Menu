#include "notification.hpp"
#include "../cheat/fibermain.hpp"
#include "../hooking/natives.hpp"

namespace Cheat
{
	namespace Game
	{
		void notification::MinimapAdvanced(char* Message, char* PicName1, char* PicName2, bool Flash, int IconType, char* Sender, char* Subject, float Duration, char* ClanTag)
		{
			UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Message);
			UI::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_WITH_CREW_TAG(PicName1, PicName2, Flash, IconType, Sender, Subject, Duration, ClanTag);
			UI::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
		}
		void notification::Minimap(char* Message)
		{
			UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Message);
			UI::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
		}
		void notification::Subtitle(char* Message, int duration)
		{
			UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Message);
			UI::END_TEXT_COMMAND_PRINT(duration, true);
		}

	}
}