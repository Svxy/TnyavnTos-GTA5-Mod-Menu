#pragma once
#include <Windows.h>

namespace Cheat
{
	class entry_point
	{
	public:
		static HMODULE module_handle;
		static DWORD WINAPI init_thread(LPVOID lpParam);
	};
}