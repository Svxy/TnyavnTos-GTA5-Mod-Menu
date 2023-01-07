#pragma once
#include "types.hpp"
#include "nativeinvoker.hpp"
#include "..\game\enums.hpp"
#include <vector>

typedef bool(__cdecl* IsDLCPresent)							(Hash dlcHash);
typedef uint32_t*(__cdecl* TextureFileRegister)				(int*, const char*, bool, const char*, bool);
typedef bool(__cdecl* GetEventData)							(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
using GetScriptHandlerIfNetworked							= void* (*) ();
typedef const char* (__cdecl* GetLabelText)					(void* this_, const char* label);
typedef __int64(__cdecl* GetPlayerAddress)					(Player);

class GameHooking
{
public:
	static HANDLE							fiber_main;
	static uint64_t							world_ptr;
	static __int64**						global_ptr;
	static IsDLCPresent					    is_dlc_present;
	static TextureFileRegister				texture_file_register;
	static GetEventData						get_event_data;
	static GetScriptHandlerIfNetworked		get_script_handler_if_networked;
	static GetLabelText						get_label_text;
	static GetPlayerAddress					get_player_address;
	static DWORD							fiber_main_wake_time;

	static IsDLCPresent IsDLCPresentOriginal;
	static GetLabelText GetLabelTextOriginal;
	static GetEventData GetEventDataOriginal;

	static void Init();
	static void PauseMainFiber(DWORD ms, bool ShowMessage = true);
	static std::vector<LPVOID> GetMH_Hooked();
	static void defuseEvent(GameEvents e, bool toggle);
	typedef void(__cdecl * NativeHandler)(scrNativeCallContext * context);
	struct NativeRegistrationNew
	{
		uint64_t nextRegistration1;
		uint64_t nextRegistration2;
		GameHooking::NativeHandler handlers[7];
		uint32_t numEntries1;
		uint32_t numEntries2;
		uint64_t hashes;

		inline NativeRegistrationNew* getNextRegistration()
		{
			uintptr_t result;
			auto v5 = reinterpret_cast<uintptr_t>(&nextRegistration1);
			auto v12 = 2i64;
			auto v13 = v5 ^ nextRegistration2;
			auto v14 = (char *)&result - v5;
			do
			{
				*(DWORD*)&v14[v5] = v13 ^ *(DWORD*)v5;
				v5 += 4i64;
				--v12;
			} while (v12);

			return reinterpret_cast<NativeRegistrationNew*>(result);
		}

		inline uint32_t getNumEntries()
		{
			return ((uintptr_t)&numEntries1) ^ numEntries1 ^ numEntries2;
		}

		inline uint64_t getHash(uint32_t index)
		{

			auto naddr = 16 * index + reinterpret_cast<uintptr_t>(&nextRegistration1) + 0x54;
			auto v8 = 2i64;
			uint64_t nResult;
			auto v11 = (char *)&nResult - naddr;
			auto v10 = naddr ^  *(DWORD*)(naddr + 8);
			do
			{
				*(DWORD *)&v11[naddr] = v10 ^ *(DWORD*)(naddr);
				naddr += 4i64;
				--v8;
			} while (v8);

			return nResult;
		}
	};
	static NativeHandler GetNativeHandler(uint64_t origHash);
};