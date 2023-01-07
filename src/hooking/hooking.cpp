#include "../cheat/fibermain.hpp"
#include "../cheat/file_system.hpp"
#include "../cheat/Logger.hpp"
#include "../hooking/natives.hpp"
#include "crossmap.hpp"
#include <MinHook.h>

using namespace Cheat;

IsDLCPresent														GameHooking::is_dlc_present;
TextureFileRegister													GameHooking::texture_file_register;
GetEventData														GameHooking::get_event_data;
GetLabelText														GameHooking::get_label_text;
GetScriptHandlerIfNetworked											GameHooking::get_script_handler_if_networked;
GetPlayerAddress													GameHooking::get_player_address;

HANDLE																GameHooking::fiber_main;
uint64_t															GameHooking::world_ptr;
__int64**															GameHooking::global_ptr;
DWORD																GameHooking::fiber_main_wake_time;
static eGameState* 													m_gameState;
static PUSHORT														m_requestEntityControlSpectateBypass;
static GameHooking::NativeRegistrationNew**							m_registrationTable;
static std::unordered_map<uint64_t, GameHooking::NativeHandler>		m_handlerCache;
const int EventCountInteger											= 85;
static char EventRestore[EventCountInteger]							= {};
static std::vector<void*> EventPtr;
std::vector<LPVOID>													MH_Hooked;

