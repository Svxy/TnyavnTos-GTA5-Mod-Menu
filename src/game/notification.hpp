#pragma once

namespace Cheat
{
	namespace Game
	{
		class notification
		{
		public:
			static void Minimap(char* Message);
			static void Subtitle(char* Message, int duration);
			static void MinimapAdvanced(char* Message, char* PicName1, char* PicName2, bool Flash, int IconType, char* Sender, char* Subject, float Duration, char* ClanTag);
		};
	}
}