#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../hooking/globalhandle.hpp"
#include "../../hooking/offsets.hpp"

using namespace Cheat;
int ChangeSessionInteger = 0;
void GUI::Submenus::SessionStarter()
{
	GUI::Title("Session Starter");
	GUI::Toggle("Lock to friends", Features::SessionLockFriendsOnlyBool, "Continually kicks non-friends from session");
	GUI::Break("Join/Change", SELECTABLE_CENTER_TEXT);
	if (GUI::StringVector(NETWORK::NETWORK_IS_SESSION_STARTED() ? "Change Session" : "Join Session", { "Join Public", "New Public", "Closed Crew", "Crew", "Closed Friend", "Solo", "Invite Only" }, ChangeSessionInteger, "", SELECTABLE_DISABLE_SAVE))
	{
		Game::gtao::session_types SetType;
		if (ChangeSessionInteger == 0)
		{
			SetType = Game::gtao::session_types::SessionTypeJoinPublic;
		}
		else if (ChangeSessionInteger == 1)
		{
			SetType = Game::gtao::session_types::SessionTypeNewPublic;
		}
		else if (ChangeSessionInteger == 2)
		{
			SetType = Game::gtao::session_types::SessionTypeClosedCrew;
		}
		else if (ChangeSessionInteger == 3)
		{
			SetType = Game::gtao::session_types::SessionTypeCrew;
		}
		else if (ChangeSessionInteger == 4)
		{
			SetType = Game::gtao::session_types::SessionTypeClosedFriend;
		}
		else if (ChangeSessionInteger == 5)
		{
			SetType = Game::gtao::session_types::SessionTypeSolo;
		}
		else if (ChangeSessionInteger == 6)
		{
			SetType = Game::gtao::session_types::SessionTypeInviteOnly;
		}
		Game::gtao::change_session(SetType);
	}
	if (GUI::Option("Join Session Containing Friends", "Searches for and joins a game session with one or more friends"))
	{
		Game::gtao::change_session(Game::gtao::session_types::SessionTypeFindFriend);
	}
	if (GUI::Option("Join Session Containing Crew Members", "Searches for and joins a game session with one or more crew members"))
	{
		Game::gtao::change_session(Game::gtao::session_types::SessionTypeJoinCrew);
	}
	GUI::Break("SCTV", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Start SCTV Public Session", "Also known as Rockstar Dev/Spectator Mode"))
	{
		globalHandle(GLOBAL_SCTV).As<bool>() = true;
		Game::gtao::change_session(Game::gtao::session_types::SessionTypeJoinPublic);
	}
	if (globalHandle(GLOBAL_SCTV).As<bool>())
	{
		if (GUI::Option("Exit/disable SCTV", ""))
		{
			globalHandle(GLOBAL_SCTV).As<bool>() = false;
			if (NETWORK::NETWORK_IS_SESSION_STARTED())
			{
				NETWORK::_SHUTDOWN_AND_LOAD_MOST_RECENT_SAVE();
			}
		}
	}
}