bool IsDLCPresentHooked												(std::uint32_t DLCHash);
bool GetEventDataHooked												(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
void* GetScriptHandlerIfNetworkedHooked								();
const char* GetLabelTextHooked										(void* this_, const char* label);

void GameHooking::Init()
{
	// Load pointers
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting IDP pointer");
	GameHooking::is_dlc_present = static_cast<IsDLCPresent>(Memory::pattern("48 89 5C 24 ? 57 48 83 EC 20 81 F9 ? ? ? ?").count(1).get(0).get<void>(0));

	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting GLT pointer");
	GameHooking::get_label_text = static_cast<GetLabelText>(Memory::pattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8").count(1).get(0).get<void>(0));
	
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting GSHIN pointer");
	GameHooking::get_script_handler_if_networked = static_cast<GetScriptHandlerIfNetworked>(Memory::pattern("40 53 48 83 EC 20 E8 ? ? ? ? 48 8B D8 48 85 C0 74 12 48 8B 10 48 8B C8").count(1).get(0).get<void>(0));
	
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting GED pointer");
	GameHooking::get_event_data = static_cast<GetEventData>(Memory::pattern("48 85 C0 74 14 4C 8B 10").count(1).get(0).get<void>(-28));
	
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting TFR pointer");
	GameHooking::texture_file_register = static_cast<TextureFileRegister>(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<void>());
	
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting GPA pointer");
	GameHooking::get_player_address = static_cast<GetPlayerAddress>(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));

	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting NRCOE pointer -> patched");
	m_requestEntityControlSpectateBypass = Memory::pattern("48 89 5C 24 ? 57 48 83 EC 20 8B D9 E8 ? ? ? ? ? ? ? ? 8B CB").count(1).get(0).get<USHORT>(0x13);
	*m_requestEntityControlSpectateBypass = 0x9090; // Set to 0x6A75 after changing to undo the patch

	char* c_location = nullptr;
	void* v_location = nullptr;

	// Load GameState
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting GS pointer");
	c_location = Memory::pattern("83 3D ? ? ? ? ? 75 17 8B 43 20 25").count(1).get(0).get<char>(2);
	if (c_location == nullptr) { Logger::LogMsg(LOGGER_ERROR_MSG, "Failed to load GameState"); } else { m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5); }

	// Load Vector3 Result Fix
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting VRF pointer");
	v_location = Memory::pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18").count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);

	// Load Native Registration Table
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting NRT pointer");
	c_location = Memory::pattern("76 32 48 8B 53 40 48 8D 0D").count(1).get(0).get<char>(9);
	if (c_location == nullptr) { Logger::LogMsg(LOGGER_ERROR_MSG, "Failed to load Native Registration Table"); } else { m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4); }

	// Load Game World Pointer
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting WLD pointer");
	c_location = Memory::pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07").count(1).get(0).get<char>(0);
	if (c_location == nullptr) { Logger::LogMsg(LOGGER_ERROR_MSG, "Failed to load World Pointer"); } else { GameHooking::world_ptr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7; }

	// Get Global Pointer
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Getting GLB pointer");
	c_location = Memory::pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11").count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	if (c_location == nullptr) { Logger::LogMsg(LOGGER_ERROR_MSG, "Failed to load Global Pointer"); } else { patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);	}
	GameHooking::global_ptr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	// Get Event Hook -> Used by defuseEvent
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Loading EH");
	if ((c_location = Memory::pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03").count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = (char*)"\x4C\x8D\x05";
		while (found != EventCountInteger)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}

	// Initialize Natives
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Initialized GN");
	crossmap::initNativeMap();

	bool WaitingGameLoadLogPrinted = false;
	while (*m_gameState != GameStatePlaying)
	{
		if (!WaitingGameLoadLogPrinted)
		{
			Logger::LogMsg(LoggerMsgTypes::LOGGER_INFO_MSG, "Waiting for game");
			WaitingGameLoadLogPrinted = true;
		}
		Sleep(100);
	}
	if (WaitingGameLoadLogPrinted)
	{
		Logger::LogMsg(LoggerMsgTypes::LOGGER_INFO_MSG,"Game completed loading");
	}

	// Hook Game Functions
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Hook GED");
	auto status = MH_CreateHook(GameHooking::get_event_data, GetEventDataHooked, (void**)&GetEventDataOriginal);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(GameHooking::get_event_data) != MH_OK) { Logger::LogMsg(LOGGER_FATAL_MSG, "Failed to hook GET_EVENT_DATA");  std::exit(EXIT_FAILURE); }
	MH_Hooked.push_back(GameHooking::get_event_data);

	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Hook GSHIN");
	status = MH_CreateHook(GameHooking::get_script_handler_if_networked, GetScriptHandlerIfNetworkedHooked, NULL);
	if (status != MH_OK || MH_EnableHook(GameHooking::get_script_handler_if_networked) != MH_OK) { Logger::LogMsg(LOGGER_FATAL_MSG, "Failed to hook GET_SCRIPT_HANDLER_IF_NETWORKED");  std::exit(EXIT_FAILURE); }
	MH_Hooked.push_back(GameHooking::get_script_handler_if_networked);

	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Hook GLT");
	status = MH_CreateHook(GameHooking::get_label_text, GetLabelTextHooked, (void**)&GetLabelTextOriginal);
	if (status != MH_OK || MH_EnableHook(GameHooking::get_label_text) != MH_OK) { Logger::LogMsg(LOGGER_FATAL_MSG, "Failed to hook GET_LABEL_TEXT");  std::exit(EXIT_FAILURE); }
	MH_Hooked.push_back(GameHooking::get_label_text);

	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Hook IDP");
	status = MH_CreateHook(GameHooking::is_dlc_present, IsDLCPresentHooked, (void**)&IsDLCPresentOriginal);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(GameHooking::is_dlc_present) != MH_OK) { Logger::LogMsg(LOGGER_FATAL_MSG, "Failed to hook IS_DLC_PRESENT");  std::exit(EXIT_FAILURE); }
	MH_Hooked.push_back(GameHooking::is_dlc_present);
}

void GameHooking::PauseMainFiber(DWORD ms, bool ShowMessage)
{
	if (ShowMessage) { GUI::DrawTextInGame("One Moment Please", { 255, 255, 255, 255 }, { 0.525f, 0.400f }, { 1.5f, 1.5f }, true, true); }
	fiber_main_wake_time = timeGetTime() + ms;
	SwitchToFiber(fiber_main);
}

static GameHooking::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = crossmap::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	GameHooking::NativeRegistrationNew * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

GameHooking::NativeHandler GameHooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];
	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}
	return handler;
}

void GameHooking::defuseEvent(GameEvents e, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

std::vector<LPVOID> GameHooking::GetMH_Hooked()
{
	return MH_Hooked;
}