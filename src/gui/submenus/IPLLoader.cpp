#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
int LoadOrUnloadMPData;
int IPLLoaderNorthYankton, IPLLoaderDignityHeistYacht, IPLLoaderDestroyedHospital,
IPLLoaderJewelryStore, IPLLoaderMorgue, IPLLoaderCargoship, IPLLoaderAircraftCarrier;
const std::string LoadedIPL = "Loaded specified IPL";
const std::string UnloadedIPL = "Unloaded specified IPL";
void GUI::Submenus::IPLLoader()
{
	GUI::Title("IPL Loader");
	if (GUI::StringVector("GTA:O Map Data", { "Load", "Unload" }, LoadOrUnloadMPData, "Load or unload GTA Online map data - required to load some IPL's in SP", SELECTABLE_DISABLE_SAVE))
	{
		if (LoadOrUnloadMPData == 0)
		{
			DLC::ON_ENTER_MP();
		}
		else
		{
			DLC::ON_ENTER_SP();
		}
	}
	GUI::Break("Item Placement Files", SELECTABLE_CENTER_TEXT);
	if (GUI::StringVector("North Yankton", { "Load", "Unload" }, IPLLoaderNorthYankton, "", SELECTABLE_DISABLE_SAVE))
	{
		bool LoadIPL = IPLLoaderNorthYankton == 0 ? true : false;
		for (auto const& IPLName : game_data::IPLNorthYankton)
		{
			if (LoadIPL)
			{
				STREAMING::REQUEST_IPL(IPLName);
			}
			else
			{
				STREAMING::REMOVE_IPL(IPLName);
			}
		}
		Game::notification::Minimap(helper::StringToChar(LoadIPL ? LoadedIPL : UnloadedIPL));
	}
	if (GUI::StringVector("Dignity Heist Yacht", { "Load", "Unload" }, IPLLoaderDignityHeistYacht, "", SELECTABLE_DISABLE_SAVE))
	{
		bool LoadIPL = IPLLoaderDignityHeistYacht == 0 ? true : false;
		for (auto const& IPLName : game_data::IPLDignityHeistYacht)
		{
			if (LoadIPL)
			{
				STREAMING::REQUEST_IPL(IPLName);
			}
			else
			{
				STREAMING::REMOVE_IPL(IPLName);
			}
		}
		Game::notification::Minimap(helper::StringToChar(LoadIPL ? LoadedIPL : UnloadedIPL));
	}
	if (GUI::StringVector("Destroyed Hospital", { "Load", "Unload" }, IPLLoaderDestroyedHospital, "", SELECTABLE_DISABLE_SAVE))
	{
		bool LoadIPL = IPLLoaderDestroyedHospital == 0 ? true : false;
		for (auto const& IPLName : game_data::IPLDestroyedHospital)
		{
			if (LoadIPL)
			{
				STREAMING::REQUEST_IPL(IPLName);
			}
			else
			{
				STREAMING::REMOVE_IPL(IPLName);
			}
		}
		Game::notification::Minimap(helper::StringToChar(LoadIPL ? LoadedIPL : UnloadedIPL));
	}
	if (GUI::StringVector("Jewelry Store", { "Load", "Unload" }, IPLLoaderJewelryStore, "", SELECTABLE_DISABLE_SAVE))
	{
		bool LoadIPL = IPLLoaderJewelryStore == 0 ? true : false;
		for (auto const& IPLName : game_data::IPLJewelryStore)
		{
			if (LoadIPL)
			{
				STREAMING::REQUEST_IPL(IPLName);
			}
			else
			{
				STREAMING::REMOVE_IPL(IPLName);
			}
		}
		Game::notification::Minimap(helper::StringToChar(LoadIPL ? LoadedIPL : UnloadedIPL));
	}
	if (GUI::StringVector("Morgue", { "Load", "Unload" }, IPLLoaderMorgue, "", SELECTABLE_DISABLE_SAVE))
	{
		bool LoadIPL = IPLLoaderMorgue == 0 ? true : false;
		for (auto const& IPLName : game_data::IPLMorgue)
		{
			if (LoadIPL)
			{
				STREAMING::REQUEST_IPL(IPLName);
			}
			else
			{
				STREAMING::REMOVE_IPL(IPLName);
			}
		}
		Game::notification::Minimap(helper::StringToChar(LoadIPL ? LoadedIPL : UnloadedIPL));
	}
	if (GUI::StringVector("Cargoship", { "Load", "Unload" }, IPLLoaderCargoship, "", SELECTABLE_DISABLE_SAVE))
	{
		bool LoadIPL = IPLLoaderCargoship == 0 ? true : false;
		for (auto const& IPLName : game_data::IPLCargoship)
		{
			if (LoadIPL)
			{
				STREAMING::REQUEST_IPL(IPLName);
			}
			else
			{
				STREAMING::REMOVE_IPL(IPLName);
			}
		}
		Game::notification::Minimap(helper::StringToChar(LoadIPL ? LoadedIPL : UnloadedIPL));
	}
	if (GUI::StringVector("Aircraft Carrier", { "Load", "Unload" }, IPLLoaderAircraftCarrier, "You must load the GTA:O map data (see option above) for this IPL to work in SP", SELECTABLE_DISABLE_SAVE))
	{
		bool LoadIPL = IPLLoaderAircraftCarrier == 0 ? true : false;
		for (auto const& IPLName : game_data::IPLAircraftCarrier)
		{
			if (LoadIPL)
			{
				STREAMING::REQUEST_IPL(IPLName);
			}
			else
			{
				STREAMING::REMOVE_IPL(IPLName);
			}
		}
		Game::notification::Minimap(helper::StringToChar(LoadIPL ? LoadedIPL : UnloadedIPL));
	}
}