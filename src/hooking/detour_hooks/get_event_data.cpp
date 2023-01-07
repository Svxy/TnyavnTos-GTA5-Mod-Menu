#include "../../cheat/fibermain.hpp"
#include "../../game/notification.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;

GetEventData GameHooking::GetEventDataOriginal = nullptr;
bool GetEventDataHooked(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount)
{
	auto result = static_cast<decltype(&GetEventDataHooked)>(GameHooking::GetEventDataOriginal)(eventGroup, eventIndex, args, argCount);
	if (result)
	{
		bool BlockScriptEvent = false;
		std::string ScriptEventIDType;
		const auto EventHash = static_cast<eRemoteEvents>(args[0]);

		// Check whether the incoming event needs to be blocked
		if (Features::BlockAllScriptEvents)
		{
			BlockScriptEvent = true;
		}
		else
		{
			switch (EventHash)
			{
			case eRemoteEvents::KickToSP:
			case eRemoteEvents::KickToSP2:
				if (Features::ProtectionScriptEvents_Kicks)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = "session kick";
				}
				break;
			case eRemoteEvents::CeoMoney:
				if (Features::ProtectionScriptEvents_CEOMoney)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " giving CEO money";
				}
				break;
			case eRemoteEvents::PropertyTeleport:
				if (Features::ProtectionScriptEvents_PropertyTeleport)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = "property teleport";
				}
				break;
			case eRemoteEvents::CayoPericoTeleport:
				if (Features::ProtectionScriptEvents_CayoPericoTeleport)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = "cayo perico teleport";
				}
				break;
			case eRemoteEvents::ForceIntoMission:
			case eRemoteEvents::ForceIntoMission2:
				if (Features::ProtectionScriptEvents_ForceIntoMission)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = "force into mission";
				}
				break;
			case eRemoteEvents::Bounty:
				if (Features::ProtectionScriptEvents_Bounty)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = "setting bounty";
				}
				break;
			case eRemoteEvents::ClearWantedLevel:
				if (Features::ProtectionScriptEvents_ClearWantedlevel)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " clearing wanted level";
				}
				break;
			case eRemoteEvents::GameBanner:
				if (Features::ProtectionScriptEvents_GameBanner)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " showing a banner";
				}
				break;
			case eRemoteEvents::NetworkBail:
				if (Features::ProtectionScriptEvents_NetworkBail)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " network bail";
				}
				break;
			case eRemoteEvents::Crash:
			case eRemoteEvents::Crash2:
			case eRemoteEvents::Crash3:
				if (Features::ProtectionScriptEvents_Crash)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " game crash";
				}
				break;
			case eRemoteEvents::PersonalVehicleDestroyed:
				if (Features::ProtectionScriptEvents_PersonalVehicleDestroyed)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " showing personal vehicle destroyed msg";
				}
				break;
			case eRemoteEvents::RemoteOffradar:
				if (Features::ProtectionScriptEvents_RemoteOffradar)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " activating off the radar";
				}
				break;
			case eRemoteEvents::SendToCutscene:
				if (Features::ProtectionScriptEvents_SendToCutscene)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " sending you to a cutscene";
				}
				break;
			case eRemoteEvents::SendToLocation:
				if (Features::ProtectionScriptEvents_SendToLocation)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " sending you to a location";
				}
				break;
			case eRemoteEvents::SoundSpam:
				if (Features::ProtectionScriptEvents_SoundSpam)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " sound spam";
				}
				break;
			case eRemoteEvents::Spectate:
				if (Features::ProtectionScriptEvents_Spectate)
				{
					BlockScriptEvent = true;
					ScriptEventIDType = " spectating";
				}
				break;
			}
		}

		// Do the actual event block and show a notification
		if (BlockScriptEvent)
		{
			if (!Features::BlockAllScriptEvents)
			{
				std::string MessageString = "ID: " + std::to_string(args[0]);
				if (!ScriptEventIDType.empty())
				{
					MessageString.append("~n~Block reason: attempted " + ScriptEventIDType);
				}
				Game::notification::MinimapAdvanced(MessageString.data(), (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Script Events Protection", (char*)"", 0.8f, (char*)"");
			}
			return false;
		}
	}
	return result;
}