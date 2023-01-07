#include "../../cheat/fibermain.hpp"
#include "../../cheat/Logger.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;

using GetScriptHandler = void* (*) ();
GetScriptHandler get_script_handler = nullptr;
bool init = false;

/*
This hook is required to be able to spawn vehicles and objects in GTAO
*/
void* GetScriptHandlerIfNetworkedHooked()
{
	if (!init)
	{
		get_script_handler = static_cast<GetScriptHandler>(Memory::pattern("48 83 EC 28 E8 ? ? ? ? 33 C9 48 85 C0 74 0C E8 ? ? ? ? 48 8B 88 ? ? ? ?").count(1).get(0).get<void>(0));
		if (get_script_handler == nullptr)
		{
			Logger::LogMsg(LOGGER_FATAL_MSG, "Failed getting GSH pointer");
			std::exit(EXIT_FAILURE);
		}
		Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting GSH pointer -> succeeded");
		init = true;
	}
	return get_script_handler();
}