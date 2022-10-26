#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
void GUI::Submenus::ProtectionScriptEvents()
{
	GUI::Title("Script Events Protection");
	GUI::Toggle("Block All", CheatFeatures::BlockAllScriptEvents, "Blocks all script events send to you - join a session before enabling", SELECTABLE_DISABLE_SAVE);
	GUI::Break("Script Events", SELECTABLE_CENTER_TEXT);
	GUI::Toggle("Kicks", CheatFeatures::ProtectionScriptEvents_Kicks, "");
	GUI::Toggle("CEO Kick", CheatFeatures::ProtectionScriptEvents_CEOKick, "");
	GUI::Toggle("CEO Ban", CheatFeatures::ProtectionScriptEvents_CEOBan, "");
	GUI::Toggle("CEO Money", CheatFeatures::ProtectionScriptEvents_CEOMoney, "");
	GUI::Toggle("Property Teleport", CheatFeatures::ProtectionScriptEvents_PropertyTeleport, "");
	GUI::Toggle("Cayo Perico Teleport", CheatFeatures::ProtectionScriptEvents_CayoPericoTeleport, "");
	GUI::Toggle("Force Into Mission", CheatFeatures::ProtectionScriptEvents_ForceIntoMission, "");
	GUI::Toggle("Bounty", CheatFeatures::ProtectionScriptEvents_Bounty, "");
	GUI::Toggle("Clear Wanted Level", CheatFeatures::ProtectionScriptEvents_ClearWantedlevel, "");
	GUI::Toggle("Game Banner", CheatFeatures::ProtectionScriptEvents_GameBanner, "");
	GUI::Toggle("Network Bail", CheatFeatures::ProtectionScriptEvents_NetworkBail, "");
	GUI::Toggle("Crash", CheatFeatures::ProtectionScriptEvents_Crash, "");
	GUI::Toggle("Personal Vehicle Destroyed", CheatFeatures::ProtectionScriptEvents_PersonalVehicleDestroyed, "");
	GUI::Toggle("Remote Off Radar", CheatFeatures::ProtectionScriptEvents_RemoteOffradar, "");
	GUI::Toggle("Send To Cutscene", CheatFeatures::ProtectionScriptEvents_SendToCutscene, "");
	GUI::Toggle("Send To Location", CheatFeatures::ProtectionScriptEvents_SendToLocation, "");
	GUI::Toggle("Sound Spam", CheatFeatures::ProtectionScriptEvents_SoundSpam, "");
	GUI::Toggle("Spectate", CheatFeatures::ProtectionScriptEvents_Spectate, "");
}