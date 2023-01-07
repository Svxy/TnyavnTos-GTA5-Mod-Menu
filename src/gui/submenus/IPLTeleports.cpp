#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::IPLTeleports()
{
	GUI::Title("IPL Teleports");
	if (GUI::Option("North Yankton", ""))
	{
		Vector3 Coords = { 5309.519f, -5212.375f, 83.522f };
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coords, false, false);
	}
	if (GUI::Option("Yacht", ""))
	{
		Vector3 Coords = { -2045.8f, -1031.2f, 11.9f };
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coords, false, false);
	}
	if (GUI::Option("Destroyed Hospital", ""))
	{
		Vector3 Coords = { 356.8f, -590.1f, 43.3f };
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coords, false, false);
	}
	if (GUI::Option("Jewelry Store", ""))
	{
		Vector3 Coords = { -630.4f, -236.7f, 40.0f };
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coords, false, false);
	}
	if (GUI::Option("Morgue", ""))
	{
		Vector3 Coords = { 244.9f, -1374.7f, 39.5f };
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coords, false, false);
	}
	if (GUI::Option("Cargo Ship", ""))
	{
		Vector3 Coords = { -90.0f, -2365.8f, 14.3f };
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coords, false, false);
	}
	if (GUI::Option("Aircraft Carrier", ""))
	{
		Vector3 Coords = { 3073.6f, -4715.4f, 16.f };
		Game::teleport::to_coords(PLAYER::PLAYER_PED_ID(), Coords, false, false);
	}
}