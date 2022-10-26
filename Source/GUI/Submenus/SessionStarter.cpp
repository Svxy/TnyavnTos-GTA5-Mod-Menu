#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int ChangeSessionInteger = 0;
void GUI::Submenus::SessionStarter()
{
	GUI::Title("Session Starter");
	GUI::Toggle("Lock to friends", CheatFeatures::SessionLockFriendsOnlyBool, "Continually kicks non-friends from session");
	GUI::Break("Join/Change", SELECTABLE_CENTER_TEXT);
	if (GUI::StringVector(NETWORK::NETWORK_IS_SESSION_STARTED() ? "Change Session" : "Join Session", { "Join Public", "New Public", "Closed Crew", "Crew", "Closed Friend", "Solo", "Invite Only" }, ChangeSessionInteger, "", SELECTABLE_DISABLE_SAVE))
	{
		eSessionTypes SetType;
		if (ChangeSessionInteger == 0)
		{
			SetType = SessionTypeJoinPublic;
		}
		else if (ChangeSessionInteger == 1)
		{
			SetType = SessionTypeNewPublic;
		}
		else if (ChangeSessionInteger == 2)
		{
			SetType = SessionTypeClosedCrew;
		}
		else if (ChangeSessionInteger == 3)
		{
			SetType = SessionTypeCrew;
		}
		else if (ChangeSessionInteger == 4)
		{
			SetType = SessionTypeClosedFriend;
		}
		else if (ChangeSessionInteger == 5)
		{
			SetType = SessionTypeSolo;
		}
		else if (ChangeSessionInteger == 6)
		{
			SetType = SessionTypeInviteOnly;
		}
		GameFunctions::ChangeGTAOSessionType(SetType);
	}
	if (GUI::Option("Join Session Containing Friends", "Searches for and joins a game session with one or more friends"))
	{
		GameFunctions::ChangeGTAOSessionType(SessionTypeFindFriend);
	}
	if (GUI::Option("Join Session Containing Crew Members", "Searches for and joins a game session with one or more crew members"))
	{
		GameFunctions::ChangeGTAOSessionType(SessionTypeJoinCrew);
	}
	GUI::Break("SCTV", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Start SCTV Public Session", "Also known as Rockstar Dev/Spectator Mode"))
	{
		globalHandle(GLOBAL_SCTV).As<bool>() = true;
		GameFunctions::ChangeGTAOSessionType(SessionTypeJoinPublic);
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