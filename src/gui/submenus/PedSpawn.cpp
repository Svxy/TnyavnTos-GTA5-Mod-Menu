#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/data/game_data.hpp"

using namespace Cheat;
void GUI::Submenus::PedSpawn()
{
	GUI::Title("Ped Spawn");
	for (auto const& i : game_data::PedModels)
	{
		if (GUI::Option(i, "Select to spawn"))
		{
			Hash PedHash = MISC::GET_HASH_KEY(helper::StringToChar(i));
			if (STREAMING::IS_MODEL_A_PED(PedHash))
			{
				while (!STREAMING::HAS_MODEL_LOADED(PedHash)) { STREAMING::REQUEST_MODEL(PedHash); GameHooking::PauseMainFiber(0); }
				Vector3 NewPedPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0f, 5.0f, 0.0f);
				Ped NewPedHandle = PED::CREATE_PED(0, PedHash, NewPedPosition.x, NewPedPosition.y, NewPedPosition.z, 0, true, true);
				ENTITY::SET_ENTITY_VISIBLE(NewPedHandle, true, false);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PedHash);
			}
		}
	}
}