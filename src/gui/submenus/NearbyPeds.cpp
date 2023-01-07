#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;
void GUI::Submenus::NearbyPeds()
{
	GUI::Title("Nearby Peds");
	if (GUI::Option("Explode Peds", "Explode nearby peds"))
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			Game::entity::request_network_control(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(peds[OffsetID], false);
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 0, 1000.f, true, false, 0.f, false);
			}
		}
	}
	if (GUI::Option("Kill Peds", "Kill nearby peds"))
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			Game::entity::request_network_control(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false, 0);
			}
		}
	}
}