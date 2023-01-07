#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::Television()
{
	GUI::Title("Television");
	GUI::Toggle("Draw TV", Features::ShowTVBool, "");
	GUI::Break("Playlist", SELECTABLE_CENTER_TEXT);
	for (auto& pl : game_data::TelevisionPlaylists)
	{
		if (GUI::Option(pl.DisplayName, ""))
		{
			GRAPHICS::SET_TV_CHANNEL(-1);
			GRAPHICS::SET_TV_CHANNEL_PLAYLIST(0, pl.InternalName.c_str(), true);
			GRAPHICS::SET_TV_CHANNEL(0);
		}
	}
}