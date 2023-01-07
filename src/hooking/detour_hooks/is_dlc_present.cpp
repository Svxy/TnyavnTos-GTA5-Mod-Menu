#include "../../cheat/fibermain.hpp"
#include "../../cheat/cheat.hpp"
#include "../../hooking/natives.hpp"

IsDLCPresent GameHooking::IsDLCPresentOriginal = nullptr;
bool IsDLCPresentHooked(std::uint32_t DLCHash)
{
	static uint64_t	Last = 0;
	uint64_t Current = MISC::GET_FRAME_COUNT();
	if (Cheat::core::c_running && Last != Current)
	{
		Last = Current;
		if (GameHooking::fiber_main == nullptr)
		{
			GameHooking::fiber_main = ConvertThreadToFiber(nullptr);
		}

		static HANDLE scriptFiber;
		if (timeGetTime() > GameHooking::fiber_main_wake_time)
		{
			if (scriptFiber != nullptr)
			{
				SwitchToFiber(scriptFiber);
			}
			else
			{
				scriptFiber = CreateFiber(NULL, Cheat::fibermain::func_, nullptr);
			}
		}
	}
	return GameHooking::IsDLCPresentOriginal(DLCHash);
}